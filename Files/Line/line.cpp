#include "line.h"

#include "Files/field.h"
#include "Files/Line/propertieslinedialog.h"

int Line::m_left = 0;
int Line::m_right = 0;

void Line::setLeft(int l)
{
    m_left = l;
}

void Line::setRight(int r)
{
    m_right = r;
}

Line::Line(PointUI* point1, PointUI* point2, const QString & name):
    Shape(Type::Type_Line, 2, point1, point2),
    m_point1(point1),
    m_point2(point2),
    m_a(),
    m_b(),
    m_c()
{
    if(name == "")
    {
        setName(m_point1->name() + m_point2->name());
    }
    else
    {
        setName(name);
    }

    setPropertiesDialog(new PropertiesLineDialog(this, m_field));
    recount();
}

Line::~Line()
{

}

void Line::recount()
{
    m_a = m_point2->posXOY().y() - m_point1->posXOY().y();
    m_b = m_point1->posXOY().x() - m_point2->posXOY().x();
    m_c = m_point1->posXOY().y() * m_point2->posXOY().x() - m_point2->posXOY().y() * m_point1->posXOY().x();
}

void Line::draw(QPainter & painter) const
{
    painter.setPen(QPen(QColor(0,0,0), 2, Qt::SolidLine));

    if(m_b == 0)
    {
        QPoint p = m_field->fromXOY(QPointF(m_left, -m_c/m_a));
        painter.drawLine(p.x(), 0, p.x(), m_field->height());
    }
    else
    {
         painter.drawLine(m_field->fromXOY(QPointF(m_left, -(m_a * m_left + m_c)/m_b)), m_field->fromXOY(QPointF(m_right, -(m_a * m_right + m_c)/m_b)));
    }
}

Double Line::a() const
{
    return m_a;
}

Double Line::b() const
{
    return m_b;
}

Double Line::c() const
{
    return m_c;
}
