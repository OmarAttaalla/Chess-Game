#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
#include "KnightScan.h"


using namespace std;

class Knight : public ChessPiece {
    private:
	Square* placeAt;
	vector<Square*> moveableSquares;
        ScanAlg* movement;
    public:
        Knight(bool newColor, Square* newPlaceAt);
        void moves(Square* sq);
        void scan(Chessboard &Board);
        void pieceDeath(); 
};


#endif
