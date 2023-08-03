#include <iostream>
using namespace std;

#define TAM 50

struct Lista{
    char item[TAM];
    int ultimo;
};

void inicializarLista( Lista &lst ){
    lst.ultimo = -1;
}

int getUltimo(Lista lst){
    return lst.ultimo;
}

char getValor(Lista lst, int pos){
    return lst.item[pos];
}

bool inserirFinalLista( Lista &lst, char valor ){
    if( lst.ultimo == TAM-1 ) return false;
    lst.ultimo++;
    lst.item[lst.ultimo] = valor;
    return true;
}

bool inserirOrdemLista( Lista &lst, char valor ){
    int pos=0;

    if( lst.ultimo == TAM-1 ) return false;

    while( pos <= lst.ultimo && lst.item[pos] < valor ) pos++;
    lst.ultimo++;
    for( int i=lst.ultimo; i>pos; i-- ) lst.item[i] = lst.item[i-1];
    lst.item[pos] = valor;
    return true;
}

void mostrarLista( Lista lst, char frase[] ){
    cout << frase << ": ";
    for( int i=0; i<=lst.ultimo; i++ ){
        cout << lst.item[i] << " ";
    }
}

int buscarLista( Lista lst, char valor ){
    for( int i=0; i<=lst.ultimo; i++ ){
        if( lst.item[i] == valor ) return i;
    }
    return -1;
}

bool retirarLista( Lista &lst, int pos ){
    if( pos > lst.ultimo ) return false;

    for( int i=pos; i<lst.ultimo; i++ )
        lst.item[i] = lst.item[i+1];
    lst.ultimo--;
    return true;
}

bool retirarLista( Lista &lst, char valor ){
    int pos = buscarLista(lst, valor);
    if( pos == -1 )
        return false;
    else
        retirarLista( lst, pos );
    return true;
}

// Final do TADS

Lista clonarLista( Lista lst ){
    Lista res;
    char aux;

    inicializarLista(res);
    for( int i=0; i<=getUltimo(lst); i++ ){
        aux = getValor(lst,i);
        inserirFinalLista(res, aux);
    }
    return res;
}

Lista combinarListas( Lista l1, Lista l2 ){
    Lista res;

    inicializarLista(res);
    for( int i=0; i<=getUltimo(l1); i++ ){
        inserirOrdemLista(res, getValor(l1, i) );
    }
    for( int i=0; i<=getUltimo(l2); i++ ){
        inserirOrdemLista(res, getValor(l2, i) );
    }
    return res;
}

Lista eliminarRepetidos( Lista lst ){
    Lista res;
    char aux;

    for( int i=0; i<getUltimo(lst); i++ ){
        aux = getValor(lst, i);
        for( int j=i+1; j<=getUltimo(lst); j++ ){
            if( aux == getValor(lst,j) ){
                retirarLista(lst, j);
                j--;
            }
        }
    }

    return lst;
}

int main(){
    Lista lista1;

    inicializarLista(lista1);
    inserirFinalLista(lista1, 'P');
    inserirFinalLista(lista1, 'E');
    inserirFinalLista(lista1, 'R');
    inserirFinalLista(lista1, 'N');
    inserirFinalLista(lista1, 'A');
    inserirFinalLista(lista1, 'M');
    inserirFinalLista(lista1, 'B');
    inserirFinalLista(lista1, 'U');
    inserirFinalLista(lista1, 'C');
    inserirFinalLista(lista1, 'O');
    mostrarLista(lista1, "Lista 1" );
    cout << endl;
    retirarLista(lista1, 'B' );
    retirarLista(lista1, 'M' );
    mostrarLista(lista1, "Lista 1" );
    cout << endl;

    Lista lista2;
    inicializarLista(lista2);
    inserirOrdemLista(lista2, 'P');
    inserirOrdemLista(lista2, 'E');
    inserirOrdemLista(lista2, 'R');
    inserirOrdemLista(lista2, 'N');
    inserirOrdemLista(lista2, 'A');
    inserirOrdemLista(lista2, 'M');
    inserirOrdemLista(lista2, 'B');
    inserirOrdemLista(lista2, 'U');
    inserirOrdemLista(lista2, 'C');
    inserirOrdemLista(lista2, 'O');
    mostrarLista(lista2, "Lista 2" );
    cout << endl;
    retirarLista(lista2, 5 );
    retirarLista(lista2, 4 );
    mostrarLista(lista2, "Lista 2" );
    cout << endl;

    Lista lista3;
    lista3 = clonarLista(lista2);
    mostrarLista(lista3, "Lista 3" );
    cout << endl;

    Lista lista4 = combinarListas(lista1,lista2);
    mostrarLista(lista4, "Lista 4" );
    cout << endl;

    inserirOrdemLista(lista4, 'C');
    inserirOrdemLista(lista4, 'C');
    Lista lista5 = eliminarRepetidos(lista4);
    mostrarLista(lista5, "Lista 5" );
    cout << endl;

    if( buscarLista(lista1, 'X') == -1 )
        cout << "Nao encontrado";
    else
        cout << "Encontrado";
    cout << endl;

}
