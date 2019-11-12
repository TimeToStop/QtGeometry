#ifndef PROPERTIESABSTRACTSHAPEDIALOG_H
#define PROPERTIESABSTRACTSHAPEDIALOG_H

#include "Files/Object/propertiesobjectdialog.h"
#include "Files/Shape/shape.h"


class PropertiesShapeDialog : public PropertiesObjectDialog
{
    Q_OBJECT

    Shape* m_shape;

public:
    explicit PropertiesShapeDialog(Shape* shape, QWidget *parent = nullptr);
    virtual ~PropertiesShapeDialog();

    virtual void setPropertiesToObject() = 0;
    virtual void setPropertiesToDialog() = 0;

signals:

public slots:
};

#endif // PROPERTIESABSTRACTSHAPEDIALOG_H
