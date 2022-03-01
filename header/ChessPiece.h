#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Square.h"
#include <vector>
#include <iostream>
#include "ChessBoard.h"

using namespace std;

class ChessPiece {
    private:
        bool color;
        vector<Square*> moveableSquares; //vector of Square moveable locations
        Square* placeAt; //The square where the piece is located
    public:
        virtual void moves() = 0;
        virtual void scan(ChessBoard &Board) = 0;
        virtual void pieceDeath() = 0;
        bool get_color(){ return color;}
        void set_color(bool newColor){ color = newColor;}
        Square* get_placeAt(){ return placeAt;}
        void set_placeAt(Square* newPlaceAt) {placeAt = newPlaceAt;} 
        void add_move(Square* newMove){ moveableSquares.push_back(newMove);}
	vector<Square*> get_moveableSquares() {return moveableSquares;}
	void clear_moveableSquares() {moveableSquares.clear();}
};

#endif
