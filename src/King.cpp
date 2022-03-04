#include "../header/King.h"

void King::scan(ChessBoard &Board) {
    //Add all Diagonal Path moves and Straight Path Moves
    for (int i =0; i < 8; ++i) {
        kingScan->Scan(this, i, Board);
    }
}