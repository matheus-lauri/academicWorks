#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define TAM 20

void insercao_direta(int vetor[] ){
    int chave, i;
    for( int j=1; j<TAM; j++ ){
        chave = vetor[j];
        i = j - 1;
        while( i>=0 && vetor[i] > chave ){
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = chave;
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
    insercao_direta( vet );
    cout << endl;
    cout << "Vetor final: ";
    mostrar(vet);
    cout << endl;
}
