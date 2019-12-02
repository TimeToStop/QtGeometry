#include "object.h"
#include "Files/field.h"
#include "propertiesobjectdialog.h"

#include <stdarg.h>

Field* Object::m_field = nullptr;
bool Object::m_protect = true;

void Object::setField(Field * field)
{
    if(m_protect)
    {
        m_field = field;
        m_protect = false;
    }
}

Object::Object():
    m_parents(),
    m_childs(),
    m_is_properties_open(false),
    m_properties(nullptr)
{

}

Object::Object(int n, ...)
{
    va_list list;

    va_start(list, n);

    for(int i = 0; i < n; i++)
    {
        Object* obj = va_arg(list, Object*);

        addParent(obj);
        obj->addChild(this);
    }

    va_end(list);
}

Object::~Object()
{
    for(Object* child : m_childs)
    {
        m_field->eraseShape(child);
        delete child;
    }

    for(Object* parent : m_parents)
    {
        parent->eraseChild(this);
    }
}

void Object::count()
{
    recount();

    for(Object* child : m_childs)
    {
        child->count();
    }
}

void Object::showProperties() const
{
    m_is_properties_open = true;
    m_properties->setPropertiesToDialog();
    m_properties->show();
}

void Object::hideProperties() const
{
    m_is_properties_open = false;
}

QString Object::name() const
{
    return m_name;
}

void Object::setPropertiesDialog(PropertiesObjectDialog * properties)
{
    m_properties = properties;
}

void Object::setName(const QString& name)
{
    m_name = name;
}

void Object::addChild(Object* child)
{
    m_childs.push_back(child);
}

void Object::addParent(Object* parent)
{
    m_parents.push_back(parent);
}

void Object::eraseChild(Object * child)
{
    for(auto iter = m_childs.begin(); iter != m_childs.end(); iter++)
    {
        if(*iter == child)
        {
            m_childs.erase(iter);
            return;
        }
    }
}
