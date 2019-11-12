#ifndef REMOVEPOINTDIALOG_H
#define REMOVEPOINTDIALOG_H

#include "Files/PointUI/pointui.h"
#include <QDialog>
#include <QComboBox>

class RemovePointDialog : public QDialog
{
    Q_OBJECT

    QComboBox* m_list;
    std::vector<PointUI*>& m_points;

public:
    explicit RemovePointDialog(std::vector<PointUI*>&, QWidget *parent = nullptr);
    virtual ~RemovePointDialog();


signals:

public slots:
    void admit();
};

#endif // REMOVEPOINTDIALOG_H
