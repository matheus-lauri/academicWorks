#pragma once
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\structs.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\sistemas.h"  
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\final.h"  
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

void pre_combate_aranha(criatura& player, condicionais& condicao) // prepara��o e conclus�o do combate com a aranha.
{
	criatura aranha;
	CriarCriatura(aranha, "Aranha Gigante", "aranha", 22, 13, 10, 0, 0, "aranha_final", "aranha_crit", "aranha_dano", "aranha_erro");

	if (player.tipo == "cavaleiro")
		definir_tags(player, "cav_aranha_final", "cav_aranha_crit", "cav_aranha_dano", "cav_aranha_erro");
	if (player.tipo == "cacador")
		definir_tags(player, "cac_aranha_final", "cac_aranha_crit", "cac_aranha_dano", "cac_aranha_erro");
	if (player.tipo == "mercenario")
		definir_tags(player, "mer_aranha_final", "mer_aranha_crit", "mer_aranha_dano", "mer_aranha_erro");

	CicloDeCombate(player, aranha);

	if (player.vida <= 0){
		cout << "\nVoc� morreu.";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nVoc� ganhou! recompensa: 20G";
		player.inv.ouro = player.inv.ouro + 20;
		cout << "\nSeu ouro: " << player.inv.ouro << endl; 
		condicao.inimigos.aranha = false;
		system("pause");
		system("cls");
	}
}

void pre_combate_gargulas(criatura& player, condicionais& condicao)  //prepara��o e conclus�o do combate com as gargulas
{
	criatura gargula1, gargula2;
	CriarCriatura(gargula1, "Gargula 1", "gargula", 24, 7, 13, 0, 0, "gargula_final", "gargula_crit", "gargula_dano", "gargula_erro");
	CriarCriatura(gargula2, "Gargula 2", "gargula", 24, 7, 13, 0, 0, "gargula_final", "gargula_crit", "gargula_dano", "gargula_erro");

	if (player.tipo == "cavaleiro"){
		definir_tags(player, "cav_gargula_final", "cav_gargula_crit", "cav_gargula_dano", "cav_gargula_erro");
	}
	if (player.tipo == "cacador"){
		definir_tags(player, "cac_gargula_final", "cac_gargula_crit", "cac_gargula_dano", "cac_gargula_erro");
	}
	if (player.tipo == "mercenario"){
		definir_tags(player, "mer_gargula_final", "mer_gargula_crit", "mer_gargula_dano", "mer_gargula_erro");
	}

	CicloDeCombate(player, gargula1, gargula2);

	if (player.vida <= 0){
		cout << "\nVoc� morreu.";
		system("pause");
		system("cls");
	}else{
		cout << "\nVoc� ganhou! recompensa: 40G";
		player.inv.ouro = player.inv.ouro + 40;
		cout << "\nSeu ouro: " << player.inv.ouro;
		condicao.inimigos.gargulas = false;
		system("pause");
		system("cls");
	}
}

