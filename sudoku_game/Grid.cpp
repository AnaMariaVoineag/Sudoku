#include "Grid.h"
#include "SudokuGenerator.h"

Grid::Grid(QObject *parent) : QAbstractTableModel(parent) {
    SudokuGenerator sudokuGenerator(1);
    sudokuGenerator.umplu();

    int **initialValues = sudokuGenerator.get_matrice();
    gridData = initialValues;

    sudokuGenerator.scrie_initial();

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

        int inputValue = value.toInt();

        if (inputValue < 1 || inputValue > 9)
            return false;


        for (int i = 0; i < 9; ++i) {
            if (gridData[index.row()][i] == inputValue || gridData[i][index.column()] == inputValue)
                return false;
        }

        if (inputValue == 0 && gridData[index.row()][index.column()] != 0)
            return false;

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

void Grid::solveSudoku()
{
    SudokuGenerator sudokuGenerator(1);
    sudokuGenerator.umplu();

    QVector<QVector<int>> solution(9, QVector<int>(9));


    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (gridData[i][j] != 0) {
                solution[i][j] = gridData[i][j];
            } else {
                solution[i][j] = sudokuGenerator.get_matrice()[i][j];
            }

            QModelIndex index = createIndex(i, j);
            gridData[i][j] = solution[i][j];
            emit dataChanged(index, index);
        }
    }

    sudokuGenerator.scrie_solutie();


}
