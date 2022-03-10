#ifndef PAWNSCAN_H
#define PAWNSCAN_H

#include "ScanAlg.h"

class PawnScan : public ScanAlg {
    public:
	    virtual void Scan(ChessPiece* chessPiece, int i, ChessBoard &Board);
};


#endif
