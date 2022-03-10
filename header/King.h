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
        virtual ~King(){delete kingScan;}
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
        bool checkScan(ChessBoard &Board); //checks if the king would be in check 
        bool checkMoves(const std::vector<Square*> &v,ChessBoard &Board); //helper function that traverses moves list v and checks if a move is the kings location
        bool checkmate(ChessBoard Board); //assumes king is in check
};


#endif