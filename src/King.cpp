#include "../header/King.h"
#include "../header/Queen.h"
#include "../header/Knight.h"

void King::scan(ChessBoard &Board) {
    //Add all Diagonal Path moves and Straight Path Moves
    for (int i =0; i < 8; ++i) {
        kingScan->Scan(this, i, Board);
    }
}

bool King::checkMoves(const std::vector<Square*> &v,ChessBoard &Board) {
    //traverse all possible moves and check if a piece exists at that location
    for (int i = 0; i < v.size(); ++i){
        if (v.at(i)->getPiece() != nullptr) { //check if a piece exists at that location
            v.at(i)->getPiece()->scan(Board); //if a piece exists call its scan and check if the kings location is a moveableSquare
            std::vector<Square*> moveablePieceSquares =  v.at(i)->getPiece()->get_moveableSquares();
            for (int g = 0; g < moveablePieceSquares.size(); ++g) {
                if (moveablePieceSquares.at(g)->get_row() == get_placeAt()->get_row() && moveablePieceSquares.at(g)->get_column() == get_placeAt()->get_column()) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool King::checkScan(ChessBoard &Board) {
    //std::vector<ChessPiece*> oppPieces = Board.get_pieces(!get_color()); //opposite pieces

    ChessPiece* tempQueen = new Queen(get_color(), get_placeAt()); //Create a Queen at the Kings location
    ChessPiece* tempKnight = new Knight(get_color(), get_placeAt()); //Create a Knight at the Kings location

    tempQueen->scan(Board); //scan all possible Queen moves
    tempKnight->scan(Board); //scan all possible Knight moves

    bool inCheck = false; //boolean for if the king is in check

    //traverse all possible Queen moves and check if a piece exists at that location
    std::vector<Square*> moveableSquares = tempQueen->get_moveableSquares();
    inCheck = checkMoves(moveableSquares, Board);

    if (!inCheck) {
        //traverse all possible Knight moves and check if a piece exists at that location
        std::vector<Square*> kmoveableSquares = tempKnight->get_moveableSquares();
        inCheck = checkMoves(kmoveableSquares, Board);
    }

    // deallocate temporary pieces
    delete tempQueen;
    delete tempKnight;

    return inCheck;
}