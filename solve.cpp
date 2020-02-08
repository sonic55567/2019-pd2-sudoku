#include<iostream>
#include"sudoku.h"
using namespace std;

int solve_sudoku(Sudoku question,Sudoku & answer) {
    int firstzero;
    firstzero = question.getFirstZeroIndex();
    if(firstzero == -1) {
        if(question.isCorrect()) {
            answer = question;
            return 1;
        } else
            return 0;
    } else {
        for(int num=9; num>=1; --num) {
            int flag=0;
            //check up
            for(int i=firstzero; i>=0; i-=9) {
                if(num == question.map[i]) {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                continue;

            //check down
            for(int i=firstzero+9; i<=81; i+=9) {
                if(num == question.map[i]) {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                continue;

            //check row
            for(int i=(firstzero/9)*9+8; i>=((firstzero/9)*9); --i) {
                if(num == question.map[i]) {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                continue;

            //check cell
            //0
            if((firstzero>=0&&firstzero<=2) || (firstzero>=9&&firstzero<=11) || (firstzero>=18&&firstzero<=20)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }
                /*if(num == question.map[0]) {flag=1;}
                if(num == question.map[1]) {flag=1;}
                if(num == question.map[2]) {flag=1;}
                if(num == question.map[9]) {flag=1;}
                if(num == question.map[10]) {flag=1;}
                if(num == question.map[11]) {flag=1;}
                if(num == question.map[18]) {flag=1;}
                if(num == question.map[19]) {flag=1;}
                if(num == question.map[20]) {flag=1;}*/

            }
            if(flag)
                continue;

            //1
            if((firstzero>=3&&firstzero<=5) || (firstzero>=12&&firstzero<=14) || (firstzero>=21&&firstzero<=23)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[3 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[3]) {flag=1;}
                if(num == question.map[4]) {flag=1;}
                if(num == question.map[5]) {flag=1;}
                if(num == question.map[12]) {flag=1;}
                if(num == question.map[13]) {flag=1;}
                if(num == question.map[14]) {flag=1;}
                if(num == question.map[21]) {flag=1;}
                if(num == question.map[22]) {flag=1;}
                if(num == question.map[23]) {flag=1;}
*/
            }
            if(flag)
                continue;

            //2
            if((firstzero>=6&&firstzero<=8) || (firstzero>=15&&firstzero<=17) || (firstzero>=24&&firstzero<=26)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[6 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[6]) {flag=1;}
                if(num == question.map[7]) {flag=1;}
                if(num == question.map[8]) {flag=1;}
                if(num == question.map[15]) {flag=1;}
                if(num == question.map[16]) {flag=1;}
                if(num == question.map[17]) {flag=1;}
                if(num == question.map[24]) {flag=1;}
                if(num == question.map[25]) {flag=1;}
                if(num == question.map[26]) {flag=1;}
*/
            }
            if(flag)
                continue;

            //3
            if((firstzero>=27&&firstzero<=29) || (firstzero>=36&&firstzero<=38) || (firstzero>=45&&firstzero<=47)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[27 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[27]) {flag=1;}
                if(num == question.map[28]) {flag=1;}
                if(num == question.map[29]) {flag=1;}
                if(num == question.map[36]) {flag=1;}
                if(num == question.map[37]) {flag=1;}
                if(num == question.map[38]) {flag=1;}
                if(num == question.map[45]) {flag=1;}
                if(num == question.map[46]) {flag=1;}
                if(num == question.map[47]) {flag=1;}
*/
            }
            if(flag)
                continue;

            //4
            if((firstzero>=30&&firstzero<=32) || (firstzero>=39&&firstzero<=41) || (firstzero>=48&&firstzero<=50)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[30 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[30]) {flag=1;}
                if(num == question.map[31]) {flag=1;}
                if(num == question.map[32]) {flag=1;}
                if(num == question.map[39]) {flag=1;}
                if(num == question.map[40]) {flag=1;}
                if(num == question.map[41]) {flag=1;}
                if(num == question.map[48]) {flag=1;}
                if(num == question.map[49]) {flag=1;}
                if(num == question.map[50]) {flag=1;}
*/
            }
            if(flag)
                continue;

            //5
            if((firstzero>=33&&firstzero<=35) || (firstzero>=42&&firstzero<=44) || (firstzero>=51&&firstzero<=53)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[33 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[33]) {flag=1;}
                if(num == question.map[34]) {flag=1;}
                if(num == question.map[35]) {flag=1;}
                if(num == question.map[42]) {flag=1;}
                if(num == question.map[43]) {flag=1;}
                if(num == question.map[44]) {flag=1;}
                if(num == question.map[51]) {flag=1;}
                if(num == question.map[52]) {flag=1;}
                if(num == question.map[53]) {flag=1;}
*/
            }
            if(flag)
                continue;

            //6
            if((firstzero>=54&&firstzero<=56) || (firstzero>=63&&firstzero<=65) || (firstzero>=72&&firstzero<=74)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[54 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[54]) {flag=1;}
                if(num == question.map[55]) {flag=1;}
                if(num == question.map[56]) {flag=1;}
                if(num == question.map[63]) {flag=1;}
                if(num == question.map[64]) {flag=1;}
                if(num == question.map[65]) {flag=1;}
                if(num == question.map[72]) {flag=1;}
                if(num == question.map[73]) {flag=1;}
                if(num == question.map[74]) {flag=1;}
*/
            }
            if(flag)
                continue;

            //7
            if((firstzero>=57&&firstzero<=59) || (firstzero>=66&&firstzero<=68) || (firstzero>=75&&firstzero<=77)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[57 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[57]) {flag=1;}
                if(num == question.map[58]) {flag=1;}
                if(num == question.map[59]) {flag=1;}
                if(num == question.map[66]) {flag=1;}
                if(num == question.map[67]) {flag=1;}
                if(num == question.map[68]) {flag=1;}
                if(num == question.map[75]) {flag=1;}
                if(num == question.map[76]) {flag=1;}
                if(num == question.map[77]) {flag=1;}
*/
            }
            if(flag)
                continue;

            //8
            if((firstzero>=60&&firstzero<=62) || (firstzero>=69&&firstzero<=71) || (firstzero>=78&&firstzero<=80)) {
                for(int i=8; i>=0; --i) {
                    if(num == question.map[60 + 9*(i/3) + (i%3)]) {
                        flag = 1;
                        break;
                    }
                }/*
                if(num == question.map[60]) {flag=1;}
                if(num == question.map[61]) {flag=1;}
                if(num == question.map[62]) {flag=1;}
                if(num == question.map[69]) {flag=1;}
                if(num == question.map[70]) {flag=1;}
                if(num == question.map[71]) {flag=1;}
                if(num == question.map[78]) {flag=1;}
                if(num == question.map[79]) {flag=1;}
                if(num == question.map[80]) {flag=1;}
*/
            }
            if(flag)
                continue;


            question.changeValue(firstzero,num);
            if(solve_sudoku(question,answer))
                return 1;
        }
        return 0;
    }
}

int main() {
    // finish your solve code...
    int A[81];
    int index = -1,count = 0;
    for(int i=0; i<81; ++i) {
        cin >> A[i];
    }

    Sudoku sol(A);
    Sudoku ans;

    for(int i=0; i<81; ++i)
        if(A[i]!=0)
            ++count;
    if(count<17)
        index = 2;
    else
        index = solve_sudoku(sol,ans);

    if(index == 0)
        cout<<0<<endl;
    else if(index == 1) {
        cout<<1<<endl;
        ans.printmap();
    } else if(index == 2)
        cout<<2<<endl;
    return 0;
}
