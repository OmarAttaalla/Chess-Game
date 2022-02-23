#ifndef SQUARE_H
#define SQUARE_H


class Square {
    private:
        int row;
        int column;
    public:
        Square() {}
        Square(int r, int c) { row = r; column = c; }
    
        int get_row() {return row;}
        int get_column() {return column;}
};

#endif