#ifndef SQUARE_H
#define SQUARE_H


class Square {
    private:
        int row;
        int column;
    public:
        Square();
        Square(int r, int c);
    
        int get_row();
        int get_column();
};

#endif