#ifndef KING_TEST_H
#define KING_TEST_H

#include "gtest/gtest.h"

#include "../header/King.h"
#include "../header/Bishop.h"

TEST(KingTest, ScanNoPiecesAround){
    ChessBoard Board(true); //Creates empty board

	ChessPiece* King1 = new King(true, Board.getSquare(4,4)); // create King at 4,4
    Board.setSquare(King1, 4, 4); // set the square to the chess piece

    King1->scan(Board); //scan available moves

    std::vector<Square*> moveableSquares = King1->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{5,4},{3,4},{5,5},{3,3},{4,3},{5,3},{3,5},{4,5}};
    
    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());

    delete King1;
}

TEST(KingTest, ScanSurroundedOppositeColor) {
    ChessBoard Board(true);
    
    ChessPiece* mainKing = new King(true, Board.getSquare(4,4));
    Board.setSquare(mainKing, 4, 4);

  
    ChessPiece* s_1 = new King(false, Board.getSquare(4,5));
    Board.setSquare(s_1, 4, 5);
    ChessPiece* s_2 = new King(false, Board.getSquare(5,4));
    Board.setSquare(s_2, 5, 4);
    ChessPiece* s_3 = new King(false, Board.getSquare(4,3));
    Board.setSquare(s_3, 4, 3);
    ChessPiece* s_4 = new King(false, Board.getSquare(3,4));
    Board.setSquare(s_4, 3, 4); 
    ChessPiece* s_5 = new King(false, Board.getSquare(5,3));
    Board.setSquare(s_5, 5, 3);
    ChessPiece* s_6 = new King(false, Board.getSquare(5,5));
    Board.setSquare(s_6, 5, 5);
    ChessPiece* s_7 = new King(false, Board.getSquare(3,5));
    Board.setSquare(s_7, 3, 5);
    ChessPiece* s_8 = new King(false, Board.getSquare(3,3));
    Board.setSquare(s_8, 3, 3);


    mainKing->scan(Board);

    std::vector<Square*> moveableSquares = mainKing->get_moveableSquares(); //get the moveable squares that were just scanned

    std::vector<std::vector<int>> expectedSquares = {{4,5}, {5,4}, {4,3}, {3,4}, {5,3}, {5,5}, {3,5}, {3,3}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());

    delete mainKing;
    delete s_1;
    delete s_2;
    delete s_3;
    delete s_4;
    delete s_5;
    delete s_6;
    delete s_7;
    delete s_8;
}

TEST(KingTest, ScanSurroundedSameColor) {
    ChessBoard Board(true);
    
    ChessPiece* mainKing = new King(false, Board.getSquare(4,4));
    Board.setSquare(mainKing, 4, 4);
  
    ChessPiece* s_1 = new King(false, Board.getSquare(4,5));
    Board.setSquare(s_1, 4, 5);
    ChessPiece* s_2 = new King(false, Board.getSquare(5,4));
    Board.setSquare(s_2, 5, 4);
    ChessPiece* s_3 = new King(false, Board.getSquare(4,3));
    Board.setSquare(s_3, 4, 3);
    ChessPiece* s_4 = new King(false, Board.getSquare(3,4));
    Board.setSquare(s_4, 3, 4); 
    ChessPiece* s_5 = new King(false, Board.getSquare(5,3));
    Board.setSquare(s_5, 5, 3);
    ChessPiece* s_6 = new King(false, Board.getSquare(5,5));
    Board.setSquare(s_6, 5, 5);
    ChessPiece* s_7 = new King(false, Board.getSquare(3,5));
    Board.setSquare(s_7, 3, 5);
    ChessPiece* s_8 = new King(false, Board.getSquare(3,3));
    Board.setSquare(s_8, 3, 3);

    mainKing->scan(Board);

    std::vector<Square*> moveableSquares = mainKing->get_moveableSquares(); //get the moveable squares that were just scanned

    EXPECT_TRUE(moveableSquares.size() == 0);

    delete mainKing;
    delete s_1;
    delete s_2;
    delete s_3;
    delete s_4;
    delete s_5;
    delete s_6;
    delete s_7;
    delete s_8;
    
}

