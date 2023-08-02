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

void encontro_prisioneiro(criatura& player, condicionais &condicao)
{
	if (condicao.eventos.caverna_visitada == false) {
		system("cls");
		get_line("ser_estranho_descricao", 2);
		system("pause");
		if (condicao.eventos.alquimista_visita) {
			system("cls");
			get_line("ser_estranho_primeiro_vila", 6);
			system("pause");
		}
		else {
			system("cls");
			get_line("ser_estranho_primeiro", 5);
			system("pause");
		}
	}
	else if (condicao.eventos.prisioneiro_sumiu)
	{
		system("cls");
		get_line("ser_estranho_sumiu");
		system("pause");
	}
	else
	{
		system("cls");
		get_line("ser_estranho_descricao_depois");
		system("pause");
		if(player.inv.cristal_dourado && player.inv.adaga && player.inv.colar_quebrado)
		{
			int escolha = 0;
			do
			{
				system("cls");
				get_line("ser_estranho_final", 9);
				cout << "\n-";
				cin >> escolha;
				switch(escolha)
				{
					case 1:
						system("cls");
						get_line("ser_estranho_final_aceito", 9);
						system("pause");
						system("cls");

						player.inv.cristal_dourado = false;
						player.inv.cristal_negro = true;

						player.inv.colar_quebrado = false;
						player.inv.colar_magico = true;

						condicao.eventos.prisioneiro_sumiu = true;
						break;
					case 2:
						system("cls");
						get_line("ser_estranho_final_negado");
						system("pause");
						system("cls");
						break;
				}
			} while (escolha > 2 || escolha < 1);
		}
		else
		{
			get_line("ser_estranho_sem_itens");
			system("pause");
			system("cls");
		}
	}
}

void pre_combate_esqueletos(criatura& player, condicionais& condicao) // preparacao e conclusao do combate com esqueletos
{
	criatura esqueleto1, esqueleto2;
	CriarCriatura(esqueleto1, "Esqueleto 1", "Esqueleto", 15, 13, 11, 0, 0, "esqueleto_final", "esqueleto_crit", "esqueleto_dano", "esqueleto_erro");
	CriarCriatura(esqueleto2, "Esqueleto 2", "Esqueleto", 15, 13, 11, 0, 0, "esqueleto_final", "esqueleto_crit", "esqueleto_dano", "esqueleto_erro");

	if (player.tipo == "cavaleiro")
		definir_tags(player, "cav_esqueleto_final", "cav_esqueleto_crit", "cav_esqueleto_dano", "cav_esqueleto_erro");
	if (player.tipo == "cacador")
		definir_tags(player, "cac_esqueleto_final", "cac_esqueleto_crit", "cac_esqueleto_dano", "cac_esqueleto_erro");
	if (player.tipo == "mercenario")
		definir_tags(player, "mer_esqueleto_final", "mer_esqueleto_crit", "mer_esqueleto_dano", "mer_esqueleto_erro");

	CicloDeCombate(player, esqueleto1, esqueleto2);

	if (player.vida <= 0){
		cout << "\nVocê morreu.";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nVocê ganhou! recompensa: 30G\n";
		player.inv.ouro = player.inv.ouro + 30;
		cout << "\nSeu ouro: " << player.inv.ouro;
		condicao.inimigos.esqueletos = false;
		system("pause");
		system("cls");

		if (player.tipo == "cacador")
		{
			int d20 = 1 + rand() % 20 + player.mod_srt;
			int escolha;
			if (d20 > 12)
			{
				system("pause");
				system("cls");
				do {
					cout << "Há um arco longo nos escombros dos esqueletos, não há flechas,\n";
					cout << "mas a qualidade do arco é melhor que a sua.";
					cout << "\nArma atual- " << player.inv.arma << ": " << player.inv.dano_arma << "de dano.";
					cout << "\n\nArma nos escombros- Arco longo: 13 de dano";
					cout << "\n\nPegar arma?\n\n1- Sim\n\n2-Não\n\n-";
					cin >> escolha;

					switch (escolha)
					{
					case 1:
						cout << "\nVocê pegou o arco longo e deixou a sua arma nos escombros.";
						pegar_arma(player, "Arco Longo", 13);
						break;
					case 2:
						cout << "\nVocê decide ficar com a sua arma.";
						break;
					}
				} while (escolha < 1 || escolha > 2);
			}
		}
	}
}

