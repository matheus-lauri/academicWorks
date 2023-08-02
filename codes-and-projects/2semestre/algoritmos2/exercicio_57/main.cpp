#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int val=0,menor,media,soma=0,soma_t=0,n_val=0;

    while( val != -1){

        cout << "Informe um valor: " << endl;
        cin >> val;

        if(val != -1){
            if(val > 100 && val < 1000){
                if(n_val == 0){
                    menor = val;
                }
                if(val < menor){
                    val = menor;
                }
                n_val++;
            }

        }
    }
    soma = soma + val;
    media = soma / n_val;
    soma_t = soma + soma_t + val;
    if(n_val == 0){
        cout << "Nenhum dos valores estão entre o intervalo" << endl;
    }

    cout << "Menor entre o intervalo: " << menor << "\nMédia entre o intervalo: " << media << "\nSoma entre o intervalo: " << soma << "\nSoma de todos os valores: "<< soma_t << endl;

    return 0;
}
