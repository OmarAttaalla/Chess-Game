#include "../header/Queen.h"

void Queen::scan(ChessBoard &Board) {
    //Add all Diagonal Path moves and Straight Path Moves
    for (int i =0; i < 4; ++i) {
        straightScan->Scan(this, i, Board); // add all straight moves
        diagonalScan->Scan(this, i, Board); // add all diagonal moves
    }
}