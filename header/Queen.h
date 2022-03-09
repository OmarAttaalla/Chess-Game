#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"
#include "StraightScan.h"
#include "DiagonalScan.h"

class Queen : public ChessPiece {
    private:
        ScanAlg* straightScan; //pointer to object that represents the movement algorithm needed for Rook (StraightMove alg)
        ScanAlg* diagonalScan; //pointer to object that represents the movement algorithm needed for Rook (DiagonalMove alg)
    public:
        Queen(bool newColor, Square* newPlaceAt) {
            set_color(newColor);
            set_placeAt(newPlaceAt);
            straightScan = new StraightScan;
            diagonalScan = new DiagonalScan;
        }
        ~Queen(){delete straightScan; delete diagonalScan;}
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
};


#endif