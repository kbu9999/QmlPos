#ifndef QORMFILTERMODEL_H
#define QORMFILTERMODEL_H

#include <QOrmTableModel>
#include <QSortFilterProxyModel>


class FilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel *sourceModel READ sourceModel WRITE setSourceModel NOTIFY sourceModelChanged)
public:
    Q_INVOKABLE int sourceIndex(int row);

    Q_INVOKABLE QOrmObject *findByID(QVariant id);

public slots:
    void setSourceModel(QAbstractItemModel *model);

signals:
    void sourceModelChanged(QAbstractItemModel *value);
};

class QOrmAbstractFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    QOrmAbstractFilterModel(QOrmAbstractModel *model);

    Q_INVOKABLE void load();

    Q_INVOKABLE QOrmObject* at(int row);
};

template <class T>
class QOrmFilterModel : public QOrmAbstractFilterModel
{
public:
    QOrmFilterModel() :  QOrmAbstractFilterModel(new QOrmTableModel<T>()) {
    }
};

#endif // QORMFILTERMODEL_H
