#ifndef CHOOSESHAPEDIALOG_H
#define CHOOSESHAPEDIALOG_H

#include "shape.h"

#include <QComboBox>
#include <QDialog>

class ChooseShapeDialog : public QDialog
{
    Q_OBJECT

    QComboBox* m_list;

public:
    explicit ChooseShapeDialog(const std::vector<Shape*>&, QWidget *parent = nullptr);
    virtual ~ChooseShapeDialog();

signals:
    void result(int);

public slots:
    void admit();
};


#endif // CHOOSESHAPEDIALOG_H
