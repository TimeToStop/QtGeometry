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

    mutable bool m_is_properties_open;
    PropertiesObjectDialog* m_properties;

protected:
    QString m_name;

public:
    Object();
    Object(int, ...);
    virtual ~Object();

    virtual void recount() = 0;
    virtual void draw(QPainter&) const = 0;

    void count();

    void showProperties() const;
    void hideProperties() const;

    QString name() const;

protected:
    void setPropertiesDialog(PropertiesObjectDialog*);
    void setName(const QString&);

private:
    void addChild(Object*);
    void addParent(Object*);

    void eraseChild(Object*);
};

#endif // OBJECT_H
