#include "widget.h"
#include "Files/field.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* main = new QHBoxLayout(this);

    Field* field = new Field(1000, 800);
    QVBoxLayout* buttons = new QVBoxLayout();

    main->addWidget(field);
    main->addLayout(buttons);

    QPushButton* addPoint = new QPushButton("Add point");
    QPushButton* propPoint = new QPushButton("Properties point");
    QPushButton* rmPoint = new QPushButton("Remove point");

    QSpacerItem* spacer1 = new QSpacerItem(10, 120);

    QPushButton* addShape = new QPushButton("Add shape");
    QPushButton* propShape = new QPushButton("Properties shape");
    QPushButton* rmShape = new QPushButton("Remove shape");

    QSpacerItem* spacer2 = new QSpacerItem(10, 510);

    buttons->addWidget(addPoint);
    buttons->addWidget(propPoint);
    buttons->addWidget(rmPoint);

    buttons->addSpacerItem(spacer1);

    buttons->addWidget(addShape);
    buttons->addWidget(propShape);
    buttons->addWidget(rmShape);

    buttons->addSpacerItem(spacer2);

    connect(addPoint, SIGNAL(clicked()), field, SLOT(addPointUIDialog()));
    connect(propPoint, SIGNAL(clicked()), field, SLOT(openPointUIPropertiesDialog()));
    connect(rmPoint, SIGNAL(clicked()), field, SLOT(rmPointUIDialog()));

    connect(addShape, SIGNAL(clicked()), field, SLOT(addShapeDialog()));
    connect(propShape, SIGNAL(clicked()), field, SLOT(openShapePropertiesDialog()));
    connect(rmShape, SIGNAL(clicked()), field, SLOT(rmShapeDialog()));
}

Widget::~Widget()
{

}
