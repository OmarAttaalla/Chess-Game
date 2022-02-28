#include "../header/Bishop.h"

Bishop::Bishop(bool newColor, Square* newPlaceAt) {
    set_color(newColor);
    set_placeAt(newPlaceAt);
    diagonal = new DiagonalScan;
}

// input can be changed, depends on other classes. Maybe pointers?
void Bishop::moves(Square sq) {
    scan();
    
    for(int i = 0, i < moveableSquares.length(), i++) {
	if(placeAt.getRow() == moveableSquares.at(i).getRow() && placeAt.getColumn() == moveableSquares.at(i).getColumn()) {
	    placeAt = moveableSquares.at(i);
	    moveableSquares.clear();
	    return;
	}
    }
}

// assume ChessBoard has double array, Square should have "getPiece"
void Bishop::scan(Chessboard &Board) {
    diagonalScan->Scan(this, 0, Board);
    diagonalScan->Scan(this, 1, Board);
    diagonalScan->Scan(this, 2, Board);
    diagonalScan->Scan(this, 3, Board);
}

// note to self: getSquare in chessBoard needs to check if input is out of bounds or not
bool Bishop::isMoveable(int row, int col){
    Square moveSquare = chessBoard.getSquare(row, col);
        
    if(moveSquare.hasPiece && moveSquare.getPiece.getColor == this.getColor()) {        
        return false;
    } else
        return true;
}
