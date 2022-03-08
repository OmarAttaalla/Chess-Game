#include "ingame.h"
#include "ui_ingame.h"
#include <QPixmap>

InGame::InGame(QWidget *parent): QMainWindow(parent), ui(new Ui::InGame)
{
    ui->setupUi(this);

    board();
    black_pieces();
    white_pieces();

    buttonEvents();
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

void InGame::buttonEvents()
{
    connect(ui->a1, SIGNAL(clicked()), this, SLOT(on_a1_clicked()));
    connect(ui->a2, SIGNAL(clicked()), this, SLOT(on_a2_clicked()));
    connect(ui->a3, SIGNAL(clicked()), this, SLOT(on_a3_clicked()));
    connect(ui->a4, SIGNAL(clicked()), this, SLOT(on_a4_clicked()));
    connect(ui->a5, SIGNAL(clicked()), this, SLOT(on_a5_clicked()));
    connect(ui->a6, SIGNAL(clicked()), this, SLOT(on_a6_clicked()));
    connect(ui->a7, SIGNAL(clicked()), this, SLOT(on_a7_clicked()));
    connect(ui->a8, SIGNAL(clicked()), this, SLOT(on_a8_clicked()));

    connect(ui->b1, SIGNAL(clicked()), this, SLOT(on_b1_clicked()));
    connect(ui->b2, SIGNAL(clicked()), this, SLOT(on_b2_clicked()));
    connect(ui->b3, SIGNAL(clicked()), this, SLOT(on_b3_clicked()));
    connect(ui->b4, SIGNAL(clicked()), this, SLOT(on_b4_clicked()));
    connect(ui->b5, SIGNAL(clicked()), this, SLOT(on_b5_clicked()));
    connect(ui->b6, SIGNAL(clicked()), this, SLOT(on_b6_clicked()));
    connect(ui->b7, SIGNAL(clicked()), this, SLOT(on_b7_clicked()));
    connect(ui->b8, SIGNAL(clicked()), this, SLOT(on_b8_clicked()));

    connect(ui->c1, SIGNAL(clicked()), this, SLOT(on_c1_clicked()));
    connect(ui->c2, SIGNAL(clicked()), this, SLOT(on_c2_clicked()));
    connect(ui->c3, SIGNAL(clicked()), this, SLOT(on_c3_clicked()));
    connect(ui->c4, SIGNAL(clicked()), this, SLOT(on_c4_clicked()));
    connect(ui->c5, SIGNAL(clicked()), this, SLOT(on_c5_clicked()));
    connect(ui->c6, SIGNAL(clicked()), this, SLOT(on_c6_clicked()));
    connect(ui->c7, SIGNAL(clicked()), this, SLOT(on_c7_clicked()));
    connect(ui->c8, SIGNAL(clicked()), this, SLOT(on_c8_clicked()));

    connect(ui->d1, SIGNAL(clicked()), this, SLOT(on_d1_clicked()));
    connect(ui->d2, SIGNAL(clicked()), this, SLOT(on_d2_clicked()));
    connect(ui->d3, SIGNAL(clicked()), this, SLOT(on_d3_clicked()));
    connect(ui->d4, SIGNAL(clicked()), this, SLOT(on_d4_clicked()));
    connect(ui->d5, SIGNAL(clicked()), this, SLOT(on_d5_clicked()));
    connect(ui->d6, SIGNAL(clicked()), this, SLOT(on_d6_clicked()));
    connect(ui->d7, SIGNAL(clicked()), this, SLOT(on_d7_clicked()));
    connect(ui->d8, SIGNAL(clicked()), this, SLOT(on_d8_clicked()));

    connect(ui->e1, SIGNAL(clicked()), this, SLOT(on_e1_clicked()));
    connect(ui->e2, SIGNAL(clicked()), this, SLOT(on_e2_clicked()));
    connect(ui->e3, SIGNAL(clicked()), this, SLOT(on_e3_clicked()));
    connect(ui->e4, SIGNAL(clicked()), this, SLOT(on_e4_clicked()));
    connect(ui->e5, SIGNAL(clicked()), this, SLOT(on_e5_clicked()));
    connect(ui->e6, SIGNAL(clicked()), this, SLOT(on_e6_clicked()));
    connect(ui->e7, SIGNAL(clicked()), this, SLOT(on_e7_clicked()));
    connect(ui->e8, SIGNAL(clicked()), this, SLOT(on_e8_clicked()));

    connect(ui->f1, SIGNAL(clicked()), this, SLOT(on_f1_clicked()));
    connect(ui->f2, SIGNAL(clicked()), this, SLOT(on_f2_clicked()));
    connect(ui->f3, SIGNAL(clicked()), this, SLOT(on_f3_clicked()));
    connect(ui->f4, SIGNAL(clicked()), this, SLOT(on_f4_clicked()));
    connect(ui->f5, SIGNAL(clicked()), this, SLOT(on_f5_clicked()));
    connect(ui->f6, SIGNAL(clicked()), this, SLOT(on_f6_clicked()));
    connect(ui->f7, SIGNAL(clicked()), this, SLOT(on_f7_clicked()));
    connect(ui->f8, SIGNAL(clicked()), this, SLOT(on_f8_clicked()));

    connect(ui->g1, SIGNAL(clicked()), this, SLOT(on_g1_clicked()));
    connect(ui->g2, SIGNAL(clicked()), this, SLOT(on_g2_clicked()));
    connect(ui->g3, SIGNAL(clicked()), this, SLOT(on_g3_clicked()));
    connect(ui->g4, SIGNAL(clicked()), this, SLOT(on_g4_clicked()));
    connect(ui->g5, SIGNAL(clicked()), this, SLOT(on_g5_clicked()));
    connect(ui->g6, SIGNAL(clicked()), this, SLOT(on_g6_clicked()));
    connect(ui->g7, SIGNAL(clicked()), this, SLOT(on_g7_clicked()));
    connect(ui->g8, SIGNAL(clicked()), this, SLOT(on_g8_clicked()));

    connect(ui->h1, SIGNAL(clicked()), this, SLOT(on_h1_clicked()));
    connect(ui->h2, SIGNAL(clicked()), this, SLOT(on_h2_clicked()));
    connect(ui->h3, SIGNAL(clicked()), this, SLOT(on_h3_clicked()));
    connect(ui->h4, SIGNAL(clicked()), this, SLOT(on_h4_clicked()));
    connect(ui->h5, SIGNAL(clicked()), this, SLOT(on_h5_clicked()));
    connect(ui->h6, SIGNAL(clicked()), this, SLOT(on_h6_clicked()));
    connect(ui->h7, SIGNAL(clicked()), this, SLOT(on_h7_clicked()));
    connect(ui->h8, SIGNAL(clicked()), this, SLOT(on_h8_clicked()));
}

QLabel *InGame::pieceTypeSearch(const QPushButton *coordinate)
{
    QLabel *piece = pawnSearch(coordinate);
    if(piece != 0)
    {
        return piece;
    }

    piece = rookSearch(coordinate);
    if(piece != 0)
    {
        return piece;
    }

    piece = knightSearch(coordinate);
    if(piece != 0)
    {
        return piece;
    }

    piece = bishopSearch(coordinate);
    if(piece != 0)
    {
        return piece;
    }

    piece = queenSearch(coordinate);
    if(piece != 0)
    {
        return piece;
    }

    piece = kingSearch(coordinate);
    if(piece != 0)
    {
        return piece;
    }

    return 0;
}

QLabel *InGame::pawnSearch(const QPushButton *coordinate)
{
    if(ui->bPawn1->x() == (coordinate->x() + 7) && ui->bPawn1->y() == (coordinate->y() + 5))
    {
        return ui->bPawn1;
    }

    if(ui->bPawn2->x() == (coordinate->x() + 7) && ui->bPawn2->y() == (coordinate->y() + 5))
    {
        return ui->bPawn2;
    }

    if(ui->bPawn3->x() == (coordinate->x() + 7) && ui->bPawn3->y() == (coordinate->y() + 5))
    {
        return ui->bPawn3;
    }

    if(ui->bPawn4->x() == (coordinate->x() + 7) && ui->bPawn4->y() == (coordinate->y() + 5))
    {
        return ui->bPawn4;
    }

    if(ui->bPawn5->x() == (coordinate->x() + 7) && ui->bPawn5->y() == (coordinate->y() + 5))
    {
        return ui->bPawn5;
    }

    if(ui->bPawn6->x() == (coordinate->x() + 7) && ui->bPawn6->y() == (coordinate->y() + 5))
    {
        return ui->bPawn6;
    }

    if(ui->bPawn7->x() == (coordinate->x() + 7) && ui->bPawn7->y() == (coordinate->y() + 5))
    {
        return ui->bPawn7;
    }

    if(ui->bPawn8->x() == (coordinate->x() + 7) && ui->bPawn8->y() == (coordinate->y() + 5))
    {
        return ui->bPawn8;
    }

    if(ui->wPawn1->x() == (coordinate->x() + 7) && ui->wPawn1->y() == (coordinate->y() + 5))
    {
        return ui->wPawn1;
    }

    if(ui->wPawn2->x() == (coordinate->x() + 7) && ui->wPawn2->y() == (coordinate->y() + 5))
    {
        return ui->wPawn2;
    }

    if(ui->wPawn3->x() == (coordinate->x() + 7) && ui->wPawn3->y() == (coordinate->y() + 5))
    {
        return ui->wPawn3;
    }

    if(ui->wPawn4->x() == (coordinate->x() + 7) && ui->wPawn4->y() == (coordinate->y() + 5))
    {
        return ui->wPawn4;
    }

    if(ui->wPawn5->x() == (coordinate->x() + 7) && ui->wPawn5->y() == (coordinate->y() + 5))
    {
        return ui->wPawn5;
    }

    if(ui->wPawn6->x() == (coordinate->x() + 7) && ui->wPawn6->y() == (coordinate->y() + 5))
    {
        return ui->wPawn6;
    }

    if(ui->wPawn7->x() == (coordinate->x() + 7) && ui->wPawn7->y() == (coordinate->y() + 5))
    {
        return ui->wPawn7;
    }

    if(ui->wPawn8->x() == (coordinate->x() + 7) && ui->wPawn8->y() == (coordinate->y() + 5))
    {
        return ui->wPawn8;
    }

    return 0;
}

QLabel *InGame::rookSearch(const QPushButton *coordinate)
{
    if(ui->bRook1->x() == (coordinate->x() + 5) && ui->bRook1->y() == (coordinate->y() + 5))
    {
        return ui->bRook1;
    }

    if(ui->bRook2->x() == (coordinate->x() + 5) && ui->bRook2->y() == (coordinate->y() + 5))
    {
        return ui->bRook2;
    }

    if(ui->wRook1->x() == (coordinate->x() + 5) && ui->wRook1->y() == (coordinate->y() + 5))
    {
        return ui->wRook1;
    }

    if(ui->wRook2->x() == (coordinate->x() + 5) && ui->wRook2->y() == (coordinate->y() + 5))
    {
        return ui->wRook2;
    }

    return 0;
}

QLabel *InGame::knightSearch(const QPushButton *coordinate)
{
    if(ui->bKnight1->x() == (coordinate->x() + 5) && ui->bKnight1->y() == (coordinate->y() + 5))
    {
        return ui->bKnight1;
    }

    if(ui->bKnight2->x() == (coordinate->x() + 5) && ui->bKnight2->y() == (coordinate->y() + 5))
    {
        return ui->bKnight2;
    }

    if(ui->wKnight1->x() == (coordinate->x() + 5) && ui->wKnight1->y() == (coordinate->y() + 5))
    {
        return ui->wKnight1;
    }

    if(ui->wKnight2->x() == (coordinate->x() + 5) && ui->wKnight2->y() == (coordinate->y() + 5))
    {
        return ui->wKnight2;
    }

    return 0;
}

QLabel *InGame::bishopSearch(const QPushButton *coordinate)
{
    if(ui->bBishop1->x() == (coordinate->x() + 4) && ui->bBishop1->y() == (coordinate->y() + 5))
    {
        return ui->bBishop1;
    }

    if(ui->bBishop2->x() == (coordinate->x() + 4) && ui->bBishop2->y() == (coordinate->y() + 5))
    {
        return ui->bBishop2;
    }

    if(ui->wBishop1->x() == (coordinate->x() + 4) && ui->wBishop1->y() == (coordinate->y() + 5))
    {
        return ui->wBishop1;
    }

    if(ui->wBishop2->x() == (coordinate->x() + 4) && ui->wBishop2->y() == (coordinate->y() + 5))
    {
        return ui->wBishop2;
    }

    return 0;
}

QLabel *InGame::queenSearch(const QPushButton *coordinate)
{
    if(ui->bQueen->x() == (coordinate->x() + 2) && ui->bQueen->y() == (coordinate->y() + 5))
    {
        return ui->bQueen;
    }

    if(ui->wQueen->x() == (coordinate->x() + 2) && ui->wQueen->y() == (coordinate->y() + 5))
    {
        return ui->wQueen;
    }

    return 0;
}

QLabel *InGame::kingSearch(const QPushButton *coordinate)
{
    if(ui->bKing->x() == (coordinate->x() + 4) && ui->bKing->y() == (coordinate->y() + 5))
    {
        return ui->bKing;
    }

    if(ui->wKing->x() == (coordinate->x() + 4) && ui->wKing->y() == (coordinate->y() + 5))
    {
        return ui->wKing;
    }

    return 0;
}

void InGame::pieceTypeMove(const QPushButton *coordinate)
{
    if(moving == true)
    {
        pawnMove(coordinate);
        rookMove(coordinate);
        knightMove(coordinate);
        bishopMove(coordinate);
        queenMove(coordinate);
        kingMove(coordinate);
    }

    currentPiece = 0;
    moving = false;
}

void InGame::pawnMove(const QPushButton *coordinate)
{
    if(currentPiece == ui->bPawn1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->bPawn2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->bPawn3)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->bPawn4)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->bPawn5)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->bPawn6)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->bPawn7)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->bPawn8)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn3)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn4)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn5)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn6)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn7)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }

    if(currentPiece == ui->wPawn8)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 7, coordinate->y() + 5, 38, 45));
    }
}

