#include <iostream>

using namespace std;

int main()
{
    int soma = 0,media;
    int matriz[10][10];
    matriz [0][0] = 1;
    matriz [1][1] = 1;
    matriz [2][2] = 1;
    matriz [3][3] = 1;
    matriz [4][4] = 1;
    matriz [5][5] = 1;
    matriz [6][6] = 1;
    matriz [7][7] = 1;
    matriz [8][8] = 1;
    matriz [9][9] = 1;

    for(int i =0;i < 10;i++){
        soma = soma + matriz[i][i];
    }
    media = soma / 10;


    cout << media << endl;



    return 0;
}
