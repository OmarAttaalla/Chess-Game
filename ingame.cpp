#include "ingame.h"
#include "ui_ingame.h"
#include <QPixmap>

InGame::InGame(QWidget *parent): QMainWindow(parent), ui(new Ui::InGame)
{
    ui->setupUi(this);

    board();
    black_pieces();
    white_pieces();
}

InGame::~InGame()
{
    delete ui;
}

void InGame::board()
{
    QPixmap edge(":/images/Images/square gray dark _1x.png");
    ui->boardEdge->setPixmap(edge);

    QPixmap cboard(":/images/Images/ChessBoard.png");
    ui->chessBoard->setPixmap(cboard);
}
void InGame::black_pieces()
{
    QPixmap pawn(":/images/Images/b_pawn_1x.png");
    ui->bPawn1->setPixmap(pawn);
    ui->bPawn2->setPixmap(pawn);
    ui->bPawn3->setPixmap(pawn);
    ui->bPawn4->setPixmap(pawn);
    ui->bPawn5->setPixmap(pawn);
    ui->bPawn6->setPixmap(pawn);
    ui->bPawn7->setPixmap(pawn);
    ui->bPawn8->setPixmap(pawn);

    QPixmap rook(":/images/Images/b_rook_1x.png");
    ui->bRook1->setPixmap(rook);
    ui->bRook2->setPixmap(rook);

    QPixmap knight(":/images/Images/b_knight_1x.png");
    ui->bKnight1->setPixmap(knight);
    ui->bKnight2->setPixmap(knight);

    QPixmap bishop(":/images/Images/b_bishop_1x.png");
    ui->bBishop1->setPixmap(bishop);
    ui->bBishop2->setPixmap(bishop);

    QPixmap queen(":/images/Images/b_queen_1x.png");
    ui->bQueen->setPixmap(queen);

    QPixmap king(":/images/Images/b_king_1x.png");
    ui->bKing->setPixmap(king);
}
void InGame::white_pieces()
{
    QPixmap pawn(":/images/Images/w_pawn_1x.png");
    ui->wPawn1->setPixmap(pawn);
    ui->wPawn2->setPixmap(pawn);
    ui->wPawn3->setPixmap(pawn);
    ui->wPawn4->setPixmap(pawn);
    ui->wPawn5->setPixmap(pawn);
    ui->wPawn6->setPixmap(pawn);
    ui->wPawn7->setPixmap(pawn);
    ui->wPawn8->setPixmap(pawn);

    QPixmap rook(":/images/Images/w_rook_1x.png");
    ui->wRook1->setPixmap(rook);
    ui->wRook2->setPixmap(rook);

    QPixmap knight(":/images/Images/w_knight_1x.png");
    ui->wKnight1->setPixmap(knight);
    ui->wKnight2->setPixmap(knight);

    QPixmap bishop(":/images/Images/w_bishop_1x.png");
    ui->wBishop1->setPixmap(bishop);
    ui->wBishop2->setPixmap(bishop);

    QPixmap queen(":/images/Images/w_queen_1x.png");
    ui->wQueen->setPixmap(queen);

    QPixmap king(":/images/Images/w_king_1x.png");
    ui->wKing->setPixmap(king);
}
