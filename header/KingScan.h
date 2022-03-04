#ifndef KINGSCAN_H
#define KINGSCAN_H

#include "ScanAlg.h"

class KingScan : public ScanAlg {
    public:
	    virtual void Scan(ChessPiece* chessPiece, int i, ChessBoard &Board);
};


#endif