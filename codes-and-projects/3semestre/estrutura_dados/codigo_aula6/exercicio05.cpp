#include <iostream>
using namespace std;
#define TAM 50
#include "pilha.h"
#include "fila.h"

template <typename T>
bool eh_palindromo( Fila <T> f ){
    Fila <T> f1;
    Pilha <T> p1;
    char aux1, aux2;

    inicializar(f1);
    inicializar(p1);
    while( retirar(f, aux1) ){
        inserir(f1, aux1);
        inserir(p1, aux1);
    }

    while( retirar(f1,aux1) && retirar(p1,aux2) ){
        if( aux1 != aux2 )return false;
    }
    return true;
}

int main(){
    Fila <char> fila;
    string frase;

    do{
        cout << "Digite uma frase (0-fim): ";
        getline(cin, frase);
        if( frase[0] != '0' ){
            inicializar(fila);
            for( int i=0; i<frase.length(); i++ ){
                if( frase[i] != ' ' ) inserir(fila, frase[i]);
            }
            if( eh_palindromo(fila) )
                cout << "Essa frase eh um palindromo" << endl;
            else
                cout << "Essa frase nao eh um palindromo" << endl;
        }
    }while( frase[0] != '0' );
    cout << endl;
}
