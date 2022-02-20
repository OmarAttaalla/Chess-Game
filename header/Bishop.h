#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"
#include "ChessBoard.h"

using namespace std;

class Bishop : public ChessPiece {
    private:
        bool color;
	Square placeAt;
	vector<Square> moveableSquares;
        
	bool isMoveable(int, int);
    public:
        Bishop(bool newColor, Square newPlaceAt);
        void moves(Square);
        void scan();
        void pieceDeath(); 
};


#endif
