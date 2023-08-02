/*ESQUELETO PARA UM JOGO DE LABIRINTO UTILIZANDO RECURSOS APRENDIDOS EM AULA
OBS: O programa tem melhorias óbvias considerando os conteúdos vistos em aula
- Por exemplo, o arquivo não é atualizado no final da execução

Enunciado da atividade feita em aula:
Faça um programa que lê um arquivo com indicações de espaço livre(0), barreira(1), personagem(2)
O jogo deve ter uma função que permite o movimento do personagem pelas posições livres sem deixar rastro

*/

/*
Desenvolvido por Gustavo Baron Lauritzen, Matheus Baron Lauritzen e Gabriel Bósio
*/

#include <iostream>
#include <fstream>
#include <conio.h> //getch()
#include <windows.h> ///remover
#include <time.h>
#include <ctime>

using namespace std;

#define debuf 5.0

struct PLAYER {
    int x, y, campo= 3, blind=0;
    bool andar=1, ver=1;
    float Dvisao, Dfreeze;
    string nome = "Player";


    //Define as coordenadas x e y do player para linha e coluna da matriz
    void coord (int li, int co){
        x=li;
        y=co;
    }
    //Imobiliza o player
    void parar(float temp){
        //Tira a condição de andar
        andar=0;
        //Armazena o instante em que o jogador andou em cima do buff
        Dfreeze= temp;
    }
    //O player volta a andar
    void rebuff_andar(float temp)
    {
        //Verifica se o tempo do congelamento acabou
        if(Dfreeze < temp - 5.0)
        {
            //Define a codição de andar igual a true
            andar=1;
        }
    }
    //Diminui o campo de visão do player
    void cegar(int range,float temp){
        system("cls");
        ver = 0;
        //Diminui o campo de visão a partir de um novo range
        campo = campo-range;
        blind = range;
        //Armazena o instante em que o jogador andou em cima do buff
        Dvisao = temp;
    }
    //Define o campo de visão ao normal
    void rebuff_visao(float temp)
    {
        //Verifica se o tempo do campo de visão reduzido acabou
        if(Dvisao < temp - 5.0)
        {
            //Campo de visão volta ao tamanho normal
            campo= campo + blind;
            blind=0;
            ver=1;
        }
    }
};

struct ARQUIVO {
    const char* nome;
    int x, y;
    int** m;
    int t0=0;

    void tam(int li, int co){
        x=li;
        y=co;
    }

    //Carrega a matriz
    void carrega (){
        m = new int*[x];
        for (int i=0; i<x; i++){
            m[i]=new int[y];
        }

        ifstream mapa;
        mapa.open(nome);
        char c;

        //Coloca o mapa na matriz
        for(int i=0; i<x;i++){
            for(int j=0; j<y;j++){
                    mapa>>c;
                    m[i][j]=c-48;
            }
        }
    }

    void loadtime()
    {
        char c;
        ifstream load;
        load.open("cronometro.txt");
        load >> c;
        t0 = (c-48)*1000;
        load >> c;
        t0 = t0 + (c-48)*100;
        load >> c;
        t0 = t0 + (c-48)*10;
        load >> c;
        t0 = t0 + (c-48);
        load.close();
    }

};

//Salva o jogo
void salvar (ARQUIVO mapa, PLAYER p1, PLAYER p2, int temp)
{
    ofstream save;
    save.open ("save.txt");
    for (int i=0; i < mapa.x; i++)
    {
        for(int j=0; j < mapa.y; j++)
        {
            save << mapa.m[i][j];
        }
        save << "\n";
    }
    save.close();
    save.open ("players.txt");
    if (p1.x < 10)
        save << '0';
    save << p1.x << endl;
    if (p1.y < 10)
        save << '0';
    save << p1.y << endl;
    if (p2.x < 10)
        save << '0';
    save << p2.x << endl;
    if (p2.y < 10)
        save << '0';
    save << p2.y;
    save.close();
    save.open("cronometro.txt");
    if (temp < 10)
        save << '0';
    if (temp < 100)
        save << '0';
    if (temp < 1000)
        save << '0';
    save << temp;
    save.close();
}

