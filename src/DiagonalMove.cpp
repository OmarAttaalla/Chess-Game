#include "../header/DiagonalMove.h"

void DiagonalMove::Movement(ChessPiece* chessPiece, bool d, int i, int pieceLocations[8][8]) {
    int r = chessPiece->get_placeAt().get_row(); // start at row of current rook
    int c = chessPiece->get_placeAt().get_column(); // start at column of current rook

    int axisIncrement; //Either 1 or -1 depending on if we are going left or right

    if (d) { // if we are moving to the right or left
        axisIncrement = 1; //we are moving to the right
    } else {
        axisIncrement = -1; //we are moving to the left
    }

    c += axisIncrement; //move to the right
    r += i; //move up or down

    while (pieceLocations[c][r] == 0 && c <= 7 && r <= 7 && c >= 0 && r >= 0) { //Check if a piece exists at the Square location or if we passed the bounds of the Chess Board
        Square newMove(r,c);
        chessPiece->add_move(newMove); //add the new square to the moveableSquares vector
        
        c += axisIncrement; //move to the right
        r += i; //move up or down
    }

    if (pieceLocations[c][r] == 1 && chessPiece->get_color() == false) { //if the piece at the Square we stopped at is white and our color is black then add the move to the moveableSquares vector
        Square newMove(r,c);
        chessPiece->add_move(newMove);
    } else if (pieceLocations[c][r] == 2 && chessPiece->get_color() == true) { //if the piece at the Square we stopped at is black and our color is white then add the move to the moveableSquares vector
        Square newMove(r,c);
        chessPiece->add_move(newMove);
    }
}