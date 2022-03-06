#include "../header/KnightScan.h"

void KnightScan::Scan(ChessPiece* chessPiece, int i, ChessBoard &Board) {
    int r = chessPiece->get_placeAt()->get_row(); // start at row of current rook
    int c = chessPiece->get_placeAt()->get_column(); // start at column of current rook

    // clockwise from top
    if (i == 0) {
        r += 1;
        c += 2;
    } else if (i == 1) {
        r += 2;
        c += 1;
    } else if (i == 2) {
        r += 2;
        c -= 1;
    } else if (i == 3) {
        r += 1;
        c -= 2;
    } else if (i == 4) {
        r -= 1;
        c -= 2;
    } else if (i == 5) {
        r -= 2;
        c -= 1;
    } else if (i == 6) {
        r -= 2;
        c += 1;
    } else if (i == 7) {
        r -= 1;
        c += 2;
    }

    if (c <= 7 && r <= 7 && c >= 0 && r >= 0 && Board.getSquare(r,c)->getPiece() == nullptr) {
        chessPiece->add_move(Board.getSquare(r,c));
    } else if (c <= 7 && r <= 7 && c >= 0 && r >= 0 && Board.getSquare(r,c)->getPiece()->get_color() != chessPiece->get_color()) {
        chessPiece->add_move(Board.getSquare(r,c));
    }
}
