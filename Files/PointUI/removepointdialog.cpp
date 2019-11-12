#include "removepointdialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

RemovePointDialog::RemovePointDialog(std::vector<PointUI*>& points, QWidget *parent) :
    QDialog(parent),
    m_points(points)
{
    setFixedSize(200, 100);

    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* name = new QHBoxLayout();
    QHBoxLayout* buttons = new QHBoxLayout();

    main->addLayout(name);
    main->addLayout(buttons);

    QLabel* pointName = new QLabel("Name: ");
    QComboBox* list = new QComboBox();

    name->addWidget(pointName);
    name->addWidget(list);

    QPushButton* accept = new QPushButton("Ok");
    QPushButton* reject = new QPushButton("Exit");

    buttons->addWidget(accept);
    buttons->addWidget(reject);

    connect(accept, SIGNAL(clicked()), this, SLOT(accept()));
    connect(accept, SIGNAL(clicked()), this, SLOT(admit()));
    connect(reject, SIGNAL(clicked()), this, SLOT(reject()));

    for(PointUI* e : m_points)
    {
        list->addItem(e->name());
    }

    m_list = list;
}

RemovePointDialog::~RemovePointDialog()
{

}

void RemovePointDialog::admit()
{
    delete m_points[static_cast<size_t>(m_list->currentIndex())];

    m_points.erase(m_points.begin() + m_list->currentIndex());
}
