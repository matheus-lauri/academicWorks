#pragma once
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\structs.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\sistemas.h"  
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

void pre_combate_lobos(criatura& player, condicionais& condicao) // preparacao e conclusao do combate com lobos 
{
	criatura lobo1, lobo2, lobo3;
	CriarCriatura(lobo1, "Lobo 1", "Lobo", 23, 5, 13, 0, 0, "lobo_final", "lobo_crit", "lobo_dano", "lobo_erro");
	CriarCriatura(lobo2, "Lobo 2", "Lobo", 23, 5, 13, 0, 0, "lobo_final", "lobo_crit", "lobo_dano", "lobo_erro");
	CriarCriatura(lobo3, "Lobo 3", "Lobo", 23, 5, 13, 0, 0, "lobo_final", "lobo_crit", "lobo_dano", "lobo_erro");

	if (player.tipo == "cavaleiro")
		definir_tags(player, "cav_lobo_final", "cav_lobo_crit", "cav_lobo_dano", "cav_lobo_erro");
	if (player.tipo == "cacador")
		definir_tags(player, "cac_lobo_final", "cac_lobo_crit", "cac_lobo_dano", "cac_lobo_erro");
	if (player.tipo == "mercenario")
		definir_tags(player, "mer_lobo_final", "mer_lobo_crit", "mer_lobo_dano", "mer_lobo_erro");

	CicloDeCombate(player, lobo1, lobo2, lobo3);

	if (player.vida <= 0){
		cout << "\nVocê morreu.";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nVocê ganhou! recompensa: 25G";
		player.inv.ouro = player.inv.ouro + 25;
		cout << "\nSeu ouro: " << player.inv.ouro;
		condicao.inimigos.lobos = false;
		system("pause");
		system("cls");
	}
}

void pre_combate_goblin(criatura& player, condicionais& condicao) // preparacao e conclusao do combate com goblins
{
	criatura goblin1, goblin2, goblin3;
	CriarCriatura(goblin1, "Goblin Pálido", "Goblin", 20, 7, 11, 0, 0, "goblin_final", "goblin_crit", "goblin_dano", "goblin_erro");
	CriarCriatura(goblin2, "Goblin Verde", "Goblin", 20, 7, 11, 0, 0, "goblin_final", "goblin_crit", "goblin_dano", "goblin_erro");
	CriarCriatura(goblin3, "Goblin Rozado", "Goblin", 20, 7, 11, 0, 0, "goblin_final", "goblin_crit", "goblin_dano", "goblin_erro");

	if (player.tipo == "cavaleiro")
		definir_tags(player, "cav_goblin_final", "cav_goblin_crit", "cav_goblin_dano", "cav_goblin_erro");
	if (player.tipo == "cacador")
		definir_tags(player, "cac_goblin_final", "cac_goblin_crit", "cac_goblin_dano", "cac_goblin_erro");
	if (player.tipo == "mercenario")
		definir_tags(player, "mer_goblin_final", "mer_goblin_crit", "mer_goblin_dano", "mer_goblin_erro");

	CicloDeCombate(player, goblin1, goblin2, goblin3);

	if (player.vida <= 0){
		cout << "\nVocê morreu.";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nVocê ganhou! recompensa: 25G";
		player.inv.ouro = player.inv.ouro + 25;
		cout << "\nSeu ouro: " << player.inv.ouro;
		if (player.tipo == "cacador")
		{
			int d20 = 1 + rand() % 20 + player.mod_srt;
			int escolha;
			if (d20 > 12)
			{
				system("pause");
				system("cls");
				do {
					cout << "Há uma espada longa refinada no corpo do goblin verde\n";
					cout << "aparenta ter uma qualidade melhor que a sua.";
					cout << "\nArma atual- " << player.inv.arma << ": " << player.inv.dano_arma << "de dano.";
					cout << "\n\nArma nos escombros- Espada longa refinada: 9 de dano";
					cout << "\n\nPegar arma?\n\n1- Sim\n\n2-Não\n\n-";
					cin >> escolha;

					switch (escolha)
					{
					case 1:
						cout << "\nVocê pegou a espada longa e deixou a sua arma nos escombros.";
						pegar_arma(player, "Espada longa refinada", 9);
						break;
					case 2:
						cout << "\nVocê decide ficar com a sua arma.";
						break;
					}
				} while (escolha < 1 || escolha > 2);
			}
		}
		condicao.inimigos.goblins = false;
	}
}

