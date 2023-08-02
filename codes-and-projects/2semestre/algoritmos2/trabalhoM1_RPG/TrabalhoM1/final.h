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

void pre_combate_dragao(criatura& player, condicionais& condicao) { //combate contra o dragão
	criatura dragao;
	CriarCriatura(dragao, "Dragão morto_vivo", "dragao", 35, 16, 14, 0, 0, "drag_final", "drag_crit", "drag_dano", "drag_erro");

	if (player.tipo == "cavaleiro")
		definir_tags(player, "cav_drag_final", "cav_drag_crit", "cav_drag_dano", "cav_drag_erro");
	if (player.tipo == "cacador")
		definir_tags(player, "cac_drag_final", "cac_drag_crit", "cac_drag_dano", "cac_drag_erro");
	if (player.tipo == "mercenario")
		definir_tags(player, "mer_drag_final", "mer_drag_crit", "mer_drag_dano", "mer_drag_erro");

	CicloDeCombate(player, dragao);

	if (player.vida <= 0){
		cout << "\nVocê morreu.";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nVocê matou o dragão, agora tem caminho livre até o Lich";
		system("pause");
		system("cls");
	}
}

void ataque_lich(criatura& atacante, int contador) //ataque voltado para o lich
{
	int d20 = 1 + rand() % 20;
	if (d20 == 20)
	{
		cout << "--Crítico--";
		get_line(atacante.lines.crit);
		contador = contador + 4;
	}
	else
	{
		d20 = d20 + atacante.mod_srt;
		if (atacante.tipo == "mercenario")
			d20 = d20 + 2;
		if (d20 >= 13)
		{
			cout << "--Acerto--";
			get_line(atacante.lines.dano);
			contador = contador + 2;
		}
		else {
			cout << "--Erro--";
			get_line(atacante.lines.erro);

		}
	}
}

void turno_drag_aliado(criatura& lich, criatura& inimigo, int &contador) //turno do dragão caso ele esteja do seu lado
{
	if (inimigo.vida > 0 && lich.vida > 0)
	{
		cout << "\n\nTurno de " << inimigo.nome << endl << endl;
		ataque(inimigo, lich);
		system("pause");
		system("cls");
	}
}

void ciclo_lich_drag(condicionais& condicao, criatura& player, criatura& inimigo1, criatura& inimigo2, int &contador) //combate do lich após o dragao
{
	system("cls");
	get_line("drag_entrada_inimigo");
	system("pause");
	criatura dragao;
	CriarCriatura(dragao, "Dragão morto_vivo", "dragao", 35, 16, 14, 0, 0, "drag_final", "drag_crit", "drag_dano", "drag_erro");

	while (player.vida > 0 && inimigo2.vida > 0 && contador > 0)
	{
		int resposta;
		cout << "\n\nO turno é seu.";

		cout << "\n\n" << player.nome << ": " << player.vida << " HP" << "\n\nLich:" << inimigo2.vida << " HP" << "\n\n" << contador << "turnos até o fim do ritual...";

		cout << "\n\nO que você fará?\n\n1-Atacar\n2-Usar poção de cura";

		cout << "\n\n-";
		cin >> resposta;
		switch (resposta) {
		case 1:
			system("cls");
			int atacar;
			cout << "\nQual inimigo?\n1-" << inimigo1.nome << "\n2-" << inimigo2.nome << "\n\n-";
			cin >> atacar;

			switch (atacar) {
			case 1:
				system("cls");
				definir_tags(player, "none", "geral_lich_crit", "geral_lich_dano", "geral_lich_erro");
				ataque_lich(player, contador);
				break;
			case 2:
				system("cls");
				definir_tags(player, "geral_cristal_final", "geral_cristal_crit", "geral_cristal_dano", "geral_cristal_erro");
				ataque(player, inimigo2);
				break;
			case 3:
				system("cls");
				if (player.tipo == "cavaleiro")
					definir_tags(player, "cav_drag_final", "cav_drag_crit", "cav_drag_dano", "cav_drag_erro");
				if (player.tipo == "cacador")
					definir_tags(player, "cac_drag_final", "cac_drag_crit", "cac_drag_dano", "cac_drag_erro");
				if (player.tipo == "mercenario")
					definir_tags(player, "mer_drag_final", "mer_drag_crit", "mer_drag_dano", "mer_drag_erro");
				ataque(player, dragao);
			default:
				system("cls");
				cout << "\nPerdeu o turno";
			}
			break;

		case 2:
			system("cls");
			if (player.inv.pocao > 0)
			{
				player.vida = player.vida + 20;
				player.inv.pocao--;
				cout << "\n\nVoce usou uma poção";
				if (player.vida > 60)
					player.vida = 60;
			}
			else { cout << "\n\nVoce nao tem mais poções"; }
			break;
		default:
			system("cls");
			cout << "\n\nVocê perdeu o turno";
			system("pause");
			system("cls");
		}
		TurnoInimigo(player, inimigo1);

		TurnoInimigo(player, dragao);

		contador--;
	}

}

