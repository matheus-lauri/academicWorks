#include <iostream>
using namespace std;

struct No{
    int info;
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

int contar_nos( No *raiz ){
    if( raiz == NULL ) return 0;
    return contar_nos(raiz->esq) + contar_nos(raiz->dir) + 1;
}

void infixado( No *raiz, int vetor[], int &pos ){
    if( raiz == NULL ) return;
    infixado( raiz->esq, vetor, pos );
    vetor[pos++] = raiz->info;
    infixado( raiz->dir, vetor, pos );
}

bool verificar_abb( No *raiz ){
    int cont = contar_nos(raiz);
    int *vetor = new int[cont];
    int pos = 0;

    infixado( raiz, vetor, pos );
    for( int i=0; i<cont-1; i++ ){
        if( vetor[i] > vetor[i+1] ) return false;
    }
    return true;
}

int main(){
/*
    No *no1, *no2, *no3, *no4, *no5, *raiz;

    no1 = inserir( NULL, 10, NULL );
    no2 = inserir( NULL, 50, NULL );
    no3 = inserir( NULL, 70, NULL );
    no4 = inserir( no1, 20, NULL );
    no5 = inserir( no2, 60, no3 );
    raiz = inserir( no4, 40, no5 );
*/
    No *no1, *no2, *no3, *no4, *no5, *no6, *raiz;

    no1 = inserir( NULL, 5, NULL );
    no2 = inserir( NULL, 25, NULL );
    no3 = inserir( NULL, 30, NULL );
    no4 = inserir( NULL, 50, NULL );
    no5 = inserir( no1, 15, no2 );
    no6 = inserir( no3, 40, no4 );
    raiz = inserir( no5, 20, no6 );


    if( verificar_abb(raiz) )
        cout << "Essa eh uma ABB";
    else
        cout << "Essa arvore nao eh uma ABB";
    cout << endl;
}
