#pragma once
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\structs.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\sistemas.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\floresta.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\caverna.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\ruina.h"
#include "C:\TrabalhoM1\TrabalhoM1\TrabalhoM1\final.h"

#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Estalagem(criatura& player, condicionais& condicao, int& chave) {

	int escolha;
	bool sair = 0;

	do {

		get_line("estalagem_entrada", 3);
		cout << "\nSua vida atual:" << player.vida << endl;
		cout << "1 - Sim\n";
		cout << "2 - Não\n";
		cin >> escolha;
		if (escolha == 0) {
			sair = Opcoes(player);
		}
		switch (escolha) {
		case 1:
			cout << "Pegando no sono...\n";
			Sleep(1000);
			cout << ".\n";
			Sleep(1000);
			cout << ".\n";
			Sleep(1000);
			cout << "Dormindo...\n";
			Sleep(1000);
			cout << ".\n";
			Sleep(1000);
			cout << ".\n";
			Sleep(1000);
			cout << "Acordando...\n";
			Sleep(1000);
			cout << "Parabéns! Você recuperou toda a sua vida!!\n";
			player.vida = 60;
			cout << "Sua vida: " << player.vida << "\n";
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			break;
		} 
	} while ((escolha < 0 || escolha > 2) && sair == 0);
	
}

void Loja(criatura& player, condicionais& condicao, int& chave){
	int escolha;
	bool sair = 0;
	system("cls");

	if (condicao.eventos.loja_visitada == false) {
		system("cls");
		get_line("lojista_fala1", 2);
		system("pause");
		condicao.eventos.loja_visitada = true;
	}
	else {

		system("cls");
		get_line("lojista_fala2");
		system("pause");
	}

	do{
		if(player.tipo == "cacador"){
			system("cls");
			get_line("tabela_loja_cac", 5);
			cin >> escolha;
			switch (escolha) {
				case 1:
					if (player.inv.ouro >= 5) {
						player.inv.ouro = player.inv.ouro - 5;
						player.inv.pocao += 1;
						system("cls");
						cout << "Você comprou uma poção de cura!\n";
						system("pause");
					}
					else {
						system("cls");
						cout << "Gold insuficiente :(\n";
						system("pause");
					}
					break;
				case 2:
					if(condicao.eventos.arma_comprada){
						system("cls");
						cout << "Desculpe, mas parece que acabou o estoque desse produto...\n";
						system("pause");
					}
					if (player.inv.ouro >= 40) {
						player.inv.ouro = player.inv.ouro - 40;
						pegar_arma(player, "arco celeste", 15);
						condicao.eventos.arma_comprada = true;
						system("cls");
						cout << "Você comprou o Arco Celeste!\n";
						system("pause");
					}
					else {
						system("cls");
						cout << "Gold insuficiente :(\n";
						system("pause");
					}
					break;
				case 3:
					if (condicao.eventos.armadura_comprada) {
						system("cls");
						cout << "Me desculpe, mas acho que acabou o estoque desse produto...\n";
						system("pause");
					}
					if (player.inv.ouro >= 50) {
						player.inv.ouro = player.inv.ouro - 50;
						pegar_armadura(player, "Armadura de Escamas", 14, 2);
						condicao.eventos.armadura_comprada = true;
						system("cls");
						cout << "Você comprou a Armadura de escamas!\n";
						system("pause");
					}
					else {
						system("cls");
						cout << "Gold insuficiente :(\n";
						system("pause");
					}
					break;
			}
		}
		if (player.tipo == "mercenario") {
			system("cls");
			get_line("tabela_loja_mer", 5);
			cin >> escolha;
			switch(escolha){
			case 1:
				if (player.inv.ouro >= 5) {
					player.inv.ouro = player.inv.ouro - 5;
					player.inv.pocao += 1;
					system("cls");
					cout << "Você comprou uma poção de cura!\n";
					system("pause");
				} else{
					system("cls");
					cout << "Gold insuficiente\n";
					system("pause");
				}
				break;
			case 2:
				if (condicao.eventos.arma_comprada) {
					system("cls");
					cout << "Me desculpe, mas acho que acabou o estoque desse produto...\n";
					system("pause");
				}
				if (player.inv.ouro >= 40) {
					player.inv.ouro = player.inv.ouro - 40;
					pegar_arma(player, "executor", 13);
					condicao.eventos.arma_comprada = true;
					system("cls");
					cout << "Você comprou o Executor!\n";
					system("pause");
				}
				else {
					system("cls");
					cout << "Gold insuficiente :(\n";
					system("pause");
				}
				break;
			case 3:
				if (condicao.eventos.armadura_comprada) {
					system("cls");
					cout << "Me desculpe, mas parece que acabou o estoque desse produto...\n";
					system("pause");
				}
				if (player.inv.ouro >= 50) {
					player.inv.ouro = player.inv.ouro - 50;
					pegar_armadura(player, "Armadura de Cotas", 16, 2);
					condicao.eventos.armadura_comprada = true;
					system("cls");
					cout << "Você comprou a Armadura de cotas!\n";
					system("pause");
				}
				else {
					cout << "Gold insuficiente :(\n";
					system("pause");
				}
				break;
			}
		}
		if (player.tipo == "cavaleiro") {
			system("cls");
			get_line("tabela_loja_cav", 5);
			cin >> escolha;
			switch (escolha) {
			case 1:
				if (player.inv.ouro >= 5) {
					player.inv.ouro = player.inv.ouro - 5;
					player.inv.pocao += 1;
					system("cls");
					cout << "Você comprou uma poção de cura!\n";
					system("pause");
				}
				else {
					system("cls");
					cout << "Gold insuficiente\n";
					system("pause");
				}
				break;
			case 2:
				if (condicao.eventos.arma_comprada) {
					system("cls");
					cout << "Desculpe aventureiro, mas acho que acabou o estoque desse produto...\n";
					system("pause");
				}
				if (player.inv.ouro >= 40) {
					player.inv.ouro = player.inv.ouro - 40;
					pegar_arma(player, "julgamento real", 11);
					condicao.eventos.arma_comprada = true;
					system("cls");
					cout << "Você comprou o Julgamento Real!\n";
					system("pause");
				}
				else {
					system("cls");
					cout << "Gold insuficiente :(\n";
					system("pause");
				}
				break;
			case 3:
				if (condicao.eventos.armadura_comprada) {
					system("cls");
					cout << "Me desculpe, mas parece que acabou o estoque desse produto...\n";
					system("pause");
				}
				if (player.inv.ouro >= 50) {
					player.inv.ouro = player.inv.ouro - 50;
					pegar_armadura(player, "Armadura de Placas", 18, -2);// colocar o status da Armadura de placas
					condicao.eventos.armadura_comprada = true;
					system("cls");
					cout << "Você comprou a Armadura de placas!\n";
					system("pause");
				}
				else {
					cout << "Gold insuficiente :(\n";
					system("pause");
				}
				break;
			}
		}
		if (escolha == 0) {
			sair = Opcoes(player);
		}
	} while (escolha != 4 && sair == 0);
	cout << "Até a próxima aventureiro!\n";
	system("pause");
	system("cls");
}