TEST (KingTest, checkScanInCheck) {
    ChessBoard Board(true);
    
    King* mainKing = new King(false, Board.getSquare(4,4));
    Board.setSquare(mainKing, 4, 4);


    ChessPiece* newBishop = new Bishop(true, Board.getSquare(6,6));
    Board.setSquare(newBishop, 6, 6);

    EXPECT_TRUE(mainKing->checkScan(Board));

    delete mainKing;
    delete newBishop;
}

TEST (KingTest, checkScanInCheckBySameColor) {
    ChessBoard Board(true);
    
    King* mainKing = new King(false, Board.getSquare(4,4));
    Board.setSquare(mainKing, 4, 4);


    ChessPiece* newBishop = new Bishop(false, Board.getSquare(6,6));
    Board.setSquare(newBishop, 6, 6);

    EXPECT_FALSE(mainKing->checkScan(Board));

    delete mainKing;
    delete newBishop;
}

TEST (KingTest, checkScanNotInCheck) {
    ChessBoard Board(true);
    
    King* mainKing = new King(false, Board.getSquare(4,4));
    Board.setSquare(mainKing, 4, 4);

    ChessPiece* newBishop = new Bishop(false, Board.getSquare(5,5)); //Bishop blocks other bishop
    Board.setSquare(newBishop, 5, 5);

    ChessPiece* newBishop1 = new Bishop(true, Board.getSquare(6,6));
    Board.setSquare(newBishop1, 6, 6);

    EXPECT_FALSE(mainKing->checkScan(Board));

    delete mainKing;
    delete newBishop;
    delete newBishop1;
}

TEST(KingTest, checkmateSurroundedInCheckMate) {
    ChessBoard Board(true);
    
    King* mainKing = new King(false, Board.getSquare(0,7));
    Board.setSquare(mainKing, 0, 7);
    Board.addPiece(mainKing);

    ChessPiece* enemyBishop = new Bishop(true, Board.getSquare(3,4));
    Board.setSquare(enemyBishop, 3, 4);
    Board.addPiece(enemyBishop);

    ChessPiece* newBishop1 = new Bishop(false, Board.getSquare(0,6));
    Board.setSquare(newBishop1, 0, 6);
    Board.addPiece(newBishop1);

    ChessPiece* newBishop2 = new Bishop(false, Board.getSquare(1,7));
    Board.setSquare(newBishop2, 1, 7);
    Board.addPiece(newBishop2);

    EXPECT_TRUE(mainKing->checkmate(Board));

    // delete mainKing;
    // delete enemyBishop;
    // delete newBishop1;
    // delete newBishop2;
}

TEST(KingTest, checkmateOnlyInCheck) {
    ChessBoard Board(true);
    
    King* mainKing = new King(false, Board.getSquare(0,7));
    Board.setSquare(mainKing, 0, 7);
    Board.addPiece(mainKing);

    ChessPiece* enemyBishop = new Bishop(true, Board.getSquare(3,4));
    Board.setSquare(enemyBishop, 3, 4);
    Board.addPiece(enemyBishop);

    ChessPiece* newBishop1 = new Bishop(false, Board.getSquare(0,6));
    Board.setSquare(newBishop1, 0, 6);
    Board.addPiece(newBishop1);

    ChessPiece* newBishop2 = new Rook(false, Board.getSquare(1,7));
    Board.setSquare(newBishop2, 1, 7);
    Board.addPiece(newBishop2);

    EXPECT_FALSE(mainKing->checkmate(Board));

    // delete mainKing;
    // delete enemyBishop;
    // delete newBishop1;
    // delete newBishop2;
}

#endif