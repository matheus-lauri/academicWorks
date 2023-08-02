#pragma once
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\structs.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\menu.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Jogo feito por Gabriel Bósio, Gustavo Baron Lauriezen e Matheus Baron Lauriezen.

int main() {
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    //Chama a função Menu Principal para carregar a "capa" do jogo
    MenuPrincipal();
    return 0;
}
