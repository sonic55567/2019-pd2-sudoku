#include"sudoku.h"
using namespace std;

Sudoku::Sudoku() {
    for(int i=0; i<size; ++i)
        map[i] = 0;
}
Sudoku::Sudoku(const int init_map[]) {
    for(int i=0; i<size; ++i)
        map[i] = init_map[i];
}

void Sudoku::changeValue(int index,int value) {
    map[index] = value;
}

void Sudoku::setMap(const int set_map[]) {
    for(int i=0; i<size; ++i)
        map[i] = set_map[i];
}

int Sudoku::getElement(int index) {
    return map[index];
}

void Sudoku::swapNum(int x, int y) {
    for(int i=0; i<81; ++i)
        if(map[i] == x)
            map[i] = 10;
    for(int i=0; i<81; ++i)
        if(map[i] == y)
            map[i] = x;
    for(int i=0; i<81; ++i)
        if(map[i] == 10)
            map[i] = y;
}


void Sudoku::swapRow(int x, int y) {
    int temp[27];
    if(x==0) {
        for(int i=0; i<27; ++i)
            temp[i] = map[i];
        if(y==1) {
            for(int i=0; i<27; ++i) {
                map[i] = map[27+i];
                map[27+i] = temp[i];
            }
        }

        if(y==2) {
            for(int i=0; i<27; ++i) {
                map[i] = map[54+i];
                map[54+i] = temp[i];
            }
        }
    }

    if(x==1) {
        for(int i=27; i<54; ++i)
            temp[i-27] = map[i];
        if(y==0) {
            for(int i=27; i<54; ++i) {
                map[i] = map[i-27];
                map[i-27] = temp[i-27];
            }
        }
        if(y==2) {
            for(int i=27; i<54; ++i) {
                map[i] = map[i+27];
                map[i+27] = temp[i-27];
            }
        }
    }

    if(x==2) {
        for(int i=54; i<81; ++i)
            temp[i-54] = map[i];
        if(y==0) {
            for(int i=54; i<81; ++i) {
                map[i] = map[i-54];
                map[i-54] = temp[i-54];
            }
        }
        if(y==1) {
            for(int i=54; i<81; ++i) {
                map[i] = map[i-27];
                map[i-27] = temp[i-27];
            }
        }
    }
}

void Sudoku::swapCol(int x, int y) {
    int temp[81];

    if(x==0) {
        for(int i=0; i<9; ++i)
            for(int j=0; j<3; ++j)
                temp[9*i+j] = map[9*i+j];
        if(y==1) {
            for(int i=0; i<9; ++i)
                for(int j=0; j<3; ++j) {
                    map[9*i+j] = map[9*i+j+3];
                    map[9*i+j+3] = temp[9*i+j];
                }
        }
        if(y==2) {
            for(int i=0; i<9; ++i)
                for(int j=0; j<3; ++j) {
                    map[9*i+j] = map[9*i+j+6];
                    map[9*i+j+6] = temp[9*i+j];
                }
        }
    }

    if(x==1) {
        for(int i=0; i<9; ++i)
            for(int j=3; j<6; ++j)
                temp[9*i+j] = map[9*i+j];
        if(y==0) {
            for(int i=0; i<9; ++i)
                for(int j=3; j<6; ++j) {
                    map[9*i+j] = map[9*i+j-3];
                    map[9*i+j-3] = temp[9*i+j];
                }
        }
        if(y==2) {
            for(int i=0; i<9; ++i)
                for(int j=3; j<6; ++j) {
                    map[9*i+j] = map[9*i+j+3];
                    map[9*i+j+3] = temp[9*i+j];
                }
        }
    }

    if(x==2) {
        for(int i=0; i<9; ++i)
            for(int j=6; j<9; ++j)
                temp[9*i+j] = map[9*i+j];
        if(y==0) {
            for(int i=0; i<9; ++i)
                for(int j=6; j<9; ++j) {
                    map[9*i+j] = map[9*i+j-6];
                    map[9*i+j-6] = temp[9*i+j];
                }
        }
        if(y==1) {
            for(int i=0; i<9; ++i)
                for(int j=6; j<9; ++j) {
                    map[9*i+j] = map[9*i+j-3];
                    map[9*i+j-3] = temp[9*i+j];
                }
        }
    }
}

void Sudoku::rotate(int x) {
    int temp[81];

    for(int a=0; a<x; ++a) {
        int k=0;
        for(int i=0; i<81; ++i)
            temp[i] = map[i];
        for(int i=0; i<9; ++i)
            for(int j=8; j>=0; --j) {
                map[k] = temp[9*j+i];
                ++k;
            }
    }
}