//Encontra as últimas coordenadas salvas dos jogadores
void achar_p (PLAYER &p1, PLAYER &p2)
{
    ifstream player;
    player.open("players.txt");
    char c;
    player >> c;
    p1.x = (c-48)*10;
    player >> c;
    p1.x = p1.x + (c-48);
    player >> c;
    p1.y = (c-48)*10;
    player >> c;
    p1.y = p1.y + (c-48);
    player >> c;
    p2.x = (c-48)*10;
    player >> c;
    p2.x = p2.x + (c-48);
    player >> c;
    p2.y = (c-48)*10;
    player >> c;
    p2.y = p2.y + (c-48);
}

//Menu do jogo
int menu ()
{
    int escolha= 0;

    do
    {
        cout << "                                                                                                              " << endl;
        cout << "   MMMMMMMM               MMMMMMMM               AAA               ZZZZZZZZZZZZZZZZZZZEEEEEEEEEEEEEEEEEEEEEE  " << endl;
        cout << "   M:::::::M             M:::::::M              A:::A              Z:::::::::::::::::ZE::::::::::::::::::::E  " << endl;
        cout << "   M::::::::M           M::::::::M             A:::::A             Z:::::::::::::::::ZE::::::::::::::::::::E  " << endl;
        cout << "   M:::::::::M         M:::::::::M            A:::::::A            Z:::ZZZZZZZZ:::::Z EE::::::EEEEEEEEE::::E  " << endl;
        cout << "   M::::::::::M       M::::::::::M           A:::::::::A           ZZZZZ     Z:::::Z    E:::::E       EEEEEE  " << endl;
        cout << "   M:::::::::::M     M:::::::::::M          A:::::A:::::A                  Z:::::Z      E:::::E               " << endl;
        cout << "   M:::::::M::::M   M::::M:::::::M         A:::::A A:::::A                Z:::::Z       E::::::EEEEEEEEEE     " << endl;
        cout << "   M::::::M M::::M M::::M M::::::M        A:::::A   A:::::A              Z:::::Z        E:::::::::::::::E     " << endl;
        cout << "   M::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A            Z:::::Z         E:::::::::::::::E     " << endl;
        cout << "   M::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A          Z:::::Z          E::::::EEEEEEEEEE     " << endl;
        cout << "   M::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A        Z:::::Z           E:::::E               " << endl;
        cout << "   M::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A    ZZZ:::::Z     ZZZZZ  E:::::E       EEEEEE  " << endl;
        cout << "   M::::::M               M::::::M   A:::::A             A:::::A   Z::::::ZZZZZZZZ:::ZEE::::::EEEEEEEE:::::E  " << endl;
        cout << "   M::::::M               M::::::M  A:::::A               A:::::A  Z:::::::::::::::::ZE::::::::::::::::::::E  " << endl;
        cout << "   M::::::M               M::::::M A:::::A                 A:::::A Z:::::::::::::::::ZE::::::::::::::::::::E  " << endl;
        cout << "   MMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAAZZZZZZZZZZZZZZZZZZZEEEEEEEEEEEEEEEEEEEEEE  " << endl;
        cout << "                                                                                                              " << endl;
        cout << "\n\n1-Novo jogo\n2-Continuar Jogo\n3-Mostrar Rank\n(Para salvar o jogo: aperte a tecla 'p' durante o jogo)\n\n-";
        cin >> escolha;
        system ("cls");
    }while (escolha < 1 && escolha > 3);
    return escolha;
}

//Define a visibilidade do cursor
void mostrarCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

//Define a coordenada do cursor
void posicaoxy( int column, int line )
    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
    }

//Mostra o mapa do jogador 1
void mostra_mapa1 (PLAYER p, ARQUIVO a) {
    bool achou=0;
    int linha=5;
    posicaoxy(6,4);
    cout << "--- JOGADOR 1 ---\n";
    posicaoxy(10 + p.blind, linha + p.blind);
    for (int i=p.x - p.campo; i<= p.x + p.campo; i++){
        for (int j= p.y - p.campo; j<= p.y + p.campo; j++){
            switch(a.m[i][j]){
            case 0: cout<<" "; break;
            case 1: cout<<char(219); break;
            case 2: cout<<char(2); break;
            case 3: cout <<char(207); break;
            case 4: cout <<char(157); break;
            case 5: cout <<char(176); break;
            }
        }
        linha++;
        posicaoxy(10 + p.blind,linha + p.blind);
    }
}

