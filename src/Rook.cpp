#include "../header/Rook.h"

void Rook::straightMove(bool d, int i, int pieceLocations[8][8]) {
    int r = this->get_placeAt().get_row(); // start at row of current rook
    int c = this->get_placeAt().get_column(); // start at column of current rook

    if (d) { // if we are moving through rows or columns, if d is true (increment column)
        c += i; //move to next Square
    } else {
        r += i; //move to next Square
    }

    while (pieceLocations[c][r] == 0 && c < 63 && r < 63 && c >= 0 && r >= 0) { //Check if a piece exists at the Square location or if we passed the bounds of the Chess Board
        Square newMove(r,c);
        this->add_move(newMove); //add the new square to the moveableSquares vector
        if (d) { // if we are moving through rows or columns, if d is true (increment column)
            c += i;
        } else {
            r += i;
        }
    }

    if (pieceLocations[c][r] == 1 && this->get_color() == false) { //if the piece at the Square we stopped at is white and our color is black then add the move to the moveableSquares vector
        Square newMove(r,c);
        this->add_move(newMove);
    } else if (pieceLocations[c][r] == 2 && this->get_color() == true) { //if the piece at the Square we stopped at is black and our color is white then add the move to the moveableSquares vector
        Square newMove(r,c);
        this->add_move(newMove);
    }
}

void Rook::scan(std::vector<ChessPiece*> &Pieces) {
    
    int pieceLocations[8][8] = {0}; //Initialize 2d array of Chess Board to 0 (no piece at that location)

    for (int i =0; i < Pieces.size(); ++i) { // traverse over Pieces vector and assign the Pieces to their pieceLocation
        if (Pieces.at(i)->get_color()) {
            pieceLocations[Pieces.at(i)->get_placeAt().get_column()][Pieces.at(i)->get_placeAt().get_row()] = 1; //assign 1 to locations that contain a white piece
        } else {
            pieceLocations[Pieces.at(i)->get_placeAt().get_column()][Pieces.at(i)->get_placeAt().get_row()] = 2; //assign 2 to locations that contain a black piece
        }
    }

    straightMove(true, 1, pieceLocations); // add all moves available to the right of the rook
    straightMove(false, 1, pieceLocations); // add all moves available above the rook
    straightMove(true, -1, pieceLocations); // add all moves available to the left of the rook
    straightMove(false, -1, pieceLocations); // add all moves available under the rook
}