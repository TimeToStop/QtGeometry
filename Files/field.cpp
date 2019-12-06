#include "field.h"

#include "PointUI/choosepointuidialog.h"
#include "PointUI/createpointuidialog.h"

#include "Shape/chooseshapedialog.h"
#include "Shape/createshapedialog.h"

#include "Line/line.h"

Field::Field(int w, int h, QWidget* parent):
    QWidget(parent),
    m_width(w),
    m_height(h),
    m_p(50),
    m_step(m_width / m_p),
    m_is_left_mouse_click(false),
    m_is_right_mouse_click(false),
    m_is_ctrl_pressed(false),
    m_has_point_selected(false),
    m_pos_of_left_mouse_click(0,0),
    m_pos_of_right_mouse_click(0,0),
    m_pos_of_mouse(0,0),
    m_right_click_delta(0,0),
    m_points()
{
    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(m_width, m_height);
    Object::setField(this);

    m_points.push_back(new PointUI(0, 0, "A"));
    m_points.push_back(new PointUI(10, 6, "B"));
    m_points.push_back(new PointUI(-3, -8, "C"));
    m_points.push_back(new PointUI(7, -15, "D"));

    m_shapes.push_back(new Line(m_points[0], m_points[1]));
    m_shapes.push_back(new Line(m_points[1], m_points[2]));
    m_shapes.push_back(new Line(m_points[0], m_points[2]));

    repaint();
}

Field::~Field()
{
    for(PointUI* e : m_points)
    {
        delete e;
    }

    m_points.clear();
    m_shapes.clear();
}

void Field::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setPen(QPen(QColor(0,0,0), 2, Qt::SolidLine));

    painter.drawLine(0, 0, m_width, 0);
    painter.drawLine(m_width, 0, m_width, m_height);
    painter.drawLine(0, m_height, m_width, m_height);
    painter.drawLine(0, 0, 0, m_height);

    if(m_is_left_mouse_click)
    {
        painter.setPen(QPen(QColor(0,0, 220), 2, Qt::SolidLine));
        painter.setBrush(QBrush(QColor(100,100,200, 60), Qt::SolidPattern));
        painter.drawRect(m_pos_of_left_mouse_click.x(),
                         m_pos_of_left_mouse_click.y(),
                         m_pos_of_mouse.x() - m_pos_of_left_mouse_click.x(),
                         m_pos_of_mouse.y() - m_pos_of_left_mouse_click.y());

        painter.setBrush(Qt::NoBrush);
    }

    drawGrid(painter);

    for(PointUI* e : m_points)
    {
        e->draw(painter);
    }

    for(Shape* e : m_shapes)
    {
        e->draw(painter);
    }
}

void Field::mousePressEvent(QMouseEvent* e)
{
    if((e->button() == Qt::LeftButton && m_is_right_mouse_click)
            || (e->button() == Qt::RightButton && m_is_left_mouse_click))
    {
        m_is_left_mouse_click = false;
        m_is_right_mouse_click = false;

        return;
    }

    if(e->button() == Qt::LeftButton)
    {
        m_is_left_mouse_click = true;
        m_pos_of_left_mouse_click = e->pos();

        for(PointUI* e : m_points)
        {
            e->setSelected(false);
        }

        m_has_point_selected = false;
    }

    if(e->button() == Qt::RightButton)
    {
        m_is_right_mouse_click = true;
        m_pos_of_right_mouse_click = e->pos();
    }

    m_pos_of_mouse = e->pos();
}

void Field::mouseReleaseEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_is_left_mouse_click = false;
    }

    if(e->button() == Qt::RightButton)
    {
        m_is_right_mouse_click = false;
        m_pos_of_right_mouse_click = QPoint(0,0);
    }

    repaint();
}

void Field::mouseMoveEvent(QMouseEvent* e)
{
    if(m_is_right_mouse_click && !m_has_point_selected)
    {
         QPoint point = e->pos() - m_pos_of_mouse;

         m_right_click_delta += point;

         for(PointUI* e : m_points)
         {
             e->movePos(point);
         }
    }

    if(m_is_left_mouse_click)
    {
        int left = min(e->pos().x(), m_pos_of_left_mouse_click.x());
        int right = max(e->pos().x(), m_pos_of_left_mouse_click.x());
        int top = min(e->pos().y(), m_pos_of_left_mouse_click.y());
        int buttom = max(e->pos().y(), m_pos_of_left_mouse_click.y());

        for(PointUI* point : m_points)
        {
            if(left <= point->pos().x() && point->pos().x() <= right
                    && top <= point->pos().y() && point->pos().y() <= buttom)
            {
                m_has_point_selected = true;
                point->setSelected(true);
            }
            else
            {
                point->setSelected(false);
            }
        }
    }

    if(m_has_point_selected && m_is_right_mouse_click)
    {
        QPointF point = e->pos() - m_pos_of_mouse;

        point.ry() = - point.y();

        for(PointUI* e : m_points)
        {
            if(e->isSelected())
            {
               e->movePosXOY(point / static_cast<double>(m_step));
            }
        }
    }

    m_pos_of_mouse = e->pos();

    repaint();
}

void Field::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Control)
    {
        m_is_ctrl_pressed = true;
    }
}

