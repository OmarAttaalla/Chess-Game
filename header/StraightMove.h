#ifndef STRAIGHTMOVE_H
#define STRAIGHTMOVE_H

#include "MoveAlg.h"
#include "Square.h"

class StraightMove : public MoveAlg {
    public:
        virtual void Movement(ChessPiece* chessPiece, bool d, int i, int pieceLocations[8][8]);  //function that increments up,down,left,right until a ChessPiece is found or it reaches a bound
};


#endif