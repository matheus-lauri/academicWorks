/*Vers�o beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <time.h> ///para habilitar a fun��o time
#include <conio.h> ///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: n�o permitido o uso de fun��es e vari�veis compostas como structs, vetores e matrizes
    - Corrigir os rastros (p�ssaro e obst�culos)
    - Implementar colis�o
    - Implementar pontua��o (mais um ponto para cada obst�culo superado)
    - Fazer 2 obst�culos simult�neos (obstaculo1 e obstaculo2)
    - Deixar a pontua��o vis�vel durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    COORD   coord;

    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.


    int bird_x=5, bird_y=10;
    int abird_x=5, abird_y=10;
    int obstaculo_x=59, obstaculo_y;
    int aobstaculo_x=59, aobstaculo_y;
    int obstaculo2_x=119, obstaculo2_y;
    int aobstaculo2_x=119, aobstaculo2_y;
    int cont = 0;
    int tecla;
    int n_aleatorio, n_aleatorio2;
    int v1, v2, v3, v4;
    int velocidade = 200;


    ///DESENHO DO CEN�RIO
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------";

    srand(time(NULL));

    n_aleatorio = rand() % 3;
    n_aleatorio2 = rand() % 3;


    while (true) { //esse la�o faz o jogo rodar para sempre

        ///POSICIONA O P�SSARO
        coord.X = bird_x;    coord.Y = bird_y;
        abird_x = coord.X;    abird_y = coord.Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);

        ///POSICIONA O OBST�CULO
        obstaculo_y=1;
        while(obstaculo_y<20){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            switch(n_aleatorio) {

        case 0:
            if(obstaculo_y<3 || obstaculo_y>9 ){
                cout<<char(219);
            } else {
                cout<<" ";
            }
            v1 = 3;
            v2 = 9;
            break;
        case 1:
            if(obstaculo_y<7 || obstaculo_y>13 ){
                cout<<char(219);
            } else {
                cout<<" ";
            }
            v1 = 7;
            v2 = 13;
            break;
        case 2:
            if(obstaculo_y<11 || obstaculo_y>17 ){
                cout<<char(219);
            } else {
                cout<<" ";
            }
            v1 = 11;
            v2 = 17;
            break;

            }

            obstaculo_y++;
        }

        obstaculo2_y=1;
        while(obstaculo2_y<20){
            coord.X = obstaculo2_x;    coord.Y = obstaculo2_y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            switch(n_aleatorio2) {

        case 0:
            if(obstaculo2_y<3 || obstaculo2_y>9 ){
                cout<<char(219);
            } else {
                cout<<" ";
            }
            v3 = 3;
            v4 = 9;
            break;
        case 1:
            if(obstaculo2_y<7 || obstaculo2_y>13 ){
                cout<<char(219);
            } else {
                cout<<" ";
            }
            v3 = 7;
            v4 = 13;
            break;
        case 2:
            if(obstaculo2_y<11 || obstaculo2_y>17 ){
                cout<<char(219);
            } else {
                cout<<" ";
            }
            v3 = 11;
            v4 = 17;
            break;

            }

            obstaculo2_y++;

        }

        ///VERIFICA COLIS�O
        if(bird_y == 0 || bird_y == 20){
            cout << "\nGAME OVER";
            return 0;
        }
        if((bird_x == obstaculo_x) && (bird_y<v1 || bird_y>v2)){
            cout << "\nGAME OVER";
            return 0;
        }
        if((bird_x == obstaculo2_x) && (bird_y<v3 || bird_y>v4)){
            cout << "\nGAME OVER";
            return 0;
        }

        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }

        if ( tecla=='w' ){
            bird_y--;
            tecla='0';w
        } else {
            bird_y++;
        }
        ///P�SSARO CAI 1 POSI��O SE N�O FOI PRESSIONADO PARA SUBIR

        ///QUANDO O OBST�CULO ATINGIR O CANTO ESQUERDO, ELE VOLTA PARA O IN�CIO
        if (obstaculo_x == 0) {
            obstaculo_x = 119;
            n_aleatorio = rand() % 3;
        }
        if (obstaculo2_x == 0) {
            obstaculo2_x = 119;
            n_aleatorio2 = rand() % 3;
        }

        ///OBST�CULO AVAN�A UMA POSI��O PARA ESQUERDA
        obstaculo_x--;
        obstaculo2_x--;

        ///CONTADOR DE PONTOS
        if(((bird_x == obstaculo_x) && (bird_y>v1 || bird_y<v2)) || ((bird_x == obstaculo2_x) && (bird_y>v3 || bird_y<v4)) ){
            cont++;
            if(cont%5==0 && cont!=0){
                velocidade = velocidade - 50;
        }
        }

        cout << "\n\nPontos: " << cont << "\n         ";

        ///TEMPO DE ESPERA
        Sleep(velocidade);

        ///APAGA O RASTRO DO P�SSARO
        coord.X = abird_x; coord.Y = abird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ";

        ///APAGA O RASTRO DO OBST�CULO
        aobstaculo_y=1;
        while(aobstaculo_y<20){
            coord.X = aobstaculo_x;    coord.Y = aobstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            cout << " ";

            aobstaculo_y++;
        }

        aobstaculo2_y=1;
        while(aobstaculo2_y<20){
            coord.X = aobstaculo2_x;    coord.Y = aobstaculo2_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            cout << " ";

            aobstaculo2_y++;
        }

        ///APAGADOR ANDA UMA COORDENADA A MENOS NO SEU EIXO X
        aobstaculo_x--;
        aobstaculo2_x--;

        ///APAGADOR VOLTA PARA O IN�CIO
        if (aobstaculo_x == -1) {
            aobstaculo_x = 118;
        }
        if (aobstaculo2_x == -1) {
            aobstaculo2_x = 118;
        }
    }
    return 0;
}
