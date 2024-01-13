#pragma once

#include <QAbstractTableModel>

class Grid : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Grid(QObject *parent = nullptr);

public:
    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

signals:

private:
    int gridData[9][9];

};
