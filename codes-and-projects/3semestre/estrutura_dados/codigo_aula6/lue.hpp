//
// Lista Unicamente Encadeada Genérica
//

#include <iostream>

template <typename T>
struct No{
    T info;
    No *elo;
};

template <typename T>
struct LUE{
    No<T> *comeco, *fim;
};

template <typename T>
void inicializarLUE(LUE <T> &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
}

template <typename T>
void mostrarLUE(LUE <T> lista, char frase[]){
    std::cout << frase << ": ";
    if( lista.comeco == NULL ) std::cout << " vazia";

    No <T> *aux = lista.comeco;
    while( aux != NULL ){
        std::cout << aux->info << " ";
        aux = aux->elo;
    }
}

template <typename T>
bool inserirLUE( LUE <T> &lista, T valor ){
    No <T> *novo = new No<T>;

    if( novo == NULL ) return false;
    novo->info = valor;
    novo->elo = NULL;

    // Inserir em lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    // Inserir no inicio da lista
    if( valor < lista.comeco->info ){
        novo->elo = lista.comeco;
        lista.comeco = novo;
        return true;
    }

    // Inserir no final da lista
    if( valor > lista.fim->info ){
        lista.fim->elo = novo;
        lista.fim = novo;
        return true;
    }

    // Inserir no meio da lista
    No <T> *aux = lista.comeco;
    while( aux->info < valor && aux->elo->info < valor )
        aux = aux->elo;
    novo->elo = aux->elo;
    aux->elo = novo;
    return true;
}

template <typename T>
bool inserirFinalLUE( LUE <T> &lista, T valor ){
    No <T> *novo = new No <T>;

    if( novo == NULL ) return false;
    novo->info = valor;
    novo->elo = NULL;

    // Inserir em lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
    } else {
        lista.fim->elo = novo;
        lista.fim = novo;
    }
    return true;
}

template <typename T>
No <T> *buscarLUE( LUE <T> lista, T valor ){
    No <T> *aux = lista.comeco;
    while( aux != NULL ){
        if( aux->info == valor ) return aux;
        aux = aux->elo;
    }
    return NULL;
}

template <typename T>
bool retirarLUE( LUE <T> &lista, T valor ){
    No <T> *ant=NULL, *pos;

    pos = lista.comeco;
    while( pos != NULL && pos->info != valor ){
        ant = pos;
        pos = pos->elo;
    }
    if( pos == NULL ) return false;  // Lista vazia ou valor não encontrado

    // Retirada no inicio da lista
    if( pos == lista.comeco ){
        lista.comeco = lista.comeco->elo;
        if( pos == lista.fim ) lista.fim = NULL;
    }
    else{
        ant->elo = pos->elo;
        if( pos == lista.fim ) lista.fim = ant;
    }
    delete( pos );
    return true;
}

