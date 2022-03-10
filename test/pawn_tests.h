#ifndef PAWN_TESTS_H
#define PAWN_TESTS_H

#include "gtest/gtest.h"

#include "../header/Pawn.h"

TEST(PawnTest, NoPiecesAround){
    ChessBoard Board(true);
    ChessPiece* p1 = new Pawn(true, Board.getSquare(4,4)); // creates white Pawn at 4,4
    Board.setSquare(p1, 4, 4);

    p1->scan(Board);
    std::vector<Square*> moveableSquares = p1->get_moveableSquares();

    std::vector<std::vector<int>> expectedSquares = {{4,5},{4,6}};

    for (int i = 0; i < moveableSquares.size(); ++i) {
        EXPECT_TRUE(find_square(moveableSquares.at(i), expectedSquares));
    }
    
    EXPECT_TRUE(expectedSquares.size() == moveableSquares.size());
}

#endif
