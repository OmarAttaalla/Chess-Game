#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"
#include "PawnScan.h"

class Pawn : public ChessPiece {
    private:
	Square* placeAt;
	std::vector<Square*> moveableSquares;
	ScanAlg* movement;
	bool initialMove;
    public:
	Pawn(bool newColor, Square* newPlaceAt);
	void moves(Square* sq, ChessBoard &Board);
	virtual void scan(ChessBoard &Board);
	virtual void pieceDeath() {}
};

#endif
