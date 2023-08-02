#pragma once
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\structs.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <locale.h>

using namespace std;

//Atualiza os status da arma quando o jogador pega/compra uma arma nova 
void pegar_arma(criatura &player, string nome, int dano)
{
    player.inv.arma = nome;
    player.inv.dano_arma = dano;
    player.atq = dano;
}

//Atualiza os status da armadura quando o jogador pega/compra uma armadura nova 
void pegar_armadura(criatura &player, string nome, int def, int fur)
{
    player.inv.armadura = nome;
    player.inv.defesa_armadura = def;
    player.inv.furtividade_armadura = fur;

    player.def = def;
    player.fur = fur;
    if (player.tipo == "cacador")
        player.fur = fur + 2;
}

//Mostra todos os atributos do jogador e os itens que o ele tem consigo
void MostrarInventario(criatura player) {

	cout << "Nome: ";
	cout << player.nome << "\n";

	cout << "Vida atual: ";
	cout << player.vida << "\n";

	cout << "Ataque: ";
	cout << player.atq << "\n";

	cout << "Defesa: ";
	cout << player.def << "\n";

	cout << "Sorte: ";
	cout << player.srt << "\n";

	cout << "Modificador de Sorte: ";
	cout << player.mod_srt << "\n";

    cout << "Segue os itens dentro do seu inventário:\n";

    cout << "- " << player.inv.ouro << " Quantidade de Ouro -\n";
    if (player.inv.pocao > 0) {
        cout << "- " << player.inv.pocao << " Poção(ões) de Cura -\n";
    }
    if (player.inv.colar_quebrado == true) {
        cout << "- Colar Quebrado -\n";
    }
    if (player.inv.colar_magico == true) {
        cout << "- Colar Mágico -\n";
    }
    if (player.inv.adaga == true) {
        cout << "- Adaga -\n";
    }
    if (player.inv.cristal_quebrado == true) {
        cout << "- Cristal Quebrado-\n";
    }
	if (player.inv.cristal_dourado == true) {
		cout << "- Cristal Dourado-\n";
	}
	if (player.inv.cristal_negro == true) {
		cout << "- Cristal Negro-\n";
	}
    if (player.inv.esc_necro == true) {
        cout << "- Escrituras de Necromancia -\n";
    }
    if (player.inv.reg_cler == true) {
        cout << "- Registros do Clerigo -\n";
    }
    if (player.inv.liv_ant_necro == true) {
        cout << "- Livros anti-Necromancia -\n";
    }

    system("pause");

}

//Mostra a opção de sair do jogo ou de mostrar o inventário quando aparece para o jogador apertar '0'
bool Opcoes(criatura player) {
    int escolha = 0;
    system("cls");
    do {
        cout << "O que você deseja fazer?" << endl;
        cout << "\n1- Abrir o inventário." << endl;
        cout << "2- Ir para o menu principal" << endl;
        cin >> escolha;
    } while (escolha < 1 || escolha > 2);
    switch (escolha) {
    case 1:
        MostrarInventario(player);
        return 0;
        break;
    case 2:
        cout << "Voltando ao Menu Principal...";
        Sleep(1000);
        return 1;
        break;
    }
    system("cls");
}

//Define as tags de combate que mudam dependendo do combate
void definir_tags (criatura &c, string fim, string crit, string dano, string erro)
{
    c.lines.fim= fim;
    c.lines.crit= crit;
    c.lines.dano= dano;
    c.lines.erro= erro;
}

//Funcao para gerar um criatura
void CriarCriatura(criatura& c, string nome, string tipo, int hp, int damage, int def, int luck, int fur, string fim, string crit, string dano, string erro)
{
    c.nome = nome;
    c.tipo = tipo;
    c.vida = hp;
    c.atq = damage;
    c.def = def;
    c.srt = luck;
    c.mod_srt = luck / 4;
    c.fur = fur;

    definir_tags(c, fim, crit, dano, erro);
}

void get_line(string tag, int linhas=1) //Função para puxar caixas de texto do arquivo  
{

	ifstream textos;
	string texto;

	textos.open("textos.txt");
    setlocale(LC_ALL, "pt_BR.UTF-8");
	do
	{
		textos >> texto;
	} while (texto != tag);

	for (int i = 0; i <= linhas; i++)
	{
		getline(textos, texto);
		cout << texto << endl;
	}
    setlocale(LC_ALL, "Portuguese");
	textos.close();
}


