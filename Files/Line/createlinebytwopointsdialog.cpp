#include "createlinebytwopointsdialog.h"

CreateLineByTwoPointsDialog::CreateLineByTwoPointsDialog(const std::vector<PointUI*>& points, std::vector<Shape*>& shapes, QWidget *parent) :
    QWidget(parent),
    m_points(points),
    m_shapes(shapes)
{

}

CreateLineByTwoPointsDialog::~CreateLineByTwoPointsDialog()
{

}

void CreateLineByTwoPointsDialog::admit()
{

}
