#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Square.h"

class ChessPiece {
    private:
        bool color;
        Square moveableSquares[64]; //64 since the maximum possible squares are 64. However this could be less
        Square placeAt; //The square where the piece is located
    public:
        virtual void Moves() = 0;
        virtual void scan() = 0;
        virtual void pieceDeath() = 0;
};

#endif