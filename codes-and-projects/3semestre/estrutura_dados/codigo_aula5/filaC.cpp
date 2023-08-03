#include <iostream>
using namespace std;
#define TAM 5
#include "filaC.h";

int main(){
    Fila <char> f1, f2;
    char aux;

    inicializar(f1);
    if( !inserir(f1, 'P') ) cout << "Fila cheia P" << endl;
    if( !inserir(f1, 'E') ) cout << "Fila cheia E" << endl;
    if( !inserir(f1, 'R') ) cout << "Fila cheia R" << endl;
    if( !inserir(f1, 'N') ) cout << "Fila cheia N" << endl;
    if( !inserir(f1, 'A') ) cout << "Fila cheia A" << endl;
    retirar(f1,aux);
    retirar(f1,aux);
    if( !inserir(f1, 'M') ) cout << "Fila cheia M" << endl;
    if( !inserir(f1, 'B') ) cout << "Fila cheia B" << endl;
    if( !inserir(f1, 'U') ) cout << "Fila cheia U" << endl;

    inicializar(f2);

    cout << "Fila 1: ";
    while( retirar(f1, aux) ){
        cout << "  " << aux;
        inserir(f2,aux);
    }
    cout << endl;
    cout << "Fila 2: ";
    while( retirar(f2, aux) ){
        cout << "  " << aux;
    }
    cout << endl;
}


