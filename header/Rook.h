#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
    private:
        
    public:
        virtual void Moves();
        virtual void scan(std::vector<ChessPiece*> &Pieces);
        virtual void pieceDeath();
};


#endif