void Goblins(criatura& player, condicionais& condicao, int& chave) { //sistema para spawnar os goblins com base em aletoriedade  
	int escolha;
	if (condicao.inimigos.goblins == true) {
		if (int d20 = 1 + rand() % 20 > player.srt) {
			do {
				system("cls");
				get_line("encontro_goblins", 3);
				cout << "\n\nO que você irá fazer?\n";
				cout << "1- Lutar\n";
				cout << "2- Passar furtivamente\n";
				cout << "3- Passar correndo\n";
				cin >> escolha;
			} while (escolha < 1 || escolha > 4);
			switch (escolha) {
			case 1:
				system("cls");
				pre_combate_goblin(player, condicao);
				break;
			case 2:
				system("cls");
				if (d20 = 1 + rand() % 20 + player.fur > 10) {
					cout << "Você conseguiu passar furtivamente\n";
					system("pause");
					system("cls");
				}
				else {
					cout << "Você não conseguiu passar furtivamente e terá que lutar\n";
					system("pause");
					system("cls");
					pre_combate_goblin(player, condicao);
				}
				break;
			case 3:
				system("cls");
				cout << "Você não conseguiu passar correndo e terá que lutar\n";
				system("pause");
				system("cls");
				pre_combate_goblin(player, condicao);
				break;
			}
		}
	}
}

void Cabana(criatura& player, condicionais& condicao, int& chave) { //funcao da cabana
	bool sair=0;
	int escolha;
	system("cls");
	if (condicao.inimigos.lobos == true) {
		system("cls");
		get_line("encontro_lobos", 2);
		pre_combate_lobos(player, condicao);
	}
	if (player.vida > 0) {
	if (condicao.eventos.cabana_visitada == false) {
		system("cls");
		get_line("desc_cabana_primeira", 3);
		system("pause");
		do {
			if (player.inv.cristal_quebrado == false && player.inv.adaga == false) {
				do {
					system("cls");
					cout << "O que você irá fazer?\n";
					cout << "1- Checar gavetas\n";
					cout << "2- Pegar Cristal Quebrado\n";
					cout << "3- Pegar Adaga\n";
					cout << "4- Sair da Cabana\n";
					cin >> escolha;

				} while (escolha < 0 || escolha > 4);
			}
			else if (player.inv.cristal_quebrado == false && player.inv.adaga == true) {
				do {
					system("cls");
					cout << "O que você irá fazer?\n";
					cout << "1- Checar gavetas\n";
					cout << "2- Pegar Cristal Misterioso\n";
					cout << "3- Sair da Cabana\n";
					cin >> escolha;

				} while (escolha < 0 || escolha > 3);
			}
			else if (player.inv.cristal_quebrado == true && player.inv.adaga == false) {
				do {
					system("cls");
					cout << "O que você irá fazer?\n";
					cout << "1- Checar gavetas\n";
					cout << "2- Pegar Adaga\n";
					cout << "3- Sair da Cabana\n";
					cin >> escolha;

				} while (escolha < 0 || escolha > 3);
			}
			else if (player.inv.cristal_quebrado == true && player.inv.adaga == true) {
				do {
					system("cls");
					cout << "O que você irá fazer?\n";
					cout << "1- Checar gavetas\n";
					cout << "2- Sair da Cabana\n";
					cin >> escolha;
				} while (escolha < 0 || escolha > 2);
			}
			if (escolha == 0) {
				sair = Opcoes(player);
			}
			switch (escolha) {
			case 1:
				system("cls");
				if (condicao.eventos.cabana_gaveta == true) {
					cout << "Você encontrou 3 poções e 20 moedas de ouro\n";
					system("pause");
					player.inv.pocao = player.inv.pocao + 3;
					player.inv.ouro = player.inv.ouro + 20;
					condicao.eventos.cabana_gaveta = false;
				}
				else {

					cout << "Não há mais nada aqui\n";
					system("pause");
				}
				break;
			case 2:
				system("cls");
				if (player.inv.cristal_quebrado == false) {
					get_line("pegou_cristal");
					system("pause");
					player.inv.cristal_quebrado = true;
					player.inv.reg_cler = true;
				}
				else if (player.inv.adaga == false) {
					get_line("pegou_adaga");
					system("pause");
					player.inv.adaga = true;
				}
				else {
					condicao.eventos.cabana_visitada = true;
					Goblins(player, condicao, chave);
					sair = 1;
					chave = 4;
				}
				break;
			case 3:
				system("cls");
				if (player.inv.adaga == false) {
					get_line("pegou_adaga");
					system("pause");
					player.inv.adaga = true;
				}
				else {
					condicao.eventos.cabana_visitada = true;
					Goblins(player, condicao, chave);
					sair = 1;
					chave = 4;
				}
				break;
			case 4:
				system("cls");
				condicao.eventos.cabana_visitada = true;
				Goblins(player, condicao, chave);
				sair = 1;
				chave = 4;
				break;
			}
			condicao.eventos.cabana_visitada = true;
		} while (sair == 0);
	}
	else {
		cout << "Você entra na cabana novamente...\n";
		do {
			if (player.inv.cristal_quebrado == false && player.inv.adaga == false) {
				do {
					system("cls");
					cout << "O que você deseja fazer?\n";
					cout << "1- Checar gavetas\n";
					cout << "2- Pegar Cristal Misterioso\n";
					cout << "3- Pegar Adaga\n";
					cout << "4- Sair da Cabana\n";
					cin >> escolha;

				} while (escolha < 0 || escolha > 4);
			}
			else if (player.inv.cristal_quebrado == false && player.inv.adaga == true) {
				do {
					system("cls");
					cout << "O que você deseja fazer?\n";
					cout << "1- Checar gavetas\n";
					cout << "2- Pegar Cristal Quebrado\n";
					cout << "3- Sair da Cabana\n";
					cin >> escolha;

				} while (escolha < 0 || escolha > 3);
			}
			else if (player.inv.cristal_quebrado == true && player.inv.adaga == false) {
				do {
					system("cls");
					cout << "O que você deseja fazer?\n";
					cout << "1- Checar gavetas\n";
					cout << "2- Pegar Adaga\n";
					cout << "3- Sair da Cabana\n";
					cin >> escolha;

				} while (escolha < 0 || escolha > 3);
			}
			else if (player.inv.cristal_quebrado == true && player.inv.adaga == true) {
				do {
					system("cls");
					cout << "O que você deseja fazer?\n";
					player.inv.reg_cler = true;
					cout << "1- Checar gavetas\n";
					cout << "2- Sair da Cabana\n";
					cin >> escolha;
				} while (escolha < 0 || escolha > 2);
			}
			if (escolha == 0) {
				sair = Opcoes(player);
			}
			switch (escolha) {
			case 1:
				if (condicao.eventos.cabana_gaveta == true) {
					cout << "Você encontrou 3 poções e 20 moedas de ouro\n";
					system("pause");
					player.inv.pocao = player.inv.pocao + 3;
					player.inv.ouro = player.inv.ouro + 20;
					condicao.eventos.cabana_gaveta = false;
				}
				else {
					cout << "Não há mais nada aqui\n";
					system("pause");
				}
				break;
			case 2:
				if (player.inv.cristal_quebrado == false) {
					player.inv.cristal_quebrado = true;
					player.inv.reg_cler = true;
				}
				else if (player.inv.adaga == false) {
					player.inv.adaga = true;
				}
				else {
					Goblins(player, condicao, chave);
					sair = 1;
					chave = 4;
				}
				break;
			case 3:
				if (player.inv.adaga == false) {
					player.inv.adaga = true;
				}
				else {
					Goblins(player, condicao, chave);
					sair = 1;
					if(player.vida >0)
					chave = 4;
				}
				break;
			case 4:
				Goblins(player, condicao, chave);
				sair = 1;
				if(player.vida > 0)
				chave = 4;
				break;
			}

		} while (sair == 0);
	}
}
}

