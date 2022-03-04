#ifndef KING_H
#define KING_H

#include "ChessPiece.h"
#include "KingScan.h"

class King : public ChessPiece {
    private:
        ScanAlg* kingScan;
    public:
        King(bool newColor, Square* newPlaceAt) {
            set_color(newColor);
            set_placeAt(newPlaceAt);
            kingScan = new KingScan;
        }
        virtual void moves(Square* sq) {}
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
        bool checkScan(ChessBoard &Board); //checks if the king would be in check 
};


#endif