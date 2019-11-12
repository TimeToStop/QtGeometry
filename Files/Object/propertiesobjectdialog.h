#ifndef PROPERTIESOBJECTDIALOG_H
#define PROPERTIESOBJECTDIALOG_H

#include <QDialog>

class Object;

class PropertiesObjectDialog : public QDialog
{
    Q_OBJECT

protected:
    Object* m_obj;

public:
    explicit PropertiesObjectDialog(Object*, QWidget *parent = nullptr);
    virtual ~PropertiesObjectDialog();

    virtual void hideEvent(QHideEvent*) final;
    virtual void setPropertiesToObject() = 0;
    virtual void setPropertiesToDialog() = 0;

signals:

public slots:
};

#endif // PROPERTIESOBJECTDIALOG_H
