#include "Grid.h"
#include "SudokuGenerator.h"

Grid::Grid(QObject *parent) : QAbstractTableModel(parent) {
    SudokuGenerator sudokuGenerator(1);
    sudokuGenerator.umplu();
    int **initialValues = sudokuGenerator.get_matrice();
    gridData = initialValues;
}

int Grid::rowCount(const QModelIndex &) const {
    return 9;
}

int Grid::columnCount(const QModelIndex &) const {
    return 9;
}

QVariant Grid::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role) {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (gridData[row][col] == 0) {
            return QVariant();
        } else {
            return gridData[row][col];
        }
    }

    return QVariant();
}

bool Grid::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        if (!checkIndex(index))
            return false;

        if (value.toInt() == 0 && gridData[index.row()][index.column()] != 0)
            return false;

        gridData[index.row()][index.column()] = value.toInt();

        emit dataChanged(index, index);

        return true;
    }
    return false;
}

Qt::ItemFlags Grid::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    if (gridData[index.row()][index.column()] == 0)
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
