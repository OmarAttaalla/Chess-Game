#include "../header/StraightScan.h"

void StraightScan::Scan(ChessPiece* chessPiece, int i, ChessBoard &Board) {
    int r = chessPiece->get_placeAt()->get_row(); // start at row of current rook
    int c = chessPiece->get_placeAt()->get_column(); // start at column of current rook

    bool u; //vertical or horizontal
    int inc; // positive or negative

    if (i == 0) {
        u = false;
        inc = 1;
    } else if (i == 1) {
        u = true;
        inc = 1;
    } else if (i == 2) {
        u = false;
        inc = -1;
    } else if (i == 3) {
        u = true;
        inc = -1;
    }

    if (u) { // if we are moving through rows or columns, if d is true (increment column)
        c += inc; //move to next Square
    } else {
        r += inc; //move to next Square
    }


    while (c <= 7 && r <= 7 && c >= 0 && r >= 0 && Board.getSquare(r,c)->getPiece() == nullptr) { //Check if a piece exists at the Square location or if we passed the bounds of the Chess Board
        chessPiece->add_move(Board.getSquare(r,c)); //add the new square to the moveableSquares vector
        if (u) { // if we are moving through rows or columns, if d is true (increment column)
            c += inc;
        } else {
            r += inc;
        }
    }

    if (c <= 7 && r <= 7 && c >= 0 && r >= 0 && Board.getSquare(r,c)->getPiece()->get_color() != chessPiece->get_color()) { //if the piece at the Square we stopped at is white and our color is black then add the move to the moveableSquares vector
        chessPiece->add_move(Board.getSquare(r,c)); //add the new square to the moveableSquares vector
    }
}