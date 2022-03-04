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
        bool checkScan(ChessBoard &Board, King* piece); //checks if the king would be in check (piece refers to the king object, would be "this" if it was this king)
};


#endif