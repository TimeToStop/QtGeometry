#include "createabstractshapedialog.h"

CreateAbstractShapeDialog::CreateAbstractShapeDialog(const std::vector<Shape*>& shapes, const std::vector<PointUI*>& points, QWidget *parent):
    QDialog(parent),
    m_shapes(shapes),
    m_points(points)
{

}

CreateAbstractShapeDialog::~CreateAbstractShapeDialog()
{

}
