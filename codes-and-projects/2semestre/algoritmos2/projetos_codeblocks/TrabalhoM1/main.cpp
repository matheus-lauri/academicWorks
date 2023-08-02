#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

struct inventario
{
    int pocao= 0, ouro= 0;
    bool colar_quebrado=false, colar_magico=false, adaga= false, cristal=false, esc_necro= false, esc_cler= false, esc_ruin= false;
};
struct falas
{
    string final, crit, dano, erro;
};
struct criatura
{
    string nome , tipo;
    int vida, atq, def, srt, mod_srt;
    falas resultados;
    inventario inv;
};
void CriarCriatura (criatura &c, string nome, string tipo, int hp, int damage, int def)
{
    c.nome= nome;
    c.tipo= tipo;
    c.vida= hp;
    c.atq= damage;
    c.def= def;
    int luck = 1 + rand()%20;
    c.srt= luck;
    c.mod_srt= luck/4;
    c.inv.ouro= luck*2;
}
void Selecao(){

    int tipo;
    string nome;
    criatura player;

    cout << "Nome: ";
    cin >> nome;
    cout << "Defina seu boneco(Cavaleiro 1,Caçador 2,Merceário 3):";
    cin >> tipo;
    switch(tipo){
    case 0:
        cout << "Voltando pro menu principal..." << endl;
        system("pause");
        system("cls");
        //return main();
    break;
    case 1:
        CriarCriatura(player, nome, "cavaleiro", 7, 16); //respectivamente variavel struct, nome, tipo, ataque, defesa
        cout << "C";
    break;
    case 2:
        CriarCriatura(player, nome, "caçador", 11, 12); //respectivamente variavel struct, nome, tipo, ataque, defesa
        cout << "Caça";
    break;
    case 3:
        CriarCriatura(player, nome, "mercenario", 9, 14); //respectivamente variavel struct, nome, tipo, ataque, defesa
        cout << "M";
    break;
    default:
        cout<<"erro";
        system("cls");
        Selecao();
    }


}

int Capa(int &escolha){
    cout << R"(
      _____                    _____                    _____                _____                    _____
     /\    \                  /\    \                  /\    \              /\    \                  /\    \
    /::\    \                /::\    \                /::\    \            /::\    \                /::\    \
    \:::\    \              /::::\    \              /::::\    \           \:::\    \              /::::\    \
     \:::\    \            /::::::\    \            /::::::\    \           \:::\    \            /::::::\    \
      \:::\    \          /:::/\:::\    \          /:::/\:::\    \           \:::\    \          /:::/\:::\    \
       \:::\    \        /:::/__\:::\    \        /:::/__\:::\    \           \:::\    \        /:::/__\:::\    \
       /::::\    \      /::::\   \:::\    \       \:::\   \:::\    \          /::::\    \      /::::\   \:::\    \
      /::::::\    \    /::::::\   \:::\    \    ___\:::\   \:::\    \        /::::::\    \    /::::::\   \:::\    \
     /:::/\:::\    \  /:::/\:::\   \:::\    \  /\   \:::\   \:::\    \      /:::/\:::\    \  /:::/\:::\   \:::\    \
    /:::/  \:::\____\/:::/__\:::\   \:::\____\/::\   \:::\   \:::\____\    /:::/  \:::\____\/:::/__\:::\   \:::\____\
   /:::/    \::/    /\:::\   \:::\   \::/    /\:::\   \:::\   \::/    /   /:::/    \::/    /\:::\   \:::\   \::/    /
  /:::/    / \/____/  \:::\   \:::\   \/____/  \:::\   \:::\   \/____/   /:::/    / \/____/  \:::\   \:::\   \/____/
 /:::/    /            \:::\   \:::\    \       \:::\   \:::\    \      /:::/    /            \:::\   \:::\    \
/:::/    /              \:::\   \:::\____\       \:::\   \:::\____\    /:::/    /              \:::\   \:::\____\
\::/    /                \:::\   \::/    /        \:::\  /:::/    /    \::/    /                \:::\   \::/    /
 \/____/                  \:::\   \/____/          \:::\/:::/    /      \/____/                  \:::\   \/____/
                           \:::\    \               \::::::/    /                                 \:::\    \
                            \:::\____\               \::::/    /                                   \:::\____\
                             \::/    /                \::/    /                                     \::/    /
                              \/____/                  \/____/                                       \/____/

    )" << endl;

    cout<<"Jogar(1): "<<"\nRegras(2): "<<"\nSair(3): "<< endl;
    cin >> escolha;

    return escolha;
}
void Erro(){
    cout << "Valor inválido :("<< endl;
    cout << R"(
      _             _            _
   _  /\ \         / /\       _  /\ \
  /\_\\ \ \       / /  \     /\_\\ \ \
 / / / \ \ \     / / /\ \   / / / \ \ \
/ / /   \ \ \   / / /\ \ \ / / /   \ \ \
\ \ \____\ \ \ /_/ /  \ \ \\ \ \____\ \ \
 \ \________\ \\ \ \   \ \ \\ \________\ \
  \/________/\ \\ \ \   \ \ \\/________/\ \
            \ \ \\ \ \___\ \ \         \ \ \
             \ \_\\ \/____\ \ \         \ \_\
              \/_/ \_________\/          \/_/
    )" << endl;
    system("pause");
}

void Regras(){
    string lido;
    ifstream regras;
    regras.open("regras.txt");
    if(regras.is_open()){
        while(regras.eof()==false){
            getline(regras, lido);
            cout << lido << "\n";
            Sleep(200);
        }
        system("pause");
        regras.close();
    }else{
        cout<< "O arquivo não pode ser aberto";
    }
}

int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");
    system("cls");
    int escolha;
    Capa(escolha);
    switch(escolha){
        case 1:
            system("cls");
            Selecao();
        break;
        case 2:
            system("cls");
            Regras();
            return main();
        break;
        case 3:
            return 0;
        break;
        default:
            system("cls");
            Erro();
            return main();
    }
    return 0;
}
