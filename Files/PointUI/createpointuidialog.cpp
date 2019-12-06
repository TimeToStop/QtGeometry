#include "createpointuidialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QDoubleValidator>

CreatePointUIDialog::CreatePointUIDialog(std::vector<PointUI*> &points, QWidget* parent):
    QDialog(parent),
    m_points(points)
{
    setMinimumSize(200, 150);

    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* name = new QHBoxLayout();

    QLabel* nameLabel = new QLabel("Name: ");
    QLineEdit* nameEdit = new QLineEdit();

    name->addWidget(nameLabel);
    name->addWidget(nameEdit);

    QSpacerItem* spacer = new QSpacerItem(100, 10);

    QHBoxLayout* posX = new QHBoxLayout();

    QLabel* x = new QLabel("X: ");
    QLineEdit* lineX = new QLineEdit();

    posX->addSpacerItem(spacer);
    posX->addWidget(x);
    posX->addWidget(lineX);

    QHBoxLayout* posY = new QHBoxLayout();

    QLabel* y = new QLabel("Y: ");
    QLineEdit* lineY = new QLineEdit();

    posY->addSpacerItem(spacer);
    posY->addWidget(y);
    posY->addWidget(lineY);

    QHBoxLayout* buttons = new QHBoxLayout();

    QPushButton* admit = new QPushButton("Ok");
    QPushButton* exit = new QPushButton("Exit");

    buttons->addWidget(admit);
    buttons->addWidget(exit);

    main->addLayout(name);
    main->addLayout(posX);
    main->addLayout(posY);
    main->addLayout(buttons);

    connect(admit, SIGNAL(clicked()), this, SLOT(accept()));
    connect(admit, SIGNAL(clicked()), this, SLOT(admit()));
    connect(exit, SIGNAL(clicked()), this, SLOT(reject()));

    m_name = nameEdit;
    m_x = lineX;
    m_y = lineY;

    QDoubleValidator* validator = new QDoubleValidator();

    m_x->setValidator(validator);
    m_y->setValidator(validator);
}

CreatePointUIDialog::~CreatePointUIDialog()
{

}

void CreatePointUIDialog::admit()
{
    if(m_name->text() == "" || m_x->text() == "" || m_y->text() == "")
    {
        return;
    }

    for(PointUI* point : m_points)
    {
        if(point->name() == m_name->text())
        {
            return;
        }
        else
        {
            Double x = m_x->text().toDouble();
            Double y = m_y->text().toDouble();

            if ((x == point->posXOY().x()) && (y == point->posXOY().y()))
            {
                return;
            }
        }
    }

    m_points.push_back(new PointUI(m_x->text().toDouble(), m_y->text().toDouble(), m_name->text()));
}
