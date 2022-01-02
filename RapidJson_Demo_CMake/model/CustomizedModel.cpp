
#include "CustomizedModel.h"

QVariant CustomizedModel::data(const QModelIndex &index, int role) const
{
    if (Qt::TextAlignmentRole == role)
    {
        return Qt::AlignCenter;
    }

    return QStandardItemModel::data(index, role);
}

