#ifndef QUEEN_TEST_H
#define QUEEN_TEST_H

#include "gtest/gtest.h"

#include "../header/Queen.h"

TEST(QueenTest, NoPiecesAround){
    ChessBoard Board(true); //Creates empty board

	ChessPiece* Queen1 = new Queen(true, Board.getSquare(4,4)); // create rook at 4,4
    Board.setSquare(Queen1, 4, 4); // set the square to the chess piece

    Queen1->scan(Board); //scan available moves

    std::vector<Square*> moveableSquares = Queen1->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{5,4},{6,4},{7,4},{4,5},{4,6},{4,7},{4,3},{4,2},{4,1},{4,0},{3,4},{2,4},{1,4},{0,4},{5,3},{6,2},{7,1},{5,5},{6,6},{7,7},{3,5},{2,6},{1,7},{3,3},{2,2},{1,1},{0,0}};
    
    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());
}

TEST(QueenTest, SurroundedOppositeColor) {
    ChessBoard Board(true);
    
    ChessPiece* mainQueen = new Queen(true, Board.getSquare(4,4));
    Board.setSquare(mainQueen, 4, 4);

  
    ChessPiece* s_1 = new Queen(false, Board.getSquare(4,5));
    Board.setSquare(s_1, 4, 5);
    ChessPiece* s_2 = new Queen(false, Board.getSquare(5,4));
    Board.setSquare(s_2, 5, 4);
    ChessPiece* s_3 = new Queen(false, Board.getSquare(4,3));
    Board.setSquare(s_3, 4, 3);
    ChessPiece* s_4 = new Queen(false, Board.getSquare(3,4));
    Board.setSquare(s_4, 3, 4); 
    ChessPiece* s_5 = new Queen(false, Board.getSquare(5,3));
    Board.setSquare(s_5, 5, 3);
    ChessPiece* s_6 = new Queen(false, Board.getSquare(5,5));
    Board.setSquare(s_6, 5, 5);
    ChessPiece* s_7 = new Queen(false, Board.getSquare(3,5));
    Board.setSquare(s_7, 3, 5);
    ChessPiece* s_8 = new Queen(false, Board.getSquare(3,3));
    Board.setSquare(s_8, 3, 3);


    mainQueen->scan(Board);

    std::vector<Square*> moveableSquares = mainQueen->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{4,5}, {5,4}, {4,3}, {3,4}, {5,3}, {5,5}, {3,5}, {3,3}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());
}

TEST(QueenTest, SurroundedSameColor) {
    ChessBoard Board(true);
    
    ChessPiece* mainQueen = new Queen(false, Board.getSquare(4,4));
    Board.setSquare(mainQueen, 4, 4);

  
    ChessPiece* s_1 = new Queen(false, Board.getSquare(4,5));
    Board.setSquare(s_1, 4, 5);
    ChessPiece* s_2 = new Queen(false, Board.getSquare(5,4));
    Board.setSquare(s_2, 5, 4);
    ChessPiece* s_3 = new Queen(false, Board.getSquare(4,3));
    Board.setSquare(s_3, 4, 3);
    ChessPiece* s_4 = new Queen(false, Board.getSquare(3,4));
    Board.setSquare(s_4, 3, 4); 
    ChessPiece* s_5 = new Queen(false, Board.getSquare(5,3));
    Board.setSquare(s_5, 5, 3);
    ChessPiece* s_6 = new Queen(false, Board.getSquare(5,5));
    Board.setSquare(s_6, 5, 5);
    ChessPiece* s_7 = new Queen(false, Board.getSquare(3,5));
    Board.setSquare(s_7, 3, 5);
    ChessPiece* s_8 = new Queen(false, Board.getSquare(3,3));
    Board.setSquare(s_8, 3, 3);

    mainQueen->scan(Board);

    std::vector<Square*> moveableSquares = mainQueen->get_moveableSquares(); //get the moveable squares that were just scanned

    EXPECT_TRUE(moveableSquares.size() == 0);
    
}

#endif