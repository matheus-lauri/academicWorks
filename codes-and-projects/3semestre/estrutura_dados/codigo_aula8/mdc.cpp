#include <iostream>
using namespace std;

int mdc( int a, int b ){
    if( a == b ) return a;
//    if( a < b )
//        return mdc( a, b-a );
//    else
//        return mdc( b, a-b );
    return (a<b) ? mdc( a, b-a ) : mdc( b, a-b );
}

int main(){

    cout << "mdc(12,20) = " << mdc(12,20) << endl;
    cout << "mdc(48,160) = " << mdc(48,160) << endl;
    cout << "mdc(17,31) = " << mdc(17,31) << endl;
    cout << "mdc(52,65) = " << mdc(52,65) << endl;
}
