#include "../header/KingScan.h"
#include "../header/King.h"

void KingScan::Scan(ChessPiece* chessPiece, int i, ChessBoard &Board) {
    int r = chessPiece->get_placeAt()->get_row(); // start at row of current rook
    int c = chessPiece->get_placeAt()->get_column(); // start at column of current rook

    // clockwise from top
    if (i == 0) {
        r += 1;
        c += 1;
    } else if (i == 1) {
        r += -1;
        c += 1;
    } else if (i == 2) {
        r += 1;
        c += -1;
    } else if (i == 3) {
        r += -1;
        c += -1;
    } else if (i == 4) {
        r += 1;
        c += 0;
    } else if (i == 5) {
        r += 0;
        c += 1;
    } else if (i == 6) {
        r -= -1;
        c += 0;
    } else if (i == 7) {
        r -= 0;
        c += -1;
    }

    King* newKing = new King(chessPiece->get_color(),Board.getSquare(r,c));
    
    if (c <= 7 && r <= 7 && c >= 0 && r >= 0 && Board.getSquare(r,c)->getPiece()->get_color() != chessPiece->get_color() && !newKing->checkScan(Board)) {
        chessPiece->add_move(Board.getSquare(r,c));
    }
}