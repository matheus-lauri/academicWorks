#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
#define TAM 20

void randomizarVetor(int vet[]) {
	for (int i = 0; i < TAM; i++) {
		vet[i] = rand() % 100;
	}
}

void imprimirVetor(int vet[]) {
	for (int i = 0; i < TAM; i++) {
		cout << vet[i] << " ";
	}
	cout << endl;
}

void insertionSort(int vet[]) {
	int chave, i;
	for (int j = 1; j <= TAM - 1;j++) {
		chave = vet[j];
		i = j - 1;
		while((i >= 0) && (vet[i])>chave) {
			vet[i + 1] = vet[i];
			i = i - 1;
		}
		vet[i + 1] = chave;
	}
}
void shellSort(int vet[], int inicio, int salto) {
	int j, k, temp;
	bool achei;
	for (int i = (inicio + salto); i < TAM; i+=salto ) {
		j = inicio;
		achei = false;
		while (j<i && !achei) {
			if (vet[i] < vet[j])
				achei = true;
			else
				j = j + salto;
		}
		if (achei) {
			temp = vet[i];
			k = i - salto;
			while (k > (j - salto)) {
				vet[k + salto] = vet[k];
				k = k - salto;
			}
			vet[j] = temp;
		}
	}
}

void chamaShellSort(int vet[], int np) {
	int inc;
	for (int i = np; i >= 0; i--) {
		inc = pow( 2, i);
		for (int j = 0; j < inc; j++) {
			shellSort(vet, j, inc);
		}
	}
}

void betterBubbleSort(int vet[]) {
	int lim = TAM - 1, aux, k;
	bool troca = true;
	while (troca) {
		troca = false;
		for (int i = 0; i <= lim; i++) {
			if (vet[i] > vet[i + 1]) {
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
				k = i;
				troca = true;
			}
		}
		lim = k;
	}
}

void combinar(int vet[], int comeco, int meio, int fim) {
	int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
	int* vetAux = new int[tam];

	while (com1 <= meio && com2 <= fim) {
		if (vet[com1] < vet[com2]) {
			vetAux[comAux] = vet[com1];
			com1++;
		}
		else {
			vetAux[comAux] = vet[com2];
			com2++;
		}
		comAux++;
	}
	while (com1 <= meio) {
		vetAux[comAux] = vet[com1];
		comAux++;
		com1++;
	}
	while (com2 <= fim) {
		vetAux[comAux] = vet[com2];
		comAux++;
		com2++;
	}
	for (comAux = comeco; comAux <= fim; comAux++) {
		vet[comAux] = vetAux[comAux - comeco];
	}
	delete[]vetAux;
}

void mergeSort(int vet[], int inicio, int fim) {
	if (inicio == fim) return;

	int meio = (inicio + fim) / 2;

	mergeSort(vet, inicio, meio);
	mergeSort(vet, meio+1, fim);

	combinar(vet, inicio, meio, fim);

}

void quickSort(int vet[], int esq, int dir) {
    int x, i, j, aux;
    i = esq;
    j = dir;
    x = vet[(i+j)/2];
    do{
        while( x > vet[i] ) i = i + 1;
        while( x < vet[j] ) j = j -1;
        if( i <= j ){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while( i<= j );
    if( esq < j ) quickSort(vet, esq, j);
    if( dir > i ) quickSort(vet, i, dir);
}

void selecaoDiretaSort(int vet[]) {
	int posMenor, temp;
	for (int i = 0; i < TAM - 2; i++) {
		posMenor = i;
		for (int j = i + 1; j < TAM - 1; j++) {
			if (vet[j] < vet[posMenor]) {
				posMenor = j;
			}
		}
		temp = vet[i];
		vet[i] = vet[posMenor];
		vet[posMenor] = temp;
	}
}

int main()
{
	int vet[TAM];
	cout << "Vetor randomizado e depois organizado com insertion sort" << endl;
	randomizarVetor(vet);
	imprimirVetor(vet);
	insertionSort(vet);
	imprimirVetor(vet);

	int vet2[TAM];
	cout << endl;
	cout << "Vetor randomizado e depois organizado com shell sort" << endl;
	randomizarVetor(vet2);
	imprimirVetor(vet2);
	chamaShellSort(vet2, 8);
	imprimirVetor(vet2);

	/*
	int vet3[TAM];
	cout << endl;
	cout << "Vetor randomizado e depois organizado com bubble sort" << endl;
	randomizarVetor(vet3);
	imprimirVetor(vet3);
	betterBubbleSort(vet3);
	imprimirVetor(vet3);
	

	
	int vet4[TAM];
	cout << endl;
	cout << "Vetor randomizado e depois organizado com quick sort" << endl;
	randomizarVetor(vet4);
	imprimirVetor(vet4);
	quickSort(vet4, 0, 20);
	imprimirVetor(vet4);
	*/
	int vet5[TAM];
	cout << endl;
	cout << "Vetor randomizado e depois organizado com selecao direta" << endl;
	randomizarVetor(vet5);
	imprimirVetor(vet5);
	selecaoDiretaSort(vet5);
	imprimirVetor(vet5);

	/*
	int vet6[TAM];
	cout << endl;
	cout << "Vetor randomizado e depois organizado com merge sort" << endl;
	randomizarVetor(vet6);
	imprimirVetor(vet6);
	mergeSort(vet6, 0, TAM);
	imprimirVetor(vet6);
	*/
}

