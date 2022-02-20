#include "../header/Knight.h"

Knight::Knight(bool newColor, Square newPlaceAt) {
    color = newColor;
    placeAt = newPlaceAt;
}

// input can be changed, depends on other classes. Maybe pointers?
void Knight::moves(Square sq) {
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
void Knight::scan() {
    int currRow = placeAt.getRow();
    int currCol = placeAt.getColumn();

    if(isMovable(currRow+1, currCol+2))
        moveableSquares.pushback(chessBoard.getSquare(currRow+1, currCol+2));

    if(isMovable(currRow+2, currCol+1))
        moveableSquares.pushback(chessBoard.getSquare(currRow+2, currCol+1));

    if(isMovable(currRow+2, currCol-1))
        moveableSquares.pushback(chessBoard.getSquare(currRow+2, currCol-1));

    if(isMovable(currRow+1, currCol-2))
        moveableSquares.pushback(chessBoard.getSquare(currRow+1, currCol-2));

    if(isMovable(currRow-1, currCol-2))
        moveableSquares.pushback(chessBoard.getSquare(currRow-1, currCol-2));

    if(isMovable(currRow-2, currCol-1))
        moveableSquares.pushback(chessBoard.getSquare(currRow-2, currCol-1));

    if(isMovable(currRow-2, currCol+1))
        moveableSquares.pushback(chessBoard.getSquare(currRow-2, currCol+1));

    if(isMovable(currRow-1, currCol+2))
        moveableSquares.pushback(chessBoard.getSquare(currRow-1, currCol+2));

    return;
}


bool Knight::isMoveable(int row, int col){
    // note to self: getSquare in chessBoard needs to check if input is out of bounds or not
    Square moveSquare = chessBoard.getSquare(row, col);
        
    if(moveSquare.hasPiece && moveSquare.getPiece.getColor == this.getColor()) {        
        return false;
    } else
        return true;
}

