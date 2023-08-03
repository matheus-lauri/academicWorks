//Integrantes do Trabalho: Gustavo Baron Lauritzen e Matheus Baron Lauritzen

#include <iostream>

using namespace std;

struct NoCompromisso {
    int hComeco, mComeco, hFim, mFim;
    string* texto;
    NoCompromisso* eloA, * eloP;
};

struct Data {
    unsigned int dia, mes, ano; //"unsigned int" faz com que você só tenha numeros int positivos
};

struct NoData {
    Data data;
    NoCompromisso* comecoCompromisso, * fimCompromisso;
    NoData* eloA, *eloP;
};

struct Agenda {
    NoData* comeco, * fim;
};

//Verifica se é ano bissexto
bool anoBissexto(int ano) {
    return ((ano % 4 == 0) && ((!(ano % 100 == 0)) ||
        (ano % 400 == 0)));
}

//Verifica se é uma data válida
Data* novaData(int d, int m, int a) {
    int dias[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (anoBissexto(a)) dias[2] = 29;

    if (m >= 1 && m <= 12 && a > 1900 && d > 0 && d <= dias[m]) {
        Data* data = new Data;
        data->dia = d;
        data->mes = m;
        data->ano = a;
        return data;
    }
    return NULL;
}

/*Retorna 0 se data1 == data2, um n�mero positivo se
  data1 > data2, ou negativo se data1 < data2. */
int compararData(Data* data1, Data* data2) {
    int D_anos = data1->ano - data2->ano;
    int D_meses = data1->mes - data2->mes;
    int D_dias = data1->dia - data2->dia;

    if (D_anos != 0) return D_anos;
    if (D_meses != 0) return D_meses;
    return D_dias;
}

/*Retorna 0 se data1 == data2, um n�mero positivo se
  data1 > data2, ou negativo se data1 < data2. */
int compararData(Data data1, Data data2) {
    int D_anos = data1.ano - data2.ano;
    int D_meses = data1.mes - data2.mes;
    int D_dias = data1.dia - data2.dia;

    if (D_anos != 0) return D_anos;
    if (D_meses != 0) return D_meses;
    return D_dias;
}

/*Retorna 0 se data1 == data2, um n�mero positivo se
  data1 > data2, ou negativo se data1 < data2. */
int compararData(Data data1, Data* data2) {
    int D_anos = data1.ano - data2->ano;
    int D_meses = data1.mes - data2->mes;
    int D_dias = data1.dia - data2->dia;

    if (D_anos != 0) return D_anos;
    if (D_meses != 0) return D_meses;
    return D_dias;
}

void inicializarLstData(Agenda& lst) {
    lst.comeco = NULL;
    lst.fim = NULL;
}

bool inserirFinalLstData(Agenda& lst, Data* d) {
    NoData* novo = new NoData;
    if (novo == NULL) return false;

    //Guardando a informacao no novo no
    novo->data.dia = d->dia;
    novo->data.mes = d->mes;
    novo->data.ano = d->ano;
    //Setando os elos como nulos pois não apontam para nada por enquanto
    novo->eloA = NULL;
    novo->eloP = NULL;

    //Verificando se é o primeiro, ou unico
    if (lst.comeco == NULL) {
        lst.comeco = novo;
        lst.fim = novo;
    }
    else {
        lst.fim->eloP = novo;
        novo->eloA = lst.fim;
        lst.fim = novo;
    }
    return true;
}

bool inserirOrdenadoLstData(Agenda& lst, Data * d) {
    NoData* novo = new NoData;
    if (novo == NULL) return false;

    novo->data.dia = d->dia;
    novo->data.mes = d->mes;
    novo->data.ano = d->ano;

    // Lista vazia
    if (lst.comeco == NULL) {
        lst.comeco = novo;
        lst.fim = novo;
        return true;
    }

    // Inserir no inicio
    int x = compararData(novo->data, lst.comeco->data);
    if (x < 0) {
        novo->eloP = lst.comeco;
        lst.comeco->eloA = novo;
        lst.comeco = novo;
        return true;
    }
    
    // Inserir no final
    int y = compararData(novo->data, lst.fim->data);
    if (y > 0) {
        lst.fim->eloP = novo;
        novo->eloA = lst.fim;
        lst.fim = novo;
        return true;
    }
    
    NoData* aux = lst.comeco;
    //comparando datas, usando a funcao de comparar e adicionando o retorno em variaveis
    //auxiliares "a" e "b" para poder comparar no laco de repeticao
    int a = compararData(novo->data, aux->data);
    int b = compararData(novo->data, aux->eloP->data);
    while (a > 0 && b > 0) {
        aux = aux->eloP;
        a = compararData(novo->data, aux->data);
        b = compararData(novo->data, aux->eloP->data);
    }
    // Inserir no meio da lista
    NoData* prox = aux->eloP;
    novo->eloA = aux;
    novo->eloP = prox;
    aux->eloP = novo;
    prox->eloA = novo;
    return true;
}

NoData* buscarData(Agenda lst, Data *d) {
    NoData* aux = lst.comeco;
    int a;
    while (aux != NULL) {
        a = compararData(aux->data, d);
        if (a == 0) return aux;
        aux = aux->eloP;
    }
    return NULL;
}

bool retirarData(Agenda& lst, Data* d) {
    NoData* aux, * ant, * prox;

    aux = buscarData(lst, d);
    if (aux == NULL) return false; // Valor nao encontrado

    ant = aux->eloA;
    prox = aux->eloP;

    // Remover o primeiro ou unico
    if (aux == lst.comeco) {
        lst.comeco = prox;
        if (aux == lst.fim) lst.fim = prox;
        else prox->eloA = NULL;
    }
    else {
        ant->eloP = aux->eloP;
        if (aux == lst.fim) lst.fim = ant;
        else prox->eloA = ant;
    }
    delete aux;
    return true;
}

void mostrarlstData(Agenda lst, string frase) {
    NoData* aux = lst.comeco;

    cout << frase << ": ";
    while (aux != NULL) {
        cout << aux->data.dia << "/" << aux->data.mes << "/" << aux->data.ano << "  ";
        aux = aux->eloP;
    }
    cout << endl;
}

void 

int main() {
    
    Agenda lista1;

	inicializarLstData(lista1);
    Data* d1 = novaData(30, 01, 2004);
    Data* d2 = novaData(20, 01, 2004);
    Data* d3 = novaData(20, 12, 2004);
    Data* d4 = novaData(20, 12, 2005);
    Data* d5 = novaData(16, 10, 2020);

    if (d1 == NULL || d2 == NULL || d3 == NULL || d4 == NULL) {
        cout << "Data invalida" << endl;
        return 0;
    }
    
    inserirFinalLstData(lista1, d1);
    inserirFinalLstData(lista1, d2);
    mostrarlstData(lista1, "lista 1: ");

    Agenda lista2;

    inicializarLstData(lista2);
    
    inserirOrdenadoLstData(lista2, d3);
    inserirOrdenadoLstData(lista2, d2);
    inserirOrdenadoLstData(lista2, d4);
    inserirOrdenadoLstData(lista2, d5);
    inserirOrdenadoLstData(lista2, d1);
    mostrarlstData(lista2, "lista 2: ");
    retirarData(lista2, d5);
    mostrarlstData(lista2, "lista 2: ");

}