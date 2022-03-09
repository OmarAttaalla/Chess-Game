#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard; //forward declare ChessBoard

#include "Square.h"
#include "ChessPiece.h"
#include <vector>


class ChessBoard {
   private:
       std::vector<std::vector<Square*>> squares;
       std::vector<ChessPiece*> whitePieces;
       std::vector<ChessPiece*> blackPieces;
       King* whiteKing;
       King* blackKing;
   public:
       //for testing purposes (Creates board with no pieces)
       ChessBoard(bool t);
       ChessBoard();
       ~ChessBoard();
       std::vector<ChessPiece*> get_pieces(bool color);

       //for testing purposes (Sets the Piece in the Square to the requests ChessPiece)
       void setSquare(ChessPiece* newPiece, int row, int column);
       void addPiece(ChessPiece* newPiece);
       void removePiece(ChessPiece* newPiece);
       Square* getSquare(int row, int column);
};



#endif
