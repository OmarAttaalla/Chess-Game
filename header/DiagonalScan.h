#ifndef DIAGONALSCAN_H
#define DIAGONALSCAN_H

#include "ScanAlg.h"

class DiagonalScan : public ScanAlg {
    public:
        //function that increments diagonal paths (up-left, up-right, down-left, down-right)
	virtual void Scan(ChessPiece* chessPiece, int i, ChessBoard &Board);
};


#endif
