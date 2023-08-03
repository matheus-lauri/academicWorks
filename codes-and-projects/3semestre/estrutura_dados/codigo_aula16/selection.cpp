#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define TAM 20

void selecao(int vetor[] ){
    int pos_menor, temp;

    for( int i=0; i<TAM-1; i++ ){
        pos_menor = i;
        for( int j=i+1; j<TAM; j++ ){
            if( vetor[j] < vetor[pos_menor] ) pos_menor = j;
        }
        temp = vetor[i];
        vetor[i] = vetor[pos_menor];
        vetor[pos_menor] = temp;
    }
}

void preencher( int vetor[], int maximo ){
    srand( time(NULL) );
    for( int i=0; i<TAM; i++ ){
        vetor[i] = rand() % maximo;
    }
}

void mostrar( int vetor[] ){
    for( int i=0; i<TAM; i++ ){
        cout << vetor[i] << " ";
    }
}

int main(){
    int vet[TAM];

    preencher(vet, 100);
    cout << "Vetor inicial: ";
    mostrar(vet);
    selecao( vet );
    cout << endl;
    cout << "Vetor final: ";
    mostrar(vet);
    cout << endl;
}
