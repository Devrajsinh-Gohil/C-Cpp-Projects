#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define UNASSIGNED 0
#define N 9

bool SEARCH(int BOX[N][N], int &R, int &C);
bool PROTECT(int BOX[N][N], int R, int C, int digit);


bool SUDOKU_SOL(int BOX[N][N])
{
    int R, C;
    if (!SEARCH(BOX, R, C))
       return true;
    for (int digit = 1; digit <= 9; digit++)
    {
        if (PROTECT(BOX, R, C, digit))
        {
            BOX[R][C] = digit;
            if (SUDOKU_SOL(BOX))
                return true;
            BOX[R][C] = UNASSIGNED;
        }
    }
    return false;
}


bool SEARCH(int BOX[N][N], int &R, int &C)
{
    for (R = 0; R < N; R++)
        for (C = 0; C < N; C++)
            if (BOX[R][C] == UNASSIGNED)
                return true;
    return false;
}


bool UsedInR(int BOX[N][N], int R, int digit)
{
    for (int C = 0; C < N; C++)
        if (BOX[R][C] == digit)
            return true;
    return false;
}


bool UsedInC(int BOX[N][N], int C, int digit)
{
    for (int R = 0; R < N; R++)
        if (BOX[R][C] == digit)
            return true;
    return false;
}


bool UsedInBox(int BOX[N][N], int boxStartR, int boxStartC, int digit)
{
    for (int R = 0; R < 3; R++)
        for (int C = 0; C < 3; C++)
            if (BOX[R+boxStartR][C+boxStartC] == digit)
                return true;
    return false;
}


bool PROTECT(int BOX[N][N], int R, int C, int digit)
{
    return !UsedInR(BOX, R, digit) && !UsedInC(BOX, C, digit) &&
           !UsedInBox(BOX, R - R % 3 , C - C % 3, digit);
}


void printBOX(int BOX[N][N])
{
    for (int R = 0; R < N; R++)
    {
        for (int C = 0; C < N; C++)
            cout<<BOX[R][C]<<"  ";
        cout<<endl;
    }
}


int main()
{
    int BOX[N][N] = { {2, 0, 3, 6, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 2, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {6, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 9, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 8, 3, 0, 0}};
    if (SUDOKU_SOL(BOX) == true)
          printBOX(BOX);
    else
        cout<<"No solution exists"<<endl;
    return 0;
}
//Output
// OUTPUT:1
// int BOX[N][N] = { {2, 0, 3, 6, 0, 8, 4, 0, 0},
//                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
//                       {0, 8, 7, 0, 0, 0, 0, 2, 1},
//                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
//                       {6, 0, 0, 8, 6, 3, 0, 0, 5},
//                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
//                       {1, 9, 0, 0, 0, 0, 2, 5, 0},
//                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
//                       {0, 0, 5, 2, 0, 8, 3, 0, 0}};
