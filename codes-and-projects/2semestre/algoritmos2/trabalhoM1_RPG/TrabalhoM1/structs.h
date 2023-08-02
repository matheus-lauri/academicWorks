#pragma once
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
//Struct para todos os atributos e itens do inventario do jogador
struct inventario
{
    string arma = "none", armadura = "none";
    int dano_arma = 0, defesa_armadura = 0, furtividade_armadura= 0;
    int pocao = 0, ouro = 0;
    bool colar_quebrado = false, colar_magico = false, adaga = false, cristal_quebrado= false, cristal_dourado= false, cristal_negro=false, esc_necro = false, reg_cler = false, liv_ant_necro = false, explosivo= false;
};
//Struct para as falas principais do jogo
struct falas
{
    string fim, crit, dano, erro;
};
//Struct para criação de inimigos ou jogadores(qualquer criatura)
struct criatura
{
    string nome = "none", tipo = "none";
    int vida = 0, atq = 0, def = 0, srt = 0, mod_srt = 0, fur = 0;
    falas lines;
    inventario inv;
};
//Struct para registrar a condição de vida dos inimigos
struct cond_inimigos
{
    bool lobos = true, goblins = true, urso = true, esqueletos = true, aranha = true, gargulas = true;
};
//Struct para registrar os lugares visitados ou itens adiquiridos durante o jogo
struct cond_eventos
{
    bool cabana_visitada = false, caverna_visitada = false, ruina_visitada = false, urso_gerado = false, alquimista_visita = false, cabana_gaveta = true, machado_trocado = false, prisioneiro_sumiu= false, loja_visitada = false, arma_comprada = false, armadura_comprada = false, drag_fugiu= false, drag_domado=false;
};
//Struct para deixar todos os registros somente em um lugar
struct condicionais
{
    cond_inimigos inimigos;
    cond_eventos eventos;
};