#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define TAM 20

void bolha(int vetor[] ){
    int lim=TAM-1, aux, k;
    bool troca = true;
    while( troca ){
        troca = false;
        for( int i=0; i<=lim; i++ ){
            if( vetor[i] > vetor[i+1] ){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                k = i;
                troca = true;
            }
        }
        lim = k;
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
    bolha( vet );
    cout << endl;
    cout << "Vetor final: ";
    mostrar(vet);
    cout << endl;
}
