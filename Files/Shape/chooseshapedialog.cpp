#include "chooseshapedialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QPushButton>
#include <QComboBox>

ChooseShapeDialog::ChooseShapeDialog(const std::vector<Shape*>& points, QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(200, 100);

    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* names = new QHBoxLayout();

    QLabel* label = new QLabel("Name: ");
    QComboBox* list = new QComboBox();

    names->addWidget(label);
    names->addWidget(list);

    QHBoxLayout* buttons = new QHBoxLayout();

    QSpacerItem* spacer = new QSpacerItem(50, 10);
    QPushButton* button = new QPushButton("Ok");

    buttons->addSpacerItem(spacer);
    buttons->addWidget(button);

    main->addLayout(names);
    main->addLayout(buttons);

    m_list = list;

    for(Shape* e : points)
    {
        m_list->addItem(e->nameAndType());
    }

    connect(button, SIGNAL(clicked()), this, SLOT(admit()));
    connect(this, SIGNAL(result(int)), this, SLOT(done(int)));
}

ChooseShapeDialog::~ChooseShapeDialog()
{

}

void ChooseShapeDialog::admit()
{
    emit(result(m_list->currentIndex()));
}
