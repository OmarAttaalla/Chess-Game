#ifndef MOVEALG_H
#define MOVEALG_H

#include "ChessPiece.h"

class MoveAlg {
    public:
        virtual void Movement(ChessPiece* chessPiece, bool d, int i, int pieceLocations[8][8]) = 0; //Passes in column/row axis, the move increment (1 or -1), and 2d array of the locations of all ChessPieces
};


#endif