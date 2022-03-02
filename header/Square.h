#ifndef SQUARE_H
#define SQUARE_H

class ChessPiece;

class Square {
    private:
        int row;
        int column;
        ChessPiece* Piece;
    public:
        Square() {}
        Square(int r, int c) { row = r; column = c; Piece = nullptr;}
    
        int get_row() {return row;}
        int get_column() {return column;}
        ChessPiece* getPiece() { return Piece;}
        void setPiece(ChessPiece* newPiece) { Piece = newPiece;}
};

#endif
