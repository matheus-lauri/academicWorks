#include <iostream>
#include "lue.hpp"
#define TAM 10
using namespace std;

int ler_valor( char frase[], int min, int max ){
    int x;

    do{
        cout << frase << " (entre " << min << " e " << max << "): ";
        cin >> x;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            x = min-1;
        }
    }while( x < min || x > max );
    return x;
}

int calcularEndereco(int num){
    return num % TAM;
}

template <typename T>
bool inserirHash( LUE <T> lista[], int num ){
    int pos = calcularEndereco(num);
    return inserirLUE(lista[pos], num );
}

template <typename T>
bool retirarHash( LUE <T> lista[], int num ){
    int pos = calcularEndereco(num);
    return retirarLUE(lista[pos], num);
}

template <typename T>
bool buscarHash( LUE <T> lista[], int num ){
    int pos = calcularEndereco(num);
    return (buscarLUE(lista[pos], num) == NULL ) ? false : true;
}

int main(){
    LUE <int> lista[TAM];
    int op, num;

    for( int i=0; i<TAM; i++ )
        inicializarLUE(lista[i]);

    do{
        cout << "Escolha a funcao: " << endl;
        cout << "\t1. Inserir" << endl;
        cout << "\t2. Retirar" << endl;
        cout << "\t3. Pesquisar" << endl;
        cout << "\t4. Mostra tudo" << endl;
        cout << "\t0. Fim" << endl;

        op = ler_valor( "Opcao: ", 0, 4 );

        switch( op ){
            case 1:
                num = ler_valor( "Digite o valor ", 1, 1000 );
                if( inserirHash( lista, num ) )
                    cout << "Valor inserido com sucesso" << endl;
                else
                    cout << "Erro na insercao do valor" << endl;
                break;
            case 2:
                num = ler_valor( "Digite o valor a retirar ", 1, 1000);
                if( retirarHash(lista, num) )
                    cout << "Valor retirado com sucesso" << endl;
                else
                    cout << "Valor nao encontrado" << endl;
                break;
            case 3:
                num = ler_valor( "Digite o valor a buscar ", 1, 1000);
                if( buscarHash(lista, num) )
                    cout << "Valor encontrado" << endl;
                else
                    cout << "Valor nao encontrado" << endl;
                break;
            case 4:
                cout << "Tabela completa" << endl;
                for( int i=0; i<TAM; i++ ){
                    cout << i;
                    mostrarLUE(lista[i], "");
                    cout << endl;
                }
                break;
        }

    }while( op != 0 );
    cout << endl;
}
