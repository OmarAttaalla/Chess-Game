#ifndef SQUARE_H
#define SQUARE_H


class Square {
    private:
        int row;
        int column;
	ChessPiece* Piece;
    public:
        Square();
        Square(int r, int c);
    
        int getRow() {return row;}
        int getColumn() {return column;}
	ChessPiece* getPiece() {return Piece;}
        void setPiece(ChessPiece* newPiece) {Piece = newPiece;}
};

#endif