//Mostra o mapa do jogador 2
void mostra_mapa2 (PLAYER p, ARQUIVO a) {
    int linha=5;
    posicaoxy(46,4);
    cout << "--- JOGADOR 2 ---\n";
    posicaoxy(50 + p.blind, linha + p.blind);
    for (int i=p.y - p.campo; i<= p.y + p.campo; i++){
        for (int j= p.x - p.campo; j<= p.x + p.campo; j++){
            switch(a.m[j][i]){
            case 0: cout<<" "; break;
            case 1: cout<<char(219); break;
            case 2: cout<<char(2); break;
            case 3: cout <<char(207); break;
            case 4: cout <<char(157); break;
            case 5: cout <<char(176); break;
            }
        }
        linha++;
        posicaoxy(50 + p.blind,linha + p.blind);
    }
}

//Cria portais
void portal(ARQUIVO &mapa, PLAYER &p)
{
    int tx, ty;
    mapa.m[p.x][p.y] = 0;
    do
    {
        tx= 5 + rand()%38;
        ty= 5 + rand()%38;
        p.coord(tx, ty);
    }while(mapa.m[tx][ty] == 1);

    mapa.m[tx][ty] = 2;
}

//Checa se os campos de visões dos jogadores se encontraram
bool checar(PLAYER p1, PLAYER p2)
{
    for (int i= p1.x - p1.campo; i <= p1.x + p1.campo; i++)
    {
        for (int j= p1.y - p1.campo; j <= p1.y + p1.campo; j++)
        {
            if(p2.x == i && p2.y == j)
            return 1;
        }
    }
    return 0;
}

