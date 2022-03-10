#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"
#include "DiagonalScan.h"

using namespace std;

class Bishop : public ChessPiece {
    private:
        ScanAlg* diagonal;        

    public:
        Bishop(bool newColor, Square* newPlaceAt);
        virtual ~Bishop();
        virtual void scan(ChessBoard &Board);
        virtual void pieceDeath() {}
};


#endif
