#ifndef SUDOKUSOLVER_HEADER_H
#define SUDOKUSOLVER_HEADER_H

#include <vector>
#include "Coord.h"
#include "Cell.h"

#define n 9

namespace sudoku {

	typedef std::vector<Cell> sudokuRow;
	typedef std::vector<sudokuRow> sudokuVector;

	bool CheckColumn(sudokuVector& Grid, Coord& c);
	bool CheckRow(sudokuVector& Grid, Coord& c);
	bool CheckSubGrid(sudokuVector& Grid, Coord& c);
	bool CheckConditions(sudokuVector& Grid, Coord& c);
	sudokuVector Init(int grid[][n]);
	void Solve(sudokuVector& grid);
//	void PrintGrid(sudokuVector& grid); // For debug purposes 
	int CtoI(const char& x);
}
#endif //SUDOKUSOLVER_SRC_HEADER_H