#include <iostream>
using namespace std;

int main() {

    //autores do código: Elena Nunes, Gustavo Baron Lauritzen e Matheus Baron Lauritzen

    //Reconhece a linguagem do português
    setlocale(LC_ALL, "Portuguese");

    //Declaração das variáveis utilizadas durante o algoritmo
    long long int passo3, passo4, passo5, passo6, passo7, n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, num;

    //Entrada do código de barras para ser verificado   
    cout << "Insira o código de barras: " << endl;
    cin >> num;

    //Encontrando o dígito verificador
    n0 = num % 10;

    //Descobrindo os digitos do código de barras para seguir com a verificação
    n1 = (num / 10) % 10;
    n2 = (num / 100) % 10;
    n3 = (num / 1000) % 10;
    n4 = (num / 10000) % 10;
    n5 = (num / 100000) % 10;
    n6 = (num / 1000000) % 10;
    n7 = (num / 10000000) % 10;
    n8 = (num / 100000000) % 10;
    n9 = (num / 1000000000) % 10;
    n10 = (num / 10000000000) % 10;
    n11 = (num / 100000000000) % 10;
    n12 = (num / 1000000000000) % 10;

    //Multiplicando os dígitos ímpares por 3
    n1 = n1 * 3;
    n2 = n2 * 1;
    n3 = n3 * 3;
    n4 = n4 * 1;
    n5 = n5 * 3;
    n6 = n6 * 1;
    n7 = n7 * 3;
    n8 = n8 * 1;
    n9 = n9 * 3;
    n10 = n10 * 1;
    n11 = n11 * 3;
    n12 = n12 * 1;

    //Calculando o somatório dos resultados da multiplicação
    passo3 = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10 + n11 + n12;

    //Dividindo o resultado da soma por 10
    passo4 = passo3 / 10;

    //Somando 1 ao resultado da divisão
    passo5 = passo4 + 1;

    //Multiplicando o resultado da divisão por 10
    passo6 = passo5 * 10;

    //Subtraindo o resultado do passo 6 pelo resultado do passo 3
    passo7 = passo6 - passo3;

    /*Verifica o resultado do dígito verificador e substitui por zero,
      caso o resultado do dígito verificador(passo7) for múltiplo de 10*/
    if (passo7 % 10 == 0) {
        passo7 = 0;
    }

    //Parte de Verificação
    if ((num >= 1000000000000 && num <= 9999999999999) == false) { /*Verifica os códigos de barras que possuírem mais ou menos do que 13 dígitos*/
        cout << "O seu código de barras não possui 13 dígitos, tente novamente!" << endl;
    }
    else if (passo7 != n0) { /*Verifica os a os códigos que passarem nos testes de tamanho, mas possuem um erro no dígito verificador*/
        cout << "Dígito verificador inconsistente, tente novamente!" << endl;
    }
    else if (passo7 == n0) { //Verifica se o dígito verificador é verdadeiro
        cout << "Código de barras correto!" << endl;
    }

    return 0;

}