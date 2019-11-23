#include "pointui.h"
#include "Files/field.h"
#include "Files/PointUI/propertiespointuidialog.h"

const int PointUI::m_d_selected = 7;
const int PointUI::m_text_delta_selected = 15;
const int PointUI::m_d_unselected = 3;
const int PointUI::m_text_delta_unselected = 7;

PointUI::PointUI(const QPointF & pos, const QString & name):
    Object(),
    m_is_selected(false),
    m_pos(m_field->fromXOY(pos)),
    m_posXOY(pos)
{
    setPropertiesDialog(new PropertiesPointUIDialog(this, m_field));
    setName(name);
}

PointUI::PointUI(Double x, Double y, const QString & name):
    Object(),
    m_is_selected(false),
    m_pos(m_field->fromXOY(QPointF(x, y))),
    m_posXOY(x, y)
{
    setPropertiesDialog(new PropertiesPointUIDialog(this, m_field));
    setName(name);
}

PointUI::~PointUI()
{

}

void PointUI::setSelected(bool b)
{
    m_is_selected = b;
}

bool PointUI::isSelected() const
{
    return m_is_selected;
}

QPointF PointUI::posXOY() const
{
    return m_posXOY;
}

QPoint PointUI::pos() const
{
    return m_pos;
}

void PointUI::setPos(QPoint pos)
{
    m_pos = pos;
    m_posXOY = m_field->toXOY(pos);
}

void PointUI::setPosXOY(QPointF pos)
{
    m_pos = m_field->fromXOY(pos);
    m_posXOY = pos;

    countChild();
}

void PointUI::movePos(QPoint pos)
{
    m_pos += pos;
}

void PointUI::movePosXOY(QPointF pos)
{
    m_posXOY += pos;
    m_pos = m_field->fromXOY(m_posXOY);

    countChild();
}

void PointUI::recount()
{

}

void PointUI::draw(QPainter& painter) const
{
    painter.setPen(QColor(0,0,0));
    painter.setBrush(QBrush(QColor(0,0,0), Qt::SolidPattern));

    if (m_is_selected)
    {
        painter.drawEllipse(m_pos, m_d_selected, m_d_selected);
        painter.drawText(m_pos.x() + m_text_delta_selected, m_pos.y() + m_text_delta_selected, m_name);
    }
    else
    {
        painter.drawEllipse(m_pos, m_d_unselected, m_d_unselected);
        painter.drawText(m_pos.x() + m_text_delta_unselected, m_pos.y() + m_text_delta_unselected, m_name);
    }
}