void ataque(criatura &atacante, criatura &vitima) //Jogada de  ataque com base em D20
{
    int d20= 1 + rand() % 20;
    if (d20==20)
    {
        vitima.vida= vitima.vida - atacante.atq*2;
        if (atacante.tipo == "cacador")
            vitima.vida= vitima.vida - atacante.atq;
        if (vitima.vida <= 0){
            cout << "--Finalização--";
            get_line(atacante.lines.fim);
            if (atacante.tipo == "cacador"){
                cout << "-" << atacante.atq * 3 << " vida";
            }else{ 
                cout << "-" << atacante.atq * 2 << " vida";
            }
        }else {
            cout << "--Crítico--";
            get_line(atacante.lines.crit);
			if (atacante.tipo == "cacador")
				cout << "-" << atacante.atq * 3 << " vida";
			else cout << "-" << atacante.atq * 2 << " vida";
        }
    }
    else
    {
        d20= d20 + atacante.mod_srt;
        if (atacante.tipo== "mercenario")
            d20= d20 + 2;
        if (d20 >= vitima.def)
        {
            vitima.vida= vitima.vida- atacante.atq;
            if (vitima.vida <= 0){
                cout << "--Finalizou--";
                get_line(atacante.lines.fim);
                    cout << "-" << atacante.atq << " de dano";
            }else { 
                cout << "--Acerto--";
                get_line(atacante.lines.dano);
				cout << "-" << atacante.atq << " de dano";
            }
        }else if (vitima.tipo=="cavaleiro" && d20 >= vitima.def-2)
        {
            cout << "\nSeus reflexos de duelista o permitiu aparar o ataque e quebrar a postura do inimigo, revidando com um ataque.";
            ataque (vitima, atacante);
        }
        else{ 
        cout << "--Erro--";
        get_line(atacante.lines.erro);

        }
    }
}

void TurnoInimigo(criatura &player, criatura &inimigo) //Turno de ataque inimigo ao todo.
{
    if (inimigo.vida > 0 && player.vida > 0)
        {
            cout << "\n\nTurno de " << inimigo.nome << endl << endl;
            ataque(inimigo, player);
            system("pause");
            system("cls");
        }
    else if (inimigo.vida > 0)
        {
            cout << "\nInimigo derrotado";
            if (player.tipo=="mercenario")
            {
                cout << "\nSeu gosto por sangue o motiva, você curou 10 de vida";
                player.vida= player.vida + 10;
                if (player.vida > 60)
                        player.vida= 60;
                system("pause");
                system("cls");
            }
        }
}


void CicloDeCombate (criatura &player, criatura &inimigo) //Ciclos de combate do jogo usando sobrecarga para suportar multiplos inimigos 
{
    while (player.vida > 0 && inimigo.vida > 0)
    {   
        int resposta;
        cout << "\n\nO turno é seu";

        cout << "\n\n" << player.nome << ": " << player.vida << " HP" << "\n\n" << inimigo.nome << ": " << inimigo.vida << " HP";

        cout << "\n\nO que você fará?\n\n1-Atacar\n2-Usar poção de cura";
        
        cout << "\n\n-";
        cin >> resposta;
        switch (resposta)
        {
            case 1: 
                ataque(player, inimigo);
                break;
            case 2:
                if (player.inv.pocao > 0)
                {
                    player.vida= player.vida + 20;
                    player.inv.pocao--;
                    cout << "\n\nVoce usou uma poção";
                    if (player.vida > 60)
                        player.vida= 60;
                }
                else cout << "\n\nVoce nao tem mais poções";
                break;
            default:
                cout << "\n\nVocê perdeu o turno";
        }
        system("pause");
        system("cls");

        TurnoInimigo(player, inimigo);
    }
}

void CicloDeCombate (criatura &player, criatura &inimigo1, criatura &inimigo2)
{
    while (player.vida > 0 && inimigo1.vida > 0 && inimigo2.vida > 0)
    {   
        int resposta;
        cout << "\n\nO turno é seu.";

        cout << "\n\n" << player.nome << ": " << player.vida << " HP" << "\n\n" << inimigo1.nome << ": " << inimigo1.vida << " HP" << "\n\n" << inimigo2.nome << ": " << inimigo2.vida << " HP";

        cout << "\n\nO que você fará?\n\n1-Atacar\n2-Usar poção de cura";
        
        cout << "\n\n-";
        cin >> resposta;
        switch (resposta)
        {
            case 1: 
                int atacar;
                    cout << "\nQual inimigo?\n1-"<< inimigo1.nome << "\n2-" << inimigo2.nome << "\n\n-";
                    cin >> atacar;

                    switch (atacar)
                    {
                    case 1:
                        ataque(player, inimigo1);
                        break;
                    case 2:
                        ataque(player, inimigo2);
                        break;
                    default:
                        cout << "\nPerdeu o turno";
                    }
                break;
            case 2:
                if (player.inv.pocao > 0)
                {
                    player.vida= player.vida + 20;
                    player.inv.pocao--;
                    cout << "\n\nVoce usou uma poção";
                    if (player.vida > 60)
                        player.vida= 60;
                }
                else cout << "\n\nVoce nao tem mais poções";
            default:
                cout << "\n\nVocê perdeu o turno";
        }
		system("pause");
        system("cls");

        TurnoInimigo(player, inimigo1);
        TurnoInimigo(player, inimigo2);

        if (inimigo1.vida <= 0)
            CicloDeCombate(player, inimigo2);
        else if (inimigo2.vida <= 0)
            CicloDeCombate(player, inimigo1);
    }
}

