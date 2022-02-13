#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
    private:
        
    public:
        virtual void Moves();
        virtual void scan(std::vector<ChessPiece*> &Pieces);
        virtual void pieceDeath();
        //Helper function that increments up,down,left,right until a ChessPiece is found or it reaches a bound
        void straightMove(bool d, int i, int pieceLocations[8][8]); //Passes in column/row axis, the move increment (1 or -1), and 2d array of the locations of all ChessPieces
};


#endif
