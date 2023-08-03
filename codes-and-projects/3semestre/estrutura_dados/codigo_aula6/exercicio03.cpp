#include <iostream>
using namespace std;
#define TAM 50
#include "pilha.h"
#include "fila.h"

template <typename T>
void formatar( Fila <T> f, Fila <T> &res ){
    Pilha <T> p1,p2;
    char aux;
    int cont=0;

    inicializar(p1);
    while( retirar(f, aux) )
        inserir(p1, aux);

    inicializar(p2);

    if( !retirar(p1, aux) ) aux = '0';
    inserir(p2, aux);
    if( !retirar(p1, aux) ) aux = '0';
    inserir(p2, aux);
    inserir(p2, ',' );
    if( !retirar(p1, aux) ) inserir(p2, '0');
    else inserir(p1, aux);

    while( retirar(p1,aux) ) {
        cont++;
        inserir(p2,aux);
        if( cont == 3 ){
            inserir(p2, '.' );
            cont = 0;
        }
    }

    inicializar(res);
    while( retirar(p2, aux) )
        inserir(res, aux);
}

int main(){
    Fila <char> fila, res;
    string num;
    char aux;

    do{
        cout << "Digite um numero (sem espaco e sem virgula - 0-fim): ";
        cin >> num;
        if( num[0] != '0' ){
            inicializar(fila);
            for( int i=0; i<num.length(); i++ )
                inserir(fila, num[i]);
            formatar( fila, res );
            cout << "Resultado: ";
            while( retirar(res, aux) )
                cout << aux;
            cout << endl;
        }
    }while( num[0] != '0' );
    cout << endl;
}
