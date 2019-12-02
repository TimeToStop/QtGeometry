#include "propertiespointuidialog.h"

#include "Files/PointUI/pointui.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QDoubleValidator>

PropertiesPointUIDialog::PropertiesPointUIDialog(PointUI* point, QWidget *parent) :
    PropertiesObjectDialog(point, parent)
{
    setWindowTitle("PointUI: " + dynamic_cast<PointUI*>(m_obj)->name());
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

    buttons->addWidget(admit);

    main->addLayout(name);
    main->addLayout(posX);
    main->addLayout(posY);
    main->addLayout(buttons);

    connect(admit, SIGNAL(clicked()), this, SLOT(accept()));

    nameEdit->setReadOnly(true);

    m_name = nameEdit;
    m_x = lineX;
    m_y = lineY;

    QDoubleValidator* validator = new QDoubleValidator();

    m_x->setValidator(validator);
    m_y->setValidator(validator);
}

PropertiesPointUIDialog::~PropertiesPointUIDialog()
{

}

void PropertiesPointUIDialog::setPropertiesToObject()
{
    dynamic_cast<PointUI*>(m_obj)->setPosXOY(QPointF(m_x->text().toDouble(), m_y->text().toDouble()));
}

void PropertiesPointUIDialog::setPropertiesToDialog()
{
    m_name->setText(dynamic_cast<PointUI*>(m_obj)->name());

    QString buff;

    buff.setNum(dynamic_cast<PointUI*>(m_obj)->posXOY().x());
    m_x->setText(buff);

    buff.setNum(dynamic_cast<PointUI*>(m_obj)->posXOY().y());
    m_y->setText(buff);
}
