#include "createlinedialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

CreateLineDialog::CreateLineDialog(std::vector<Shape*>& shapes, std::vector<PointUI*>& points,QWidget *parent) :
    CreateAbstractShapeDialog(shapes, points, parent)
{
    setFixedSize(300, 100);

    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* name = new QHBoxLayout();

    QLabel* label = new QLabel("Create by: ");
    QComboBox* box = new QComboBox();

    name->addWidget(label);
    name->addWidget(box);

    QHBoxLayout* buttons = new QHBoxLayout();

    QSpacerItem* spacer = new QSpacerItem(150, 20);
    QPushButton* accept = new QPushButton("Ok");
    QPushButton* reject = new QPushButton("Exit");

    buttons->addSpacerItem(spacer);
    buttons->addWidget(accept);
    buttons->addWidget(reject);

    main->addLayout(name);
    main->addLayout(buttons);

    connect(accept, SIGNAL(clicked()), this, SLOT(accept()));
    connect(accept, SIGNAL(clicked()), this, SLOT(admit()));
    connect(reject, SIGNAL(clicked()), this, SLOT(reject()));

    m_box = box;

    m_box->addItem("Two points");
    m_box->addItem("Point and line");
    m_box->addItem("Equation");
}

CreateLineDialog::~CreateLineDialog()
{
}

void CreateLineDialog::admit()
{
    switch(m_box->currentIndex()) {
    case 0: {

    } break;
    case 1: {

    } break;
    case 2: {

    } break;
    default:
        break;
    }
}
