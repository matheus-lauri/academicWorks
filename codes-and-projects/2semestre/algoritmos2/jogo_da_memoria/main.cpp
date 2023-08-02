#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int m_principal[4][4] = {1,4,5,2,
                             7,2,8,7,
                             3,6,1,4,
                             6,5,3,8};
    int m_jogo[4][4] = {0};
    int m_gabarito[4][4], n_jogada, escolha,tipo=0, i, j, pontos = 0, i_coluna = 3, i_linha = 3;
    int linha1, coluna1, linha2, coluna2;
    int carta1, carta2;

    /// Capa do Jogo

  system("CLS");

  cout << "--------------------------------------------------" << endl;
  cout << "--                                              --" << endl;
  cout << "--              Jogo da mem�ria                 --" << endl;
  cout << "--                                              --" << endl;
  cout << "--               Desenvolvido por               --" << endl;
  cout << "--       Elena, Giueseppe, Matheus e Gustavo    --" << endl;
  cout << "--                                              --" << endl;
  cout << "--------------------------------------------------" << endl;

  cout << "\n Selcione o que voc� deseja fazer:" << endl;
  cout << "\n 1 - Manual" << endl;
  cout << " 2 - Jogar" << endl;
  cout << " 3 - Sair" << endl;

  cin >> escolha;

  switch(escolha){

  case 1:
    system("CLS");
    cout << "Seja bem vindo ao Jogo da Memoria, desenvolvido por Elena, Giueseppe, Matheus e Gustavo." << endl;
    system("pause");
    system("CLS");
    cout << "Ent�o, o jogo funciona da seguinte maneira..." << endl;
    system("pause");
    system("CLS");
    cout << "Primeiramente voc� deve fornecer a linha da carta que voc� deseja virar e depois a sua coluna." << endl;
    system("pause");
    system("CLS");
    cout << "Ap�s isso, forne�a as mesmas informa��es para a segunda carta e sucessivamente." << endl;
    system("pause");
    system("CLS");
    cout << "Vou te mostrar pra ficar mais f�cil(primeiro n�mero = linha e segundo n�mero = coluna):" << endl;
    cout << "\n 1.1 1.2 1.3 1.4 \n 2.1 2.2 2.3 2.4 \n 3.1 3.2 3.3 3.4 \n 1.1 2.2 3.3 4.4" << endl;
    cout << "\n " << endl;
    system("pause");
    system("CLS");

    return main();
  break;
  case 2:

    system("cls");

    ///Sele��o da matriz do jogo

    //Semente aleat�ria gerada a partir da hora do sistema
    srand(time(NULL));
    tipo = rand() % 4 ;

    switch(tipo){

        case 0:
            //Matriz sem altera��o
            for(i = 0;i<4;i++){
                for(j = 0;j<4;j++){
                    m_gabarito[i][j] = m_principal[i][j];
                }
            }

        break;
        case 1:
            //Matriz transposta
            for(i = 0;i<4;i++){
                for(j = 0;j<4;j++){
                    m_gabarito[i][j] = m_principal[j][i];
                }
            }

        break;
        case 2:
            //Matriz invertida por linha
             for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    m_gabarito[i][j] = m_principal[i_linha][j];
                    cout << m_gabarito[i][j];
                }
                i_linha--;
                cout << "\n";
            }

        break;
        case 3:
            //Matriz invertida por coluna
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    m_gabarito[i][j] = m_principal[i][i_coluna];
                    i_coluna--;
                    cout << m_gabarito[i][j];
                }
                i_coluna = 3;
                cout << "\n";
            }

        break;
    }

    ///JOGO

    for(n_jogada = 1; n_jogada <= 24; n_jogada++){

        system("cls");

        cout << "Jogada " << n_jogada << " de 24. \n" << endl;

        cout << "Pares encontrados: " << pontos << " de 8\n" << endl;

        //Mostrando a matriz jogo
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << " [" << m_jogo[i][j] << "] ";
            }
        cout << "\n";
        }

        cout << "\nInforme a linha da primeira carta: ";
        cin >> linha1;
        cout << "\nInforme a coluna da primeira carta: ";
        cin >> coluna1;

        //Transforma o valor digitado na forma de �ndice
        linha1--;
        coluna1--;

              //Verifica se o usu�rio j� selecionou uma carta "virada"    //Verifica se o usu�rio digitou uma linha ou coluna maior que a matriz
        while(m_jogo[linha1][coluna1] != 0 || linha1 >= 4 || coluna1 >= 4){
            cout << "\nEssa carta j� foi selecionada ou a linha/coluna n�o existe, insira outra carta!" << endl;
            cout << "\nInforme a linha da primeira carta: "<< endl;
            cin >> linha1;
            cout << "\nInforme a coluna da primeira carta: "<< endl;
            cin >> coluna1;
            cout << "\n" << endl;
            linha1--;
            coluna1--;
        }

        //"Vira" a carta que o usu�rio selecionou
        m_jogo[linha1][coluna1] = m_gabarito[linha1][coluna1];

        //Guarda a carta virada na vari�vel
        carta1 = m_jogo[linha1][coluna1];

        system("cls");

        cout << "Jogada " << n_jogada << " de 24. \n" << endl;

        cout << "Pares encontrados: " << pontos << " de 8\n" << endl;

        //Mostrando a matriz jogo
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << " [" << m_jogo[i][j] << "] ";
            }
        cout << "\n";
        }

        cout << "\nInforme a linha da segunda carta: ";
        cin >> linha2;
        cout << "\nInforme a coluna segunda carta: ";
        cin >> coluna2;

        //Transforma o valor digitado na forma de �ndice
        linha2--;
        coluna2--;

              //Verifica se o usu�rio j� selecionou uma carta "virada"    //Verifica se o usu�rio digitou uma linha ou coluna maior que a matriz
        while(m_jogo[linha2][coluna2] != 0 || linha2 >= 4 || coluna2 >= 4){
            cout << "\nEssa carta j� foi selecionada ou a linha/coluna n�o existe, insira outra carta!" << endl;
            cout << "\nInforme a linha da primeira carta: "<< endl;
            cin >> linha2;
            cout << "\nInforme a coluna da primeira carta: "<< endl;
            cin >> coluna2;
            cout << "\n" << endl;
            linha2--;
            coluna2--;
        }

        //"Vira" a carta que o usu�rio selecionou
        m_jogo[linha2][coluna2] = m_gabarito[linha2][coluna2];

        //Guarda a carta virada na vari�vel
        carta2 = m_jogo[linha2][coluna2];

        system("cls");

        cout << "Jogada " << n_jogada << " de 24. \n" << endl;

        //Mostrando a matriz jogo
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << " [" << m_jogo[i][j] << "] ";
            }
        cout << "\n";
        }

        //Verifica se as duas cartas viradas s�o um par,
        //se for verdade deixa as duas cartas "Viradas",
        //se n�o "vira para baixo" as duas cartas
        if(carta1 == carta2){
            cout << "JOGADA OK" << endl;
            pontos++;
        } else {
            cout << "JOGADA NOK" << endl;
            m_jogo[linha1][coluna1] = 0;
            m_jogo[linha2][coluna2] = 0;
        }

        cout << "Pares encontrados: " << pontos << " de 8" << endl;
        system("pause");

        //Verifica se o usu�rio atingiu o n�mero m�ximo de pontos
        if(pontos == 8){
        system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << "--                                              --" << endl;
        cout << "--           Voce tem memoria boa hein!         --" << endl;
        cout << "--                   Parabens!                  --" << endl;
        cout << "--                                              --" << endl;
        cout << "--------------------------------------------------" << endl;
        n_jogada = 25;
        system("pause");
        }
        //Verifica se o usu�rio atingiu o n�mero m�ximo de jogadas
        if(pontos != 8 && n_jogada >= 25) {
        system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << "--                                              --" << endl;
        cout << "--             Sua memoria falhou!              --" << endl;
        cout << "--                  Game Over!                  --" << endl;
        cout << "--                                              --" << endl;
        cout << "--------------------------------------------------" << endl;
        system("pause");
        }
    }
    return main();
    break;
    case 3:
        ///OP��O SAIR
        system("cls");
        cout << "G O O D B Y E ! ! ! !" << endl;
        return 0;
    break;
  }
}
