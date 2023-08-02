#pragma once
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\structs.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\sistemas.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\vila.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Selecao() {

    int tipo;
    string nome;
    criatura player;
    condicionais condicao;
    int sorte = 1 + rand() % 20;
    int chave;

    do {
        cout << "Nome: ";
        cin >> nome;
        cout << "Escolha seu personagem(Cavaleiro 1, Caçador 2, Mercenário 3) : \n";
        cin >> tipo;
    } while (tipo < 0 || tipo > 3);
    switch (tipo) {
    case 0:
        system("cls");
        cout << "Voltando ao Menu Principal...";
        Sleep(1000);
        break;
    case 1:
		chave = 1;
        CriarCriatura(player, nome, "cavaleiro", 60, 7, 16, sorte, -2, "none", "none", "none", "none"); //respectivamente variavel struct, nome, tipo, vida, ataque, defesa, sorte, furtividade e 4 tags para combate
        pegar_arma(player, "Espada longa", 7);
        pegar_armadura(player, "Armadura desgastada", 16, -2);
        
        cout << "Olá Cavaleiro " << nome << "! " << "Seus atibutos iniciais são: \n\n";
        cout << "Vida: " << player.vida << "\n";
        cout << "Ataque: " <<player.atq << "\n";
        cout << "Defesa: " << player.def << "\n";
        cout << "Sorte: " << player.srt << "\n";
        cout << "Furtividade: " << player.fur << "\n";
        system("pause");

        ChaveDeAcesso(player, condicao, chave);

        break;
    case 2:
        chave = 2;
        CriarCriatura(player, nome, "cacador", 60, 11, 12, sorte, 4, "none", "none", "none", "none"); //respectivamente variavel struct, nome, tipo, vida, ataque, defesa, sorte, furtividade e 4 tags para combate
        pegar_arma(player, "Arco de caça", 11);
        pegar_armadura(player, "Traje de pele", 12, 2);

        cout << "Olá Caçador " << nome << "! " << "Seus atibutos iniciais são: \n\n";
        cout << "Vida: " << player.vida << "\n";
        cout << "Ataque: " << player.atq << "\n";
        cout << "Defesa: " << player.def << "\n";
        cout << "Sorte: " << player.srt << "\n";
        cout << "Furtividade: " << player.fur << "\n";
        system("pause");

        ChaveDeAcesso(player, condicao, chave);
        break;
    case 3:
		chave = 3;
        CriarCriatura(player, nome, "mercenario", 60, 9, 14, sorte, 2, "none", "none", "none", "none"); //respectivamente variavel struct, nome, tipo, vida, ataque, defesa, sorte, furtividade e 4 tags para combate
        pegar_arma(player, "Machado de batalha", 9);
        pegar_armadura(player, "Armadura de couro", 14, 2);

        cout << "Olá Mercenário " << nome << "! " << "Seus atibutos iniciais são: \n\n";
        cout << "Vida: " << player.vida << "\n";
        cout << "Ataque: " << player.atq << "\n";
        cout << "Defesa: " << player.def << "\n";
        cout << "Sorte: " << player.srt << "\n";
        cout << "Furtividade: " << player.fur << "\n";
        system("pause");

        ChaveDeAcesso(player, condicao, chave);
        break;
    }
}

int Capa(int& escolha) {
    cout << R"(


  /$$$$$$$$ /$$                       /$$       /$$           /$$      
|__  $$__/| $$                      | $$      |__/          | $$      
   | $$   | $$$$$$$   /$$$$$$       | $$       /$$  /$$$$$$$| $$$$$$$ 
   | $$   | $$__  $$ /$$__  $$      | $$      | $$ /$$_____/| $$__  $$
   | $$   | $$  \ $$| $$$$$$$$      | $$      | $$| $$      | $$  \ $$
   | $$   | $$  | $$| $$_____/      | $$      | $$| $$      | $$  | $$
   | $$   | $$  | $$|  $$$$$$$      | $$$$$$$$| $$|  $$$$$$$| $$  | $$
   |__/   |__/  |__/ \_______/      |________/|__/ \_______/|__/  |__/
                                                                      

    )" << endl;

    cout << "Novo Jogo(1)\n" << "Carregar Jogo(2)\n" << "Regras(3)\n" << "Sair(4)\n";
    cin >> escolha;

    return escolha;
}
void Erro() {
    system("cls");
    cout << "Valor inválido :(" << endl;
    cout << R"(

  __ __        __    __ __      
/\ \\ \     /'__`\ /\ \\ \     
\ \ \\ \   /\ \/\ \\ \ \\ \    
 \ \ \\ \_ \ \ \ \ \\ \ \\ \_  
  \ \__ ,__\\ \ \_\ \\ \__ ,__\
   \/_/\_\_/ \ \____/ \/_/\_\_/
      \/_/    \/___/     \/_/                                
                           
  
    )" << endl;
    system("pause");
}

