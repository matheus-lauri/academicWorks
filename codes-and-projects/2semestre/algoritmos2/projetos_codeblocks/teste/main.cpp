/**
Já implementado:
    -> O pássaro “deixa rastros”: Quando o pássaro é desenhado na sua nova posição
    -> o jogo não apaga o desenho do pássaro da posição anterior;
    -> O obstáculo “deixa rastros”: O obstáculo é desenhado em sua nova posição, mas o jogo não apaga o desenho da posição anterior do obstáculo;
    -> Não é apresentado o placar em lugar nenhum da tela
    -> Não existe tratamento de colisão, o pássaro não colide com o teto, chão ou com os obstáculos
     -> O jogo deveria apresentar uma pontuação que aumenta a cada obstáculo superado
     -> O Passaro ao passar pelo espaço entre os pipes também gera colisão, precisa corrigir;


Falta Implementar:
    -> Os obstáculos deverão ser escolhidos aleatoriamente com passagens: no meio, em cima e embaixo (explicação no pdf do trabalho)
    -> O jogo deverá apresentar 2 obstáculos simultâneos com uma certa distância entre eles
    -> A velocidade do jogo deverá aumentar a cada 5 obstáculos superados





 */


/*Vers�o beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
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
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.


    int bird_x=5, bird_y=10;
    int obstaculo_x=50 , obstaculo_y; //119 ta antes na obstaculo_x
    int tecla;
    int pontos=0;
    bool game_over = false;

    while (true) { //esse la�o faz o jogo rodar para sempre

        ///DESENHO DO CENARIO E SCORE
        system("cls"); // limpa o terminal para o próximo loop
        cout<<"----------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"----------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n";
        cout << "SCORE >>> ";
        cout << pontos;
        cout << "\n\n";
        cout<<"---------------";


        ///POSICIONA O P�SSARO
        coord.X = bird_x;
        coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(205);


        ///POSICIONA O OBST�CULO
        obstaculo_y=1;
        while(obstaculo_y<20){
            coord.X = obstaculo_x;
            coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y<5 || obstaculo_y>10){ // Felipe - tamanho do buraco entre os pipes superior e inferior
                cout<<char(219);
            }

            obstaculo_y++;

        }

        ///OBST�CULO AVAN�A UMA POSI��O PARA ESQUERDA
        if (obstaculo_x <= 0) {
            obstaculo_x = 119; //Felipe - quando o pipe atingir o limite no lado esquerdo da tela, ele vai voltar pra posição inicial x = 110
        }
        obstaculo_x--;



        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { //verifica se uma tecla foi pressionada
            if (game_over == false) {
                tecla=getch(); //verifica comando do jogador
            }
        }

        if ( tecla=='w') {
            bird_y--; // Felipe - faz o passaro ir pra cima
            tecla='0';
        } else {
            bird_y++; // Felipe - Passaro cai uma posição se não pressionar a tecla para subir
        }

        // Felipe - o jogo para quando o passaro tocar uma das extremidades
        if (bird_y == 21 ){
            system("pause");
        } else if (bird_y == -1) {
            system("pause");
        }



        ///VERIFICA COLIS�O
        if (bird_x  == obstaculo_x && (bird_y >= 6 && bird_y <= 9)){ //se a coordenada x do passaro for igual a coordenada x do obstaculo e se a coordenada y  e x do passaro estiverem entre o vão dos pipes, marca 1 ponto
            pontos += 1; // Se o passaro passar no vão entre os pipes, acrescenta 1 ponto

        } else if (bird_x  == obstaculo_x){ // se a afirmação de cima for falsa, então verifica se a coordenada x do passaro é igual a coordenada x do obstaculo, significando a colisão entre eles no ponto onde não tem o vão
            system("pause");
            game_over = true;
        }

        ///TEMPO DE ESPERA
        if (game_over == true){
            system("pause");
        }

        Sleep(150); // Felipe - tempo de espera para rodar o while loop novamente, é a velocidade do jogo
    }


    return 0;
}
