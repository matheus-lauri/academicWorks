#include <iostream>
#include "meusProcedimentos.h"

using namespace std;

struct Personagem {
    int x=2, y=2;
};

void desenhaMapa(int m[10][10]){
    posicaoxy(0,0); ///posiciona a escrita no console no eixo x,y. A posição 0,0 é a do canto superior esquerdo.
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            switch(m[i][j]){
                case 0:
                    cout<<" "; ///impressão do espaço vazio
                    break;

                case 1:
                    colorir(14);
                    cout<<char(178); ///impressão da parede
                    colorir(7);
                    break;

                case 2:
                    colorir(12);
                    cout<<char(219); ///impressão da caixa
                    colorir(7);
                    break;
                case 3:
                    colorir(9);
                    cout<<char(4); ///impressão do destino da caixa
                    colorir(7);
                    break;
                case 4:
                    colorir(11);
                    cout<<char(219); ///impressão da caixa no destino
                    colorir(7);
                    break;

                case 9:
                    colorir(10); ///colorir faz com que a escrita a seguir seja com a cor número 10
                    cout<<char(2); ///impressão do personagem.
                    colorir(7); ///retorna a cor original após o fim da escrita
                    break;
            } ///switch

        }
        cout<<"\n";
    } ///for i

}

void movimento (int m[10][10], Personagem &p){
    char tecla;
    Personagem pa; ///guarda a posição antiga
    pa=p;
    if (_kbhit()){
        tecla=getch();
        switch(tecla){
            case 72: p.x--; break;
            case 80: p.x++; break;
            case 75: p.y--; break;
            case 77: p.y++; break;
        }
        m[pa.x][pa.y]=0; ///tira o personagem da posição antiga
        m[p.x][p.y]=9; ///coloca o personagem na posição nova
    }
}

int main()
{
    Personagem p;
    mostrarCursor(false);
    int m[10][10]={ 1,1,1,1,1,1,0,0,0,0,
                    1,0,0,0,0,1,0,0,0,0,
                    1,0,9,2,0,1,1,1,1,1,
                    1,0,0,0,0,0,0,0,0,1,
                    1,0,0,0,0,2,2,0,0,1,
                    1,0,0,0,0,2,0,1,3,1,
                    1,1,1,0,1,0,0,1,3,1,
                    1,0,0,0,0,0,0,1,3,1,
                    1,0,0,0,0,0,0,1,3,1,
                    1,1,1,1,1,1,1,1,1,1  };

    while(true){
        desenhaMapa(m);
        movimento(m, p);
    }


    return 0;
}
