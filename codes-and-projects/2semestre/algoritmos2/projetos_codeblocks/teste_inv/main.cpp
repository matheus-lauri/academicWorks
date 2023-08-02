#include <iostream>

using namespace std;

int main()
{

    int i_coluna = 3, i_linha = 3, m_gabarito[4][4];
    int m_principal[4][4] = {1,4,5,2,
                             7,2,8,7,
                             3,6,1,4,
                             6,5,3,8};

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m_gabarito[i][j] = m_principal[i][i_coluna];
            i_coluna--;
            cout << m_gabarito[i][j];
        }
        i_coluna = 3;
        cout << "\n";
    }

    cout << "\n";

    //Matriz invertida por coluna
            for(int i = 0;i<4;i++){
                for(int j = 0;j<4;j++){
                    if(j == 0){
                    m_gabarito [i][j] = m_principal [i][j+3];
                    }
                    if(j == 1){
                    m_gabarito [i][j] = m_principal [i][j+1];
                    }
                    if(j == 2){
                    m_gabarito [i][j] = m_principal [i][j-1];
                    }
                    if(j == 3){
                    m_gabarito [i][j] = m_principal [i][j-3];
                    }
                    cout << m_gabarito[i][j];
                }
                cout << "\n";
            }
    cout << "\n";

     for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m_gabarito[i][j] = m_principal[i_linha][j];
            cout << m_gabarito[i][j];
        }
        i_linha--;
        cout << "\n";
    }

    cout << "\n";

    //Matriz invertida por linha
            for(int i = 0;i<4;i++){
                for(int j = 0;j<4;j++){
                    if(i == 0){
                    m_gabarito [i][j] = m_principal [i+3][j];
                    }
                    if(i == 1){
                    m_gabarito [i][j] = m_principal [i+1][j];
                    }
                    if(i == 2){
                    m_gabarito [i][j] = m_principal [i-1][j];
                    }
                    if(i == 3){
                    m_gabarito [i][j] = m_principal [i-3][j];
                    }
                    cout << m_gabarito[i][j];
                }
                cout << "\n";
            }

    return 0;
}
