#include "../header/King.h"

void King::scan(ChessBoard &Board) {
    //Add all Diagonal Path moves and Straight Path Moves
    for (int i =0; i < 8; ++i) {
        kingScan->Scan(this, i, Board);
    }
}

bool King::checkScan(ChessBoard &Board) {
    ///traverse list of opposite color pieces, call scan and check if the Kings location is a moveableSquare
}