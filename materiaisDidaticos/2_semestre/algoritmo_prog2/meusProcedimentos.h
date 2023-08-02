#ifndef MEUSPROCEDIMENTOS_H_INCLUDED
#define MEUSPROCEDIMENTOS_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
    void posicaoxy( int column, int line )
    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
    }

    void mostrarCursor(bool showFlag)
    {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO     cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }
    void colorir (int cor) {

        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(out, cor);
    }

#endif // MEUSPROCEDIMENTOS_H_INCLUDED
