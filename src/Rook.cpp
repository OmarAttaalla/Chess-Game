#include "../header/Rook.h"

void Rook::scan(ChessBoard &Board) {
    
    //Add all Straight Path Moves
    for (int i =0; i < 4; ++i) {
        straightScan->Scan(this, i, Board); // add all straight moves
    }
}