// SudokuValidator.cpp
#include "SudokuValidator.h"

SudokuValidator::SudokuValidator(Grid *grid, int row, int col, QValidator *qmlValidator, QObject *parent)
    : QValidator(parent), grid(grid), row(row), col(col), qmlValidator(qmlValidator)
{
}

QValidator::State SudokuValidator::validate(QString &input, int &pos) const
{
    Q_UNUSED(pos);

    // Use the QML validator first to ensure only numbers between 1 and 9 are entered
    QValidator::State qmlState = qmlValidator->validate(input, pos);
    if (qmlState != QValidator::Acceptable) {
        return qmlState;
    }

    // Check if the entered number is valid in the Sudoku grid
    if (grid->verif(row, col, input.toInt())) {
        return QValidator::Acceptable;
    } else {
        return QValidator::Invalid;
    }
}
