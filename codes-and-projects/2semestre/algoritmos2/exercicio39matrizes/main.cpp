#include <iostream>
#include <time.h>

using namespace std;

int main()
{

    int matriz[12][4];
    int i,j, t_v_mes=0, t_v_sem=0, t_v_ano=0;

    for(i=0; i<13; i++){
        for(j=0; j<5; j++){
            cout << "Insira os dados da matriz: " << endl;
            cin >> matriz[i][j];

        }
    }


    return 0;
}
