#include <iostream>

using namespace std;

class PlayerC{
    int idade = 1;

public:
    void SetIdade(int i){
        if(i > 0){
            idade = i;
        }
    }
    int GetIdade(){
        return idade;
    }
};

int main()
{

    PlayerC PC;

    PC.SetIdade(18);

    cout << PC.GetIdade();

    return 0;
}
