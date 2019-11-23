#ifndef PROPERTIESLINEDIALOG_H
#define PROPERTIESLINEDIALOG_H

#include "Files/Object/propertiesobjectdialog.h"
#include "line.h"

class PropertiesLineDialog : public PropertiesObjectDialog
{
    Q_OBJECT
public:
    explicit PropertiesLineDialog(Line*,QWidget *parent = nullptr);
    virtual ~PropertiesLineDialog();

    virtual void setPropertiesToObject();
    virtual void setPropertiesToDialog();

signals:

public slots:
};

#endif // PROPERTIESLINEDIALOG_H
