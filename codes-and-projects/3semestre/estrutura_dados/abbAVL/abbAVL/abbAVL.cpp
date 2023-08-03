#include <iostream>
using namespace std;

template <typename T>
struct No {
    T info;
    int altura;
    No* esq, * dir;
};

template <typename T>
void prefixado(No <T>* raiz) {
    if (raiz == NULL) return;
    cout << raiz->info << " (" << raiz->altura << ") ";
    prefixado(raiz->esq);
    prefixado(raiz->dir);
}

template <typename T>
void infixado(No <T>* raiz) {
    if (raiz == NULL) return;
    infixado(raiz->esq);
    cout << raiz->info << " (" << raiz->altura << ") ";
    infixado(raiz->dir);
}

template <typename T>
void posfixado(No <T>* raiz) {
    if (raiz == NULL) return;
    posfixado(raiz->esq);
    posfixado(raiz->dir);
    cout << raiz->info << " (" << raiz->altura << ") ";
}

template <typename T>
int altura(No <T>* raiz) {
    return (raiz == NULL) ? 0 : raiz->altura;
}

template <typename T>
int calcular_altura(No <T>* raiz) {
    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);
    return (h_esq > h_dir) ? h_esq + 1 : h_dir + 1;
}

template <typename T>
No <T>* rotacao_simples_direita(No <T>* k) {
    No <T>* x = k->esq;
    No <T>* t2 = x->dir;

    x->dir = k;
    k->esq = t2;
    k->altura = calcular_altura(k);
    x->altura = calcular_altura(x);
    cout << "RSD" << endl;
    return x;
}

template <typename T>
No <T>* rotacao_dupla_direita(No <T>* k) {
    No <T>* x = k->esq;
    No <T>* w = x->dir;
    No <T>* t2 = w->esq;
    No <T>* t3 = w->dir;

    w->esq = x;
    w->dir = k;
    x->dir = t2;
    k->esq = t3;
    k->altura = calcular_altura(k);
    x->altura = calcular_altura(x);
    w->altura = calcular_altura(w);
    cout << "RDD" << endl;
    return w;
}

template <typename T>
No <T>* rotacao_simples_esquerda(No <T>* k) {
    No <T>* y = k->dir;
    No <T>* t2 = y->esq;

    y->esq = k;
    k->dir = t2;
    k->altura = calcular_altura(k);
    y->altura = calcular_altura(y);
    cout << "RSE" << endl;
    return y;
}

template <typename T>
No <T>* rotacao_dupla_esquerda(No <T>* k) {
    No <T>* y = k->dir;
    No <T>* z = y->esq;
    No <T>* t2 = z->esq;
    No <T>* t3 = z->dir;
    
    z->esq = k;
    z->dir = y;
    k->dir = t2;
    y->esq = t3;
    k->altura = calcular_altura(k);
    y->altura = calcular_altura(y);
    z->altura = calcular_altura(z);
    cout << "RDE" << endl;
    return z;
}

template <typename T>
No <T>* aplicar_rotacao(No <T>* k) {
    if (altura(k->esq) > altura(k->dir)) { // Rotação a direita
        No <T>* x = k->esq;
        if (altura(x->esq) >= altura(x->dir))
            return rotacao_simples_direita(k);
        else
            return rotacao_dupla_direita(k);
    }
    else { // Rotação a esquerda
        No <T>* y = k->dir;
        if (altura(y->esq) > altura(y->dir))
            return rotacao_dupla_esquerda(k);
        else
            return rotacao_simples_esquerda(k);
    }
}

template <typename T>
No <T>* inserir(No <T>*& raiz, char valor) {
    if (raiz == NULL) {
        raiz = new No <T>;
        if (raiz == NULL) return false; // Memoria cheia
        raiz->info = valor;
        raiz->altura = 1;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return raiz;
    }
    if (valor < raiz->info)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);
    if (h_esq - h_dir == 2 || h_esq - h_dir == -2)
        raiz = aplicar_rotacao(raiz);
    else
        raiz->altura = (h_esq > h_dir) ? h_esq + 1 : h_dir + 1;
    return raiz;
}

template <typename T>
T buscar_maior_valor(No <T>* raiz) {
    if (raiz->dir != NULL)
        return buscar_maior_valor(raiz->dir);
    else
        return raiz->info;
}

template <typename T>
No <T>* retirar(No <T>*& raiz, char valor) {
    if (raiz == NULL) return NULL;
    if (raiz->info == valor) {
        // No folha
        if (raiz->esq == NULL && raiz->dir == NULL) {
            delete raiz;
            return NULL;
        }
        // So tem filho a esquerda
        if (raiz->esq != NULL && raiz->dir == NULL) {
            No <T>* aux = raiz->esq;
            delete raiz;
            return aux;
        }
        // So tem filho a direita
        if (raiz->esq == NULL && raiz->dir != NULL) {
            No <T>* aux = raiz->dir;
            delete raiz;
            return aux;
        }
        // Tem dois filhos
        if (raiz->esq != NULL && raiz->dir != NULL) {
            T aux = buscar_maior_valor(raiz->esq);
            raiz->info = aux;
            raiz->esq = retirar(raiz->esq, aux);
            return raiz;
        }
    }
    if (valor < raiz->info)
        raiz->esq = retirar(raiz->esq, valor);
    else
        raiz->dir = retirar(raiz->dir, valor);
    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);
    raiz->altura = (h_esq > h_dir) ? h_esq + 1 : h_dir + 1;
    return raiz;
}

int main() {
    No<int>* raiz = NULL;
    int op, num;

    do {
        cout << "Menu: " << endl;
        cout << "\t1  - Inserir" << endl;
        cout << "\t2  - Retirar" << endl;
        cout << "\t3  - Prefixado" << endl;
        cout << "\t4  - Infixado" << endl;
        cout << "\t5  - Posfixado" << endl;
        cout << "\t0  - Fim" << endl;
        cout << "\tOpcao: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "\nQual o valor a inserir: ";
            cin >> num;
            raiz = inserir(raiz, num);
            break;
        case 2:
            cout << "\nQual o valor a retirar: ";
            cin >> num;
            raiz = retirar(raiz, num);
            break;
        case 3:
            cout << "Prefixado => ";
            prefixado(raiz);
            cout << endl;
            break;
        case 4:
            cout << "Infixado => ";
            infixado(raiz);
            cout << endl;
            break;
        case 5:
            cout << "Posfixado => ";
            posfixado(raiz);
            cout << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opcao invalida" << endl;
        }
    } while (op != 0);
    cout << endl;
}
