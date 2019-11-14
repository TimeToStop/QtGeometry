#include "object.h"
#include "Files/field.h"
#include "propertiesobjectdialog.h"

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
    m_is_changed(true),
    m_is_properties_open(false),
    m_properties(nullptr)
{

}

Object::Object(Object* parent):
    m_parents(),
    m_childs(),
    m_is_changed(true),
    m_is_properties_open(false),
    m_properties(nullptr)
{
    m_parents.push_back(parent);
    parent->addChild(this);
}

Object::Object(const int N, ...):
    m_parents(),
    m_childs(),
    m_is_changed(true),
    m_is_properties_open(false),
    m_properties(nullptr)
{    
    va_list list;

    va_start(list, N);

    for(int i = 0; i < N; i++)
    {
        Object* parent = va_arg(list, Object*);

        m_parents.push_back(parent);
        parent->addChild(this);
    }

    va_end(list);
}

Object::~Object()
{
    for(Object* parents : m_parents)
    {
        parents->eraseChild(this);
    }

    for(Object* childs : m_childs)
    {
        delete childs;
    }

    m_parents.clear();
    m_childs.clear();

    if(m_properties)
    {
        delete m_properties;
    }
}

void Object::countChild()
{
    if(m_is_changed)
    {
        recount();
        m_is_changed = false;
    }

    for(Object* childs : m_childs)
    {
        if(m_is_changed)
        {
            childs->countChild();
        }
    }
}

void Object::change()
{    
    if(m_is_properties_open)
    {
        recount();
        m_properties->setPropertiesToDialog();

        m_is_changed = false;
    }
    else
    {
        m_is_changed = true;
    }

    for(Object* childs : m_childs)
    {
        childs->change();
    }
}

void Object::showProperties() const
{
    m_is_properties_open = true;
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

void Object::eraseChild(Object* child)
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

void Object::setChangeFalse()
{
    m_is_changed = false;
}