void Sudoku::flip(int x) {
    int temp[81];

    for(int i=0; i<81; ++i)
        temp[i] = map[i];

    if(x==0) {
        int k=8;
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j)
                map[9*i+j] = temp[9*k+j];
            --k;
        }
    }

    if(x==1) {
        for(int i=0; i<9; ++i) {
            int k=8;
            for(int j=0; j<9; ++j) {
                map[9*i+j] = temp[9*i+k];
                --k;
            }
        }
    }
}

Sudoku Sudoku::generate() {
    srand(time(NULL));
    int a=rand()%4,x=rand()%3,y=rand()%3;
    if(a==0) this->swapNum(x,y);
    else if(a==1) this->swapRow(x,y);
    else if(a==2) this->swapCol(x,y);
    else this->rotate(x);

    for(int i=0; i<50; ++i) {
        this->changeValue(rand()%81,0);
    }

}

bool Sudoku::checkUnity(int arr[]) {
    int arr_unity[9] = {0,0,0,0,0,0,0,0,0}; //counters

    for(int i=0; i<9; ++i)
        ++arr_unity[arr[i]-1]; //count
    for(int i=0; i<9; ++i)
        if(arr_unity[i] != 1) //all element
            return false; //must be 1
    return true;
}

bool Sudoku::isCorrect() {
    bool check_result;
    int check_arr[9];
    int location;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j)
            check_arr[j] = map[9*i+j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j)
            check_arr[j] = map[i+9*j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    /*for(int i=0; i<9; ++i) { //check cells
        for(int j=0; j<9; ++j) {
            location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
            check_arr[j] = map[location];
        }
        check_result = checkUnity(check_arr);
        if(check_result==false)
            return false;
    }*/
    
    //0
    check_arr[0] = map[0];
    check_arr[1] = map[1];
    check_arr[2] = map[2];
    check_arr[3] = map[9];
    check_arr[4] = map[10];
    check_arr[5] = map[11];
    check_arr[6] = map[18];
    check_arr[7] = map[19];
    check_arr[8] = map[20];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //1
    check_arr[0] = map[3];
    check_arr[1] = map[4];
    check_arr[2] = map[5];
    check_arr[3] = map[12];
    check_arr[4] = map[13];
    check_arr[5] = map[14];
    check_arr[6] = map[21];
    check_arr[7] = map[22];
    check_arr[8] = map[23];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //2
    check_arr[0] = map[6];
    check_arr[1] = map[7];
    check_arr[2] = map[8];
    check_arr[3] = map[15];
    check_arr[4] = map[16];
    check_arr[5] = map[17];
    check_arr[6] = map[24];
    check_arr[7] = map[25];
    check_arr[8] = map[26];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //3
    check_arr[0] = map[27];
    check_arr[1] = map[28];
    check_arr[2] = map[29];
    check_arr[3] = map[36];
    check_arr[4] = map[37];
    check_arr[5] = map[38];
    check_arr[6] = map[45];
    check_arr[7] = map[46];
    check_arr[8] = map[47];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //4
    check_arr[0] = map[30];
    check_arr[1] = map[31];
    check_arr[2] = map[32];
    check_arr[3] = map[39];
    check_arr[4] = map[40];
    check_arr[5] = map[41];
    check_arr[6] = map[48];
    check_arr[7] = map[49];
    check_arr[8] = map[50];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //5
    check_arr[0] = map[33];
    check_arr[1] = map[34];
    check_arr[2] = map[35];
    check_arr[3] = map[42];
    check_arr[4] = map[43];
    check_arr[5] = map[44];
    check_arr[6] = map[51];
    check_arr[7] = map[52];
    check_arr[8] = map[53];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //6
    check_arr[0] = map[54];
    check_arr[1] = map[55];
    check_arr[2] = map[56];
    check_arr[3] = map[63];
    check_arr[4] = map[64];
    check_arr[5] = map[65];
    check_arr[6] = map[72];
    check_arr[7] = map[73];
    check_arr[8] = map[74];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //7
    check_arr[0] = map[57];
    check_arr[1] = map[58];
    check_arr[2] = map[59];
    check_arr[3] = map[66];
    check_arr[4] = map[67];
    check_arr[5] = map[68];
    check_arr[6] = map[75];
    check_arr[7] = map[76];
    check_arr[8] = map[77];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    //8
    check_arr[0] = map[60];
    check_arr[1] = map[61];
    check_arr[2] = map[62];
    check_arr[3] = map[69];
    check_arr[4] = map[70];
    check_arr[5] = map[71];
    check_arr[6] = map[78];
    check_arr[7] = map[79];
    check_arr[8] = map[80];
    check_result = checkUnity(check_arr);
    if(check_result==false)
        return false;
    
    return true;
}

int Sudoku::getFirstZeroIndex() {
    for(int i=0; i<81; ++i)
        if(map[i]==0)
            return i;
    return -1;
}

void Sudoku::printmap() {
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cout<<map[9*i+j];
            if(j!=8) cout<<" ";
        }
        cout<<endl;
    }
}
