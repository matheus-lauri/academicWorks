#include <iostream>
#include <ctime>
#define TAMANHO 3
#include "arvoreDecisao.h"
using namespace std;

// Desenvolvido por Gustavo Baron Lauritzen e Matheus Baron Lauritzen

// Gerar aleatoriamente o jogador que ira comecar
char randomizar() {
	char c = ' ';
	srand(time(NULL));
	int num = rand() % 2;
	(num == 0) ? c = 'X' : c = 'O';
	return c;
}

void imprimirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			cout << tabuleiro[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// Retornar o numero de posicoes que foram preenchidas
int calcularPosicoesPreenchidas(char tabuleiro[TAMANHO][TAMANHO]){
	int cont = 0;
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			if (tabuleiro[i][j] != '*') {
				cont++;
			}
		}
	}
	return cont;
}

// Fazer a jogada de defesa do computador
No * defesaPC(No *raiz, No *filho) {
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			if (raiz->tabuleiro[i][j] != filho->tabuleiro[i][j]) {
				raiz->tabuleiro[i][j] = 'O';
				return raiz;
			}
		}
	}
}

// Realizar a primeira jogada aleatoria do computador
void realizarJogadaAleatoria(No* raiz, char tabuleiro[TAMANHO][TAMANHO]){
	int i, j;
	do {
		i = rand() % 3;
		j = rand() % 3;
	} while (tabuleiro[i][j] != '*');
	tabuleiro[i][j] = 'O';
	copiarTabuleiro(tabuleiro, raiz->tabuleiro);
}

// Realizar a jogada do computador a partir da arvore gerada
void realizarJogadaPC(char tabuleiro[TAMANHO][TAMANHO]) {
	No raiz;
	inicializarNo(&raiz);
	int num = 0;
	num = calcularPosicoesPreenchidas(tabuleiro);
	// faz a primeira jogada aleatoriamente
	if (num < 2) {
		realizarJogadaAleatoria(&raiz, tabuleiro);
		return;
	}
	gerarArvore(&raiz, tabuleiro, 'O');
	adicionarPeso(&raiz);

	No* melhorFilho = new No;
	inicializarNo(melhorFilho);
	for (int i = 0; i < 7; i++) {
		if (raiz.filhos[i] != NULL) {
			if (verificarVitoriaPC(raiz.filhos[i]->tabuleiro)) {
				melhorFilho = raiz.filhos[i];
				break;
			}
			if (verificarVitoriaHumano(raiz.filhos[i]->tabuleiro)) {
				melhorFilho = defesaPC(&raiz, raiz.filhos[i]);
				break;
			}
			if (raiz.filhos[i]->peso == 1) {
				melhorFilho = raiz.filhos[i];
				break;
			}
			if (raiz.filhos[i]->peso == 0 && melhorFilho != NULL) {
				melhorFilho = raiz.filhos[i];
			}
			if (raiz.filhos[i]->peso == -1 && melhorFilho != NULL) {
				melhorFilho = raiz.filhos[i];
			}
		}
	}

	if (melhorFilho != NULL) {
		copiarTabuleiro(melhorFilho->tabuleiro, tabuleiro);
	}
}

// Função do laco principal do jogo
void Jogo() {
	//Tabuleiro como matriz de char
	char tabuleiro[TAMANHO][TAMANHO];

	int linha, coluna;
	char jogadorAtual = randomizar();


	// Inicializar o tabuleiro com '*'
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++) {
			tabuleiro[i][j] = '*';
		}
	}

	cout << "-------------|| X = Jogador Humano ||-------------" << endl;
	cout << "-------------||   O = Computador   ||-------------" << endl;
	cout << endl;

	//Loop do jogo
	do {
		imprimirTabuleiro(tabuleiro);
		if (jogadorAtual == 'X') {
			cout << "Jogador(X) e a sua vez. Informe a posicao (linha e coluna): ";
			cin >> linha >> coluna;

			// Verificar se a posição é válida
			if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO || tabuleiro[linha][coluna] != '*') {
				cout << "Posicao invalida. Tente novamente." << endl;
				continue;
			}
			// Realizar jogada Humano
			tabuleiro[linha][coluna] = jogadorAtual;
		}
		else {
			cout << "O computador fez a sua jogada: " << endl;
			//Realizar jogada Computador
			realizarJogadaPC(tabuleiro);
		}

		// Verificar se houve a vitoria do Computador
		if (verificarVitoriaPC(tabuleiro)) {
			cout << "O computador venceu o jogo! Nao foi dessa vez..." << endl;
			break;
		}

		// Verificar se houve a vitoria do Computador
		if (verificarVitoriaHumano(tabuleiro)) {
			cout << "Parabens jogador! Voce venceu o computador!" << endl;
			break;
		}

		// Verificar se houve empate
		if (verificarEmpate(tabuleiro)) {
			cout << "Nao houve vencedores! O jogo terminou em empate!" << endl;
			break;
		}

		// Alternar para o próximo jogador
		jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
		
	} while (true);
	imprimirTabuleiro(tabuleiro);
}

//Menu inicial
int menuInicial(){
	int escolhaMenuInicial;
	do {
		cout << "																									" << endl;
		cout << "  ________  __                  ________                         ________                          " << endl;
		cout << " /        |/  |                /        |                       /        |                         " << endl;
		cout << " $$$$$$$$/ $$/   _______       $$$$$$$$/______    _______       $$$$$$$$/______    ______          " << endl;
		cout << "    $$ |   /  | /       |         $$ | /      \  /       |          $$ | /      \  /      \        " << endl;
		cout << "    $$ |   $$ |/$$$$$$$/          $$ | $$$$$$  |/$$$$$$$/          $$ |/$$$$$$  |/$$$$$$  |        " << endl;
		cout << "    $$ |   $$ |$$ |               $$ | /    $$ |$$ |               $$ |$$ |  $$ |$$    $$ |        " << endl;
		cout << "    $$ |   $$ |$$ \_____           $$ |/$$$$$$$ |$$ \_____           $$ |$$  \__$$ |$$$$$$$$/      " << endl;
		cout << "    $$ |   $$ |$$       |         $$ |$$    $$ |$$       |         $$ |$$    $$/ $$       |        " << endl;
		cout << "    $$/    $$/  $$$$$$$/          $$/  $$$$$$$/  $$$$$$$/          $$/  $$$$$$/   $$$$$$$/         " << endl;
		cout << "																									" << endl;
		cout << "Bem vindo ao Jogo da Velha (Player vs PC)!" << endl;
		cout << "1 - Jogar" << endl;
		cout << "2 - Sair" << endl;
		cin >> escolhaMenuInicial;
		switch (escolhaMenuInicial) {
		case 1:
			system("cls");
			Jogo();
			return 0;
			break;
		case 2:
			system("cls");
			return 0;
			break;
		default:
			cout << "Opcao invalida. Tente novamente." << endl;
			system("pause");
			system("cls");
		}
	} while (escolhaMenuInicial != 1 || escolhaMenuInicial != 2);
    return 0;
}
int main() {
	menuInicial();
	return 0;
}