#ifndef CREATELINEDIALOG_H
#define CREATELINEDIALOG_H

#include "Files/Shape/createabstractshapedialog.h"

#include <QComboBox>

class CreateLineDialog : public CreateAbstractShapeDialog
{
    Q_OBJECT

    QComboBox* m_box;

public:
    explicit CreateLineDialog(std::vector<Shape*>&, std::vector<PointUI*>&, QWidget *parent = nullptr);
    virtual ~CreateLineDialog();

signals:

public slots:
    void admit();
};

#endif // CREATELINEDIALOG_H
