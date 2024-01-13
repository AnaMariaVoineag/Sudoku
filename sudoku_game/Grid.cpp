#include "Grid.h"

Grid::Grid(QObject *parent) : QAbstractTableModel(parent)
{
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            gridData[row][col] = (row * 3 + row / 3 + col) % 9 + 1;
        }
    }
}

int Grid::rowCount(const QModelIndex &) const
{
    return 9;
}

int Grid::columnCount(const QModelIndex &) const
{
    return 9;
}

QVariant Grid::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return gridData[index.row()][index.column()];
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> Grid::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}
