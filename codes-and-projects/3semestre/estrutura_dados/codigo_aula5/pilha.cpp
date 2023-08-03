#include <iostream>
using namespace std;
#define TAM 50
#include "pilha.h";

int main(){
    Pilha <char> p1, p2;
    char aux;

    inicializar(p1);
    inserir(p1, 'P');
    inserir(p1, 'E');
    inserir(p1, 'R');
    inserir(p1, 'N');
    inserir(p1, 'A');
    inserir(p1, 'M');
    inserir(p1, 'B');
    inserir(p1, 'U');
    inserir(p1, 'C');
    inserir(p1, 'O');

    inicializar(p2);

    cout << "Pilha 1: ";
    while( retirar(p1, aux) ){
        cout << "  " << aux;
        inserir(p2,aux);
    }
    cout << endl;
    cout << "Pilha 2: ";
    while( retirar(p2, aux) ){
        cout << "  " << aux;
    }
    cout << endl;
}


