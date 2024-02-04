#pragma once

#include <QAbstractTableModel>
#include <QVariant>

class Grid : public QAbstractTableModel
{
    Q_OBJECT
public:
    Grid(QObject *parent = nullptr);
    ~Grid();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE bool verif(int row, int col, int num) const;

public slots:
    void solveSudoku();

private:
    int** gridData;


};
