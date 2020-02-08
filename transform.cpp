#include<iostream>
#include"sudoku.h"
using namespace std;

int main() {
    // finish your transform code...
    int A[81];
    int num;
    int x,y;
    for(int i=0; i<81; ++i) {
        cin >> A[i];
    }

    Sudoku tra(A);

    while(1) {
        cin >> num;
        if(num == 1) {
            cin>>x>>y;
            tra.swapNum(x,y);
        } else if(num == 2) {
            cin>>x>>y;
            tra.swapRow(x,y);
        } else if(num == 3) {
            cin>>x>>y;
            tra.swapCol(x,y);
        } else if(num == 4) {
            cin>>x;
            tra.rotate(x);
        } else if(num == 5) {
            cin>>x;
            tra.flip(x);
        } else if(num == 0)
            break;
        else
            cout<<"Invalid."<<endl;
    }
    tra.printmap();

    return 0;
}
