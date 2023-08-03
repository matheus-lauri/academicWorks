#include <iostream>
using namespace std;
#define TAM 50
#include "pilha.h"

template <typename T>
void juntarPilhas( Pilha <T> p1, Pilha <T> p2, Pilha <T> &p3 ){
    T aux1, aux2;
    bool flag1, flag2;

    inicializar(p3);
    flag1 = retirar(p1, aux1);
    flag2 = retirar(p2, aux2);
    while( flag1 || flag2 ){

        if( flag1 && flag2 ){ // Retirou das duas
            if( aux1 < aux2 ){
                inserir(p3, aux1);
                flag1 = retirar(p1, aux1);
            }
            else{
                inserir(p3, aux2);
                flag2 = retirar(p2, aux2);
            }
        }
        else{
            if( !flag1 && flag2 ){ // Retirou somente da 2
                inserir(p3, aux2);
                flag2 = retirar(p2, aux2);
            }
            else{ // Retirou somente da 1
                inserir(p3, aux1);
                flag1 = retirar(p1, aux1);
            }
        }
    }
}

int main(){
    Pilha <int> p1, p2, p3;
    int aux;

    inicializar(p1);
    inserir(p1, 8);
    inserir(p1, 6);
    inserir(p1, 4);
    inserir(p1, 2);

    inicializar(p2);
    inserir(p2, 10);
    inserir(p2, 9);
    inserir(p2, 3);

    juntarPilhas( p1, p2, p3 );

    cout << "Pilha 3: ";
    while( retirar(p3, aux) )
        cout << aux << "  ";
    cout << endl;
}
