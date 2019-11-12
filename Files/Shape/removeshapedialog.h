#ifndef REMOVESHAPEDIALOG_H
#define REMOVESHAPEDIALOG_H

#include "Files/Shape/shape.h"

#include <vector>
#include <QDialog>
#include <QComboBox>

class RemoveShapeDialog : public QDialog
{
    Q_OBJECT

    QComboBox* m_list;
    std::vector<Shape*>& m_shapes;

public:
    explicit RemoveShapeDialog(std::vector<Shape*>&, QWidget *parent = nullptr);
    virtual ~RemoveShapeDialog();

signals:

public slots:
    void admit();
};

#endif // REMOVESHAPEDIALOG_H
