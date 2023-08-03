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

bool testar_arvores(No *raizA, No *raizB ){
    int contA = contar_nos(raizA);
    int contB = contar_nos(raizB);

    if( contA != contB ) return false;

    int *vetorA = new int[contA];
    int *vetorB = new int[contB];
    int posA = 0, posB = 0;
    infixado( raizA, vetorA, posA );
    infixado( raizB, vetorB, posB );

    for( int i=0; i<contA; i++ ){
        if( vetorA[i] != vetorB[i] ) return false;
    }
    return true;
}

int main(){
    No *noA1, *noA2, *noA3, *noA4, *noA5, *raizA;
    noA1 = inserir( NULL, 10, NULL );
    noA2 = inserir( NULL, 50, NULL );
    noA3 = inserir( NULL, 70, NULL );
    noA4 = inserir( noA1, 20, NULL );
    noA5 = inserir( noA2, 60, noA3 );
    raizA = inserir( noA4, 40, noA5 );

    No *noB1, *noB2, *noB3, *noB4, *noB5, *noB6, *raizB;
    noB1 = inserir( NULL, 5, NULL );
    noB2 = inserir( NULL, 20, NULL );
    noB3 = inserir( NULL, 30, NULL );
    noB4 = inserir( NULL, 50, NULL );
    noB5 = inserir( noB1, 15, noB2 );
    noB6 = inserir( noB3, 40, noB4 );
    raizB = inserir( noB5, 25, noB6 );

    No *noC1, *noC2, *noC3, *noC4, *noC5, *noC6, *raizC;
    noC1 = inserir( NULL, 5, NULL );
    noC2 = inserir( noC1, 15, NULL );
    noC3 = inserir( noC2, 20, NULL );
    noC4 = inserir( NULL, 30, NULL );
    noC5 = inserir( noC3, 25, noC4 );
    noC6 = inserir( NULL, 50, NULL );
    raizC = inserir( noC5, 40, noC6 );

    if( testar_arvores(raizA, raizB ) )
        cout << "A e B sao iguais";
    else
        cout << "A e B sao diferentes";
    cout << endl;

    if( testar_arvores(raizB, raizC ) )
        cout << "B e C sao iguais";
    else
        cout << "B e C sao diferentes";
    cout << endl;
}
