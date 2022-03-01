#ifndef KNIGHTSCAN_H
#define KNIGHTSCAN_H

#include "ScanAlg.h"

class KnightScan : public ScanAlg {
    public:
	virtual void Scan(ChessPiece* chessPiece, int i, ChessBoard &Board);
};


#endif
