#include <iostream>
using namespace std;
#define TAM 50
#include "pilha.h"
#include "fila.h"

template <typename T>
void inverter_fila( Fila <T> &f ){
    Pilha <T> p;
    T aux;

    inicializar(p);
    while( retirar(f, aux) )
        inserir(p,aux);
    inicializar(f);
    while( retirar(p, aux) )
        inserir(f,aux);
}

int main(){
    Fila <int> f;
    int aux;

    inicializar(f);
    do{
        cout << "Digite um numero (0-fim): ";
        cin >> aux;
        if( aux != 0 ) inserir(f, aux);
    }while( aux != 0 );

    inverter_fila(f);

    cout << "Resultado: ";
    while( retirar(f, aux) )
        cout << aux << "  ";
    cout << endl;
}
