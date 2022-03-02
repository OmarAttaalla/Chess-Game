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

void Knight::scan(ChessBoard &Board) {
    movement->Scan(this, 0, Board);
    movement->Scan(this, 1, Board);
    movement->Scan(this, 2, Board);
    movement->Scan(this, 3, Board);
    movement->Scan(this, 4, Board);
    movement->Scan(this, 5, Board);
    movement->Scan(this, 6, Board);
    movement->Scan(this, 7, Board);
}

