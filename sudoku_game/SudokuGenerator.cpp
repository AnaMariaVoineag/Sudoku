#include "SudokuGenerator.h"
#include <iostream>
SudokuGenerator::SudokuGenerator(int n) {
	niv_dif = n;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			matr[i][j] = 0;
			matrsol[i][j] = 0;
		}

}
//SudokuGenerator::SudokuGenerator(Int)
SudokuGenerator::~SudokuGenerator() {}
void SudokuGenerator::alegere() {
	std::cout << "Select difficulty: \n";
	std::cout << "1) Very Easy \n";
	std::cout << "2) Easy \n";
	std::cout << "3) Medium \n";
	std::cout << "4) Difficult \n";
	std::cout << "5) May God have mercy \n";
	int c;
	std::cin >> c;
	switch (c) {
	case 1:
		niv_dif = 34;
		std::cout << "You have chosen: Very Easy \n";
		std::cout << "Good Luck! \n";
		break;
	case 2:
		niv_dif = 45;
		std::cout << "You have chosen: Easy \n";
		std::cout << "Good Luck!\n";
		break;
	case 3:
		niv_dif = 49;
		std::cout << "You have chosen: Medium\n";
		std::cout << "Good Luck!\n";
		break;
	case 4:
		niv_dif = 53;
		std::cout << "You have chosen: Difficult\n";
		std::cout << "Good Luck!\n";
		break;
	case 5:
		niv_dif = 64;
		std::cout << "You have chosen: May God have mercy\n";
		std::cout << "Good Luck!\n";
		break;
	}
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
	while (nr < niv_dif)
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
void SudokuGenerator::afis_matr() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			std::cout << matr[i][j] << " ";
		std::cout << '\n';
	}
}
void SudokuGenerator::afis_matrsol() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			std::cout << matrsol[i][j] << " ";
		std::cout << '\n';
	}
}