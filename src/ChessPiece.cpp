#include "../header/ChessPiece.h"

void ChessPiece::moves(Square* sq, ChessBoard &Board) {    
    for(int i = 0; i < moveableSquares.size(); i++) {
        if(moveableSquares.at(i) == sq) {
            if (sq->getPiece() != nullptr) {
                Board.removePiece(sq->getPiece());
            }

	    placeAt->setPiece(nullptr); //set the current location to blank
            moveableSquares.at(i)->setPiece(this);
            placeAt = moveableSquares.at(i);
            clear_moveableSquares();
            return;
        }
    }
}
