#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"
#include "StraightScan.h"

class Rook : public ChessPiece {
    private:
        ScanAlg* straightScan; //pointer to object that represents the movement algorithm needed for Rook (StraightMove alg)
    public:
        Rook(bool newColor, Square* newPlaceAt) {
            set_color(newColor);
            set_placeAt(newPlaceAt);
            straightScan = new StraightScan;
        }
        ~Rook(){delete straightScan;}
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
};


#endif
