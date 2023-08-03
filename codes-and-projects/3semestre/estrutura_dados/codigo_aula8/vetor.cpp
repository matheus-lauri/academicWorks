#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define TAM 15

void ordena(int vetor[] ){
    bool flag=true;
    int aux;

    while( flag ){
        flag = false;
        for( int i=0; i<TAM-1; i++ ){
            if( vetor[i] > vetor[i+1] ){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                flag = true;
            }
        }
    }
}

int pesquisar( int vetor[], int num, int inicio, int fim ){
    if( inicio > fim ) return -1;

    int meio = (inicio+fim)/2;
    if( vetor[meio] == num ) return meio;
    if( num < vetor[meio] )
        return pesquisar(vetor, num, inicio, meio-1 );
    else
        return pesquisar(vetor, num, meio+1, fim );
}

int main(){
    srand(time(NULL));
    int v[TAM], num, pos;

    for( int i=0; i<TAM; i++ ){
        v[i] = rand() % 100;
    }
    ordena(v);

    cout << "Vetor: ";
    for( int i=0; i<TAM; i++ ){
        cout << v[i] << "  ";
    }
    cout << endl;

    do{
        cout << "Numero a buscar: ";
        cin >> num;
    }while( num < 0);

    pos = pesquisar(v, num, 0, TAM-1);
    if( pos == -1 )
        cout << "O numero " << num << " nao se encontra no vetor";
    else
        cout << "O numero " << num << " esta na posicao em v[" << pos << "]";
    cout << endl;
}
