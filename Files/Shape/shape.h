#ifndef SHAPE_H
#define SHAPE_H

#include "Files/Object/object.h"

enum Type
{
    Line
};

class Shape : public Object
{
    QString m_name;
    Type m_type;

public:
    Shape(Type);
    Shape(Type, Object*);
    template<typename ... Objs>
    Shape(Type, const int, Objs ...);
    virtual ~Shape();

    virtual void recount() = 0;
    virtual void draw(QPainter&) const = 0;

    QString name() const;
    Type type() const;

protected:
    void setName(const QString&);
};

#endif // SHAPE_H
