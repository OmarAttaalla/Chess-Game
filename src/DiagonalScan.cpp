#include "../header/DiagonalScan.h"

void DiagonalScan::Scan(ChessPiece* chessPiece, int i, ChessBoard &Board) {
    int r = chessPiece->get_placeAt()->get_row(); // start at row of current rook
    int c = chessPiece->get_placeAt()->get_column(); // start at column of current rook

    int u; //up or down
    int inc; // left or right

    if (i == 0) {
        u = 1;
        inc = 1;
    } else if (i == 1) {
        u = -1;
        inc = 1;
    } else if (i == 2) {
        u = 1;
        inc = -1;
    } else if (i == 3) {
        u = -1;
        inc = -1;
    }

    c += inc; //move to the right or left
    r += u; //move up or down

    while (c <= 7 && r <= 7 && c >= 0 && r >= 0 && Board.getSquare(r,c)->getPiece() == nullptr) { //Check if a piece exists at the Square location or if we passed the bounds of the Chess Board
        chessPiece->add_move(Board.getSquare(r,c)); //add the new square to the moveableSquares vector
        
        c += inc; //move to the right or left
        r += u; //move up or down
    }

    if (c <= 7 && r <= 7 && c >= 0 && r >= 0 && Board.getSquare(r,c)->getPiece()->get_color() != chessPiece->get_color()) { //if the piece at the Square we stopped at is white and our color is black then add the move to the moveableSquares vector
        chessPiece->add_move(Board.getSquare(r,c)); //add the new square to the moveableSquares vector
    }
}