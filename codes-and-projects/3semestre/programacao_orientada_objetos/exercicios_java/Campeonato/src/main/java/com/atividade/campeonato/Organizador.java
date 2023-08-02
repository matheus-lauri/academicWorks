
package com.atividade.campeonato;

import java.util.Date;

public class Organizador {
    
    private String nome;
    private Campeonato[] campeonatos = new Campeonato[10];
    
    private int contadorCampeonato = 0;
    
    public boolean adicionarCorrida(Autodromo autodromo, Date data, int idCampeonato){
        for(int x = 0; x < campeonatos.length; x++){
            if(this.campeonatos[x] != null){
                if(this.campeonatos[x].getIdentificadorCampeonato() == idCampeonato){
                    this.campeonatos[x].definirCorrida(autodromo, data);
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return false;
    }
    
    public int criarCampeonato(int ano, String nome){
        Campeonato campeonato = new Campeonato(ano, nome);
        this.campeonatos[contadorCampeonato++] = campeonato;
        return campeonato.getIdentificadorCampeonato();
    }
    
    public boolean inscreverEquipe(Equipe equipe, int idCampeonato){
        for(int x = 0; x < campeonatos.length; x++){
            if(this.campeonatos[x] != null){
                if(this.campeonatos[x].getIdentificadorCampeonato() == idCampeonato){
                    this.campeonatos[x].adicionarEquipe(equipe);
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return false;
    }
    
}
