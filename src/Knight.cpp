#include "../header/Knight.h"

Knight::Knight(bool newColor, Square* newPlaceAt) {
    set_color(newColor);
    set_placeAt(newPlaceAt);
    movement = new KnightScan;
}


void Knight::moves(Square* sq) {    
    for(int i = 0; i < moveableSquares.size(); i++) {
	if(moveableSquares.at(i) == sq) {
	    placeAt = moveableSquares.at(i);
	    clear_moveableSquares();
	    return;
	}
    }
}

void Knight::scan(Chessboard &Board) {
    KnightScan->Scan(this, 0, Board);
    KnightScan->Scan(this, 1, Board);
    KnightScan->Scan(this, 2, Board);
    KnightScan->Scan(this, 3, Board);
    KnightScan->Scan(this, 4, Board);
    KnightScan->Scan(this, 5, Board);
    KnightScan->Scan(this, 6, Board);
    KnightScan->Scan(this, 7, Board);
}

