#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"
#include "PawnScan.h"

class Pawn : public ChessPiece {
    private:
	ScanAlg* movement;
	bool initialMove;
    public:
    Pawn(bool newColor, Square* newPlaceAt);
	virtual void scan(ChessBoard &Board);
	virtual void pieceDeath() {}
};

#endif
