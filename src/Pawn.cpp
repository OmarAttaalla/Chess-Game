#include "../header/Pawn.h"

Pawn::Pawn(bool newColor, Square* newPlaceAt) {
    set_color(newColor);
    set_placeAt(newPlaceAt);
    movement = new PawnScan;
    initialMove = true;
}


void Pawn::moves(Square* sq, ChessBoard &Board) {    
    for(int i = 0; i < moveableSquares.size(); i++) {
	if(moveableSquares.at(i) == sq) {
	    if (sq->getPiece() != nullptr) {
		Board.removePiece(sq->getPiece());
	    }
	    placeAt->setPiece(nullptr); //set the current location to blank
	    moveableSquares.at(i)->setPiece(this);
	    placeAt = moveableSquares.at(i);
	    clear_moveableSquares();
	    initialMove = false;
	    return;
	}
    }
}

// 3 will symbolize the initial double move
void Pawn::scan(ChessBoard &Board) {
    movement->Scan(this, 0, Board);
    movement->Scan(this, 1, Board);
    movement->Scan(this, 2, Board);

    if(initialMove)
	movement->Scan(this, 3, Board);
}
