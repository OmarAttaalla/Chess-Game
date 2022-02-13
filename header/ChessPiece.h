#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Square.h"
#include <vector>

class ChessPiece {
    private:
        bool color;
        std::vector<Square> moveableSquares; //vector of Square moveable locations
        Square placeAt; //The square where the piece is located
    public:
        virtual void Moves() = 0;
        virtual void scan(std::vector<ChessPiece*> &Pieces) = 0; //function that scans available moves for the chess piece
        virtual void pieceDeath() = 0;
        bool get_color(){ return color;}
};

#endif