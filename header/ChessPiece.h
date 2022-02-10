#ifndef CHESSPIECE_H
#define CHESSPIECE_H

class ChessPiece {
    private:
        bool color;
    public:
        virtual void Moves() = 0;
        virtual void pieceDeath() = 0;
};

#endif