void pre_combate_urso(criatura & player, condicionais & condicao){ // preparacao e conclusao do combate com urso
	criatura urso;
	CriarCriatura(urso, "Urso", "Urso", 30, 8, 16, 0, 0, "urso_final", "urso_crit", "urso_dano", "urso_erro");

	if (player.tipo == "cavaleiro")
		definir_tags(player, "cav_urso_final", "cav_urso_crit", "cav_urso_dano", "cav_urso_erro");
	if (player.tipo == "cacador")
		definir_tags(player, "cac_urso_final", "cac_urso_crit", "cac_urso_dano", "cac_urso_erro");
	if (player.tipo == "mercenario")
		definir_tags(player, "mer_urso_final", "mer_urso_crit", "mer_urso_dano", "mer_urso_erro");

	CicloDeCombate(player, urso);

	if (player.vida <= 0){
		cout << "\nVocê morreu.";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nVocê ganhou! recompensa: 35G\n";
		player.inv.ouro = player.inv.ouro + 35;
		cout << "\nSeu ouro: " << player.inv.ouro;
		condicao.inimigos.urso = false;
		condicao.eventos.urso_gerado = false;
		system("pause");
		system("cls");
	}
}
//Função para acontecimentos da Tumba
void Tumba(criatura &player, condicionais& condicao, int& chave) {
	int escolha;
	bool sair = 0;
	if (condicao.eventos.caverna_visitada == false) {
		system("cls");
		get_line("desc_tumba", 2);
		system("pause");
	}
	else
	{
		encontro_prisioneiro(player, condicao);
		system("cls");
		cout << "Você chega na sala do túmulo";
		system("pause");
	}
		do {
			system("cls");
			cout << "\n\nO que você irá fazer?\n";
			cout << "1- Checar esqueletos\n";
			cout << "2- Checar baú\n";
			cout << "3- Voltar para a Vila\n";
			cin >> escolha;
			if (escolha == 0) {
				sair = Opcoes(player);
			}
			switch (escolha) {
			case 1:
				system("cls");
				cout << "Não há nada neles\n";
				system("pause");
				break;
			case 2:
				system("cls");
				if (player.inv.esc_necro == false) {
					get_line("bau_da_tumba", 3);
					player.inv.ouro = player.inv.ouro + 15;
					player.inv.pocao = player.inv.pocao + 2;
					system("pause");
					if(player.inv.cristal_dourado == true || player.inv.cristal_negro == true){
						player.inv.esc_necro = false;
					}else {
						player.inv.esc_necro = true;
					}
					if (condicao.eventos.machado_trocado == false) {
						if (player.tipo == "mercenario") {
							int escolha_machado;
							do {
								system("cls");
								get_line("machado_aprimorado");
								cout << "\nArma atual- " << player.inv.arma << ": " << player.inv.dano_arma << " de dano.\n";
								cout << "\nArma no baú-" << "Machado refinado: " << "11 de dano\n";
								cout << "\n\nPegar Machado?\n";
								cout << "1- Sim\n";
								cout << "2- Não \n";
								cin >> escolha_machado;
								if (escolha_machado == 1) {
									system("cls");
									cout << "\n\nVocê pegou o seu novo machado e deixou o seu antigo no chão";
									pegar_arma(player,"Machado Refinado", 11);
									system("pause");
									condicao.eventos.machado_trocado = true;
								}else {
									system("cls");
									cout << "\n\nVocê não pegou o machado do baú\n";
									system("pause");
								}
							} while (escolha < 0 || escolha > 2);
						}
					}
				}
				else {
					system("cls");
					cout << "Não há mais nada no baú";
					system("pause");
				}
				if (condicao.inimigos.esqueletos == true) {
					system("cls");
					get_line("encontro_esqueletos", 2);
					system("pause");
					pre_combate_esqueletos(player, condicao);
					if (player.vida <= 0)
						sair = 1;
				}
				break;
			case 3:
				system("cls");
				if (condicao.eventos.caverna_visitada == false)
					encontro_prisioneiro(player, condicao);
				condicao.eventos.caverna_visitada = true;
				sair = 1;
				chave = 4;
				break;
			}
		} while (sair == 0);
}