void InicioCacador(criatura &player, condicionais &condicao, int &chave){
	
	int escolha;
	bool sair=0;
	int sorte;

	do{
	system ("cls");
	
	get_line("inicio_cacador", 5);

		cout << "\n\nO que você irá fazer?\n";
		cout << "1- Atirar uma flecha no cervo\n";
		cout << "2- Observar o comportamento do cervo a distância\n";
		cout << "3- Ignorar o cervo e buscar por outro alvo\n";
		cin >> escolha;
		if (escolha == 0) {
			sair = Opcoes(player);
		}
	switch(escolha) {
	
	case 1:
		sorte = rand() % 2;
		switch(sorte){
		case 0:
			system("cls");
			cout << "Você errou...\n";
			system("pause");
			system("cls");
			cout << "Triste pela falta de sorte você continua seu caminho...\n";
			system("pause");
			system("cls");
			get_line("seguir_floresta", 2);
			system("pause");
			Cabana(player, condicao, chave);
			break;
		case 1:
			system("cls");
			cout << "Você acertou...\n";
			system("pause");
			do{
				system("cls");
				get_line("cervo_morto", 2);
				cout << "\n\nO que você irá fazer?\n";
				cout << "1- Entrar em direção ao interior da floresta em busca de respostas\n";
				cout << "2- Coletar uma amostra do sangue e voltar para a vila\n";
				cin >> escolha;
				if (escolha == 0) {
					sair = Opcoes(player);
				}
			switch (escolha) {
				case 1:
					system("cls");
					get_line("seguir_floresta", 2);
					system("pause");
					system("cls");
					Cabana(player, condicao, chave);
					break;
				case 2:
					sair = 1;
					chave = 4;
					break;
			}
			} while ((escolha < 0 || escolha > 2) && sair == 0);
			break;
		}
	break;
	case 2:
		system("cls");
		get_line("seguir_servo", 4);
		system("pause");
		Cabana(player, condicao, chave);
	break;
	case 3:
		system("cls");
		get_line("seguir_floresta", 2);
		system("pause");
		Cabana(player, condicao, chave);
	break;
	}
	} while ((escolha < 0 || escolha > 3) && sair == 0);
}