#include <iostream>

using namespace std;

bool par(int n);

bool impar(int n){
    if(n == 0){
        return false;
    } else if(n == 1){
        return true;
    }

    return par(n-1);
}

bool par(int n){
    if(n == 0){
        return true;
    } else if(n == 1){
        return false;
    }

    return impar(n-1);
}

int fibonacci(int pos){
    if(pos <= 2){
        return 1;
    }
    return fibonacci(pos - 1) + fibonacci(pos - 2);
}

int main()
{
    int n = 4;
    cout << par(n) << "\n";
    int pos = 6;
    cout << fibonacci(pos) << "\n";
    return 0;
}
