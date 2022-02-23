#include "../header/Queen.h"

void Queen::scan(std::vector<ChessPiece*> &Pieces) {
    
    int pieceLocations[8][8] = {0}; //Initialize 2d array of Chess Board to 0 (no piece at that location)

    for (int i =0; i < Pieces.size(); ++i) { // traverse over Pieces vector and assign the Pieces to their pieceLocation
        if (Pieces.at(i)->get_color()) {
            pieceLocations[Pieces.at(i)->get_placeAt().get_column()][Pieces.at(i)->get_placeAt().get_row()] = 1; //assign 1 to locations that contain a white piece
        } else {
            pieceLocations[Pieces.at(i)->get_placeAt().get_column()][Pieces.at(i)->get_placeAt().get_row()] = 2; //assign 2 to locations that contain a black piece
        }
    }

    //Add all straight path moves
    straightMove->Movement(this, true, 1, pieceLocations); // add all moves available to the right of the queen
    straightMove->Movement(this, false, 1, pieceLocations); // add all moves available above the queen
    straightMove->Movement(this, true, -1, pieceLocations); // add all moves available to the left of the queen
    straightMove->Movement(this, false, -1, pieceLocations); // add all moves available under the queen

    //Add all Diagonal Path moves
    diagonalMove->Movement(this, true, 1, pieceLocations); // add all moves available up-right
    diagonalMove->Movement(this, false, 1, pieceLocations); // add all moves available up-left
    diagonalMove->Movement(this, true, -1, pieceLocations); // add all moves available down-right
    diagonalMove->Movement(this, false, -1, pieceLocations); // add all moves available down-left

}