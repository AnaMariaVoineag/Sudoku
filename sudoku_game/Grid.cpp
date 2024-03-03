#include "Grid.h"
#include "SudokuGenerator.h"
#include <QDebug>

Grid::Grid(QObject *parent) : QAbstractTableModel(parent) {
    SudokuGenerator sudokuGenerator(1);
    sudokuGenerator.umplu();

    gridData = sudokuGenerator.get_matrice();

    sudokuGenerator.scrie_initial();

}

Grid::~Grid() {

    for (int i = 0; i < 9; i++)
    {
        delete[] gridData[i];
    }
    delete[] gridData;
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
            return true;

        int inputValue = value.toInt();

        if (inputValue < 1 || inputValue > 9)
            return false;

        verif(index.row(), index.column(), inputValue);

        gridData[index.row()][index.column()] = inputValue;

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

bool Grid::verif(int row, int col, int num) const
{
    if (gridData[row][col] != 0) {
        return true;
    }

    SudokuGenerator sudokuGenerator(1);
    sudokuGenerator.umplu();

    if (sudokuGenerator.verif_complet(row, col, num)) {
        return true;
    }

    return false;
}

void Grid::solveSudoku() {
    SudokuGenerator sudokuGenerator(1);
    sudokuGenerator.umplu();
    gridData = sudokuGenerator.getSolutionMatrix();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (gridData[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (sudokuGenerator.verif_complet(i, j, num)) {
                        gridData[i][j] = num;
                        break;
                    }
                }
            }
        }
    }

    sudokuGenerator.scrie_solutie();
    emit dataChanged(createIndex(0, 0), createIndex(8, 8));
}
