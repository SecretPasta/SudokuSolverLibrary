#ifndef SUDOKUSOLVER_COORD_H
#define SUDOKUSOLVER_COORD_H

class Coord {
public:
	int x, y;

	Coord(int x, int y);

	bool operator!=(const Coord& other) const;
	
	const Coord& operator++(int);

};

#endif