#include <iostream>
using namespace std;

struct Data{
    unsigned int dia, mes, ano;
};

bool anoBissexto( int ano ){
    return ((ano % 4 == 0) && ((!(ano % 100 == 0)) ||
    (ano % 400 == 0)));
}

void mostrarData( Data *d ){
    cout << d->dia << "/" << d->mes << "/" << d->ano;
}

Data *novaData(int d, int m, int a){
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( anoBissexto(a) ) dias[2] = 29;

    if( m >= 1 && m <= 12 && a > 1900 && d > 0 && d <= dias[m] ){
        Data *data = new Data;
        data->dia = d;
        data->mes = m;
        data->ano = a;
        return data;
    }
    return NULL;
}


/*Retorna 0 se data1 == data2, um número positivo se
  data1 > data2, ou negativo se data1 < data2. */
int compararData(Data *data1, Data *data2){
    int D_anos = data1->ano - data2->ano;
    int D_meses = data1->mes - data2->mes;
    int D_dias = data1->dia - data2->dia;

    if (D_anos != 0) return D_anos;
    if (D_meses != 0) return D_meses;
    return D_dias;
}

int main(){
    Data *d1, *d2;

    d1 = novaData(24, 3, 2023);
    d2 = novaData(29, 4, 2023);

    if( d1 == NULL || d2 == NULL ){
        cout << "Data invalida" << endl;
        return 0;
    }

    mostrarData(d1);
    int x = compararData(d1, d2 );
    if( x == 0 ) cout << " = ";
    else if( x < 0 ) cout << " < ";
    else cout << " > ";
    mostrarData(d2);
    cout << endl;
}
