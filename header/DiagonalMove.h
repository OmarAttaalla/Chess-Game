#ifndef DIAGONALMOVE_H
#define DIAGONALMOVE_H

#include "MoveAlg.h"

class DiagonalMove : public MoveAlg {
    public:
        //function that increments diagonal paths (up-left, up-right, down-left, down-right)
        virtual void Movement(ChessPiece* chessPiece, bool d, int i, int pieceLocations[8][8]);
};


#endif