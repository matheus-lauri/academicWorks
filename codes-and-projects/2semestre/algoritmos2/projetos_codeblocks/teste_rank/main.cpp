#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <ctime>
#include <string>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>


using namespace std;

struct PLAYER {
    int x, y, campo= 3, blind=0;
    bool andar=1, ver=1;
    float Dvisao, Dfreeze;
    string nome = "Player";

    //Define as coordenadas x e y do player para linha e coluna da matriz
    void coord (int li, int co){
        x=li;
        y=co;
    }
    //Imobiliza o player
    void parar(float temp){
        //Tira a condição de andar
        andar=0;
        //Armazena o instante em que o jogador andou em cima do buff
        Dfreeze= temp;
    }
    //O player volta a andar
    void rebuff_andar(float temp)
    {
        //Verifica se o tempo do congelamento acabou
        if(Dfreeze < temp - 5.0)
        {
            //Define a codição de andar igual a true
            andar=1;
        }
    }
    //Diminui o campo de visão do player
    void cegar(int range,float temp){
        system("cls");
        ver = 0;
        //Diminui o campo de visão a partir de um novo range
        campo = campo-range;
        blind = range;
        //Armazena o instante em que o jogador andou em cima do buff
        Dvisao = temp;
    }
    //Define o campo de visão ao normal
    void rebuff_visao(float temp)
    {
        //Verifica se o tempo do campo de visão reduzido acabou
        if(Dvisao < temp - 5.0)
        {
            //Campo de visão volta ao tamanho normal
            campo= campo + blind;
            blind=0;
            ver=1;
        }
    }
};

void bubble (int v[], int t, string v2[]){
    int temp;
    string temp2;
    for (int i=0;i<t;i++){
        for (int j=0;j<t-1;j++){
            if(v[j]<v[j-1]){
                //ordenando vetor com os tempos
                temp=v[j];
                v[j]=v[j-1];
                v[j-1]=temp;
                //ordenando vetor com os nomes
                temp2=v2[j];
                v2[j]=v2[j-1];
                v2[j-1]=temp2;
            }
        }
    }
}

void show_order_rank(PLAYER p)
{
    int i = 0;
    int v_temp[10] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
    string v_nomes[10];

    v_nomes[0] = "none";
    v_nomes[1] = "none";
    v_nomes[2] = "none";
    v_nomes[3] = "none";
    v_nomes[4] = "none";
    v_nomes[5] = "none";
    v_nomes[6] = "none";
    v_nomes[7] = "none";
    v_nomes[8] = "none";
    v_nomes[9] = "none";

    //lendo tempos
    ifstream tempo;
    tempo.open("tempo.txt");
    char c;
    while(tempo.eof() == false){
        tempo >> c;
        v_temp[i] = (c-48)*10;
        tempo >> c;
        v_temp[i] = v_temp[i] + (c-48);
        i++;
    }
    tempo.close();

    //lendo nomes
    ifstream nome;
    nome.open("nome.txt");
    int j = 0;
    while(nome.eof() == false){
        getline(nome,v_nomes[j]);
        j++;
    }

    nome.close();

    //ordenando nomes e tempos
    bubble(v_temp, i, v_nomes);


    cout << "------------RANK------------" << endl;

    for(int i = 0; i < 10; i++){
        cout << "|| " << v_nomes[i] << " || " << v_temp[i]/60 << " : " << v_temp[i]%60 << " ||" << endl;
    }

    system("pause");

}

void save_rank(PLAYER p, float temp)
{
    cout << "Digite um nome para salvar no rank:\n";
    cin >> p.nome;

    ofstream ranque;
    ranque.open ("tempo.txt", ios_base::app);
    if (temp < 10)
        ranque << '0';
    ranque << int(temp) << endl;
    ranque.close();

    ranque.open ("nome.txt", ios_base::app);
    ranque << p.nome << endl;
    ranque.close();

    show_order_rank(p);
}

int main()
{
    PLAYER p;
    float temp = 8.48;

    save_rank(p,temp);

    return 0;
}
