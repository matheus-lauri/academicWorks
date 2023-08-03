#include <iostream>
using namespace std;

struct No{
    char info;
    No *esq, *dir;
};

No * inserir( No *e, char i, No *d ){
    No * novo = new No;
    if( novo == NULL ) return NULL;
    novo->esq = e;
    novo->info = i;
    novo->dir = d;
    return novo;
}

void prefixado( No *raiz ){
    if( raiz == NULL ) return;
    cout << raiz->info << " ";
    prefixado(raiz->esq);
    prefixado(raiz->dir);
}

void infixado( No *raiz ){
    if( raiz == NULL ) return;
    infixado(raiz->esq);
    cout << raiz->info << " ";
    infixado(raiz->dir);
}

void posfixado( No *raiz ){
    if( raiz == NULL ) return;
    posfixado(raiz->esq);
    posfixado(raiz->dir);
    cout << raiz->info << " ";
}

int contar_nos( No *raiz ){
    if( raiz == NULL ) return 0;
    return contar_nos(raiz->esq) + contar_nos(raiz->dir) + 1;
}

int altura( No *raiz ){
    if( raiz == NULL ) return 0;
    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);
    return (altE > altD) ? altE+1 : altD+1;
}

int main(){
/*
    No *no1, *no2, *no3, *no4, *raiz;

    no1 = inserir( NULL, 'D', NULL );
    no2 = inserir( NULL, 'A', NULL );
    no3 = inserir( NULL, 'E', NULL );
    no4 = inserir( no2, 'C', no3 );
    raiz = inserir( no1, 'B', no4 );
*/
    No *no1 = inserir(NULL, 'A', NULL );
    No *no2 = inserir(NULL, 'C', NULL );
    No *no3 = inserir(NULL, 'E', NULL );
    No *no4 = inserir(no2, 'D', no3 );
    No *no5 = inserir(no1, 'B', no4 );
    No *no6 = inserir(NULL, 'G', NULL );
    No *no8 = inserir(NULL, 'J', NULL );
    No *no7 = inserir(NULL, 'I', no8 );
    No *no9 = inserir(no6, 'H', no7 );
    No *raiz = inserir(no5, 'F', no9 );

    cout << "Prefixado => ";
    prefixado(raiz);
    cout << endl;
    cout << "Infixado => ";
    infixado(raiz);
    cout << endl;
    cout << "Posfixado => ";
    posfixado(raiz);
    cout << endl;

    int cont = contar_nos(raiz);
    cout << "Numero de nos = " << cont << endl;

    int alt = altura(raiz);
    cout << "Altura = " << alt << endl;
    cout << endl;
}
