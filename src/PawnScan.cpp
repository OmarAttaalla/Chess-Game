#include "../header/PawnScan.h"

void PawnScan::Scan(ChessPiece* chessPiece, int i, ChessBoard &Board) {
    int r = chessPiece->get_placeAt()->get_row();
    int c = chessPiece->get_placeAt()->get_column();

    int rChange = 0, cChange = 0;
    // assume chessPiece color false means black and true means white
    // assuming you are bottom chess player (White) -> i 0 - 3
    // if black, then following if statement should inverse values to correctly implement direction
    // 0 means upper left, 1 means up by 1 square, 2 means upper right, 3 means up by 2 squares (initial move)
    if (i == 0) {
        rChange = 1;
        cChange = -1;
    } else if (i == 1) {
        rChange = 1;
    } else if (i == 2) {
        rChange = 1;
        cChange = 1;
    } else if (i == 3) {
        rChange = 2;
    }


    // checks if black
    if(!chessPiece->get_color()) {
	rChange *= -1;
	cChange *= -1;
    }

    r += rChange;
    c += cChange;

    // checks for correct bound
    if (c <= 7 && r <= 7 && c >= 0 && r >= 0) {
	// checks if only moving
	if ((i == 1 || i == 3) && Board.getSquare(r,c)->getPiece() == nullptr)
	    chessPiece->add_move(Board.getSquare(r,c));
	else if (Board.getSquare(r,c)->getPiece() != nullptr && ((i == 2 || i == 0) && Board.getSquare(r,c)->getPiece()->get_color() != chessPiece->get_color()))
	    chessPiece->add_move(Board.getSquare(r,c));
    }
}
