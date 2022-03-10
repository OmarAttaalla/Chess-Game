#ifndef KNIGHT_TEST_H
#define KNIGHT_TEST_H

#include "gtest/gtest.h"
#include "../header/Knight.h"

TEST(KnightTest, NoPiecesAround){
    ChessBoard Board(true);
    ChessPiece* k1 = new Knight(true, Board.getSquare(4,4));
    Board.setSquare(k1, 4, 4);

    k1->scan(Board);
    std::vector<Square*> moveableSquares = k1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{6,5},{5,6},{3,6},{2,5},{2,3},{3,2},{5,2},{6,3}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());

    delete k1;
}

TEST(KnightTest, EnemyPieceInRange){
    ChessBoard Board(true);
    ChessPiece* k1 = new Knight(true, Board.getSquare(4,4));
    Board.setSquare(k1, 4, 4);

    ChessPiece* k2 = new Knight(false, Board.getSquare(5,6));
    Board.setSquare(k2, 5, 6);

    k1->scan(Board);
    std::vector<Square*> moveableSquares = k1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{6,5},{5,6},{3,6},{2,5},{2,3},{3,2},{5,2},{6,3}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }

    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());

    delete k1;
    delete k2;
}

TEST(KnightTest, HopOverPiece){
    ChessBoard Board(true);
    ChessPiece* k1 = new Knight(true, Board.getSquare(4,4));
    Board.setSquare(k1, 4, 4);

    ChessPiece* k2 = new Knight(false, Board.getSquare(4,5));
    Board.setSquare(k2, 4, 5);

    ChessPiece* k3 = new Knight(true, Board.getSquare(5,4));
    Board.setSquare(k3, 5, 4);

    ChessPiece* k4 = new Knight(false, Board.getSquare(4,3));
    Board.setSquare(k4, 4, 3);

    ChessPiece* k5 = new Knight(true, Board.getSquare(3,4));
    Board.setSquare(k5, 3, 4);

    ChessPiece* k6 = new Knight(false, Board.getSquare(3,5));
    Board.setSquare(k6, 3, 5);

    ChessPiece* k7 = new Knight(false, Board.getSquare(3,3));
    Board.setSquare(k7, 3, 3);

    ChessPiece* k8 = new Knight(false, Board.getSquare(5,3));
    Board.setSquare(k8, 5, 3);

    ChessPiece* k9 = new Knight(true, Board.getSquare(5,5));
    Board.setSquare(k9, 5, 5);

    k1->scan(Board);
    std::vector<Square*> moveableSquares = k1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{6,5},{5,6},{3,6},{2,5},{2,3},{3,2},{5,2},{6,3}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }

    EXPECT_EQ(expectedSquares.size(), moveableSquares.size());

    delete k1;
    delete k2;
    delete k3;
    delete k4;
    delete k5;
    delete k6;
    delete k7;
    delete k8;
    delete k9;
}

#endif
