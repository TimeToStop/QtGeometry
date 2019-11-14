#ifndef CHOOSEPOINTUIDIALOG_H
#define CHOOSEPOINTUIDIALOG_H

#include "pointui.h"

#include <QComboBox>
#include <QDialog>

class ChoosePointUIDialog : public QDialog
{
    Q_OBJECT

    QComboBox* m_list;

public:
    explicit ChoosePointUIDialog(const std::vector<PointUI*>&, QWidget *parent = nullptr);
    virtual ~ChoosePointUIDialog();

signals:
    void result(int);

public slots:
    void admit();
};

#endif // CHOOSEPOINTUIDIALOG_H