void Alquimista(criatura& player, condicionais& condicao, int& chave) {

if(condicao.eventos.alquimista_visita)
{
	if(player.inv.esc_necro && player.inv.liv_ant_necro && player.inv.cristal_quebrado && player.inv.reg_cler)
	{
		get_line("alquimista_todos_itens",9);
		system("pause");
		system("cls");
		player.inv.explosivo = true;
		player.inv.cristal_dourado = true;
		player.inv.cristal_quebrado = false;
		player.inv.liv_ant_necro= false;
		player.inv.esc_necro = false;
		player.inv.reg_cler = false;
	}
	else if(player.inv.cristal_dourado)
	{
		get_line("alquimista_pos");
		system("pause");
		system("cls");
	}
	else
	{
		get_line("alquimista_padrao");
		system("pause");
		system("cls");
	}
}
else
{
	if(player.inv.cristal_quebrado)
	{
		get_line("alquimista_primeiro_cristal", 16);
		system("pause");
		system("cls");
	}
	else
	{
		if (player.tipo=="cavaleiro")
		{
			get_line("alquimista_primeiro_ruina",16);
			system("pause");
			system("cls");
		}
		if(player.tipo=="cacador")
		{
			get_line("alquimista_primeiro_floresta", 15);
			system("pause");
			system("cls");
		}
		if (player.tipo == "mercenario")
		{
			get_line("alquimista_primeiro_caverna", 15);
			system("pause");
			system("cls");
		}
	}
	condicao.eventos.alquimista_visita = true;
}

}

void Vila(criatura& player, condicionais& condicao, int& chave) {
	system("cls");

	int escolha;
	bool sair = 0;
	system("cls");
	get_line("vila_entrada");
	system("pause");

	do {
		cout << "Para onde você deseja ir?\n";

		cout << "1 - Estalagem\n";
		cout << "2 - Loja\n";
		cout << "3 - Falar com o Alquimista\n";
		cout << "4 -  Sair da vila\n";
		cin >> escolha;
		if (escolha == 0) {
			sair = Opcoes(player);
		}
		switch (escolha) {
		case 1:
			system("cls");
			cout << "\nVocê entrou na estalagem\n";
			system("pause");
			Estalagem(player, condicao, chave);
			break;
		case 2:
			system("cls");
			cout << "\nVocê entrou na loja\n";
			system("pause");
			Loja(player, condicao, chave);
			break;
		case 3:
			system("cls");
			cout << "\nVocê entrou na cabana do alquimista\n";
			system("pause");
			Alquimista(player, condicao, chave);
			break;
		case 4:
			if(condicao.eventos.alquimista_visita== false) //só será possivel sair da vila quando você falar com o alquimista
			{
				system("cls");
				cout << "Não há nada lá fora no momento\n";
				system("pause");
			}
			else
			{
				int escolha;
				do
				{
					cout << "Para onde?\n";
					cout << "1-Ruína\n";
					cout << "2-Floresta\n";
					cout << "3-Caverna\n";
					cin >> escolha;
					switch(escolha){
					case 1:
						sair = 1;
						chave = 5;
						break;
					case 2:
						sair = 1;
						chave = 6;
						break;
					case 3:
						sair = 1;
						chave = 7;
						break;
					}
				} while (escolha < 0 || escolha > 3);
			}
		}
	} while (sair == 0);
}

void ChaveDeAcesso(criatura &player, condicionais &condicao, int &chave){
	do {
		switch (chave) {
		case 0:
			break;
		case 1:
			chave = 0;
			InicioCavaleiro(player, condicao, chave);
			break;
		case 2:
			chave = 0;
			InicioCacador(player, condicao, chave);
			break;
		case 3:
			chave = 0;
			InicioMercenario(player, condicao, chave);
			break;
		case 4:
			chave = 0;
			Vila(player, condicao, chave);
			break;
        case 5:
            chave = 0;
			Ruina(player, condicao, chave);
            break;
		case 6:
			chave = 0;
			Cabana(player, condicao, chave);
			break;
		case 7:
			chave = 0;
			Caverna(player, condicao, chave);
			break;
		}
	} while (chave != 0);
}