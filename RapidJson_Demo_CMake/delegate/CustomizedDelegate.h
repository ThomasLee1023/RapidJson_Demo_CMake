
#ifndef CUSTOMIZED_DELEGATE_H
#define CUSTOMIZED_DELEGATE_H

#include <QItemDelegate>

class CustomizedDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit CustomizedDelegate(QObject* parent = nullptr)
    {}

public:
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    virtual void setEditorData(QWidget* editor, const QModelIndex& index) const override;

    virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;

};


#endif // !CUSTOMIZED_DELEGATE_H
