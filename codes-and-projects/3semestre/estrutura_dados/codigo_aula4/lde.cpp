#include <iostream>
using namespace std;

struct No{
    char info;
    No *eloA, *eloP;
};

struct LDE{
    No *comeco;
    No *fim;
};

void inicializarLDE(LDE &lst){
    lst.comeco = NULL;
    lst.fim = NULL;
}

bool inserirFinalLDE(LDE &lst, char valor){
    No *novo = new No;
    if( novo == NULL ) return false;

    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    if( lst.comeco == NULL ){
        lst.comeco = novo;
        lst.fim = novo;
    }
    else{
        lst.fim->eloP = novo;
        novo->eloA = lst.fim;
        lst.fim = novo;
    }
    return true;
}

bool inserirLDE(LDE &lst, char valor ){
    No *novo = new No;
    if( novo == NULL ) return false;

    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    // Lista vazia
    if( lst.comeco == NULL ){
        lst.comeco = novo;
        lst.fim = novo;
        return true;
    }

    // Inserir no inicio
    if( valor < lst.comeco->info ){
        novo->eloP = lst.comeco;
        lst.comeco->eloA = novo;
        lst.comeco = novo;
        return true;
    }

    // Inserir no final
    if( valor > lst.fim->info ){
        lst.fim->eloP = novo;
        novo->eloA = lst.fim;
        lst.fim = novo;
        return true;
    }

    No *aux = lst.comeco;
    while( valor > aux->info && valor > aux->eloP->info){
        aux = aux->eloP;
    }
    // Inserir no meio da lista
    No *prox = aux->eloP;
    novo->eloA = aux;
    novo->eloP = prox;
    aux->eloP = novo;
    prox->eloA = novo;
    return true;
}

void mostrarLDE(LDE lst, char frase[] ){
    No *aux;

    cout << frase << ": ";
    aux = lst.comeco;
    while( aux != NULL ){
        cout << aux->info << "  ";
        aux = aux->eloP;
    }
    cout << endl;
}

No *buscarLDE( LDE lst, char valor ){
    No *aux = lst.comeco;
    while( aux != NULL ){
        if( aux->info == valor ) return aux;
        aux = aux->eloP;
    }
    return NULL;
}

bool retirarLDE( LDE &lst, char valor ){
    No *aux, *ant, *prox;

    aux = buscarLDE(lst, valor);
    if( aux == NULL ) return false; // Valor não encontrado

    ant = aux->eloA;
    prox = aux->eloP;

    // Remover o primeiro ou unico
    if( aux == lst.comeco ){
        lst.comeco = prox;
        if( aux == lst.fim ) lst.fim = prox;
        else prox->eloA = NULL;
    }
    else{
        ant->eloP = aux->eloP;
        if( aux == lst.fim ) lst.fim = ant;
        else prox->eloA = ant;
    }
    delete aux;
    return true;
}

int main(){

    LDE lista1;
    inicializarLDE(lista1);
    inserirFinalLDE(lista1, 'P');
    inserirFinalLDE(lista1, 'E');
    inserirFinalLDE(lista1, 'R');
    inserirFinalLDE(lista1, 'N');
    inserirFinalLDE(lista1, 'A');
    inserirFinalLDE(lista1, 'M');
    inserirFinalLDE(lista1, 'B');
    inserirFinalLDE(lista1, 'U');
    inserirFinalLDE(lista1, 'C');
    inserirFinalLDE(lista1, 'O');
    mostrarLDE(lista1, "Lista 1" );

    LDE lista2;
    inicializarLDE(lista2);
    inserirLDE(lista2, 'P');
    inserirLDE(lista2, 'E');
    inserirLDE(lista2, 'R');
    inserirLDE(lista2, 'N');
    inserirLDE(lista2, 'A');
    inserirLDE(lista2, 'M');
    inserirLDE(lista2, 'B');
    inserirLDE(lista2, 'U');
    inserirLDE(lista2, 'C');
    inserirLDE(lista2, 'O');
    mostrarLDE(lista2, "Lista 2" );

    retirarLDE(lista2, 'B');
    retirarLDE(lista2, 'M');
    retirarLDE(lista2, 'E');
    retirarLDE(lista2, 'P');
    mostrarLDE(lista2, "Lista 2" );

    if( buscarLDE(lista2, 'X') == NULL )
        cout << "Nao encontrado" << endl;
    else
        cout << "Encontrado" << endl;

}