void InGame::rookMove(const QPushButton *coordinate)
{
    if(currentPiece == ui->bRook1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }

    if(currentPiece == ui->bRook2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }

    if(currentPiece == ui->wRook1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }

    if(currentPiece == ui->wRook2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }
}

void InGame::knightMove(const QPushButton *coordinate)
{
    if(currentPiece == ui->bKnight1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }

    if(currentPiece == ui->bKnight2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }

    if(currentPiece == ui->wKnight1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }

    if(currentPiece == ui->wKnight2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 5, coordinate->y() + 5, 41, 45));
    }
}
void InGame::bishopMove(const QPushButton *coordinate)
{
    if(currentPiece == ui->bBishop1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 4, coordinate->y() + 5, 45, 45));
    }

    if(currentPiece == ui->bBishop2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 4, coordinate->y() + 5, 45, 45));
    }

    if(currentPiece == ui->wBishop1)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 4, coordinate->y() + 5, 45, 45));
    }

    if(currentPiece == ui->wBishop2)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 4, coordinate->y() + 5, 45, 45));
    }
}

void InGame::queenMove(const QPushButton *coordinate)
{
    if(currentPiece == ui->bQueen)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 2, coordinate->y() + 5, 49, 45));
    }

    if(currentPiece == ui->wQueen)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 2, coordinate->y() + 5, 49, 45));
    }
}

