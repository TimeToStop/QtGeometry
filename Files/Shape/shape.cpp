#include "shape.h"

Shape::Shape(Type type):
    Object(),
    m_type(type)
{

}

Shape::Shape(Type type, Object * parent):
    Object(parent),
    m_type(type)
{

}

template<typename ... Objs>
Shape::Shape(Type type, const int N, Objs ... parents):
    Object(N, parents ...),
    m_type(type)
{

}

Shape::~Shape()
{

}

Type Shape::type() const
{
    return m_type;
}

QString Shape::nameAndType() const
{
    switch(m_type)
    {
    case Line: return "Line: " + name();
    }
}

