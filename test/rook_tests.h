#ifndef ROOK_TEST_H
#define ROOK_TEST_H

#include "gtest/gtest.h"

#include "../header/Rook.h"


bool find_square(Square f, std::vector<std::vector<int>> expectedSquares) {
    for (int i = 0; i < expectedSquares.size(); ++i) {
        if (expectedSquares.at(i)[0] == f.get_row() && expectedSquares.at(i)[1] == f.get_column()) {
            return true;
        }
    }

    return false;
}

TEST(RookTest, NoPiecesAround){
    Square newPlaceAt(4,4);
	ChessPiece* Rook1 = new Rook(true, newPlaceAt);

    std::vector<ChessPiece*> Pieces;
    Pieces.push_back(Rook1);

    Rook1->scan(Pieces); //scan available moves

    std::vector<Square> moveableSquares = Rook1->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{5,4},{6,4},{7,4},{4,5},{4,6},{4,7},{4,3},{4,2},{4,1},{4,0},{3,4},{2,4},{1,4},{0,4}};
    
    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());
}

#endif