#ifndef PROPERTIESLINEDIALOG_H
#define PROPERTIESLINEDIALOG_H

#include "Files/Object/propertiesobjectdialog.h"
#include "line.h"

#include <QLineEdit>

class PropertiesLineDialog : public PropertiesObjectDialog
{
    Q_OBJECT

    QLineEdit* m_a_edit;
    QLineEdit* m_b_edit;
    QLineEdit* m_c_edit;

public:
    explicit PropertiesLineDialog(Line*,QWidget *parent = nullptr);
    virtual ~PropertiesLineDialog();

    virtual void setPropertiesToObject();
    virtual void setPropertiesToDialog();

signals:

public slots:
};

#endif // PROPERTIESLINEDIALOG_H
