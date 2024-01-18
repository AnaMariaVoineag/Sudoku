#include "SudokuGenerator.h"
#include <iostream>
#include <fstream>
SudokuGenerator::SudokuGenerator(int n) {
    niv_dif = n;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            matr[i][j] = 0;
            matrsol[i][j] = 0;
        }
    switch (niv_dif) {
    case 1:
        nr_zero = 34;
        break;
    case 2:
        nr_zero = 45;
        break;
    case 3:
        nr_zero = 49;
        break;
    case 4:
        nr_zero = 53;
        break;
    case 5:
        nr_zero = 64;
        break;
    }
}
SudokuGenerator::SudokuGenerator(int m[9][9])
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            matr[i][j] = m[i][j];
}

SudokuGenerator::~SudokuGenerator() {}

int** SudokuGenerator::get_matrice() {
    int** m = new int*[9];
    for (int i = 0; i < 9; i++)
    {
        m[i] = new int[9];
            for (int j = 0; j < 9; j++)
            m[i][j] = matr[i][j];
    }
    return m;
}
bool SudokuGenerator::verif_patrat(int l, int c, int nr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (matr[l + i][c + j] == nr)
                return false;

    }
    return true;
}
bool SudokuGenerator::verif_lin(int i, int nr) {
    for (int j = 0; j < 9; j++)
        if (matr[i][j] == nr)
            return false;
    return true;
}
bool SudokuGenerator::verif_col(int j, int nr) {
    for (int i = 0; i < 9; i++)
        if (matr[i][j] == nr)
            return false;
    return true;

}
bool SudokuGenerator::verif_complet(int i, int j, int nr) {
    if (verif_col(j, nr) == true && verif_lin(i, nr) == true && verif_patrat(i - (i % 3), j - (j % 3), nr) == true)
        return true;
    return false;
}
void SudokuGenerator::umple_patr(int x, int y) {
    int pos[9] = { 1,2,3,4,5,6,7,8,9 };
    int nr;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            do {
                nr = pos[rand() % 9];
            } while (verif_patrat(x, y, nr) == false);
            matr[x + i][y + j] = nr;

        }
}
void SudokuGenerator::umplu_patrdiag() {
    for (int i = 0; i < 9; i = i + 3)
        umple_patr(i, i);
}
bool SudokuGenerator::umplu_restul(int i, int j) {
    if (j >= 9 && i < 8)
    {
        i++;
        j = 0;
    }
    if (i >= 9 && j >= 9)
        return true;
    if (i < 3)
    {
        if (j < 3)
            j = 3;
    }
    else if (i < 6)
    {
        if (j == (int)((i / 3) * 3))
            j = j + 3;

    }
    else if (j == 6) {
        i++;
        j = 0;
        if (i >= 9)
            return true;
    }
    for (int nr = 1; nr <= 9; nr++)
        if (verif_complet(i, j, nr))
        {
            matr[i][j] = nr;
            if (umplu_restul(i, j + 1))
                return true;
            matr[i][j] = 0;
        }
    return false;
}
void SudokuGenerator::umplu() {
    umplu_patrdiag();
    umplu_restul(0, 3);
    umplu_solutie();
    goleste_cel();
}
void SudokuGenerator::umplu_solutie() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            matrsol[i][j] = matr[i][j];
}
void SudokuGenerator::goleste_cel() {
    int nr = 0;
    int l;
    while (nr < nr_zero)
    {
        l = rand() % 81 - 1;
        int i = l / 9;
        int j = l % 9;
        if (matr[i][j] != 0) {
            nr++;
            matr[i][j] = 0;
        }

    }
}
void SudokuGenerator::scrie_solutie() {
    std::ofstream scrieF("SolutieSudoku.txt");
    //scrieF.open(numeFis);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            scrieF << matrsol[i][j];
        scrieF << "\n";
    }
}
void SudokuGenerator::scrie_initial() {
    std::ofstream scrieF("SudokuInitial.txt");
    //scrieF.open(numeFis);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            scrieF << matr[i][j];
        scrieF << "\n";
    }
}
void SudokuGenerator::scrie_curent() {
    std::ofstream scrieF("SudokuCurent.txt");
    //scrieF.open(numeFis);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            scrieF << matr[i][j];
        scrieF << "\n";
    }
}
