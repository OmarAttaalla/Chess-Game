#include "Pawn.h"

Pawn::Pawn(bool newColor, Square* newPlaceAt) {
    set_color(newColor);
    set_placeAt(newPlaceAt);
    movement = new PawnScan;
    initialMove = true;
}

// 3 will symbolize the initial double move
void Pawn::scan(ChessBoard &Board) {
    movement->Scan(this, 0, Board);
    movement->Scan(this, 1, Board);
    movement->Scan(this, 2, Board);

    if(initialMove)
    {
        movement->Scan(this, 3, Board);

        initialMove = false;
    }
}