void ciclo_lich_drag_aliado(condicionais& condicao, criatura& player, criatura& inimigo1, criatura& inimigo2, int &contador) // ciclo de combate com o dragão do seu lado.
{
	system("cls");
	get_line("drag_entrada_aliado");
	system("pause");
	criatura dragao;
	CriarCriatura(dragao, "Dragão morto_vivo", "dragao", 35, 16, 14, 0, 0, "drag_lich_final", "drag_lich_crit", "drag_lich_dano", "drag_lich_erro");
	
	while (player.vida > 0 && inimigo2.vida > 0 && contador > 0)
	{
		int resposta;
		cout << "\n\nO turno é seu.";

		cout << "\n\n" << player.nome << ": " << player.vida << " HP" << "\n\nLich:" << inimigo2.vida << " HP" << "\n\n" << contador << "turnos até o fim do ritual...";

		cout << "\n\nO que você fará?\n\n1-Atacar\n2-Usar poção de cura";

		cout << "\n\n-";
		cin >> resposta;
		switch (resposta) {
		case 1:
			system("cls");
			int atacar;
			cout << "\nQual inimigo?\n1-" << inimigo1.nome << "\n2-" << inimigo2.nome << "\n\n-";
			cin >> atacar;

			switch (atacar) {
			case 1:
				system("cls");
				definir_tags(player, "none", "geral_lich_crit", "geral_lich_dano", "geral_lich_erro");
				ataque_lich(player, contador);
				break;
			case 2:
				system("cls");
				definir_tags(player, "geral_cristal_final", "geral_cristal_crit", "geral_cristal_dano", "geral_cristal_erro");
				ataque(player, inimigo2);
				break;
			default:
				cout << "\nPerdeu o turno";
			}
			break;

		case 2:
			system("cls");
			if (player.inv.pocao > 0)
			{
				player.vida = player.vida + 20;
				player.inv.pocao--;
				cout << "\n\nVoce usou uma poção";
				if (player.vida > 60)
					player.vida = 60;
			}
			else { cout << "\n\nVoce nao tem mais poções"; }
			break;
		default:
			system("cls");
			cout << "\n\nVocê perdeu o turno";
			system("pause");
			system("cls");
		}
		TurnoInimigo(player, inimigo1);
		turno_drag_aliado(inimigo2, dragao, contador);
		
	}

}

void CicloLich(condicionais &condicao, criatura& player, criatura& inimigo1, criatura& inimigo2) // ciclo combate exclusivo do boss final 
{
		int contador = 6;
		int drag_contador = 6;
		while (player.vida > 0 && inimigo2.vida > 0 && contador > 0)
		{
			system("cls");
			int resposta;
			cout << "\n\nO turno é seu.";

			cout << "\n\n" << player.nome << ": " << player.vida << " HP" << "\n\nLich:" << inimigo2.vida << " HP" << "\n\n" << contador << "turnos até o fim do ritual...";

			cout << "\n\nO que você fará?\n\n1-Atacar\n2-Usar poção de cura";

			cout << "\n\n-";
			cin >> resposta;
			switch (resposta){
				case 1:
					system("cls");
					int atacar;
					cout << "\nQual inimigo?\n1-" << inimigo1.nome << "\n2-" << inimigo2.nome << "\n\n-";
					cin >> atacar;

					switch (atacar){
					case 1:
						definir_tags(player, "none", "geral_lich_crit", "geral_lich_dano", "geral_lich_erro");
						ataque_lich(player, contador);
						break;
					case 2:
						definir_tags(player, "geral_cristal_final", "geral_cristal_crit", "geral_cristal_dano", "geral_cristal_erro");
						ataque(player, inimigo2);
						break;
					default:
						cout << "\nPerdeu o turno";
					}
				break;

				case 2:
					system("cls");
					if (player.inv.pocao > 0)
					{
						player.vida = player.vida + 20;
						player.inv.pocao--;
						cout << "\n\nVoce usou uma poção";
						if (player.vida > 60)
							player.vida = 60;
					}
					else { cout << "\n\nVoce nao tem mais poções"; }
					break;
				default:
					system("cls");
					cout << "\n\nVocê perdeu o turno";
					system("pause");
					system("cls");
				}
				TurnoInimigo(player, inimigo1);

			if (condicao.eventos.drag_fugiu && drag_contador == 0) {
				ciclo_lich_drag(condicao, player, inimigo1, inimigo2, contador);
			}
			else if (condicao.eventos.drag_domado && drag_contador == 0) {
				ciclo_lich_drag_aliado(condicao, player, inimigo1, inimigo2, contador);
			}
			contador--;
			drag_contador--;
		}
	
}


