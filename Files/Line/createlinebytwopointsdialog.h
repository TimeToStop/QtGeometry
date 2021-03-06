#ifndef CREATELINEBYTWOPOINTSDIALOG_H
#define CREATELINEBYTWOPOINTSDIALOG_H

#include "Files/Shape/createabstractshapedialog.h"

class CreateLineByTwoPointsDialog : public QWidget
{
    Q_OBJECT

    const std::vector<PointUI*>& m_points;
    std::vector<Shape*>& m_shapes;

public:
    explicit CreateLineByTwoPointsDialog(const std::vector<PointUI*>&, std::vector<Shape*>&, QWidget *parent = nullptr);
    virtual ~CreateLineByTwoPointsDialog();

signals:

public slots:
    void admit();
};

#endif // CREATELINEBYTWOPOINTSDIALOG_H
