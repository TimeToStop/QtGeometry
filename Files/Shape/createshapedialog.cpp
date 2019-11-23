#include "createshapedialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

CreateShapeDialog::CreateShapeDialog(std::vector<Shape*>& shapes, QWidget *parent):
    QDialog(parent),
    m_shapes(shapes)
{
    setFixedSize(300, 100);

    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* name = new QHBoxLayout();

    QLabel* label = new QLabel("Type: ");
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

    m_box->addItem("Line");
}

CreateShapeDialog::~CreateShapeDialog()
{

}

void CreateShapeDialog::admit()
{
    switch(m_box->currentIndex())
    {
        case Type::Type_Line:
            break;
    }
}
