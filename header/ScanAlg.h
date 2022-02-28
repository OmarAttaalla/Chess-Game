#ifndef SCANALG_H
#define SCANALG_H

#include "ChessPiece.h"

class ScanAlg {
    public:
        virtual void Scan(ChessPiece* chessPiece, int i, ChessBoard &Board) = 0;
};


#endif
