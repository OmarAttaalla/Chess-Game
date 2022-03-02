#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
#include "DiagonalScan.h"


using namespace std;

class Knight : public ChessPiece {
    private:
        Square* placeAt;
        vector<Square*> moveableSquares;
        ScanAlg* movement;
    public:
        Knight(bool newColor, Square* newPlaceAt);
        virtual void moves(Square* sq);
        virtual void scan(Chessboard &Board);
        virtual void pieceDeath(); 
};


#endif
