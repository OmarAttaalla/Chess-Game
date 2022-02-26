#ifndef ROOK_TEST_H
#define ROOK_TEST_H

#include "gtest/gtest.h"

#include "../header/Rook.h"


bool find_square(Square* f, std::vector<std::vector<int>> expectedSquares) {
    for (int i = 0; i < expectedSquares.size(); ++i) {
        if (expectedSquares.at(i)[0] == f->get_row() && expectedSquares.at(i)[1] == f->get_column()) {
            return true;
        }
    }

    return false;
}

TEST(RookTest, NoPiecesAround){
    ChessBoard Board(true); //Creates empty board

	ChessPiece* Rook1 = new Rook(true, Board.getSquare(4,4)); // create rook at 4,4
    Board.setSquare(Rook1, 4, 4); // set the square to the chess piece

    Rook1->scan(Board); //scan available moves

    std::vector<Square*> moveableSquares = Rook1->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{5,4},{6,4},{7,4},{4,5},{4,6},{4,7},{4,3},{4,2},{4,1},{4,0},{3,4},{2,4},{1,4},{0,4}};
    
    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());
}

TEST(RookTest, SurroundedOppositeColor) {
    ChessBoard Board(true);
    
    ChessPiece* mainRook = new Rook(true, Board.getSquare(4,4));
    Board.setSquare(mainRook, 4, 4);

  
    ChessPiece* s_1 = new Rook(false, Board.getSquare(4,5));
    Board.setSquare(s_1, 4, 5);
    ChessPiece* s_2 = new Rook(false, Board.getSquare(5,4));
    Board.setSquare(s_2, 5, 4);
    ChessPiece* s_3 = new Rook(false, Board.getSquare(4,3));
    Board.setSquare(s_3, 4, 3);
    ChessPiece* s_4 = new Rook(false, Board.getSquare(3,4));
    Board.setSquare(s_4, 3, 4);


    mainRook->scan(Board);

    std::vector<Square*> moveableSquares = mainRook->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{4,5}, {5,4}, {4,3}, {3,4}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());
}

TEST(RookTest, SurroundedSameColor) {
    ChessBoard Board(true);
    
    ChessPiece* mainRook = new Rook(true, Board.getSquare(4,4));
    Board.setSquare(mainRook, 4, 4);

  
    ChessPiece* s_1 = new Rook(true, Board.getSquare(4,5));
    Board.setSquare(s_1, 4, 5);
    ChessPiece* s_2 = new Rook(true, Board.getSquare(5,4));
    Board.setSquare(s_2, 5, 4);
    ChessPiece* s_3 = new Rook(true, Board.getSquare(4,3));
    Board.setSquare(s_3, 4, 3);
    ChessPiece* s_4 = new Rook(true, Board.getSquare(3,4));
    Board.setSquare(s_4, 3, 4);

    mainRook->scan(Board);

    std::vector<Square*> moveableSquares = mainRook->get_moveableSquares(); //get the moveable squares that were just scanned

    EXPECT_TRUE(moveableSquares.size() == 0);
    
}

#endif