void pre_combate_lich(criatura& player, condicionais& condicao) { //preparacao de combate contra o lich 
	criatura lich, cristal;
	CriarCriatura(lich, "Lich", "lich", 0, 15, 14, 0, 0, "lich_final", "lich_crit", "lich_dano", "lich_erro");
	CriarCriatura(cristal, "Cristal", "cristal", 40, 0, 10, 0, 0, "none", "none", "none", "none");

	CicloLich(condicao, player, lich, cristal);

	if (player.vida <= 0){
		cout << "\nVocê morreu.";
		system("pause");
		system("cls");
	}
	else if (cristal.vida > 0)
	{
		cout << "\nVocê morreu. O exércido de mortos levantou";
		system("pause");
		system("cls");
	}
	else
	{
		if(player.inv.cristal_negro)
		{
			get_line("final_lich_ruim",10);
			system("pause");
			system("cls");
		}
		else
		{
			get_line("final_lich",6);
			system("pause");
			system("cls");
		}
	}
}

void Lich(criatura& player, condicionais& condicao, int& chave) { //descrição do lich
	system("cls");
	get_line("inicio_lich",3);
	system("pause");
	pre_combate_lich(player, condicao);
}



void Dragao(criatura& player, condicionais& condicao, int& chave) { //Função pós entrada nos portoes

	int escolha;
	bool sair = 0;
	int d20 = 1 + rand() % 20;
	do {
		system("cls");
		get_line("aparicao_drag", 2);

		cout << "\n\nO que você irá fazer?\n";
		cout << "1- Lutar\n";
		cout << "2- Passar furtivamente\n";
		cout << "3- Fugir correndo\n";
		if (player.inv.cristal_negro == true) {
			cout << "4- Usar Cristal Negro\n";
		}
		cin >> escolha;
		if (escolha == 0) {
			sair = Opcoes(player);
		}
		switch (escolha) {
			case 1:
				system("cls");
				pre_combate_dragao(player, condicao);
				if(player.vida > 0)
				Lich(player, condicao, chave);
				break;
			case 2:
				system("cls");
				if ((d20 + player.srt + player.fur) >= 18) {
					get_line("drag_furt_sucesso",3);
					system("pause");
					system("cls");
					Lich(player, condicao, chave);
				}
				else {
					get_line("drag_furt_falha");
					system("pause");
					system("cls");
					pre_combate_dragao(player, condicao);
					if(player.vida > 0)
					Lich(player, condicao, chave);
				}
				Lich(player, condicao, chave);
				break;
			case 3:
				system("cls");
				get_line("drag_fugir", 3);
				system("pause");
				system("cls");
				player.vida = player.vida - 16;
				if (player.vida <= 0)
				{
					cout << "\n\nVocê morreu.";
					system("pause");
					system("cls");
				}
				if(player.vida > 0)
				{
					Lich(player, condicao, chave);
				}
				break;
			if (player.inv.cristal_negro == true) {
				case 4:
					system("cls");
					get_line("drag_controle", 2);
					system("pause");
					system("cls");
					condicao.eventos.drag_domado = true;
					Lich(player, condicao, chave);
					break;
			}else {
				if(escolha == 4){
					escolha = 5;
				}
			}
		}
	} while ((escolha < 0 || escolha > 4) && sair == 0);
}
