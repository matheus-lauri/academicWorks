#include <iostream>
using namespace std;

template <typename T>
struct No {
    T info;
    No* esq, * dir;
};

template <typename T>
void prefixado(No <T>* raiz) {
    if (raiz == NULL) return;
    cout << raiz->info << " ";
    prefixado(raiz->esq);
    prefixado(raiz->dir);
}

template <typename T>
void infixado(No <T>* raiz) {
    if (raiz == NULL) return;
    infixado(raiz->esq);
    cout << raiz->info << " ";
    infixado(raiz->dir);
}

template <typename T>
void posfixado(No <T>* raiz) {
    if (raiz == NULL) return;
    posfixado(raiz->esq);
    posfixado(raiz->dir);
    cout << raiz->info << " ";
}

template <typename T>
int contar_nos(No <T>* raiz) {
    if (raiz == NULL) return 0;
    return contar_nos(raiz->esq) + contar_nos(raiz->dir) + 1;
}

template <typename T>
int altura(No <T>* raiz) {
    if (raiz == NULL) return 0;
    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);
    return (altE > altD) ? altE + 1 : altD + 1;
}

template <typename T>
bool inserir(No <T>*& raiz, char valor) {
    if (raiz == NULL) {
        raiz = new No <T>;
        if (raiz == NULL) return false; // Memoria cheia
        raiz->info = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return true;
    }
    if (valor < raiz->info)
        return inserir(raiz->esq, valor);
    else
        return inserir(raiz->dir, valor);
}

template <typename T>
bool pesquisar(No <T>*& raiz, char valor) {
    if (raiz == NULL) return false;
    if (raiz->info == valor) return true;
    if (valor < raiz->info)
        return pesquisar(raiz->esq, valor);
    else
        return pesquisar(raiz->dir, valor);
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
    return raiz;
}

template <typename T>
int contar_folha(No <T>*& raiz) {
    return 0;
}

template <typename T>
bool verifica_arvore(No <T>*& raiz) {
    return true;
}

template <typename T>
void listar_entre_valores(No <T>*& raiz, T a, T b) {
    if (raiz == NULL) return;
    listar_entre_valores(raiz->esq, a, b);
    if ((raiz->info >= a) && (raiz->info <= b)) {
        cout << raiz->info << " ";
    }
    listar_entre_valores(raiz->dir, a, b);
}

template <typename T>
int conta_raiz_filho_unico(No <T>*& raiz) {
    return 0;
}

template <typename T>
void preenche_vetor_infixado(No <T>*& raiz, T vetor[], int &pos) {
    if (raiz == NULL) return;
    preenche_vetor_infixado(raiz->esq, vetor, pos);
    vetor[pos++] = raiz->info;
    preenche_vetor_infixado(raiz->dir, vetor, pos);
}

template <typename T>
bool verifica_igualdade(No <T>*& raiz1, No <T>*& raiz2) {
    int cont1 = contar_nos(raiz1);
    int* vetor1 = new int[cont1];
    int cont2 = contar_nos(raiz2);
    int* vetor2 = new int[cont2];
    if (cont1 != cont2) return false;
    int pos1 = 0, pos2 = 0;
    preenche_vetor_infixado(raiz1, vetor1, pos1);
    preenche_vetor_infixado(raiz2, vetor2, pos2);
    for (int i = 0; i < cont1; i++) {
        if (vetor1[i] != vetor2[i]) return false;
    }
    return true;
}

int main() {
    No<int>* raiz = NULL;
    No<int>* raiz2 = NULL;
    int op, num;

    do {
        cout << "Menu: " << endl;
        cout << "\t1 - Inserir" << endl;
        cout << "\t2 - Retirar" << endl;
        cout << "\t3 - Pesquisar" << endl;
        cout << "\t4 - Prefixado" << endl;
        cout << "\t5 - Infixado" << endl;
        cout << "\t6 - Posfixado" << endl;
        cout << "\t7 - Altura" << endl;
        cout << "\t8 - Numero nos" << endl;
        cout << "\t9 - Numero nos folha" << endl;
        cout << "\t10 - Verifica arvore" << endl;
        cout << "\t11 - Listar entre valor 'a' e valor 'b'" << endl;
        cout << "\t12 - Contar nos com um filho" << endl;
        cout << "\t13 - Verificar igualdade entre duas ABB" << endl;
        cout << "\tOpcao: ";
        cin >> op;

        switch (op) {
        case 1:
            int escolha;
            cout << "\nEm qual raiz inserir(1 ou 2 - Selecione 0 para voltar ao menu principal): ";
            cin >> escolha;
                switch (escolha) {
                case 1:
                    cout << "\nValor para inserir: ";
                    cin >> num;
                    if (inserir(raiz, num))
                        cout << "Inserido com sucesso" << endl;
                    else
                        cout << "Ocorreu um erro na insercao" << endl;
                    break;
                case 2:
                    cout << "\nValor para inserir: ";
                    cin >> num;
                    if (inserir(raiz2, num))
                        cout << "Inserido com sucesso" << endl;
                    else
                        cout << "Ocorreu um erro na insercao" << endl;
                    break;
                case 0:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                }
            break;
        case 2:
            cout << "\nQual o valor a retirar: ";
            cin >> num;
            raiz = retirar(raiz, num);
            break;
        case 3:
            cout << "\nQual o valor a pesquisar: ";
            cin >> num;
            if (pesquisar(raiz, num))
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
            num = contar_folha(raiz);
            cout << "Numero de nos folha = " << num << endl;
            break;
        case 10:
            bool retorno;
            retorno = verifica_arvore(raiz);
            cout << "Verificacao da arvore = " << retorno << endl;
            break;
        case 11:
            int a, b;
            cout << "Digite o valor 'a': " << endl;
            cin >> a;
            cout << "Digite o valor 'b': " << endl;
            cin >> b;
            cout << endl;
            listar_entre_valores(raiz, a, b);
            break;
        case 12:
            num = conta_raiz_filho_unico(raiz);
            cout << "Numero de nos com um unico filho = " << num << endl;
            break;
        case 13:
            bool retorno;
            retorno = verifica_igualdade(raiz, raiz2);
            cout << "Verificacao de igualdade = " << retorno << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opcao invalida" << endl;
        }
    } while (op != 0);
    cout << endl;
}
