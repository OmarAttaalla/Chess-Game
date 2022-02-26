#ifndef SQUARE_H
#define SQUARE_H

#include "ChessPiece.h"

class Square {
    private:
        int row;
        int column;
        ChessPiece* Piece;
    public:
        Square() {}
        Square(int r, int c) { row = r; column = c; }
    
        int get_row() {return row;}
        int get_column() {return column;}
        ChessPiece* getPiece() { return Piece;}
        void setPiece(ChessPiece* newPiece) { Piece = newPiece;}
};

#endif