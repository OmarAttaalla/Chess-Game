#include "../header/ChessBoard.h"

#include "../header/Rook.h"
#include "../header/Queen.h"
#include "../header/Knight.h"
#include "../header/Bishop.h"
#include "../header/King.h"
#include "../header/Pawn.h"

std::vector<ChessPiece*> ChessBoard::get_pieces(bool color) {
    if (color) {
        return whitePieces;
    }

    return blackPieces;
}

void ChessBoard::addPiece(ChessPiece* newPiece) {
    if (newPiece == nullptr){return;}

    if (newPiece->get_color()) {
        whitePieces.push_back(newPiece);
    } else {
        blackPieces.push_back(newPiece);
    }
}

void ChessBoard::removePiece(ChessPiece* newPiece) {
    if (newPiece == nullptr) {return;}

    if (newPiece->get_color()) {
        for (int i =0; i < whitePieces.size(); ++i) {
            if (whitePieces.at(i) == newPiece) {
                whitePieces.erase(whitePieces.begin() + i);
                break;
            }
        }
    } else {
        for (int i =0; i < blackPieces.size(); ++i) {
            if (blackPieces.at(i) == newPiece) {
                blackPieces.erase(blackPieces.begin() + i);
                break;
            }
        }
    }

    newPiece->get_placeAt()->setPiece(nullptr);
    delete newPiece;
}

ChessBoard::ChessBoard(bool t){
    for (int i = 0; i < 8; ++i) {
        std::vector<Square*> rows;
        for (int g = 0; g < 8; ++g) {
            Square* newSquare = new Square(i,g);
            rows.push_back(newSquare);    
        }
        squares.push_back(rows);
    }
}


ChessBoard::ChessBoard() {
    for (int i = 0; i < 8; ++i) {
        std::vector<Square*> rows;
        for (int g = 0; g < 8; ++g) {
            Square* newSquare = new Square(i,g);
            rows.push_back(newSquare);

            std::vector<ChessPiece*>* PieceSet;

            bool sideColor;
            if (i == 0 || i == 1) { //Check if we are creating white or black pieces
                sideColor = true;
                PieceSet = &whitePieces;
            } else {
                sideColor = false;
                PieceSet = &blackPieces;
            }

            if (i == 1 || i == 6) {
                ChessPiece* newPiece = new Pawn(sideColor, newSquare); //create pawn
                newSquare->setPiece(newPiece);
		PieceSet->push_back(newPiece);
            } else if (i == 0 || i == 7) {
                ChessPiece* newPiece;
                if (g == 0 || g == 7) { //add rooks
                    newPiece = new Rook(sideColor, newSquare);

                } else if (g == 1 || g == 6) {
                    newPiece = new Knight(sideColor, newSquare); //create Knight
                } else if (g == 2 || g == 5) {
                    newPiece = new Bishop(sideColor, newSquare); //create Bishop
                } else if (g == 3) {
                    newPiece = new Queen(sideColor, newSquare); //create queen
                } else if (g == 4) {
                    newPiece = new King(sideColor, newSquare); // create King
                }

                newSquare->setPiece(newPiece);
                PieceSet->push_back(newPiece);
            }
        }
        squares.push_back(rows);
    }
}

//for testing purposes (Sets the Piece in the Square to the requests ChessPiece)
void ChessBoard::setSquare(ChessPiece* newPiece, int row, int column){
    squares.at(row).at(column)->setPiece(newPiece);
}

Square* ChessBoard::getSquare(int row, int column) {
    return squares.at(row).at(column);
}