void CicloDeCombate (criatura &player, criatura &inimigo1, criatura &inimigo2, criatura &inimigo3) 
{
    while (player.vida > 0 && inimigo1.vida > 0 && inimigo2.vida > 0)
    {   
        int resposta;
        cout << "\n\nO turno é seu.";

        cout << "\n\n" << player.nome << ": " << player.vida << " HP" << "\n\n" << inimigo1.nome << ": " << inimigo1.vida << " HP" << "\n\n" << inimigo2.nome << ": " << inimigo2.vida << " HP" << "\n\n" << inimigo3.nome << ": " << inimigo3.vida << " HP";

        cout << "\n\nO que você fará?\n1-Atacar\n2-Usar poção de cura";

        cout << "\n\n-";
        cin >> resposta;
        switch (resposta)
        {
            case 1: 
                int atacar;
                cout << "Qual inimigo?\n1-"<< inimigo1.nome << "\n2-" << inimigo2.nome << "\n3-" << inimigo3.nome << "\n\n-";
                cin >> atacar;

                switch (atacar)
                {
                    case 1:
                        ataque(player, inimigo1);
                        break;
                    case 2:
                        ataque(player, inimigo2);
                        break;
                    case 3:
                        ataque(player, inimigo3);
                    default:
                        cout << "\nVocê perdeu o turno";
                }
                        break;

            case 2:
                if (player.inv.pocao > 0)
                {
                    player.vida= player.vida + 20;
                    player.inv.pocao--;
                    cout << "\n\nVoce usou uma poção";
                    if (player.vida > 60)
                        player.vida= 60;
                }
                else cout << "\n\nVoce nao tem mais poções";
            default:
                cout << "\n\nVocê perdeu o turno.";
                break;
        }

        TurnoInimigo(player, inimigo1);
        TurnoInimigo(player, inimigo2);
        TurnoInimigo(player, inimigo3);

        if (inimigo1.vida <= 0)
            CicloDeCombate(player, inimigo2, inimigo3);
        else if (inimigo2.vida <= 0)
            CicloDeCombate(player, inimigo1, inimigo3);
        else if (inimigo3.vida <= 0)
            CicloDeCombate(player, inimigo1, inimigo2);
    }
}

template <typename T>
void EscreveArquivoSave(T dado, ofstream &arquivo_save) {
	if (arquivo_save.is_open()) {
		arquivo_save << dado << "\n";
	}
	else {
		cout << "O arquivo não pode ser aberto";
	}
}

