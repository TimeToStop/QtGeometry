#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <stdarg.h>
#include <QPainter>

class Field;
class PropertiesObjectDialog;

class Object
{
    typedef std::vector<Object*> Objects;

protected:
    static Field* m_field;
    static bool m_protect;

public:
    static void setField(Field*);

private:
    Objects m_parents;
    Objects m_childs;

    bool m_is_changed;

    mutable bool m_is_properties_open;
    PropertiesObjectDialog* m_properties;

public:
    Object();
    Object(Object*);
    Object(const int, ...);
    virtual ~Object();

    virtual void recount() = 0;
    virtual void draw(QPainter&) const = 0;
    void countChild();
    void change();

    void showProperties() const;
    void hideProperties() const;

protected:
    void setPropertiesDialog(PropertiesObjectDialog*);

private:
    void addChild(Object*);
    void eraseChild(Object*);
    void setChangeFalse();
};

#endif // OBJECT_H