//Função para os acontecimentos da caverna
void Caverna(criatura &player, condicionais &condicao, int &chave) {
	if (condicao.eventos.caverna_visitada == false)
	{
		system("cls");
		get_line("desc_caverna", 2);
		system("pause");
	}
	else
	{
		condicao.eventos.caverna_visitada = true;
		system("cls");
		get_line("desc_caverna_visitada");
		system("pause");
	}
	int d20;
	int escolha;
	if(condicao.inimigos.urso == true){
		if(d20 = 1 + rand() % 20 >= player.srt){
			condicao.eventos.urso_gerado = true;
		}
	}

	if(condicao.eventos.urso_gerado = true){
				do {
					system("cls");
					get_line("encontro_urso", 9);
					cin >> escolha;
				} while (escolha < 1 || escolha > 3);
				switch (escolha) {
				case 1:
					system("cls");
					pre_combate_urso(player, condicao);
					break;
				case 2:
					system("cls");
					if (d20 = 1 + rand() % 20 + player.fur > 10) {
						cout << "\nVocê conseguiu passar furtivamente até a tumba\n";
						system("pause");
						system("cls");

					}
					else {
						cout << "\nO urso lhe notou, você terá que lutar\n";
						system("pause");
						system("cls");
						pre_combate_urso(player, condicao);
					}
					break;
				case 3:
					system("cls");
					cout << "\nVocê correu até a entrada da tumba e bloqueou a entrada dela para evitar o urso.\n";
					system("pause");
					system("cls");
					break;
				}
				
	}
	if (player.vida > 0) {
		Tumba(player, condicao, chave);
	}
}

//Função para dar início a história do Mercenario
void InicioMercenario(criatura &player, condicionais &condicao, int &chave) {
	system("cls");
	int escolha;
	bool sair = 0;
	do {
		system("cls");
		get_line("inicio_mercenario", 8);
		cin >> escolha;
		if (escolha == 0) {
			sair = Opcoes(player);
		}
		switch (escolha) {
			case 1:
				system("cls");
				cout << "\nVocê ignora o aventureiro ferido e entra na caverna.";
				system("pause");
				system("cls");
				Caverna(player, condicao, chave);
				break;
			case 2:
				system("cls");
				cout << "\nVocê decide ouvir o que ele tem a falar";
				system("pause");
				system("cls");
				do {
					system("cls");
					get_line("aventureiro_ferido", 10);
					cin >> escolha;
					if (escolha == 0) {
						sair = Opcoes(player);
					}
					switch (escolha) {
						case 1:
							system("cls");
							cout << "\nVocê continua para a caverna.";
							system("pause");
							system("cls");
							Caverna(player, condicao, chave);
							break;
						case 2:
							system("cls");
							cout << "\nVocê sente que precisa de respostas antes de entrar na caverna, então volta para a vila";
							system("pause");
							system("cls");
							sair = 1;
							chave = 4;
							break;
						}
				} while ((escolha < 0 || escolha > 2) && sair == 0);
				break;
		} 
	} while ((escolha < 0 || escolha > 2) && sair == 0);
}