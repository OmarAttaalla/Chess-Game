#ifndef PAWN_TESTS_H
#define PAWN_TESTS_H

#include "gtest/gtest.h"
#include <iostream>
#include "../header/Pawn.h"

TEST(PawnTest, NoPiecesAround){
    ChessBoard Board(true);
    ChessPiece* p1 = new Pawn(true, Board.getSquare(4,4)); // creates white Pawn at 4,4
    Board.setSquare(p1, 4, 4);

    p1->scan(Board);
    std::vector<Square*> moveableSquares = p1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{5,4},{6,4}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());
}

TEST(PawnTest, UpperLeftEnemyPiece){
    ChessBoard Board(true);
    ChessPiece* p1 = new Pawn(true, Board.getSquare(4,4)); // creates white Pawn at 4,4
    Board.setSquare(p1, 4, 4);

    ChessPiece* p2 = new Pawn(false, Board.getSquare(5,3)); // creates black Pawn at 3,5
    Board.setSquare(p2, 5, 3);

    p1->scan(Board);
    std::vector<Square*> moveableSquares = p1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{5,4},{6,4},{5,3}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }

    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());
}

TEST(PawnTest, UpperRightEnemyPiece){
    ChessBoard Board(true);
    ChessPiece* p1 = new Pawn(true, Board.getSquare(4,4)); // creates white Pawn at 4,4
    Board.setSquare(p1, 4, 4);

    ChessPiece* p2 = new Pawn(false, Board.getSquare(5,3)); // creates black Pawn at 3,5
    Board.setSquare(p2, 5, 5);

    p1->scan(Board);
    std::vector<Square*> moveableSquares = p1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{5,4},{6,4},{5,5}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }

    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());
}

TEST(PawnTest, FullMoveOption){
    ChessBoard Board(true);
    ChessPiece* p1 = new Pawn(true, Board.getSquare(4,4)); // creates white Pawn at 4,4
    Board.setSquare(p1, 4, 4);

    ChessPiece* p2 = new Pawn(false, Board.getSquare(5,3)); // creates black Pawn at 3,5
    Board.setSquare(p2, 5, 3);

    ChessPiece* p3 = new Pawn(false, Board.getSquare(5,3)); // creates black Pawn at 3,5
    Board.setSquare(p3, 5, 5);

    p1->scan(Board);
    std::vector<Square*> moveableSquares = p1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{5,4},{6,4},{5,3},{5,5}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }

    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());
}

TEST(PawnTest, MovedOnceAlready){
    ChessBoard Board(true);
    ChessPiece* p1 = new Pawn(true, Board.getSquare(4,4)); // creates white Pawn at 4,4
    Board.setSquare(p1, 4, 4);
    p1->scan(Board);
    p1->moves(Board.getSquare(5,4), Board);
    //p1->clear_moveableSquares();

    p1->scan(Board);
    std::vector<Square*> moveableSquares = p1->get_moveableSquares();
    std::vector<std::vector<int>> expectedSquares = {{6,4}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
	//cout << moveableSquares.at(i)->get_row() << " " << moveableSquares.at(i)->get_column() << endl;
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }

    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());
}

/*
TEST(PawnTest, MovedOnceAlready){
    ChessBoard Board(true);
    ChessPiece* p1 = new Pawn(true, Board.getSquare(4,4)); // creates white Pawn at 4,4
    Board.setSquare(p1, 4, 4);
    p1->scan(Board);

    p1->moves(Board.getSquare(5,4), Board);

    ChessPiece* p2 = new Pawn(false, Board.getSquare(6,3)); // creates black Pawn at 3,5
    Board.setSquare(p2, 6, 3);

    p1->scan(Board);
    std::vector<Square*> moveableSquares = p1->get_moveableSquares();
    std::vector<std::vector<int>> expectedSquares = {{6,4},{6,3}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }

    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());
} */

#endif
