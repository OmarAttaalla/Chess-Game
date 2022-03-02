#include "../header/Bishop.h"

Bishop::Bishop(bool newColor, Square* newPlaceAt) {
    set_color(newColor);
    set_placeAt(newPlaceAt);
    diagonal = new DiagonalScan;
}


void Bishop::moves(Square* sq) {
    scan();
    
    for(int i = 0, i < moveableSquares.length(), i++) {
	if(moveableSquares.at(i) == sq) {
	    placeAt = moveableSquares.at(i);
	    clear_moveableSquares();
	    return;
	}
    }
}

void Bishop::scan(Chessboard &Board) {
    diagonalScan->Scan(this, 0, Board);
    diagonalScan->Scan(this, 1, Board);
    diagonalScan->Scan(this, 2, Board);
    diagonalScan->Scan(this, 3, Board);
}