void InGame::kingMove(const QPushButton *coordinate)
{
    if(currentPiece == ui->bKing)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 4, coordinate->y() + 5, 45, 45));
    }

    if(currentPiece == ui->wKing)
    {
        currentPiece->setGeometry(QRect(coordinate->x() + 4, coordinate->y() + 5, 45, 45));
    }
}

void InGame::on_clicked(const QPushButton *coordinate)
{
    QLabel *piece = pieceTypeSearch(coordinate);

    if(piece == 0)
    {
        pieceTypeMove(coordinate);

        return;
    }

    currentPiece = piece;
    moving = true;
}

void InGame::on_a1_clicked() { on_clicked(ui->a1); }
void InGame::on_a2_clicked() { on_clicked(ui->a2); }
void InGame::on_a3_clicked() { on_clicked(ui->a3); }
void InGame::on_a4_clicked() { on_clicked(ui->a4); }
void InGame::on_a5_clicked() { on_clicked(ui->a5); }
void InGame::on_a6_clicked() { on_clicked(ui->a6); }
void InGame::on_a7_clicked() { on_clicked(ui->a7); }
void InGame::on_a8_clicked() { on_clicked(ui->a8); }

void InGame::on_b1_clicked() { on_clicked(ui->b1); }
void InGame::on_b2_clicked() { on_clicked(ui->b2); }
void InGame::on_b3_clicked() { on_clicked(ui->b3); }
void InGame::on_b4_clicked() { on_clicked(ui->b4); }
void InGame::on_b5_clicked() { on_clicked(ui->b5); }
void InGame::on_b6_clicked() { on_clicked(ui->b6); }
void InGame::on_b7_clicked() { on_clicked(ui->b7); }
void InGame::on_b8_clicked() { on_clicked(ui->b8); }

