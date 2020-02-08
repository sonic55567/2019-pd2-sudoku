#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/
#include<iostream>
#include<cstdlib>
class Sudoku {
  public:
    Sudoku();
    Sudoku(const int init_map[]);
    void setMap(const int set_map[]);
    int getElement(int index);
    void changeValue(int index,int value);
    bool checkMap(int check_map[]);
    bool checkUnity(int arr[]);
    bool isCorrect();
    int getFirstZeroIndex();

    // generate
    Sudoku generate();

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    int solve(int arr[]);

    //map
    static const int size = 81;
    int map[size];
    void printmap();
};

#endif // SUDOKU_H
