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

TEST(RookTest, SurroundedOppositeColor) {
    Square mainPlaceAt(4,4);
    ChessPiece* mainRook = new Rook(true, mainPlaceAt);

    Square s_1_placeAt(4,5);
    ChessPiece* s_1 = new Rook(false, s_1_placeAt);

    Square s_2_placeAt(5,4);
    ChessPiece* s_2 = new Rook(false, s_2_placeAt);

    Square s_3_placeAt(4,3);
    ChessPiece* s_3 = new Rook(false, s_3_placeAt);

    Square s_4_placeAt(3,4);
    ChessPiece* s_4 = new Rook(false, s_4_placeAt);

    std::vector<ChessPiece*> Pieces;
    Pieces.push_back(mainRook);
    Pieces.push_back(s_1);
    Pieces.push_back(s_2);
    Pieces.push_back(s_3);
    Pieces.push_back(s_4);

    mainRook->scan(Pieces);

    std::vector<Square> moveableSquares = mainRook->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{4,5}, {5,4}, {4,3}, {3,4}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());
}

TEST(RookTest, SurroundedSameColor) {
    Square mainPlaceAt(4,4);
    ChessPiece* mainRook = new Rook(true, mainPlaceAt);

    Square s_1_placeAt(4,5);
    ChessPiece* s_1 = new Rook(true, s_1_placeAt);

    Square s_2_placeAt(5,4);
    ChessPiece* s_2 = new Rook(true, s_2_placeAt);

    Square s_3_placeAt(4,3);
    ChessPiece* s_3 = new Rook(true, s_3_placeAt);

    Square s_4_placeAt(3,4);
    ChessPiece* s_4 = new Rook(true, s_4_placeAt);

    std::vector<ChessPiece*> Pieces;
    Pieces.push_back(mainRook);
    Pieces.push_back(s_1);
    Pieces.push_back(s_2);
    Pieces.push_back(s_3);
    Pieces.push_back(s_4);

    mainRook->scan(Pieces);

    std::vector<Square> moveableSquares = mainRook->get_moveableSquares(); //get the moveable squares that were just scanned

    EXPECT_TRUE(moveableSquares.size() == 0);
    
}

#endif