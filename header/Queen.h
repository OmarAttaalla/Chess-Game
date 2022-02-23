#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"
#include "StraightMove.h"
#include "DiagonalMove.h"

class Queen : public ChessPiece {
    private:
        MoveAlg* straightMove; //pointer to object that represents the movement algorithm needed for Rook (StraightMove alg)
        MoveAlg* diagonalMove; //pointer to object that represents the movement algorithm needed for Rook (DiagonalMove alg)
    public:
        Queen(bool newColor, Square newPlaceAt) {
            set_color(newColor);
            set_placeAt(newPlaceAt);
            straightMove = new StraightMove;
            diagonalMove = new DiagonalMove;
        }
        virtual void Moves() {}
        virtual void scan(std::vector<ChessPiece*> &Pieces);
        virtual void pieceDeath() {}
};


#endif