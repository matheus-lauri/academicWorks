#pragma once

struct No {
	char tabuleiro[TAMANHO][TAMANHO];
	No* filhos[7];
	int peso;
};

void inicializarNo(No* no) {

	// inicializar o tabuleiro do no com todas as posicoes vazias
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			no->tabuleiro[i][j] = '*';
		}
	}
	// Inicializar os filhos como NULL
	for (int i = 0; i < 7; i++) no->filhos[i] = NULL;
	no->peso = -2;
}

// Copiar dois tabuleiros
void copiarTabuleiro(char tabuleiro[TAMANHO][TAMANHO], char tabuleiroCopia[TAMANHO][TAMANHO]) {
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			tabuleiroCopia[i][j] = tabuleiro[i][j];
		}
	}
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

// Verificar se o Computador ganhou
bool verificarVitoriaPC(char tabuleiro[TAMANHO][TAMANHO]) {
	// Verificar linhas
	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == 'O' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
			return true;
	}

	// Verificar colunas
	for (int j = 0; j < 3; j++) {
		if (tabuleiro[0][j] == 'O' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j])
			return true;
	}

	// Verificar diagonais
	if (tabuleiro[0][0] == 'O' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
		return true;

	if (tabuleiro[0][2] == 'O' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
		return true;


	return false;
}

// Verificar se o jogador Humano ganhou
bool verificarVitoriaHumano(char tabuleiro[TAMANHO][TAMANHO]) {
	// Verificar linhas
	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == 'X' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
			return true;
	}

	// Verificar colunas
	for (int j = 0; j < 3; j++) {
		if (tabuleiro[0][j] == 'X' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j])
			return true;
	}

	// Verificar diagonais
	if (tabuleiro[0][0] == 'X' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
		return true;

	if (tabuleiro[0][2] == 'X' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
		return true;


	return false;
}

// Calcular o peso(1 ou 0 ou -1) do tabuleiro de um no
int calcularPesoTabuleiro(No* no) {
	if (verificarEmpate(no->tabuleiro)) {
		return 0;
	}
	else if (verificarVitoriaPC(no->tabuleiro)) {
		return 1;
	}
	else {
		return -1;
	}
}

// Adicionar o peso(1 ou 0 ou -1) em um determinado no
int adicionarPeso(No* raiz) {
	int peso = -1;
	if (raiz == NULL) {
		return -1;
	}
	if (raiz->filhos[0] == NULL) {
		peso = calcularPesoTabuleiro(raiz);
	}
	else {
		for (int i = 0; i < 7; i++) {
			int aux = adicionarPeso(raiz->filhos[i]);
			if (aux > peso) {
				peso = aux;
			}
		}
	}
	raiz->peso = peso;
	return peso;
}

// Gerar uma arvore a partir de um tabuleiro
No* gerarArvore(No* raiz, char tabuleiro[TAMANHO][TAMANHO], char jogadorAtual) {
	// Verificar se o jogo terminou (vitória ou empate)
	if (verificarVitoriaPC(tabuleiro) || verificarEmpate(tabuleiro) || verificarVitoriaHumano(tabuleiro)) {
		return NULL;
	}

	// Gerar os filhos da raiz
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			// Verificar se a coluna está disponível para jogar
			if (tabuleiro[i][j] == '*') {
				// Criar um novo nó para a jogada
				No* novo_no = new No;
				inicializarNo(novo_no);
				copiarTabuleiro(tabuleiro, novo_no->tabuleiro);
				novo_no->tabuleiro[i][j] = jogadorAtual;

				// Adicionar o novo nó como filho da raiz
				for (int i = 0; i < 7; i++) {
					if (raiz->filhos[i] == NULL) {
						raiz->filhos[i] = novo_no;
						break;
					}
				}

				// Chamar recursivamente para o próximo jogador
				gerarArvore(novo_no, novo_no->tabuleiro, (jogadorAtual == 'O') ? 'X' : 'O');
			}
		}
	}
	return raiz;
}