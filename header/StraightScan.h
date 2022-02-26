#ifndef STRAIGHTMOVE_H
#define STRAIGHTMOVE_H

#include "ScanAlg.h"

class StraightScan : public ScanAlg {
    public:
        //function that increments up,down,left,right until a ChessPiece is found or it reaches a bound
        virtual void Scan(ChessPiece* chessPiece, int i, ChessBoard &Board);
};


#endif