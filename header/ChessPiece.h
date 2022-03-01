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
        std::vector<Square*> moveableSquares; //vector of Square moveable locations
        Square* placeAt; //The square where the piece is located
    public:
        virtual void moves() = 0;
        virtual void scan(ChessBoard &Board) = 0; //function that scans available moves for the chess piece
        virtual void pieceDeath() = 0;
        bool get_color(){ return color;}
        void set_color(bool newColor){ color = newColor;} //Set the color of the piece
        Square* get_placeAt(){ return placeAt;}
        void set_placeAt(Square* newPlaceAt) {placeAt = newPlaceAt;} //Set the square where the piece is located
        void add_move(Square* newMove){ moveableSquares.push_back(newMove);} //adds move to moveableSquares vector
	vector<Square*> get_moveableSquares() {return moveableSquares;}
	void clear_moveableSquares() {moveableSquares.clear();
};

#endif
