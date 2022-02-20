#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
#include "ChessBoard.h"

using namespace std;

class Knight : public ChessPiece {
    private:
        bool color;
	Square placeAt;
	vector<Square> moveableSquares;
    public:
        Knight(bool newColor, Square newPlaceAt);
        void moves();
        void scan();
        void pieceDeath(); 
};


#endif
