#ifndef CREATESHAPEDIALOG_H
#define CREATESHAPEDIALOG_H

#include "Files/Shape/shape.h"

#include <QComboBox>
#include <QDialog>

class CreateShapeDialog : public QDialog
{
    Q_OBJECT   

    std::vector<Shape*>& m_shapes;
    QComboBox* m_box;

public:
    explicit CreateShapeDialog(std::vector<Shape*>&, QWidget *parent = nullptr);
    virtual ~CreateShapeDialog();

signals:

public slots:
    void admit();
};

#endif // CREATESHAPEDIALOG_H
