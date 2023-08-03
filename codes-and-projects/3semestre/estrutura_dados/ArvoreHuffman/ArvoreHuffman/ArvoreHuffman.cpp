#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct No {
    int freq;
    char ch;
    No* esq = NULL, * dir = NULL;
};

struct LDE {
    No* info;
    LDE* eloA, * eloP;
};

struct Lista {
    LDE* comeco = NULL, * fim = NULL;
};

struct Bits {
    char ch;
    string bits = "";
};

bool inserir_lista(Lista& lista, No* no) {
    LDE* novo = new LDE;

    if (novo == NULL) return false;
    novo->info = no;

    // Lista vazia
    if (lista.comeco == NULL) {
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    // Inserir no inicio
    if (no->freq < lista.comeco->info->freq) {
        novo->eloP = lista.comeco;
        lista.comeco->eloA = novo;
        lista.comeco = novo;
        return true;
    }

    // Inserir no final
    if (no->freq > lista.fim->info->freq) {
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
        return true;
    }

    LDE* aux = lista.comeco;
    while (no->freq > aux->info->freq && no->freq > aux->eloP->info->freq) {
        aux = aux->eloP;
    }
    // Inserir no meio da lista
    LDE* prox = aux->eloP;
    novo->eloA = aux;
    novo->eloP = prox;
    aux->eloP = novo;
    prox->eloA = novo;
    return true;
}

LDE* retirar_comeco(Lista& lista) {
    if (lista.comeco == NULL) return NULL;
    LDE* aux = lista.comeco;
    lista.comeco = lista.comeco->eloP;
    if (lista.comeco != NULL) lista.comeco->eloA = NULL;
    return aux;
}

void tabela_frequencia(char file[], int tabela[]) {
    char ch;

    for (int i = 0; i < 256; i++) tabela[i] = 0;
    ifstream fin(file);
    while (fin.get(ch)) {
        if (ch != 10) tabela[ch]++;
    }
}

Lista construir_lista( int tabela[], int &cont ) {
    Lista lista;
    cont = 0;
    for (int i = 0; i < 256; i++) {
        if (tabela[i] != 0) {
            No* no = new No;
            no->ch = (char)i;
            no->freq = tabela[i];
            inserir_lista(lista, no);
            cont++;
        }
    }
    return lista;
}

void construir_arvore(Lista lista) {
    LDE* first, * second;

    first = retirar_comeco(lista);
    second = retirar_comeco(lista);

    while (first != NULL && second != NULL) {
        No* novo = new No;
        novo->esq = first->info;
        novo->dir = second->info;
        novo->ch = '*';
        novo->freq = first->info->freq + second->info->freq;
        inserir_lista(lista, novo);
        if (lista.comeco->eloP != NULL) {
            first = retirar_comeco(lista);
            second = retirar_comeco(lista);
        }
        else {
            first = second = NULL;
        }
    }
}

void caminhar(No *raiz, string aux, Bits tab[]) {
    static int i = 0;
    if (raiz == NULL) return;
    if (raiz->esq == NULL && raiz->dir == NULL) {
        tab[i].ch = raiz->ch;
        tab[i].bits = aux;
        i++;
        return;
    }
    caminhar(raiz->esq, aux + "0", tab);
    caminhar(raiz->dir, aux + "1", tab);
}

void construir_tabela_bits(Lista lista, Bits tab[], int tamanho) {
    string aux = "";
    caminhar(lista.comeco->info, aux, tab);
}

void mostrar_tabela_bits(Bits tab[], int tamanho) {
    cout << endl << "Tabela de bits:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "\t" << tab[i].ch << " => " << tab[i].bits << endl;
    }
}

void liberar_memoria(Lista lista) {
    //acabar
}

int main() {
    char file[] = "E:\Workspace\projetos_vsstudio\estrutura_dados\ArvoreHuffman\texto.txt";
    int tabela[256], tamanho;
    Lista lista;

    tabela_frequencia(file, tabela);
    lista = construir_lista(tabela, tamanho);
    construir_arvore(lista);

    Bits* tab = new Bits[tamanho];

    construir_tabela_bits(lista, tab, tamanho);
    mostrar_tabela_bits(tab, tamanho);

    liberar_memoria(lista); //terminar
    delete tab;

}