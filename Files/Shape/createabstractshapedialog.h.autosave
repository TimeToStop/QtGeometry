#ifndef CREATEABSTRACTSHAPEDIALOG_H
#define CREATEABSTRACTSHAPEDIALOG_H


#include "Files/Shape/shape.h"
#include "Files/PointUI/pointui.h"

#include <QDialog>

class CreateAbstractShapeDialog : public QDialog
{
    Q_OBJECT

protected:
    std::vector<Shape*>& m_shapes;
    std::vector<PointUI*>& m_points;

public:
    explicit CreateAbstractShapeDialog(std::vector<Shape*>&, std::vector<PointUI*>&, QWidget *parent = nullptr);
    virtual ~CreateAbstractShapeDialog();

signals:

public slots:
    virtual void admit() = 0;
};

#endif // CREATEABSTRACTSHAPEDIALOG_H
