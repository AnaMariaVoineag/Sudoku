#pragma once
class SudokuGenerator
{
private:
	int matr[9][9];
	int matrsol[9][9];
	int niv_dif;
	int nr_zero;
public:
	SudokuGenerator();
	~SudokuGenerator();
	void alegere();
	bool verif_patrat(int l, int c, int nr);
	bool verif_lin(int i, int nr);
	bool verif_col(int j, int nr);
	bool verif_complet(int i, int j, int nr);
	void umple_patr(int x, int y);
	void umplu_patrdiag();
	bool umplu_restul(int i, int j);
	void goleste_cel();
	void umplu();
	void umplu_solutie();
	void afis_matr();
	void afis_matrsol();

};


