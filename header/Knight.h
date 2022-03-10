#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
#include "KnightScan.h"


class Knight : public ChessPiece {
    private:
        ScanAlg* movement;
    public:
        Knight(bool newColor, Square* newPlaceAt);
        virtual ~Knight(){delete movement;}
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
};


#endif
