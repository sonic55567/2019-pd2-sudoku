#include<iostream>
#include"sudoku.h"
using namespace std;

int main() {
    // finish your generate code...
    int A[81] = {8,1,2,7,5,3,6,4,9,9,4,3,6,8,2,1,7,5,6,7,5,4,9,1,2,8,3,1,5,4,2,3,7,8,9,6,3,6,9,8,4,5,7,2,1,2,8,7,1,6,9,5,3,4,5,2,1,9,7,4,3,6,8,4,3,8,5,2,6,9,1,7,7,9,6,3,1,8,4,5,2};
    Sudoku gen(A);
    gen.generate();
    gen.printmap();
    return 0;
}
