// SudokuValidator.h
#ifndef SUDOKUVALIDATOR_H
#define SUDOKUVALIDATOR_H

#include <QValidator>
#include "Grid.h" // Include the header for the Grid class

class SudokuValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SudokuValidator(Grid *grid, int row, int col, QValidator *qmlValidator, QObject *parent = nullptr);

    QValidator::State validate(QString &input, int &pos) const override;

private:
    Grid *grid;
    int row;
    int col;
    QValidator *qmlValidator;
};

#endif // SUDOKUVALIDATOR_H
