#ifndef SCANALG_H
#define SCANALG_H

#include "ChessPiece.h"

class ScanAlg {
    public:
        virtual void Scan(ChessPiece* chessPiece, int i, ChessBoard &Board) = 0; //Passes in column/row axis, the move increment (1 or -1), and 2d array of the locations of all ChessPieces
};


#endif
