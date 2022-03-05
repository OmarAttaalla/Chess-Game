#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard; //forward declare ChessBoard

#include "Square.h"
#include "ChessPiece.h"
#include <vector>


class ChessBoard {
   private:
       std::vector<std::vector<Square*>> squares;
   public:
       //for testing purposes (Creates board with no pieces)
       ChessBoard(bool t);
       ChessBoard();

       //for testing purposes (Sets the Piece in the Square to the requests ChessPiece)
       void setSquare(ChessPiece* newPiece, int row, int column);
      
       Square* getSquare(int row, int column);
};



#endif
