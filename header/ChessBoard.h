#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "Rook.h"
#include "Queen.h"
// #include "Knight.h"
// #include "Bishop.h"
// #include "King.h"

class ChessBoard {
    private:
        std::vector<std::vector<Square*>> squares;
    public:
        //for testing purposes (Creates board with no pieces)
        ChessBoard(bool t){
            for (int i = 0; i < 8; ++i) {
                std::vector<Square*> rows;
                for (int g = 0; g < 8; ++g) {
                    Square* newSquare = new Square(i,g);
                    rows.push_back(newSquare);    
                }
                squares.push_back(rows);
            }
        }
        ChessBoard() {
            for (int i = 0; i < 8; ++i) {
                std::vector<Square*> rows;
                for (int g = 0; g < 8; ++g) {
                    Square* newSquare = new Square(i,g);
                    rows.push_back(newSquare);

                    bool sideColor;
                    if (i == 0 || i == 1) { //Check if we are creating white or black pieces
                        sideColor = true;
                    } else {
                        sideColor = false;
                    }

                    if (i == 1 || i == 6) {
                       // ChessPiece* newPiece = new Pawn; //create pawn
                       //newSquare->setPiece(newPiece);
                    } else if (i == 0 || i == 7) {
                        ChessPiece* newPiece;
                        if (g == 0 || g == 7) { //add rooks
                            newPiece = new Rook(sideColor, newSquare);

                        } else if (g == 1 || g == 6) {
                            //newPiece = new Knight(sideColor, newSquare); //create Knight
                        } else if (g == 2 || g == 5) {
                            //newPiece = new Bishop(sideColor, newSquare); //create Bishop
                        } else if (g == 3) {
                            newPiece = new Queen(sideColor, newSquare); //create queen
                        } else if (g == 4) {
                            //newPiece = new King(sideColor, newSquare); // create King
                        }

                        newSquare->setPiece(newPiece);
                    }
                }
                squares.push_back(rows);
            }
        }

        //for testing purposes (Sets the Piece in the Square to the requests ChessPiece)
        void setSquare(ChessPiece* newPiece, int row, int column){
            squares.at(row).at(column)->setPiece(newPiece);
        }
        
        Square* getSquare(int row, int column) {
            return squares.at(row).at(column);
        }
};

#endif