void InGame::on_c1_clicked() { on_clicked(ui->c1); }
void InGame::on_c2_clicked() { on_clicked(ui->c2); }
void InGame::on_c3_clicked() { on_clicked(ui->c3); }
void InGame::on_c4_clicked() { on_clicked(ui->c4); }
void InGame::on_c5_clicked() { on_clicked(ui->c5); }
void InGame::on_c6_clicked() { on_clicked(ui->c6); }
void InGame::on_c7_clicked() { on_clicked(ui->c7); }
void InGame::on_c8_clicked() { on_clicked(ui->c8); }

void InGame::on_d1_clicked() { on_clicked(ui->d1); }
void InGame::on_d2_clicked() { on_clicked(ui->d2); }
void InGame::on_d3_clicked() { on_clicked(ui->d3); }
void InGame::on_d4_clicked() { on_clicked(ui->d4); }
void InGame::on_d5_clicked() { on_clicked(ui->d5); }
void InGame::on_d6_clicked() { on_clicked(ui->d6); }
void InGame::on_d7_clicked() { on_clicked(ui->d7); }
void InGame::on_d8_clicked() { on_clicked(ui->d8); }

void InGame::on_e1_clicked() { on_clicked(ui->e1); }
void InGame::on_e2_clicked() { on_clicked(ui->e2); }
void InGame::on_e3_clicked() { on_clicked(ui->e3); }
void InGame::on_e4_clicked() { on_clicked(ui->e4); }
void InGame::on_e5_clicked() { on_clicked(ui->e5); }
void InGame::on_e6_clicked() { on_clicked(ui->e6); }
void InGame::on_e7_clicked() { on_clicked(ui->e7); }
void InGame::on_e8_clicked() { on_clicked(ui->e8); }