//Move os jogadores
void mover (PLAYER &p1, PLAYER &p2, ARQUIVO &mapa, float temp){
    char tecla= _getch();
    switch (tecla){
    case 'w':
        if(p1.andar)
        {
            if(mapa.m[p1.x-1][p1.y]==3)
                portal(mapa, p1);
            else if(mapa.m[p1.x-1][p1.y]!=1){
                switch(mapa.m[p1.x-1][p1.y]){
            case 4:
                p2.cegar(2, temp);
                break;
            case 5:
                p2.parar(temp);
                break;
                }

                mapa.m[p1.x][p1.y]=0;
                mapa.m[p1.x-1][p1.y]=2;
                p1.x=p1.x-1;
            }
        }
        break;
    case 's':
         if(p1.andar)
         {
             if(mapa.m[p1.x+1][p1.y]==3)
                portal(mapa, p1);
            else if(mapa.m[p1.x+1][p1.y]!=1){
                switch(mapa.m[p1.x+1][p1.y]){
            case 4:
                p2.cegar(2,temp);
                break;
            case 5:
                p2.parar(temp);
                break;
                }
                mapa.m[p1.x][p1.y]=0;
                mapa.m[p1.x+1][p1.y]=2;
                p1.x=p1.x+1;
            }
         }
        break;
    case 'a':
        if(p1.andar)
        {
            if(mapa.m[p1.x][p1.y-1]==3)
                portal(mapa, p1);
            else if(mapa.m[p1.x][p1.y-1]!=1){
                switch(mapa.m[p1.x][p1.y-1]){
            case 4:
                p2.cegar(2,temp);
                break;
            case 5:
                p2.parar(temp);
                break;
                }

                mapa.m[p1.x][p1.y]=0;
                mapa.m[p1.x][p1.y-1]=2;
                p1.y=p1.y-1;
            }
        }
        break;
    case 'd':
        if(p1.andar)
        {
            if(mapa.m[p1.x][p1.y+1]==3)
                portal(mapa, p1);
            else if(mapa.m[p1.x][p1.y+1]!=1){
                switch(mapa.m[p1.x][p1.y+1]){
            case 4:
                p2.cegar(2,temp);
                break;
            case 5:
                p2.parar(temp);
                break;
                }
                mapa.m[p1.x][p1.y]=0;
                mapa.m[p1.x][p1.y+1]=2;
                p1.y=p1.y+1;
            }
        }
        break;
        case 75:
        if(p2.andar)
        {
            if(mapa.m[p2.x-1][p2.y]==3)
                portal(mapa, p2);
            else if(mapa.m[p2.x-1][p2.y]!=1){
                switch(mapa.m[p2.x-1][p2.y]){
            case 4:
                p1.cegar(2,temp);
                break;
            case 5:
                p1.parar(temp);
                break;
                }
                mapa.m[p2.x][p2.y]=0;
                mapa.m[p2.x-1][p2.y]=2;
                p2.x=p2.x-1;
            }
        }
        break;
    case 77:
         if(p2.andar)
         {
            if(mapa.m[p2.x+1][p2.y]==3)
                portal(mapa, p2);
            else if(mapa.m[p2.x+1][p2.y]!=1){
                switch(mapa.m[p2.x+1][p2.y]){
            case 4:
                p1.cegar(2,temp);
                break;
            case 5:
                p1.parar(temp);
                break;
                }
                mapa.m[p2.x][p2.y]=0;
                mapa.m[p2.x+1][p2.y]=2;
                p2.x=p2.x+1;
            }
         }

        break;
    case 72:
        if(p2.andar)
        {
            if(mapa.m[p2.x][p2.y-1]==3)
                portal(mapa, p2);
            else if(mapa.m[p2.x][p2.y-1]!=1){
                switch(mapa.m[p2.x][p2.y-1]){
            case 4:
                p1.cegar(2, temp);
                break;
            case 5:
                p1.parar(temp);
                break;
                }
                mapa.m[p2.x][p2.y]=0;
                mapa.m[p2.x][p2.y-1]=2;
                p2.y=p2.y-1;
            }
        }

        break;
    case 80:
        if(p2.andar)
        {
            if(mapa.m[p2.x][p2.y+1]==3)
                portal(mapa, p2);
            else if(mapa.m[p2.x][p2.y+1]!=1){
                switch(mapa.m[p2.x][p2.y+1]){
            case 4:
                p1.cegar(2,temp);
                break;
            case 5:
                p1.parar(temp);
                break;
                }
                mapa.m[p2.x][p2.y]=0;
                mapa.m[p2.x][p2.y+1]=2;
                p2.y=p2.y+1;
            }
        }

        break;
    case 'p':
        salvar(mapa, p1, p2, temp);
    }
}

//Verifica se o tempo do buff acabou
void check_debuf(PLAYER& p, float temp)
{
    if(p.andar==0)
    {
        p.rebuff_andar(temp);
    }
    if(p.ver==0)
    {
        p.rebuff_visao(temp);
    }
}

//Ordena os vetores
void bubble (int v[], int t, string v2[]){
    int temp;
    string temp2;
    for (int i=0;i<t;i++){
        for (int j=0;j<t-1;j++){
            if(v[j]<v[j-1]){
                //ordenando vetor com os tempos
                temp=v[j];
                v[j]=v[j-1];
                v[j-1]=temp;
                //ordenando vetor com os nomes
                temp2=v2[j];
                v2[j]=v2[j-1];
                v2[j-1]=temp2;
            }
        }
    }
}

