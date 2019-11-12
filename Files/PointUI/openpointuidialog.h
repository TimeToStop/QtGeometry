#ifndef OPENPOINTUIDIALOG_H
#define OPENPOINTUIDIALOG_H

#include "Files/PointUI/pointui.h"

#include <QDialog>

class OpenPointUIDialog : public QDialog
{
    Q_OBJECT

    const std::vector<PointUI*>& m_points;

public:
    explicit OpenPointUIDialog(const std::vector<PointUI*>&,QWidget *parent = nullptr);
    virtual ~OpenPointUIDialog();

signals:

public slots:
};

#endif // OPENPOINTUIDIALOG_H
