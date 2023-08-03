#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define TAM 20

void shell( int vetor[], int inicio, int salto ){
    int j, k, temp;
    bool achei;

    for( int i=(inicio+salto); i<TAM; i+=salto ){
        j = inicio;
        achei = false;
        while( j<i && !achei ){
            if( vetor[i] < vetor[j] )
                achei = true;
            else
                j = j + salto;
        }
        if( achei ){
            temp = vetor[i];
            k = i - salto;
            while( k > (j-salto) ){
                vetor[k+salto] = vetor[k];
                k = k - salto;
            }
            vetor[j] = temp;
        }
    }
}

void shellsort(int vetor[], int np ){
    int inc;

    for( int i=np; i>=0; i-- ){
        inc = pow(2, i);
        for( int j=0; j<inc; j++ ){
            shell( vetor, j, inc );
        }
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
    shellsort( vet, 3 );
    cout << endl;
    cout << "Vetor final: ";
    mostrar(vet);
    cout << endl;
}
