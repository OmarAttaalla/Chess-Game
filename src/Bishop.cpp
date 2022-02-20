#include "../header/Bishop.h"

Bishop::Bishop(bool newColor, Square newPlaceAt) {
    color = newColor;
    placeAt = newPlaceAt;
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
void Bishop::scan() {
    int x = 1;
    int y = 1;
        
    while(isMoveable(placeAt.getRow() + x, placeAt.getColumn() + y)) {
	moveableSquares.pushback(chessBoard.getSquare(placeAt.getRow() + x, placeAt.getColumn() + y));
	x++;
	y++;
    }

    x = -1;
    y = -1;

    while(isMoveable(placeAt.getRow() + x, placeAt.getColumn() + y)) {
        moveableSquares.pushback(chessBoard.getSquare(placeAt.getRow() + x, placeAt.getColumn() + y));
        x--;
        y--;
    }

    x = -1;
    y = 1;

    while(isMoveable(placeAt.getRow() + x, placeAt.getColumn() + y)) {
        moveableSquares.pushback(chessBoard.getSquare(placeAt.getRow() + x, placeAt.getColumn() + y));
        x--;
        y++;
    }

    x = 1;
    y = -1;

    while(isMoveable(placeAt.getRow() + x, placeAt.getColumn() + y)) {
        moveableSquares.pushback(chessBoard.getSquare(placeAt.getRow() + x, placeAt.getColumn() + y));
        x++;
        y--;
    }


}

// note to self: getSquare in chessBoard needs to check if input is out of bounds or not
bool Bishop::isMoveable(int row, int col){
    Square moveSquare = chessBoard.getSquare(row, col);
        
    if(moveSquare.hasPiece && moveSquare.getPiece.getColor == this.getColor()) {        
        return false;
    } else
        return true;
}
