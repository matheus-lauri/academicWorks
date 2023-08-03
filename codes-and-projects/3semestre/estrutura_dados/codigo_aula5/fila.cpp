#include <iostream>
using namespace std;
#define TAM 50
#include "fila.h";

int main(){
    Fila <char> f1, f2;
    char aux;

    inicializar(f1);
    inserir(f1, 'P');
    inserir(f1, 'E');
    inserir(f1, 'R');
    inserir(f1, 'N');
    inserir(f1, 'A');
    inserir(f1, 'M');
    inserir(f1, 'B');
    inserir(f1, 'U');
    inserir(f1, 'C');
    inserir(f1, 'O');

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


