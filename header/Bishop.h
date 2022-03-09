#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"
#include "DiagonalScan.h"

using namespace std;

class Bishop : public ChessPiece {
    private:
        Square* placeAt;
        vector<Square*> moveableSquares;
        ScanAlg* diagonal;        

    public:
        Bishop(bool newColor, Square* newPlaceAt);
        ~Bishop();
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
};


#endif
