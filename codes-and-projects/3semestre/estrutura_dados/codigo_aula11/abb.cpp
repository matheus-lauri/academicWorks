#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    No *esq, *dir;
};

template <typename T>
void prefixado( No <T> *raiz ){
    if( raiz == NULL ) return;
    cout << raiz->info << " ";
    prefixado(raiz->esq);
    prefixado(raiz->dir);
}

template <typename T>
void infixado( No <T> *raiz ){
    if( raiz == NULL ) return;
    infixado(raiz->esq);
    cout << raiz->info << " ";
    infixado(raiz->dir);
}

template <typename T>
void posfixado( No <T> *raiz ){
    if( raiz == NULL ) return;
    posfixado(raiz->esq);
    posfixado(raiz->dir);
    cout << raiz->info << " ";
}

template <typename T>
int contar_nos( No <T> *raiz ){
    if( raiz == NULL ) return 0;
    return contar_nos(raiz->esq) + contar_nos(raiz->dir) + 1;
}

template <typename T>
int contar_folhas( No <T> *raiz ){
    if( raiz == NULL ) return 0;
    int nEsq = contar_folhas(raiz->esq);
    int nDir = contar_folhas(raiz->dir);
    if( nEsq == 0 && nDir == 0 )
        return 1;
    else
        return nEsq+nDir;
}

template <typename T>
int contar_nos_um_filho( No <T> *raiz ){
    if( raiz == NULL ) return 0;
    int nEsq = contar_nos_um_filho(raiz->esq);
    int nDir = contar_nos_um_filho(raiz->dir);
    if( (raiz->esq == NULL && raiz->dir != NULL) || (raiz->esq != NULL && raiz->dir == NULL) )
        return nEsq + nDir + 1;
    else
        return nEsq + nDir;
}

template <typename T>
int altura( No <T> *raiz ){
    if( raiz == NULL ) return 0;
    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);
    return (altE > altD) ? altE+1 : altD+1;
}

template <typename T>
bool inserir(No <T> *&raiz, char valor ){
    if( raiz == NULL ){
        raiz = new No <T>;
        if( raiz == NULL ) return false; // Memoria cheia
        raiz->info = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return true;
    }
    if( valor < raiz->info )
        return inserir(raiz->esq, valor);
    else
        return inserir(raiz->dir, valor);
}

template <typename T>
bool pesquisar(No <T> *&raiz, char valor){
    if( raiz == NULL ) return false;
    if( raiz->info == valor ) return true;
    if( valor < raiz->info )
        return pesquisar(raiz->esq, valor);
    else
        return pesquisar(raiz->dir, valor);
}

template <typename T>
T buscar_maior_valor(No <T> *raiz){
    if( raiz->dir != NULL )
        return buscar_maior_valor(raiz->dir);
    else
        return raiz->info;
}

template <typename T>
No <T> * retirar(No <T> *&raiz, char valor){
    if( raiz == NULL ) return NULL;
    if( raiz->info == valor ){
        // No folha
        if( raiz->esq == NULL && raiz->dir == NULL ){
            delete raiz;
            return NULL;
        }
        // So tem filho a esquerda
        if( raiz->esq != NULL && raiz->dir == NULL ){
            No <T> *aux = raiz->esq;
            delete raiz;
            return aux;
        }
        // So tem filho a direita
        if( raiz->esq == NULL && raiz->dir != NULL ){
            No <T> *aux = raiz->dir;
            delete raiz;
            return aux;
        }
        // Tem dois filhos
        if( raiz->esq != NULL && raiz->dir != NULL ){
            T aux = buscar_maior_valor(raiz->esq);
            raiz->info = aux;
            raiz->esq = retirar(raiz->esq, aux);
            return raiz;
        }
    }
    if( valor < raiz->info )
        raiz->esq = retirar(raiz->esq, valor);
    else
        raiz->dir = retirar(raiz->dir, valor);
    return raiz;
}

template <typename T>
void listar_intervalo( No <T> *raiz, T vA, T vB ){
    if( raiz == NULL ) return;
    listar_intervalo(raiz->esq, vA, vB );
    if( vA <= raiz->info && raiz->info <= vB ) cout << raiz->info << " ";
    listar_intervalo(raiz->dir, vA, vB );
}

int main(){
    No<int> *raiz = NULL;
    int op, num;

    do{
        cout << "Menu: " << endl;
        cout << "\t1  - Inserir" << endl;
        cout << "\t2  - Retirar" << endl;
        cout << "\t3  - Pesquisar" << endl;
        cout << "\t4  - Prefixado" << endl;
        cout << "\t5  - Infixado" << endl;
        cout << "\t6  - Posfixado" << endl;
        cout << "\t7  - Altura" << endl;
        cout << "\t8  - Numero nos" << endl;
        cout << "\t9  - Contar folhas" << endl;
        cout << "\t10 - Listar intervalo" << endl;
        cout << "\t11 - Conta nos com 1 filho" << endl;
        cout << "\t0  - Fim" << endl;
        cout << "\tOpcao: ";
        cin >> op;

        switch(op){
            case 1:
                cout << "\nQual o valor a inserir: ";
                cin >> num;
                if( inserir(raiz, num) )
                    cout << "Inserido com sucesso" << endl;
                else
                    cout << "Ocorreu um erro na insercao" << endl;
                break;
            case 2:
                cout << "\nQual o valor a retirar: ";
                cin >> num;
                raiz = retirar(raiz, num);
                break;
            case 3:
                cout << "\nQual o valor a pesquisar: ";
                cin >> num;
                if( pesquisar(raiz, num) )
                    cout << "Valor localizado" << endl;
                else
                    cout << "Valor nao esta na arvore" << endl;
                break;
            case 4:
                cout << "Prefixado => ";
                prefixado(raiz);
                cout << endl;
                break;
            case 5:
                cout << "Infixado => ";
                infixado(raiz);
                cout << endl;
                break;
            case 6:
                cout << "Posfixado => ";
                posfixado(raiz);
                cout << endl;
                break;
            case 7:
                num = altura(raiz);
                cout << "Altura = " << num << endl;
                break;
            case 8:
                num = contar_nos(raiz);
                cout << "Numero de nos = " << num << endl;
                break;
            case 9:
                num = contar_folhas(raiz);
                cout << "Numero de nos folha = " << num << endl;
                break;
            case 10:
                int a,b;
                cout << endl << "Primeiro valor do intervalo: ";
                cin >> a;
                cout << "Segundo valor do intervalo: ";
                cin >> b;
                cout << endl << "Todo os valores entre [" << a << ";" << b <<"] = ";
                listar_intervalo( raiz, a, b );
                cout << endl;
                break;
            case 11:
                num = contar_nos_um_filho(raiz);
                cout << "Numero de nos com um filho = " << num << endl;
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    }while( op != 0 );
    cout << endl;
}
