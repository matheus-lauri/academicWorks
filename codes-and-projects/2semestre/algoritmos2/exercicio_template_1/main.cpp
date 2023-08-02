#include <iostream>

using namespace std;

template <typename T>
T soma_generica(T x, T y){
    return(x + y);
}

int main()
{
    bool x, y;

    cout << "Digite dois valores booleanos: " << endl;
    cin >> x >> y;

    cout << "Resultado: " << soma_generica(x, y);

    return 0;
}
