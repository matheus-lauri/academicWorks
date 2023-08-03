#include <iostream>
using namespace std;

//Desenvolvido por Gustavo Baron Lauritzen

struct No {
    char info;
    No* esq, * dir;
};

No* criarNo(char valor) {
    No* novoNo = new No;
    novoNo->info = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    else if (valor < raiz->info) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void mostrarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

bool posicaoValida(char tabuleiro[3][3], int linha, int coluna) {
    if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) {
        return false;
    }
    if (tabuleiro[linha][coluna] != '-') {
        return false;
    }
    return true;
}

bool verificarVencedor(char tabuleiro[3][3], char jogador) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return true;
        }
    }
    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
            return true;
        }
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return true;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return true;
    }
    return false;
}

bool tabuleiroCheio(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

No* jogada(No* raiz, char tabuleiro[3][3], char jogador) {
    int linha, coluna;
    while (true) {
        cout << "Jogador " << jogador << ", digite a linha (0-2): ";
        cin >> linha;
        cout << "Jogador " << jogador << ", digite a coluna (0-2): ";
        cin >> coluna;

        if (posicaoValida(tabuleiro, linha, coluna)) {
            tabuleiro[linha][coluna] = jogador;
            raiz = inserir(raiz, jogador);
            break;
        }
        else {
            cout << "Posicao invalida. Por favor, escolha outra posicao.\n";
        }
    }
    return raiz;
}

void jogarJogoDaVelha() {
    char tabuleiro[3][3] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
    No* raiz = NULL;
    char jogadorAtual = 'X';
    bool jogoAcabou = false;

    while (!jogoAcabou) {
        mostrarTabuleiro(tabuleiro);
        raiz = jogada(raiz, tabuleiro, jogadorAtual);

        if (verificarVencedor(tabuleiro, jogadorAtual)) {
            mostrarTabuleiro(tabuleiro);
            cout << "Jogador " << jogadorAtual << " venceu!\n";
            jogoAcabou = true;
        }
        else if (tabuleiroCheio(tabuleiro)) {
            mostrarTabuleiro(tabuleiro);
            cout << "O jogo terminou em empate!\n";
            jogoAcabou = true;
        }
        else {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    jogarJogoDaVelha();
    return 0;
}