void show_order_rank()
{
    int v_temp[100];
    string v_nomes[100];

    //preenche o vetor com os tempos com valores default
    for(int i = 0;i < 100; i++){
        v_temp[i] = 10000;
    }

    //preenche o vetor com os nomes com valores default
    for(int i = 0;i < 100; i++){
        v_nomes[i] = "none";
    }

    //lendo tempos
    ifstream tempo;
    tempo.open("tempo.txt");
    char c;
    int i = 0;
    while(tempo.eof() == false){
        tempo >> c;
        v_temp[i] = (c-48)*10;
        tempo >> c;
        v_temp[i] = v_temp[i] + (c-48);
        i++;
    }
    tempo.close();

    //lendo nomes
    ifstream nome;
    nome.open("nome.txt");
    int j = 0;
    while(nome.eof() == false){
        getline(nome,v_nomes[j]);
        j++;
    }

    nome.close();

    //ordenando nomes e tempos
    bubble(v_temp, i, v_nomes);

    //mostra o rank
    cout << "---------RANK---------" << endl;

    int minutos, segundos;
    for(int i = 0; i < 10; i++){
        minutos= v_temp[i]/60;
        segundos= v_temp[i]%60;
        switch(v_temp[i]){
        case 10000:
            cout << v_nomes[i] << " || " << "0" << "min : " << "0" << "sec" << endl;
            break;
        default:
            cout << v_nomes[i] << " || " << minutos << "min : " << segundos << "sec" << endl;
            break;
        }
    }

    system("pause");

}

//Escreve o nome e o tempo nos arquivos txt
void save_rank(PLAYER p, float temp)
{
    cout << "Digite um nome para salvar no rank:\n";
    cin >> p.nome;

    ofstream ranque;
    ranque.open ("tempo.txt", ios_base::app);
    if (temp < 10)
        ranque << '0';
    ranque << int(temp) << endl;
    ranque.close();

    ranque.open ("nome.txt", ios_base::app);
    ranque << p.nome << endl;
    ranque.close();

    show_order_rank();
}

//Função de tempo
void relogio(int temp){

    posicaoxy(5, 14);
    int minutos, segundos;
    minutos= temp/60;
    segundos= temp%60;

    cout<<"Tempo: ";
    if (minutos < 10)
        cout << 0;
    cout << minutos << ":";
     if (segundos < 10)
        cout << 0;
    cout << segundos;

}

int main()
{
    //Criando uma variável para cada jogador
    PLAYER p1, p2;

    //Criando a variavel do mapa
    ARQUIVO mapa;

    //Inicializando a variável seleção
    int selec= 0;

    //Menu iniciar do jogo
    selec = menu();
    switch(selec)
    {
    //Caso o jogador escolha "Novo Jogo"
    case 1:
        //Colocando a coordenada padrão de cada jogador
        p1.coord(5,41);
        p2.coord(40,6);

        //Abrindo o arquivo txt com o labirinto
        mapa.nome="labirinto.txt";
        mapa.tam(50,50);
        mapa.carrega();

        break;
    //Caso o jogador escolha "Continuar Jogo"
    case 2:
        mapa.nome= "save.txt";
        mapa.tam(50,50);
        mapa.loadtime();
        mapa.carrega();
        //Chamando função para achar a última coordenada salva pelo jogador
        achar_p(p1, p2);
        break;
    case 3:
        system("cls");
        show_order_rank();
        return 0;
        break;
    }
    //Não deixa o cursor ficar piscando
    mostrarCursor(false);
    //Cria a variável de tempo incial
    clock_t inicio;
    //Pega a hora inicio de acordo com a bilbioteca <ctime>
    inicio = clock();
    clock_t soma=33.33;
    //Variável que irá guardar o tempo em segundos na hora de verificar os buffs
    float temp;

    bool fim = 0;
    while (fim == 0){
        //Função contador de tempo
        temp= ((( clock() - inicio + soma ) / (double) CLOCKS_PER_SEC)+ mapa.t0);
        relogio(temp);
        //Checa se o jogo chegou ao fim
        fim = checar(p1, p2);
        //Mostra o mapa do jogador 1
        mostra_mapa1(p1, mapa);
        //Mostra o mapa do jogador 2
        mostra_mapa2(p2, mapa);
        //Move os dois jogadores
        mover(p1, p2, mapa, temp);
        //Verifica se o bu
        check_debuf(p1,temp);
        check_debuf(p2,temp);
    }
    posicaoxy(5, 16);
    //Condição de vitória
    cout << "Game Over, jogador 1 Venceu!!!\n\n";
    system("pause");

    system("cls");
    save_rank(p1, temp);

    delete []mapa.m;

    return 0;
}
