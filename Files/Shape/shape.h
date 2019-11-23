#ifndef SHAPE_H
#define SHAPE_H

#include "Files/Object/object.h"

enum Type
{
    Type_Line
};

class Shape : public Object
{
    Type m_type;

public:
    Shape(Type);
    Shape(Type, Object*);
    template<typename ... Objs>
    Shape(Type type, const int N, Objs ... parents):
        Object(N, parents ...),
        m_type(type)
    {

    }
    virtual ~Shape();

    virtual void recount() = 0;
    virtual void draw(QPainter&) const = 0;

    Type type() const;
    QString nameAndType() const;
};

#endif // SHAPE_H