void SalvarJogo(criatura player, condicionais condicao, int chave) { //Sistema não implementado no jogo, já que não conseguimos ler os valores do arquivo como int ou bool.
    ofstream arquivo_save;
	arquivo_save.open("save.txt");
	//1Salvando a chave de acesso do jogador
	EscreveArquivoSave(chave, arquivo_save);
	//2Salvando o nome do jogador
	EscreveArquivoSave(player.nome, arquivo_save);
	//3Salvando o tipo do jogador
	EscreveArquivoSave(player.tipo, arquivo_save);
	//4Salvando a vida do jogador
	EscreveArquivoSave(player.vida, arquivo_save);
	//5Salvando o atq do jogador
	EscreveArquivoSave(player.atq, arquivo_save);
	//6Salvando a defesa do jogador
	EscreveArquivoSave(player.def, arquivo_save);
	//7Salvando o srt do jogador
	EscreveArquivoSave(player.srt, arquivo_save);
	//8Salvando o mod_srt do jogador
	EscreveArquivoSave(player.mod_srt, arquivo_save);
	//9Salvando o furtividade do jogador
	EscreveArquivoSave(player.fur, arquivo_save);
	//10Salvando a arma do jogador
	EscreveArquivoSave(player.inv.arma, arquivo_save);
	//11Salvando a armadura do jogador
	EscreveArquivoSave(player.inv.armadura, arquivo_save);
	//12Salvando o dano da arma do jogador
	EscreveArquivoSave(player.inv.dano_arma, arquivo_save);
	//13Salvando a defesa da armadura do jogador
	EscreveArquivoSave(player.inv.defesa_armadura, arquivo_save);
	//14Salvando a furtividade da armadura do jogador
	EscreveArquivoSave(player.inv.furtividade_armadura, arquivo_save);
	//15Salvando a qtd de poção do jogador
	EscreveArquivoSave(player.inv.pocao, arquivo_save);
	//16Salvando a qtd de ouro do jogador
	EscreveArquivoSave(player.inv.ouro, arquivo_save);
	//17Salvando o colar quebrado do jogador
	EscreveArquivoSave(player.inv.colar_quebrado, arquivo_save);
	//18Salvando o colar magico do jogador
	EscreveArquivoSave(player.inv.colar_magico, arquivo_save);
	//19Salvando a adaga quebrado do jogador
	EscreveArquivoSave(player.inv.adaga, arquivo_save);
	//20Salvando o cristal quebrado do jogador
	EscreveArquivoSave(player.inv.cristal_quebrado, arquivo_save);
	//21Salvando o cristal dourado do jogador
	EscreveArquivoSave(player.inv.cristal_dourado, arquivo_save);
	//22Salvando o cristal negro do jogador
	EscreveArquivoSave(player.inv.cristal_negro, arquivo_save);
	//23Salvando a escritura de necromancia do jogador
	EscreveArquivoSave(player.inv.esc_necro, arquivo_save);
	//24Salvando os registros do clerigo do jogador
	EscreveArquivoSave(player.inv.reg_cler, arquivo_save);
	//25Salvando o livro anti-necromancia do jogador
	EscreveArquivoSave(player.inv.liv_ant_necro, arquivo_save);
	//26Salvando o explosivo do jogador
	EscreveArquivoSave(player.inv.explosivo, arquivo_save);
	//27Salvando os lobos
	EscreveArquivoSave(condicao.inimigos.lobos, arquivo_save);
    //28Salvando os globins
	EscreveArquivoSave(condicao.inimigos.goblins, arquivo_save);
    //29Salvando o urso
	EscreveArquivoSave(condicao.inimigos.urso, arquivo_save);
    //30Salvando os esqueletos
	EscreveArquivoSave(condicao.inimigos.esqueletos, arquivo_save);
    //31Salvando a aranha
	EscreveArquivoSave(condicao.inimigos.aranha, arquivo_save);
	//32Salvando as gargulas
	EscreveArquivoSave(condicao.inimigos.gargulas, arquivo_save);
	//33Salvando a cabana visitada
	EscreveArquivoSave(condicao.eventos.cabana_visitada, arquivo_save);
	//34Salvando a caverna visitada
	EscreveArquivoSave(condicao.eventos.caverna_visitada, arquivo_save);
	//35Salvando a ruina visitada
	EscreveArquivoSave(condicao.eventos.ruina_visitada, arquivo_save);
	//36Salvando o urso gerado
	EscreveArquivoSave(condicao.eventos.urso_gerado, arquivo_save);
    //37Salvando o alquimista visita
	EscreveArquivoSave(condicao.eventos.alquimista_visita, arquivo_save);
    //38Salvando a cabana gaveta
	EscreveArquivoSave(condicao.eventos.cabana_gaveta, arquivo_save);
    //39Salvando o machado trocado
	EscreveArquivoSave(condicao.eventos.machado_trocado, arquivo_save);
	//40Salvando o prisioneiro sumiu
	EscreveArquivoSave(condicao.eventos.prisioneiro_sumiu, arquivo_save);
	//41Salvando a loja visitada
	EscreveArquivoSave(condicao.eventos.loja_visitada, arquivo_save);
	//42Salvando a arma comprada
	EscreveArquivoSave(condicao.eventos.arma_comprada, arquivo_save);
	//43Salvando a armadura comprada
	EscreveArquivoSave(condicao.eventos.armadura_comprada, arquivo_save);
	//44Salvando o dragão fugiu
	EscreveArquivoSave(condicao.eventos.drag_fugiu, arquivo_save);
	//45Salvando o dragão domado
	EscreveArquivoSave(condicao.eventos.drag_domado, arquivo_save);
    arquivo_save.close();
}