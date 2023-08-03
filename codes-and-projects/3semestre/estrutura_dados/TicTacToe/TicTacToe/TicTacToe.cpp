#include <iostream>
using namespace std;

#define TAMANHO 3

struct No {
    char info;
    int altura;
    int linha;
    int coluna;
    No* esq, * dir;
};

// Imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Verificar se houve um vencedor
bool verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    // Verificar linhas e colunas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return true; // Vencedor na linha i
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return true; // Vencedor na coluna i
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return true; // Vencedor na diagonal principal
    }
    if (tabuleiro[2][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[0][2] == jogador) {
        return true; // Vencedor na diagonal secundária
    }

    return false; // Não houve vencedor
}

// Verificar se o jogo terminou em empate
bool verificarEmpate(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == '*') {
                return false; // Ainda há espaço vazio no tabuleiro
            }
        }
    }
    return true; // O tabuleiro está cheio (empate)
}

// Realizar a jogada
void realizarJogada(char tabuleiro[TAMANHO][TAMANHO], char jogador, int linha, int coluna) {
    tabuleiro[linha][coluna] = jogador;
}
int altura(No * raiz) {
    return (raiz == NULL) ? 0 : raiz->altura;
}
int calcular_altura(No * raiz) {
    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);
    return (h_esq > h_dir) ? h_esq + 1 : h_dir + 1;
}
No * rotacao_simples_direita(No * k) {
    No * x = k->esq;
    No * t2 = x->dir;

    x->dir = k;
    k->esq = t2;
    k->altura = calcular_altura(k);
    x->altura = calcular_altura(x);
    cout << "RSD" << endl;
    return x;
}

No * rotacao_dupla_direita(No * k) {
    No * x = k->esq;
    No * w = x->dir;
    No * t2 = w->esq;
    No * t3 = w->dir;

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

No * rotacao_simples_esquerda(No * k) {
    No * y = k->dir;
    No * t2 = y->esq;

    y->esq = k;
    k->dir = t2;
    k->altura = calcular_altura(k);
    y->altura = calcular_altura(y);
    cout << "RSE" << endl;
    return y;
}


No * rotacao_dupla_esquerda(No * k) {
    No * y = k->dir;
    No * z = y->esq;
    No * t2 = z->esq;
    No * t3 = z->dir;

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


No * aplicar_rotacao(No * k) {
    if (altura(k->esq) > altura(k->dir)) { // Rotação a direita
        No * x = k->esq;
        if (altura(x->esq) >= altura(x->dir))
            return rotacao_simples_direita(k);
        else
            return rotacao_dupla_direita(k);
    }
    else { // Rotação a esquerda
        No * y = k->dir;
        if (altura(y->esq) > altura(y->dir))
            return rotacao_dupla_esquerda(k);
        else
            return rotacao_simples_esquerda(k);
    }
}

No * inserirMovimento(No *& raiz, char valor, int linha, int coluna) {
    if (raiz == NULL) {
        raiz = new No ;
        if (raiz == NULL) return NULL; // Memória cheia
        raiz->info = valor;
        raiz->altura = 1;
        raiz->linha = linha;
        raiz->coluna = coluna;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return raiz;
    }
    if (valor < raiz->info)
        raiz->esq = inserirMovimento(raiz->esq, valor, linha, coluna);
    else
        raiz->dir = inserirMovimento(raiz->dir, valor, linha, coluna);

    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);
    if (h_esq - h_dir == 2 || h_esq - h_dir == -2)
        raiz = aplicar_rotacao(raiz);
    else
        calcular_altura(raiz);
    return raiz;
}
int main() {
    //Tabuleiro como matriz de char
    char tabuleiro[TAMANHO][TAMANHO];
    No* raiz = NULL;
    int op, linha, coluna;
    char jogador_atual = 'X';

    // Inicializar o tabuleiro com '*'
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '*';
        }
    }

    //Loop do jogo
    do {
        imprimirTabuleiro(tabuleiro);

        cout << "Jogador " << jogador_atual << ", e a sua vez. Informe a posicao (linha e coluna): ";
        cin >> linha >> coluna;

        // Verificar se a posição é válida
        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO || tabuleiro[linha][coluna] != '*') {
            cout << "Posicao invalida. Tente novamente." << endl;
            continue;
        }
        
        // Realizar a jogada
        realizarJogada(tabuleiro, jogador_atual, linha, coluna);
        
        // Inserir o movimento na árvore AVL
        raiz = inserirMovimento(raiz, jogador_atual, linha, coluna);

        // Verificar se houve um vencedor
        if (verificarVencedor(tabuleiro, jogador_atual)) {
            cout << "Parabens! Jogador " << jogador_atual << " venceu o jogo!" << endl;
            break;
        }

        // Verificar se houve empate
        if (verificarEmpate(tabuleiro)) {
            cout << "O jogo terminou em empate!" << endl;
            break;
        }

        // Alternar para o próximo jogador
        jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';

    } while (true);

    cout << "Fim do jogo." << endl;

    return 0;
}