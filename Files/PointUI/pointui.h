#ifndef POINTUI_H
#define POINTUI_H

#include "Files/Object/object.h"
#include "Files/double.h"
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <QString>

class PropertiesPointUIDialog;

class PointUI : public Object
{
    static const int m_d_selected;
    static const int m_d_unselected;
    static const int m_text_delta_selected;
    static const int m_text_delta_unselected;

    bool m_is_selected;

    QString m_name;

    QPoint m_pos;
    QPointF m_posXOY;

public:
    PointUI(const QPointF&, const QString&);
    PointUI(Double, Double, const QString&);
    virtual ~PointUI();

    void setSelected(bool);
    bool isSelected() const;
    QString name() const;

    QPointF posXOY() const;
    QPoint pos() const;

    void setPos(QPoint);
    void setPosXOY(QPointF);

    void movePos(QPoint);
    void movePosXOY(QPointF);

    void recount();
    virtual void draw(QPainter&) const;
};

#endif // POINTUI_H
