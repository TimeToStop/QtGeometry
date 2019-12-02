#include "propertieslinedialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

PropertiesLineDialog::PropertiesLineDialog(Line* line, QWidget *parent) :
    PropertiesObjectDialog(line, parent)
{
    setWindowTitle(dynamic_cast<Line*>(m_obj)->nameAndType());

    QVBoxLayout* main = new QVBoxLayout(this);
    QHBoxLayout* eq = new QHBoxLayout();

    QLineEdit* a_edit = new QLineEdit();
    QLabel* a = new QLabel(" * x + ");

    QLineEdit* b_edit = new QLineEdit();
    QLabel* b = new QLabel(" * y + ");

    QLineEdit* c_edit = new QLineEdit();
    QLabel* c = new QLabel(" = 0");

    eq->addWidget(a_edit);
    eq->addWidget(a);
    eq->addWidget(b_edit);
    eq->addWidget(b);
    eq->addWidget(c_edit);
    eq->addWidget(c);

    main->addLayout(eq);

    QHBoxLayout* buttons = new QHBoxLayout();

    QPushButton* ok = new QPushButton("Ok");

    buttons->addWidget(ok);

    main->addLayout(buttons);

    connect(ok,SIGNAL(clicked()), this, SLOT(accept()));

    a_edit->setReadOnly(false);
    b_edit->setReadOnly(false);
    c_edit->setReadOnly(false);

    m_a_edit = a_edit;
    m_b_edit = b_edit;
    m_c_edit = c_edit;
}

PropertiesLineDialog::~PropertiesLineDialog()
{

}

void PropertiesLineDialog::setPropertiesToObject()
{

}

void PropertiesLineDialog::setPropertiesToDialog()
{
    const Line* l = dynamic_cast<Line*>(m_obj);
    QString buff;

    buff.setNum(static_cast<double>(l->a()));
    m_a_edit->setText(buff);
    buff.setNum(static_cast<double>(l->b()));
    m_b_edit->setText(buff);
    buff.setNum(static_cast<double>(l->c()));
    m_c_edit->setText(buff);
}
