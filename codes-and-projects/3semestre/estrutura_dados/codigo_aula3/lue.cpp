#include <iostream>
using namespace std;

struct No{
    char info;
    No *elo;
};

struct LUE{
    No *comeco;
    No *fim;
};

void inicializarLUE(LUE &lst){
    lst.comeco = NULL;
    lst.fim = NULL;
}

bool inserirFinalLUE(LUE &lst, char valor){
    No *novo = new No;
    if( novo == NULL ) return false;

    novo->info = valor;
    novo->elo = NULL;
    if( lst.comeco == NULL ){
        lst.comeco = novo;
        lst.fim = novo;
    }
    else{
        lst.fim->elo = novo;
        lst.fim = novo;
    }
    return true;
}

bool inserirLUE(LUE &lst, char valor ){
    No *novo = new No;
    if( novo == NULL ) return false;

    novo->info = valor;
    novo->elo = NULL;

    // Lista vazia
    if( lst.comeco == NULL ){
        lst.comeco = novo;
        lst.fim = novo;
        return true;
    }

    // Inserir no inicio
    if( valor < lst.comeco->info ){
        novo->elo = lst.comeco;
        lst.comeco = novo;
        return true;
    }

    // Inserir no final
    if( valor > lst.fim->info ){
        lst.fim->elo = novo;
        lst.fim = novo;
        return true;
    }

    No *aux = lst.comeco;
    while( valor > aux->info && valor > aux->elo->info){
        aux = aux->elo;
    }
    novo->elo = aux->elo;
    aux->elo = novo;
    return true;
}

void mostrarLUE(LUE lst, char frase[] ){
    No *aux;

    cout << frase << ": ";
    aux = lst.comeco;
    while( aux != NULL ){
        cout << aux->info << "  ";
        aux = aux->elo;
    }
    cout << endl;
}

No *buscarLUE( LUE lst, char valor ){
    No *aux = lst.comeco;
    while( aux != NULL ){
        if( aux->info == valor ) return aux;
        aux = aux->elo;
    }
    return NULL;
}

bool retirarLUE( LUE &lst, char valor ){
    No *aux, *ant;

    aux = lst.comeco;
    ant = NULL;
    while( aux != NULL && aux->info != valor ){
        ant = aux;
        aux = aux->elo;
    }
    if( aux == NULL ) return false; // Valor não encontrado

    if( aux == lst.comeco ){
        lst.comeco =  aux->elo;
        if( aux == lst.fim ) lst.fim = aux->elo;
    }
    else{
        ant->elo = aux->elo;
        if( aux == lst.fim ) aux = ant;
    }
    delete aux;
    return true;
}

int main(){

    LUE lista1;
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

    LUE lista2;
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

    retirarLUE(lista2, 'B');
    retirarLUE(lista2, 'M');
    retirarLUE(lista2, 'E');
    retirarLUE(lista2, 'P');
    mostrarLUE(lista2, "Lista 2" );

    if( buscarLUE(lista2, 'X') == NULL )
        cout << "Nao encontrado" << endl;
    else
        cout << "Encontrado" << endl;

}
