#include "removeshapedialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QSpacerItem>

RemoveShapeDialog::RemoveShapeDialog(std::vector<Shape*>& shapes, QWidget* parent):
    QDialog(parent),
    m_shapes(shapes)
{
    setFixedSize(300, 75);

    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* name = new QHBoxLayout();

    QLabel* label = new QLabel("Name: ");
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

    m_list = box;

    for(Shape* shape : m_shapes)
    {
        m_list->addItem(shape->name());
    }
}

RemoveShapeDialog::~RemoveShapeDialog()
{

}

void RemoveShapeDialog::admit()
{
    delete m_shapes[static_cast<size_t>(m_list->currentIndex())];

    m_shapes.erase(m_shapes.begin() + m_list->currentIndex());
}