void Field::keyReleaseEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Control)
    {
        m_is_ctrl_pressed = false;
    }
}

void Field::wheelEvent(QWheelEvent* e)
{
    if(m_is_ctrl_pressed)
    {
        m_step += e->delta() / 60;

        if(m_step <= 10) m_step = 10;
        if(m_step >= 50) m_step = 50;

        repaint();
    }
}

QPoint Field::fromXOY(QPointF point) const
{
    point.rx() = m_step * (point.x() + ((m_width / m_step) >> 1)) + m_right_click_delta.x();
    point.ry() = m_step * (-point.y() + ((m_height / m_step) >> 1)) + m_right_click_delta.y();

    return point.toPoint();
}

QPointF Field::toXOY(QPoint point) const
{
    QPointF res;

    res.rx() = (point.x() - m_right_click_delta.x()) / static_cast<double>(m_step) - ((m_width / m_step) >> 1);
    res.ry() = m_height /(2 * static_cast<double>(m_step)) - (point.y() - m_right_click_delta.y())/ static_cast<double>(m_step);

    return res;
}

void Field::drawGrid(QPainter& painter)
{
    painter.setPen(QPen(QColor(10, 10, 10, 80), 1, Qt::SolidLine));

    m_p = m_width / m_step;

    int ch_x_lines = (m_p >> 1)  + m_right_click_delta.x() / m_step;
    int ch_y_lines = ((m_height / m_step) >> 1)  + m_right_click_delta.y() / m_step;

    Line::setLeft(-ch_x_lines - 1);
    Line::setRight(-ch_x_lines + m_p + 1);

    QString buff;

    static const int text_delta = 5;

    for(int i = m_right_click_delta.x() % m_step, j = 0; i < m_width; i+= m_step, j++)
    {
        if(j == ch_x_lines)
        {
           painter.setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine));
           painter.drawLine(i, 0, i, m_height);

           painter.drawText(i + text_delta, m_right_click_delta.y() % m_step + ch_y_lines * m_step - text_delta, "0");

           painter.setPen(QPen(QColor(10, 10, 10, 80), 1, Qt::SolidLine));
        }
        else
        {
            painter.drawLine(i, 0, i, m_height);

            buff.setNum(j - ch_x_lines);
            painter.setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine));
            painter.drawText(i + text_delta, m_right_click_delta.y() % m_step + ch_y_lines * m_step - text_delta,buff);
            painter.setPen(QPen(QColor(10, 10, 10, 80), 1, Qt::SolidLine));
        }
    }

    for(int i = m_right_click_delta.y() % m_step, j = 0; i < m_height; i+= m_step, j++)
    {
        if(j == ch_y_lines)
        {
           painter.setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine));
           painter.drawLine(0, i, m_width, i);

           painter.drawText(m_right_click_delta.x() % m_step + ch_x_lines * m_step + text_delta, i - text_delta, "0");

           painter.setPen(QPen(QColor(10, 10, 10, 80), 1, Qt::SolidLine));
        }
        else
        {
            painter.drawLine(0, i, m_width, i);

            buff.setNum(ch_y_lines - j);
            painter.setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine));
            painter.drawText(m_right_click_delta.x() % m_step + ch_x_lines * m_step + text_delta, i - text_delta, buff);
            painter.setPen(QPen(QColor(10, 10, 10, 80), 1, Qt::SolidLine));
        }
    }
}

inline int Field::max(int a, int b) const
{
    return (a > b) ? a : b;
}

inline int Field::min(int a, int b) const
{
    return (a < b) ? a : b;
}

void Field::eraseShape(Object * obj)
{
    for(auto iter = m_shapes.begin(); iter != m_shapes.end(); iter++)
    {
        if(*iter == obj)
        {
            m_shapes.erase(iter);
            return;
        }
    }
}

void Field::addPointUIDialog()
{
    CreatePointUIDialog dialog(m_points, this);

    dialog.exec();
}

void Field::openPointUIPropertiesDialog()
{
    if(m_points.size())
    {
        ChoosePointUIDialog dialog(m_points, this);
        const int r = dialog.exec();
        if(r)
        {
            m_points[r - 1]->showProperties();
        }
    }
}

void Field::openShapePropertiesDialog()
{
    if(m_shapes.size())
    {
        ChooseShapeDialog dialog(m_shapes, this);

        const int r = dialog.exec();

        if(r)
        {
            m_shapes[dialog.exec() - 1]->showProperties();
        }
    }
}

void Field::rmPointUIDialog()
{
    if(m_points.size())
    {
        ChoosePointUIDialog dialog(m_points, this);

        const int r = dialog.exec();

        if(r)
        {
            delete m_points[r - 1];
            m_points.erase(m_points.begin() + r - 1);
        }
    }
}

void Field::addShapeDialog()
{
    CreateShapeDialog dialog(m_shapes, this);

    dialog.exec();
}

void Field::rmShapeDialog()
{
    if(m_shapes.size())
    {
        ChooseShapeDialog dialog(m_shapes, this);

        const int r = dialog.exec();

        if(r)
        {
            delete m_shapes[r - 1];
            m_shapes.erase(m_shapes.begin() + r - 1);
        }
    }
}
