#ifndef CREATELINEBYTWOPOINTSDIALOG_H
#define CREATELINEBYTWOPOINTSDIALOG_H

#include "Files/Shape/createabstractshapedialog.h"

class CreateLineByTwoPointsDialog : public QWidget
{
    Q_OBJECT

    const std::vector<PointUI*>& m_points;

public:
    explicit CreateLineByTwoPointsDialog(const std::vector<PointUI*>&, QWidget *parent = nullptr);
    virtual ~CreateLineByTwoPointsDialog();

signals:

public slots:
};

#endif // CREATELINEBYTWOPOINTSDIALOG_H
