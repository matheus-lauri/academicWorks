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
    int m_jogo[4][4] = {0,0,0,0,
                         0,0,0,0,
                         0,0,0,0,
                         0,0,0,0};
    int m_gabarito[4][4], n_jogada, escolha,tipo=0, i, j, pontos = 0;
    int linha1, coluna1, linha2, coluna2;
    int carta1, carta2;

    /// Capa do Jogo

  system("CLS");

  cout << "--------------------------------------------------" << endl;
  cout << "--                                              --" << endl;
  cout << "--              Jogo da memória                 --" << endl;
  cout << "--                                              --" << endl;
  cout << "--              Desenvolvido por                --" << endl;
  cout << "--           Matheus Baron Lauritzen            --" << endl;
  cout << "--                                              --" << endl;
  cout << "--------------------------------------------------" << endl;

  cout << "\n Selcione o que você deseja fazer:" << endl;
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
    cout << "Então, o jogo funciona da seguinte maneira..." << endl;
    system("pause");
    system("CLS");
    cout << "Primeiramente você deve fornecer a linha da carta que você deseja virar e depois a sua coluna." << endl;
    system("pause");
    system("CLS");
    cout << "Após isso, forneça as mesmas informações para a segunda carta e sucessivamente." << endl;
    system("pause");
    system("CLS");
    cout << "Vou te mostrar pra ficar mais fácil(primeiro número = linha e segundo número = coluna):" << endl;
    cout << "\n 1.1 1.2 1.3 1.4 \n 2.1 2.2 2.3 2.4 \n 3.1 3.2 3.3 3.4 \n 1.1 2.2 3.3 4.4" << endl;
    cout << "\n " << endl;
    system("pause");
    system("CLS");

    return main();
  break;
  case 2:

    system("cls");

    ///Seleção da matriz do jogo

    //Semente aleatória gerada a partir da hora do sistema
    srand(time(NULL));
    tipo = rand() % 4 ;

    switch(tipo){

        case 0:
            //Matriz sem alteração
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
            for(i = 0;i<4;i++){
                for(j = 0;j<4;j++){
                    if(i == 0){
                    m_gabarito [i][j] = m_principal [i+3][j];
                    }
                    if(i == 1){
                    m_gabarito [i][j] = m_principal [i+1][j];
                    }
                    if(i == 2){
                    m_gabarito [i][j] = m_principal [i-1][j];
                    }
                    if(i == 3){
                    m_gabarito [i][j] = m_principal [i-3][j];
                    }
                }
            }

        break;
        case 3:
            //Matriz invertida por coluna
            for(i = 0;i<4;i++){
                for(j = 0;j<4;j++){
                    if(j == 0){
                    m_gabarito [i][j] = m_principal [i][j+3];
                    }
                    if(j == 1){
                    m_gabarito [i][j] = m_principal [i][j+1];
                    }
                    if(j == 2){
                    m_gabarito [i][j] = m_principal [i][j-1];
                    }
                    if(j == 3){
                    m_gabarito [i][j] = m_principal [i][j-3];
                    }
                }
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

        //Transforma o valor digitado na forma de índice
        linha1--;
        coluna1--;

              //Verifica se o usuário já selecionou uma carta "virada"    //Verifica se o usuário digitou uma linha ou coluna maior que a matriz
        while(m_jogo[linha1][coluna1] != 0 && (linha1 <= 4 || coluna1 <= 4) || linha1 >= 4 || coluna1 >= 4){
            cout << "\nEssa carta já foi selecionada ou a linha/coluna não existe, insira outra carta!" << endl;
            cout << "\nInforme a linha da primeira carta: "<< endl;
            cin >> linha1;
            cout << "\nInforme a coluna da primeira carta: "<< endl;
            cin >> coluna1;
            cout << "\n" << endl;
            linha1--;
            coluna1--;
        }

        //"Vira" a carta que o usuário selecionou
        m_jogo[linha1][coluna1] = m_gabarito[linha1][coluna1];

        //Guarda a carta virada na variável
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

        //Transforma o valor digitado na forma de índice
        linha2--;
        coluna2--;

              //Verifica se o usuário já selecionou uma carta "virada"    //Verifica se o usuário digitou uma linha ou coluna maior que a matriz
        while(m_jogo[linha2][coluna2] != 0 && (linha2 <= 4 || coluna2 <= 4) || linha2 >= 4 || coluna2 >= 4){
            cout << "\nEssa carta já foi selecionada ou a linha/coluna não existe, insira outra carta!" << endl;
            cout << "\nInforme a linha da primeira carta: "<< endl;
            cin >> linha2;
            cout << "\nInforme a coluna da primeira carta: "<< endl;
            cin >> coluna2;
            cout << "\n" << endl;
            linha2--;
            coluna2--;
        }

        //"Vira" a carta que o usuário selecionou
        m_jogo[linha2][coluna2] = m_gabarito[linha2][coluna2];

        //Guarda a carta virada na variável
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

        //Verifica se as duas cartas viradas são um par,
        //se for verdade deixa as duas cartas "Viradas",
        //se não "vira para baixo" as duas cartas
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

        //Verifica se o usuário atingiu o número máximo de pontos
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
        //Verifica se o usuário atingiu o número máximo de jogadas
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
        ///OPÇÃO SAIR
        system("cls");
        cout << "G O O D B Y E ! ! ! !" << endl;
        return 0;
    break;
  }
}
