#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

template<int txt = 7, int bg = 0>
ostream& color(ostream& text) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
    return text;
}

void printArray(int array[11][11], const int row, const int column) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) {
            if (j == 0 or i == 0) { cout << setw(2) << color<6, 0> << array[i][j] << color<7, 0>; }
            else { 
                if (array[i][j] == 1) { cout << setw(2) << color<4, 0> << array[i][j] << color<7, 0>; } 
                else { cout << setw(2) << color<7, 0> << array[i][j] << color<7, 0>; } }
        }
        cout << endl;
    }
}

int main1()
{
    const int row = 11, column = 11; //размеры массива
    int array[row][column] = { 
        {0,0,1,2,3,4,5,6,7,8,9},
        {0,0,0,1,1,0,0,0,0,0,0},
        {1,0,0,1,1,0,0,0,0,0,0},
        {2,0,0,1,1,0,0,1,1,0,0},
        {3,0,0,1,1,0,0,1,1,0,0},
        {4,0,0,1,1,0,0,1,1,0,0},
        {5,0,0,0,0,0,0,1,1,0,0},
        {6,0,0,0,0,0,0,0,0,0,0},
        {7,0,0,1,1,0,0,0,0,0,0},
        {8,0,0,1,1,0,0,0,0,0,0},
        {9,0,0,1,1,0,0,0,0,0,0} };
    printArray(array, row, column);
    int sx1, sx2, sx3, sy1, sy2, sy3, tx1, tx2, tx3, ty1, ty2, ty3;
    {
        cout << "1 robot's position: ";
        cin >> sy1 >> sx1;
        cout << "1 robot's target: ";
        cin >> ty1 >> tx1;
        cout << "2 robot's position: ";
        cin >> sy2 >> sx2;
        cout << "2 robot's target: ";
        cin >> ty2 >> tx2;
        cout << "3 robot's position: ";
        cin >> sy3 >> sx3;
        cout << "3 robot's target: ";
        cin >> ty3 >> tx3;
        cout << "1)" << sy1 << " " << sx1 << " -> " << ty1 << " " << tx1 << ";  ";
        cout << "2)" << sy2 << " " << sx2 << " -> " << ty2 << " " << tx2 << ";  ";
        cout << "3)" << sy3 << " " << sx3 << " -> " << ty3 << " " << tx3;
    }
    return 0;
}