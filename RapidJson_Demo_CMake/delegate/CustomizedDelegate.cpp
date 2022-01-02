
#include "CustomizedDelegate.h"


QWidget* CustomizedDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return nullptr;
}

void CustomizedDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{

}

void CustomizedDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{

}


