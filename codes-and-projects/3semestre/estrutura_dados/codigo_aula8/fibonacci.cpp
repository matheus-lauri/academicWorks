#include <iostream>
using namespace std;

int fibonacci(int pos){
    if( pos == 1 || pos == 2 ) return 1;
    return fibonacci(pos-1) + fibonacci(pos-2);
}

int main(){
    int num;

    do{
        cout << "Informe a posicao: ";
        cin >> num;
    }while( num < 1);
    cout << "F(" << num << ") = " << fibonacci(num);
    cout << endl;

    do{
        cout << "Até qual a posicao? ";
        cin >> num;
    }while( num < 1);
    cout << "Fibonacci: ";
    for( int i=1; i<=num; i++ )
        cout << fibonacci(i) << ", ";
    cout << endl;
}
