#include "qormfiltermodel.h"

#include <QOrmLoader>

QOrmAbstractFilterModel::QOrmAbstractFilterModel(QOrmAbstractModel *model)
{
    setSourceModel(model);
}

void QOrmAbstractFilterModel::load() {
    ((QOrmAbstractModel*)this->sourceModel())->load();
}

QOrmObject *QOrmAbstractFilterModel::at(int row)
{
    int i = mapToSource(index(row, 0)).row();
    return ((QOrmAbstractModel*)this->sourceModel())->at(i);
}


int FilterModel::sourceIndex(int row) {
    QModelIndex i = mapToSource(index(row, 0));
    return i.row();
}

QOrmObject *FilterModel::findByID(QVariant id)
{
    if (!sourceModel()) return 0;

    QOrmAbstractModel *model = (QOrmAbstractModel*)sourceModel();
    QOrmBasicLoader ld(model->metaTable());
    return ld.load(id);
}

void FilterModel::setSourceModel(QAbstractItemModel *model) {
    if (model == sourceModel()) return;

    QSortFilterProxyModel::setSourceModel(model);
    emit sourceModelChanged(model);
}
