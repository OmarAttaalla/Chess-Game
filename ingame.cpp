#include "ingame.h"
#include "ui_ingame.h"
#include <QPixmap>
#include <QButtonGroup>

#include "movement/Rook.h"
#include "movement/Queen.h"
#include "movement/Knight.h"
#include "movement/Bishop.h"

InGame::InGame(QWidget *parent): QMainWindow(parent), ui(new Ui::InGame)
{
    ui->setupUi(this);

    this->setWindowTitle("Chess");
    board();
    black_pieces();
    white_pieces();

    ui->turnLabel->setText("Black's Turn");
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

void InGame::turnChanger()
{
    //gameState();

    turn = !turn;

    if(turn)
    {
        ui->turnLabel->setText("Black's Turn");

    } else
    {
        ui->turnLabel->setText("White's Turn");
    }
}

void InGame::gameState(King *king)
{
    if(king->checkmate(cb))
    {
        stop = true;

        if(!king->get_color())
        {
            ui->turnLabel->setText("Black Wins");

        } else
        {
            ui->turnLabel->setText("White Wins");
        }

    }
}

QLabel *InGame::pieceTypeSearch(const QPushButton *coordinate)
{
    QLabel *piece = pawnSearch(coordinate);
    if(piece != 0) { return piece; }
    piece = rookSearch(coordinate);
    if(piece != 0) { return piece; }
    piece = knightSearch(coordinate);
    if(piece != 0) { return piece; }
    piece = bishopSearch(coordinate);
    if(piece != 0) { return piece; }
    piece = queenSearch(coordinate);
    if(piece != 0) { return piece; }
    piece = kingSearch(coordinate);
    if(piece != 0) { return piece; }

    return 0;
}

QLabel *InGame::pawnSearch(const QPushButton *coordinate)
{
    QLabel *piece = 0;

    if(turn)
    {
        piece = pieceTypeMatch(coordinate, ui->bPawn1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bPawn2);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bPawn3);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bPawn4);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bPawn5);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bPawn6);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bPawn7);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bPawn8);
        if(piece != 0) { return piece; }

    } else
    {
        piece = pieceTypeMatch(coordinate, ui->wPawn1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wPawn2);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wPawn3);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wPawn4);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wPawn5);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wPawn6);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wPawn7);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wPawn8);
        if(piece != 0) { return piece; }
    }

    return 0;
}

QLabel *InGame::rookSearch(const QPushButton *coordinate)
{
    QLabel *piece = 0;

    if(turn)
    {
        piece = pieceTypeMatch(coordinate, ui->bRook1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bRook2);
        if(piece != 0) { return piece; }

    } else
    {
        piece = pieceTypeMatch(coordinate, ui->wRook1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wRook1);
        if(piece != 0) { return piece; }
    }

    return 0;
}

QLabel *InGame::knightSearch(const QPushButton *coordinate)
{
    QLabel *piece = 0;

    if(turn)
    {
        piece = pieceTypeMatch(coordinate, ui->bKnight1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bKnight2);
        if(piece != 0) { return piece; }

    } else
    {
        piece = pieceTypeMatch(coordinate, ui->wKnight1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wKnight2);
        if(piece != 0) { return piece; }
    }

    return 0;
}

QLabel *InGame::bishopSearch(const QPushButton *coordinate)
{
    QLabel *piece = 0;

    if(turn)
    {
        piece = pieceTypeMatch(coordinate, ui->bBishop1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->bBishop2);
        if(piece != 0) { return piece; }

    } else
    {
        piece = pieceTypeMatch(coordinate, ui->wBishop1);
        if(piece != 0) { return piece; }
        piece = pieceTypeMatch(coordinate, ui->wBishop2);
        if(piece != 0) { return piece; }
    }

    return 0;
}

QLabel *InGame::queenSearch(const QPushButton *coordinate)
{
    if(turn)
    {
        return pieceTypeMatch(coordinate, ui->bQueen);

    } else
    {
        return pieceTypeMatch(coordinate, ui->wQueen);
    }

    return 0;
}

QLabel *InGame::kingSearch(const QPushButton *coordinate)
{
    if(turn)
    {
        return pieceTypeMatch(coordinate, ui->bKing);

    } else
    {
        return pieceTypeMatch(coordinate, ui->wKing);
    }

    return 0;
}

QLabel *InGame::pieceTypeMatch(const QPushButton *coordinate, QLabel *piece)
{
    if(piece->x() == (coordinate->x()) && piece->y() == (coordinate->y()))
    {
        return piece;
    }

    return 0;
}

void InGame::move(const QPushButton *coordinate)
{
    if(moving == true)
    {
        if(cp == nullptr) { return; }

        cp->scan(cb);
        std::vector<Square*> s = cp->get_moveableSquares();

        for(Square* sq: s)
        {
            if(sq->get_row() == (370 - coordinate->y())/50 && sq->get_column() == (coordinate->x() - 20)/50)
            {
                currentPiece->setGeometry(QRect(coordinate->x(), coordinate->y(), 50, 50));
                cp->moves(sq);
                turnChanger();
                break;
            }
        }
    }

    currentPiece = 0;
    moving = false;
}

void InGame::on_clicked(const QPushButton *coordinate)
{
    if(!stop)
    {
        QLabel *piece = pieceTypeSearch(coordinate);

        if(piece == 0)
        {
            move(coordinate);

            return;
        }

        cp = cb.getSquare((370 - coordinate->y())/50, (coordinate->x() - 20)/50)->getPiece();
        currentPiece = piece;
        moving = true;
    }
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

void InGame::on_mainMenu_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}