void InGame::on_f1_clicked() { on_clicked(ui->f1); }
void InGame::on_f2_clicked() { on_clicked(ui->f2); }
void InGame::on_f3_clicked() { on_clicked(ui->f3); }
void InGame::on_f4_clicked() { on_clicked(ui->f4); }
void InGame::on_f5_clicked() { on_clicked(ui->f5); }
void InGame::on_f6_clicked() { on_clicked(ui->f6); }
void InGame::on_f7_clicked() { on_clicked(ui->f7); }
void InGame::on_f8_clicked() { on_clicked(ui->f8); }

void InGame::on_g1_clicked() { on_clicked(ui->g1); }
void InGame::on_g2_clicked() { on_clicked(ui->g2); }
void InGame::on_g3_clicked() { on_clicked(ui->g3); }
void InGame::on_g4_clicked() { on_clicked(ui->g4); }
void InGame::on_g5_clicked() { on_clicked(ui->g5); }
void InGame::on_g6_clicked() { on_clicked(ui->g6); }
void InGame::on_g7_clicked() { on_clicked(ui->g7); }
void InGame::on_g8_clicked() { on_clicked(ui->g8); }

void InGame::on_h1_clicked() { on_clicked(ui->h1); }
void InGame::on_h2_clicked() { on_clicked(ui->h2); }
void InGame::on_h3_clicked() { on_clicked(ui->h3); }
void InGame::on_h4_clicked() { on_clicked(ui->h4); }
void InGame::on_h5_clicked() { on_clicked(ui->h5); }
void InGame::on_h6_clicked() { on_clicked(ui->h6); }
void InGame::on_h7_clicked() { on_clicked(ui->h7); }
void InGame::on_h8_clicked() { on_clicked(ui->h8); }
