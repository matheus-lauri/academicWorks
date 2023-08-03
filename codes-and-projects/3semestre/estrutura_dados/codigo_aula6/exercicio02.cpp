#include <iostream>
using namespace std;
#define TAM 50
#include "pilha.h"

template <typename T>
void decompor_numero( int num, Pilha <T> &p){
    int limite = num/2;
    int i = 2;
    inicializar(p);

    while( num > 1 ){
        if( num % i == 0 ){
            inserir(p, i);
            num = num / i;
        }
        else
            i++;
    }
}

int main(){
    Pilha <int> p;
    int num, aux;

    do{
        do{
            cout << "Digite um numero positivo (0 ou 1-fim): ";
            cin >> num;
        }while( num < 0 );
        if( num > 1 ){
            decompor_numero(num, p);
            cout << "Decomposicao: ";
            while( retirar(p, aux) )
                cout << aux << "  ";
            cout << endl;
        }
    }while( num > 1 );
    cout << endl;
}
