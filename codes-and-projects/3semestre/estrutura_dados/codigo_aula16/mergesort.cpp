#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define TAM 20

void combinar( int vetor[], int comeco, int meio, int fim ){
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux = new int[tam];

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
    while(com1 <= meio){
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }
    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }
    for(comAux = comeco; comAux <= fim; comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }
    delete []vetAux;
}

void mergesort(int vetor[], int inicio, int fim ){
    if( inicio == fim ) return;

    int meio = (inicio+fim) / 2;
    mergesort( vetor, inicio, meio );
    mergesort( vetor, meio+1, fim );
    combinar(vetor, inicio, meio, fim );
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
    mergesort( vet, 0, TAM-1 );
    cout << endl;
    cout << "Vetor final: ";
    mostrar(vet);
    cout << endl;
}
