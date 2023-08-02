#include <iostream>

using namespace std;

int Dec2Bin(int n){
 if(n < 1){
    return 0;
 }
    return n%2 + 10*Dec2Bin(n/2);

}

bool primo(int vet[], int pos){

    for(int i = 2;i < vet[pos];i++){
        if(vet[pos] % i == 0){
            return 0;
        }
    }
    return 1;

}

int contar(int vet[], int pos){

    if(pos < 0){
        return 0;
    }
    return primo(vet, pos) + contar(vet,pos - 1);

}

int main()
{
    int n = 2;
    cout << Dec2Bin(n) << "\n";

    int  pos = 5;
    int vet[pos];

    for(int i = 0; i < 5; i++){
        vet[i] = 12;
    }

    cout << contar(vet, pos);

    return 0;
}
