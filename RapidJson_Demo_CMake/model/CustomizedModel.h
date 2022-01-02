
#ifndef CUSTOMIZED_MODEL_H
#define CUSTOMIZED_MODEL_H

#include <QStandardItemModel>

class CustomizedModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit CustomizedModel(QObject* parent = nullptr)
    {}

public:
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};


#endif // !CUSTOMIZED_MODEL_H