void Regras() {
    string lido;
    ifstream regras;
    regras.open("regras.txt");
    setlocale(LC_ALL, "pt_BR.UTF-8");
    if (regras.is_open()) {
        while (regras.eof() == false) {
            getline(regras, lido);
            cout << lido << "\n";
            Sleep(200);
        }
        system("pause");
        regras.close();
    }
    else {
        cout << "O arquivo não pode ser aberto";
    }
    setlocale(LC_ALL, "Portuguese");
}
/*
template <typename Tipo>
Tipo LerArquivoSave(ifstream arquivo_save_ler){
    Tipo lido;

    arquivo_save_ler >> lido;

    return lido;

}

void CarregarJogo() {
    criatura player;
    condicionais condicao;
    int chave;
	ifstream arquivo_save_ler;
	arquivo_save_ler.open("save.txt");

	//chave = LerArquivoSave(arquivo_save_ler);
	//getline(arquivo_save_ler, chave);
	//getline(arquivo_save_ler, player.nome);
    /*
	player.tipo = LerArquivoSave(arquivo_save_ler, 3);
	player.vida = LerArquivoSave(arquivo_save_ler, 4);
	player.atq = LerArquivoSave(arquivo_save_ler, 5);
	player.def = LerArquivoSave(arquivo_save_ler, 6);
	player.srt = LerArquivoSave(arquivo_save_ler, 7);
	player.mod_srt = LerArquivoSave(arquivo_save_ler, 8);
	player.fur = LerArquivoSave(arquivo_save_ler, 9);
	player.inv.arma = LerArquivoSave(arquivo_save_ler, 10);
	player.inv.armadura = LerArquivoSave(arquivo_save_ler, 11);
	player.inv.dano_arma = LerArquivoSave(arquivo_save_ler, 12);
	player.inv.defesa_armadura = LerArquivoSave(arquivo_save_ler, 13);
	player.inv.furtividade_armadura = LerArquivoSave(arquivo_save_ler, 14);
	player.inv.pocao = LerArquivoSave(arquivo_save_ler, 15);
	player.inv.ouro = LerArquivoSave(arquivo_save_ler, 16);
	player.inv.colar_quebrado = LerArquivoSave(arquivo_save_ler, 17);
	player.inv.colar_magico = LerArquivoSave(arquivo_save_ler, 18);
	player.inv.adaga = LerArquivoSave(arquivo_save_ler, 19);
	player.inv.cristal_quebrado = LerArquivoSave(arquivo_save_ler, 20);
    player.inv.cristal_dourado = LerArquivoSave(arquivo_save_ler, 21);
	player.inv.cristal_negro = LerArquivoSave(arquivo_save_ler, 22);
	player.inv.esc_necro = LerArquivoSave(arquivo_save_ler, 23);
    player.inv.reg_cler = LerArquivoSave(arquivo_save_ler, 24);
    player.inv.liv_ant_necro = LerArquivoSave(arquivo_save_ler, 25);
	player.inv.explosivo = LerArquivoSave(arquivo_save_ler, 26);
	condicao.inimigos.lobos = LerArquivoSave(arquivo_save_ler, 27);
	condicao.inimigos.goblins = LerArquivoSave(arquivo_save_ler, 28);
	condicao.inimigos.urso = LerArquivoSave(arquivo_save_ler, 29);
	condicao.inimigos.esqueletos = LerArquivoSave(arquivo_save_ler, 30);
	condicao.inimigos.aranha = LerArquivoSave(arquivo_save_ler, 31);
	condicao.inimigos.gargulas = LerArquivoSave(arquivo_save_ler, 32);
	condicao.eventos.cabana_visitada = LerArquivoSave(arquivo_save_ler, 33);
    condicao.eventos.caverna_visitada = LerArquivoSave(arquivo_save_ler, 34);
	condicao.eventos.ruina_visitada = LerArquivoSave(arquivo_save_ler, 35);
	condicao.eventos.urso_gerado = LerArquivoSave(arquivo_save_ler, 36);
	condicao.eventos.alquimista_visita = LerArquivoSave(arquivo_save_ler, 37);
	condicao.eventos.cabana_gaveta = LerArquivoSave(arquivo_save_ler, 38);
	condicao.eventos.machado_trocado = LerArquivoSave(arquivo_save_ler, 39);
	condicao.eventos.prisioneiro_sumiu = LerArquivoSave(arquivo_save_ler, 40);
	condicao.eventos.loja_visitada = LerArquivoSave(arquivo_save_ler, 41);
	condicao.eventos.arma_comprada = LerArquivoSave(arquivo_save_ler, 42);
	condicao.eventos.armadura_comprada = LerArquivoSave(arquivo_save_ler, 43);
	condicao.eventos.drag_fugiu = LerArquivoSave(arquivo_save_ler, 44);
	condicao.eventos.drag_domado = LerArquivoSave(arquivo_save_ler, 45);
    
    arquivo_save_ler.close();
}
*/
void MenuPrincipal() {
	int escolha = 0;
	do {
		system("cls");
		Capa(escolha);
		switch (escolha) {
		case 1:
			system("cls");
			Selecao();
			break;
		case 2:
			system("cls");
            //CarregarJogo();
			Selecao();
			break;
		case 3:
			system("cls");
			Regras();
			break;
			break;
		case 4:
			break;
		default:
			system("cls");
			Erro();
			system("pause");
		}
	} while (escolha != 4);
}