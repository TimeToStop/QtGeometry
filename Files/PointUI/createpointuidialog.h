#ifndef CREATEPOINTDIALOG_H
#define CREATEPOINTDIALOG_H

#include "pointui.h"

#include <QDialog>
#include <QLineEdit>

class CreatePointUIDialog : public QDialog
{
    Q_OBJECT

    std::vector<PointUI*>& m_points;

    QLineEdit* m_name;
    QLineEdit* m_x;
    QLineEdit* m_y;

public:
    explicit CreatePointUIDialog(std::vector<PointUI*>& points, QWidget *parent = nullptr);
    virtual ~CreatePointUIDialog();

signals:

public slots:

    void admit();
};

#endif // CREATEPOINTDIALOG_H
