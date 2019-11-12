#include "openpointuidialog.h"

OpenPointUIDialog::OpenPointUIDialog(const std::vector<PointUI*>& points, QWidget* parent):
    QDialog(parent),
    m_points(points)
{

}

OpenPointUIDialog::~OpenPointUIDialog()
{

}
