#include "../header/Bishop.h"

Bishop::Bishop(bool newColor, Square* newPlaceAt) {
    set_color(newColor);
    set_placeAt(newPlaceAt);
    diagonal = new DiagonalScan;
}


void Bishop::moves(Square* sq) {    
    for(int i = 0; i < moveableSquares.size(); i++) {
	if(moveableSquares.at(i) == sq) {
	    placeAt = moveableSquares.at(i);
	    clear_moveableSquares();
	    return;
	}
    }
}

void Bishop::scan(ChessBoard &Board) {
    diagonal->Scan(this, 0, Board);
    diagonal->Scan(this, 1, Board);
    diagonal->Scan(this, 2, Board);
    diagonal->Scan(this, 3, Board);
}
