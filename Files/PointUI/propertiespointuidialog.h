#ifndef PROPERTIESPOINTUIDIALOG_H
#define PROPERTIESPOINTUIDIALOG_H

#include "Files/Object/propertiesobjectdialog.h"

#include <QLineEdit>
#include <QDialog>

class PointUI;

class PropertiesPointUIDialog : public PropertiesObjectDialog
{
    Q_OBJECT

    QLineEdit* m_name;
    QLineEdit* m_x;
    QLineEdit* m_y;

public:
    explicit PropertiesPointUIDialog(PointUI*, QWidget *parent = nullptr);
    virtual ~PropertiesPointUIDialog();

    virtual void setPropertiesToObject();
    virtual void setPropertiesToDialog();

signals:

public slots:

};

#endif // PROPERTIESPOINTUIDIALOG_H
