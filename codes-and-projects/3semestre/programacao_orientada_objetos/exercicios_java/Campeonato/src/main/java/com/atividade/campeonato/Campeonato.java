

package com.atividade.campeonato;

import java.util.Date;

public class Campeonato {
    
    private int idCampeonato = 0;
    private int ano;
    private String nome;
    public Equipe[] equipes = new Equipe[12];
    public Corrida[] corridas = new Corrida[20];
    
    private int contadorEquipe = 0;
    private int contadorCorrida = 0;

    public int getIdentificadorCampeonato() {
        return idCampeonato;
    }

    public Campeonato(int ano, String nome) {
        this.ano = ano;
        this.nome = nome;
        this.idCampeonato++;
    }
    
    public void definirCorrida(Autodromo autodromo, Date data){
        Corrida corrida = new Corrida(autodromo, data);
        this.corridas[contadorCorrida++] = corrida;
    }
    
    public void adicionarEquipe(Equipe equipe){
        this.equipes[contadorEquipe++] = equipe;
    }
    
    
}
