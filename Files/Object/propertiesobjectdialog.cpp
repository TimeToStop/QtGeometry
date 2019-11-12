#include "propertiesobjectdialog.h"
#include "Files/Object/object.h"

PropertiesObjectDialog::PropertiesObjectDialog(Object* object, QWidget *parent):
    QDialog(parent),
    m_obj(object)
{
}

PropertiesObjectDialog::~PropertiesObjectDialog()
{

}

void PropertiesObjectDialog::hideEvent(QHideEvent *)
{
    m_obj->hideProperties();
    setPropertiesToObject();
}