void Portao(criatura& player, condicionais& condicao, int& chave) { //Entrada do port�o, ele s� abrir� ao ter os itens necess�rios para o boss final, h� tamb�m aqui os caminhos alternativos para explorar a cidade. 
	int escolha;
	bool sair = 0;

	if (condicao.inimigos.gargulas == true) {
		int d20 = 1 + rand() % 20;
		if (d20 >= player.srt) {
			system("cls");
			get_line("encontro_gargulas", 3);
			system("pause");
			pre_combate_gargulas(player, condicao);
		}
	}
	if(player.vida > 0) {
	do {

		system("cls");
		get_line("ruinas_descricao", 3);

		cout << "\n\nO que voc� ir� fazer?\n";
		cout << "1- Tentar abrir o port�o\n";
		cout << "2- Continuar procurando outro lugar\n";
		cout << "3- Voltar para a vila\n";
		cin >> escolha;
		if (escolha == 0) {
			sair = Opcoes(player);
		}
		switch (escolha) {
		case 1:
			system("cls");
			if (player.inv.explosivo == true) {
				cout << "Voc� bota o explosivo no p� do port�o, a explos�o abre caminho para voc�\n";
				system("pause");
				sair = 1;
				player.inv.explosivo = false;
				Dragao(player, condicao, chave);
			}
			else {
				cout << "Voc� tenta abrir mas o port�o continua fechado\n";
				system("pause");
			}
			break;
		case 2:
			do {
				system("cls");
				get_line("caminho_torre", 4);
				system("pause");
				system("cls");
				get_line("livro_anti_necro", 2);
				cout << "\n\nVoc� deseja pegar o livro?\n";
				cout << "1- Sim\n";
				cout << "2- N�o\n";
				cin >> escolha;
				if (escolha == 0) {
					sair = Opcoes(player);
				}
				switch (escolha) {
				case 1:
					system("cls");
					cout << "\nVoc� pega livro...\n";
					player.inv.liv_ant_necro = true;
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "\n\nVoc� n�o pegou o livro...\n";
					system("pause");
					break;
				}
			} while ((escolha < 0 || escolha > 2) && sair == 0);

			do {
				system("cls");
				if (player.inv.liv_ant_necro) {
					cout << "\nAgora que voc� pegou o livro... \n\nO que voc� deseja fazer?\n";
				}
				else {
					cout << "\nJ� que voc� n�o pegou o livro... \n\nO que voc� gostaria de fazer?\n";
				}
				cout << "1- Voltar para vila\n";
				cout << "2- Explorar ainda mais\n";
				cin >> escolha;
				if (escolha == 0) {
					sair = Opcoes(player);
				}
				switch (escolha) {
				case 1:
					system("cls");
					sair = 1;
					chave = 4;
					break;
				case 2:
					system("cls");
					get_line("explorar_cidade", 2);
					player.inv.colar_quebrado = true;
					system("pause");
					system("cls");
					sair = 1;
					chave = 4;
					break;
				}
			} while ((escolha < 0 || escolha > 2) && sair == 0);
			break;
		case 3:
			cout << "Voc� n�o encontra nada de conveniente ent�o decide voltar para a vila\n";
			system("pause");
			sair = 1;
			chave = 4;
			break;
		}
	} while ((escolha < 0 || escolha==1 || escolha > 3) && sair == 0);
}
}

void Ruina(criatura& player, condicionais& condicao, int& chave) { //funcao caso a aranha esteja viva ainda
	if(condicao.inimigos.aranha == true){
		system("cls");
		get_line("aranha_encontro_geral", 2);
		pre_combate_aranha(player, condicao);
	}else {
		system("cls");
		get_line("ruinas_descricao", 3);
		system("pause");
	}
	if (player.vida > 0)
		Portao(player, condicao, chave);
}

void InicioCavaleiro(criatura &player, condicionais &condicao, int &chave) {
	
	int escolha;
	bool sair = 0;

	if (condicao.inimigos.aranha == true) {
		do {
			system("cls");
			get_line("inicio_cavaleiro", 6);

			cout << "\n\nO que voc� ir� fazer?\n";
			cout << "1- Empunhar a espada e enfrentar a aranha\n";
			cout << "2- Correr\n";
			cin >> escolha;
			if (escolha == 0) {
				sair = Opcoes(player);
			}
			switch (escolha) {
			case 1:
				system("cls");
				pre_combate_aranha(player, condicao);
				if (player.vida > 0){
					if (condicao.inimigos.aranha == false) {
						system("cls");
						get_line("cavaleiro_aranha_matou", 5);
						system("pause");
						do {
							system("cls");

							cout << "\n\nO que voc� ir� fazer?\n";
							cout << "1- Voltar para a vila\n";
							cout << "2- Continuar investigando sobre a aranha \n";
							cin >> escolha;
							if (escolha == 0) {
								sair = Opcoes(player);
							}
							switch (escolha) {
							case 1:
								system("cls");
								sair = 1;
								chave = 4;
								break;
							case 2:
								system("cls");
								Portao(player, condicao, chave);
								break;
							}
						} while ((escolha < 0 || escolha > 2) && sair == 0);
					}
				}
			break;
			case 2:
				do {
					system("cls");
					get_line("cavaleiro_aranha_fugiu", 5);
					
					cout << "\n\nO que voc� ir� fazer?\n";
					cout << "1- Voltar para a vila\n";
					cout << "2- Continuar investigando sobre a aranha \n";
					cin >> escolha;
					if (escolha == 0) {
						sair = Opcoes(player);
					}
					switch (escolha) {
						case 1:
							system("cls");
							sair = 1;
							chave = 4;
							break;
						case 2:
							system("cls");
							Portao(player, condicao, chave);
							break;
					}
				} while ((escolha < 0 || escolha > 2) && sair == 0);
				break;
			}
		} while ((escolha < 0 || escolha > 3) && sair == 0);
	}
}