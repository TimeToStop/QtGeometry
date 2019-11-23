#ifndef LINE_H
#define LINE_H

#include "Files/Shape/shape.h"
#include "Files/PointUI/pointui.h"
#include "Files/double.h"

class Line : public Shape
{
    static int m_left;
    static int m_right;

public:
    static void setLeft(int);
    static void setRight(int);

private:

    PointUI* m_point1;
    PointUI* m_point2;

    Double m_a;
    Double m_b;
    Double m_c;

public:
    Line(PointUI*, PointUI*, const QString& = "");
    virtual ~Line();

    virtual void recount();
    virtual void draw(QPainter &) const;
};

#endif // LINE_H
