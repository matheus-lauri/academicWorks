#include <iostream>
using namespace std;
#include "lue.hpp";

int main(){

    LUE <char> lista1;
    inicializarLUE(lista1);
    inserirFinalLUE(lista1, 'P');
    inserirFinalLUE(lista1, 'E');
    inserirFinalLUE(lista1, 'R');
    inserirFinalLUE(lista1, 'N');
    inserirFinalLUE(lista1, 'A');
    inserirFinalLUE(lista1, 'M');
    inserirFinalLUE(lista1, 'B');
    inserirFinalLUE(lista1, 'U');
    inserirFinalLUE(lista1, 'C');
    inserirFinalLUE(lista1, 'O');
    mostrarLUE(lista1, "Lista 1" );

    LUE <char> lista2;
    inicializarLUE(lista2);
    inserirLUE(lista2, 'P');
    inserirLUE(lista2, 'E');
    inserirLUE(lista2, 'R');
    inserirLUE(lista2, 'N');
    inserirLUE(lista2, 'A');
    inserirLUE(lista2, 'M');
    inserirLUE(lista2, 'B');
    inserirLUE(lista2, 'U');
    inserirLUE(lista2, 'C');
    inserirLUE(lista2, 'O');
    mostrarLUE(lista2, "Lista 2" );
    cout << endl;

    retirarLUE(lista2, 'B');
    retirarLUE(lista2, 'M');
    retirarLUE(lista2, 'E');
    retirarLUE(lista2, 'P');
    mostrarLUE(lista2, "Lista 2" );
    cout << endl;

    if( buscarLUE(lista2, 'X') == NULL )
        cout << "Nao encontrado" << endl;
    else
        cout << "Encontrado" << endl;

}
