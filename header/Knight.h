#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
#include "KnightScan.h"


class Knight : public ChessPiece {
    private:
        Square* placeAt;
        std::vector<Square*> moveableSquares;
        ScanAlg* movement;
    public:
        Knight(bool newColor, Square* newPlaceAt);
        virtual void moves(Square* sq);
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
};


#endif
