#ifndef FIELD_H
#define FIELD_H

#include "PointUI/pointui.h"
#include "Shape/shape.h"

#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>

class Object;

class Field : public QWidget
{
    Q_OBJECT

    int m_width;
    int m_height;

    int m_p;
    int m_step;

    bool m_is_left_mouse_click;
    bool m_is_right_mouse_click;
    bool m_is_ctrl_pressed;
    bool m_has_point_selected;

    QPoint m_pos_of_left_mouse_click;
    QPoint m_pos_of_right_mouse_click;
    QPoint m_pos_of_mouse;

    QPoint m_right_click_delta;

    std::vector<PointUI*> m_points;
    std::vector<Shape*> m_shapes;

public:
    explicit Field(int, int, QWidget* parent = nullptr);
    virtual ~Field();

    virtual void paintEvent(QPaintEvent*);

    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);

    virtual void keyPressEvent(QKeyEvent*);
    virtual void keyReleaseEvent(QKeyEvent*);

    virtual void wheelEvent(QWheelEvent*);

    QPoint fromXOY(QPointF) const;
    QPointF toXOY(QPoint) const;

private:
    void drawGrid(QPainter&);

    int max(int, int) const;
    int min(int, int) const;

signals:

public slots:

    void addPointUIDialog();
    void openPointUIPropertiesDialog();
    void rmPointUIDialog();

    void addShapeDialog();
    void openShapePropertiesDialog();
    void rmShapeDialog();
};

#endif // FIELD_H
