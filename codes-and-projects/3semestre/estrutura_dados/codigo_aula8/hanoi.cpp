#include <iostream>
using namespace std;

void hanoi( int n, char origem, char dest, char temp ){
    if( n==1 ){
        cout << "Mover o disco " << n << " de " << origem << " para " << dest << endl;
        return;
    }
    hanoi( n-1, origem, temp, dest );
    cout << "Mover o disco " << n << " de " << origem << " para " << dest << endl;
    hanoi( n-1, temp, dest, origem );
}

int main(){
    int num;

    do{
        cout << "Informe a quantidade de discos (>0): ";
        cin >> num;
    }while( num < 1);
    cout << "Movimentos para " << num << " discos:" << endl;
    hanoi( num, 'A', 'B', 'C' );
}
