#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
    private:
        
    public:
        virtual void Moves();
        virtual void scan(std::vector<ChessPiece*> &Pieces);
        virtual void pieceDeath();
        void straightMove(bool d, int i, bool pieceLocations[8][8]); //helper function that passes in column/row axis, the move increment (1 or -1), and 2d array of the locations of all ChessPieces
};


#endif
