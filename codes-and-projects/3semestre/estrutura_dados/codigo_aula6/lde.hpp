//
// Lista Unicamente Encadeada Genérica
//
#include <iostream>

template <typename T>
struct No{
    T info;
    No *eloA, *eloP;
};

template <typename T>
struct LDE{
    No <T> *comeco, *fim;
};

template <typename T>
void inicializarLDE(LDE <T> &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
}

// A variável sentido pode ser C(crescente) ou D(decrescente)
template <typename T>
void mostrarLDE(LDE <T> lista, char frase[], char sentido='C'){
    std::cout << frase << ": ";
    if( lista.comeco == NULL ) std::cout << " vazia";

    No<T> *aux = (sentido == 'C') ? lista.comeco : lista.fim;
    while( aux != NULL ){
        std::cout << aux->info << " ";
        aux = (sentido == 'C') ? aux->eloP : aux->eloA;
    }
}

template <typename T>
bool inserirLDE( LDE <T> &lista, char valor ){
    No <T> *novo = new No <T>;

    if( novo == NULL ) return false;
    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    // Inserir em lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    // Inserir no inicio da lista
    if( valor < lista.comeco->info ){
        novo->eloP = lista.comeco;
        lista.comeco->eloA = novo;
        lista.comeco = novo;
        return true;
    }

    // Inserir no final da lista
    if( valor > lista.fim->info ){
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
        return true;
    }

    // Inserir no meio da lista
    No <T> *aux = lista.comeco;
    while( aux->info < valor && aux->eloP->info < valor )
        aux = aux->eloP;
    novo->eloP = aux->eloP;
    novo->eloA = aux;
    aux->eloP->eloA = novo;
    aux->eloP = novo;
    return true;
}

template <typename T>
bool inserirFinalLDE( LDE <T> &lista, T valor ){
    No <T> *novo = new No <T>;

    if( novo == NULL ) return false;
    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    // Inserir em lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
    } else {
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
    }
    return true;
}

template <typename T>
No <T> *buscarLDE( LDE <T> lista, char valor ){
    No <T> *aux = lista.comeco;
    while( aux != NULL ){
        if( aux->info == valor ) return aux;
        aux = aux->eloP;
    }
    return NULL;
}

template <typename T>
bool retirarLDE( LDE <T> &lista, char valor ){
    No <T> *pos;

    pos = buscarLDE(lista,valor);
    if( pos == NULL ) return false;  // Lista vazia ou valor não encontrado

    // Retirada no inicio da lista
    if( pos == lista.comeco ){
        No <T> *prox = pos->eloP; // Pega o próximo nó
        lista.comeco = prox;
        if( prox != NULL ) prox->eloA = NULL;
        if( pos == lista.fim ) lista.fim = NULL;
    }
    else{
        No <T> *ant = pos->eloA; // Pega o nó anterior
        No <T> *prox = pos->eloP; // Pega o nó seguinte
        if( ant != NULL ) ant->eloP = prox;
        if( prox != NULL ) prox->eloA = ant;
        if( pos == lista.fim ) lista.fim = ant;
    }
    delete( pos );
    return true;
}

