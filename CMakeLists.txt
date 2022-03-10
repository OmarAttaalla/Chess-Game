CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
	unit_tests.cpp
	src/ChessPiece.cpp
	src/ChessBoard.cpp
	src/Rook.cpp
	src/Queen.cpp
	src/Knight.cpp
	src/Bishop.cpp
	src/King.cpp
	src/Pawn.cpp
	src/StraightScan.cpp
	src/DiagonalScan.cpp
	src/KnightScan.cpp
	src/KingScan.cpp
	src/PawnScan.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
