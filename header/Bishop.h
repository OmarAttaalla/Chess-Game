#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"
#include "DiagonalScan.h"

using namespace std;

class Bishop : public ChessPiece {
    private:
	Square* placeAt;
	vector<Square*> moveableSquares;
	ScanAlg* diagonal;        
	//bool isMoveable(int, int);

    public:
        Bishop(bool newColor, Square* newPlaceAt);
        void moves(Square* sq);
        void scan(ChessBoard &Board);
        void pieceDeath(); 
};


#endif
