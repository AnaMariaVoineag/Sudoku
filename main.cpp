#include "Sudoku.h"
#include "SudokuGenerator.h"

int main()
{
	srand(static_cast<unsigned>(time(0)));
	SudokuGenerator* sdkgen = new SudokuGenerator();
	sdkgen->alegere();
	sdkgen->umplu();
	sdkgen->afis_matr();
	std::cout << '\n' << '\n';
	sdkgen->afis_matrsol();
	sdkgen->~SudokuGenerator();
	Sudoku sudoku;

	sudoku.run();

	return 0;
}