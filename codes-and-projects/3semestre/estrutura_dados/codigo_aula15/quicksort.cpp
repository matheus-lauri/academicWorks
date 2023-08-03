#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define TAM 20

void quicksort(int vetor[], int esq, int dir  ){
    int x, i, j, aux;
    i = esq;
    j = dir;
    x = vetor[(i+j)/2];
    do{
        while( x > vetor[i] ) i = i + 1;
        while( x < vetor[j] ) j = j -1;
        if( i <= j ){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while( i<= j );
    if( esq < j ) quicksort(vetor, esq, j);
    if( dir > i ) quicksort(vetor, i, dir);
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
    quicksort( vet, 0, TAM-1 );
    cout << endl;
    cout << "Vetor final: ";
    mostrar(vet);
    cout << endl;
}
