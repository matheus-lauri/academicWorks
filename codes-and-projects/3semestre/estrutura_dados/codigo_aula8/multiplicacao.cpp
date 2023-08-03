#include <iostream>
using namespace std;

int produto( int a, int b ){
    if( a == 1 ) return b;
    return b + produto(a-1, b);
}

int main(){

    cout << "6 x 8 = " << produto(6,8) << endl;
    cout << "12 x 7 = " << produto(12,7) << endl;
    cout << "9 x 15 = " << produto(9,15) << endl;
}
