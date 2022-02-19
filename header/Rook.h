#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"
#include "StraightMove.h"

class Rook : public ChessPiece {
    private:
        
    public:
        Rook(bool newColor, Square newPlaceAt) {
            set_color(newColor);
            set_placeAt(newPlaceAt);
        }
        virtual void Moves();
        virtual void scan(std::vector<ChessPiece*> &Pieces);
        virtual void pieceDeath(); 
};


#endif
