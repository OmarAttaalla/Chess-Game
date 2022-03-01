#ifndef INGAME_H
#define INGAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class InGame; }
QT_END_NAMESPACE

class InGame : public QMainWindow
{
    Q_OBJECT

public:
    InGame(QWidget *parent = nullptr);
    ~InGame();
    void board();
    void black_pieces();
    void white_pieces();

private:
    Ui::InGame *ui;
};
#endif // INGAME_H
