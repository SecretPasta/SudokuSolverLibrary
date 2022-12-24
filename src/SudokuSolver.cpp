#include "SudokuSolver.h"

namespace sudoku {

	bool CheckSubGrid(sudokuVector& Grid, Coord& c) {

		int xStart = (c.x / 3) * 3, yStart = (c.y / 3) * 3;
		for (int i = xStart; i < xStart + 3; i++) {
			for (int j = yStart; j < yStart + 3; j++) {
				if (Grid[c.x][c.y] == Grid[i][j] && c != Coord(i, j))
					return false;
			}
		}
		return true;
	}

	bool CheckRow(sudokuVector& Grid, Coord& c) {
		for (int i = 0; i < n; i++) {
			if (Grid[c.x][i] == Grid[c.x][c.y] && c != Coord(c.x, i)) {
				return false;
			}
		}
		return true;
	}

	bool CheckColumn(sudokuVector& Grid, Coord& c) {
		for (int i = 0; i < n; i++) {
			if (Grid[i][c.y] == Grid[c.x][c.y] && c != Coord(i, c.y)) {
				return false;
			}
		}
		return true;
	}

	sudokuVector Init(int grid[][n]) {

		sudokuVector result = sudokuVector();
		Coord back(0, 0);
		for (int i = 0; i < n; i++) {
			result.push_back(sudokuRow());
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					result[i].push_back(Cell(Coord(i, j), grid[i][j], back));
					back = Coord(i, j);
				}
				else
					result[i].push_back(Cell(Coord(i, j), grid[i][j], Coord(-1, -1)));
			}
		}
		return result;
	}

	bool CheckConditions(sudokuVector& Grid, Coord& c) {
		return CheckColumn(Grid, c) && CheckRow(Grid, c) && CheckSubGrid(Grid, c);
	}

	void Solve(sudokuVector& grid) {
		for (Coord currentCoord(0, 0); currentCoord.x < n;) {
			if (grid[currentCoord.x][currentCoord.y].IsSafe()) {
				currentCoord++;
				continue;
			}
			while (grid[currentCoord.x][currentCoord.y].Increment()) {
				if (CheckConditions(grid, currentCoord))
					break;
			}
			if (grid[currentCoord.x][currentCoord.y].GetNum() == 0) {
				currentCoord = grid[currentCoord.x][currentCoord.y].GoBack();
				continue;
			}
			currentCoord++;
		}

	}
	/* For Debugging
	void PrintGrid(sudokuVector& grid) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << grid[i][j].GetNum() << " ";
				if (j % 3 == 2)
					std::cout << '|';
			}
			if (i % 3 == 2)
				std::cout << "\n---------------------\n";
			else
				std::cout << "\n";
		}
	}*/

	int CtoI(const char& x) {
		return x - '0';
	}

}