
package com.atividade.campeonato;

public class Equipe {
    
    private String nome;
    public Mecanico[] mecanicos = new Mecanico[10];
    public Carro[] carros = new Carro[2];
    
    private int indiceCarro = 0;
    private int indiceMecanico = 0;
    
    public Equipe(String nomeEq){
        this.nome = nomeEq;
    }
    
    public void addCarro(Carro carro){
        this.carros[indiceCarro++] = carro;        
    }
    
    public void addMecanico(Mecanico mecanico){
        this.mecanicos[indiceMecanico++] = mecanico;
    }    
    
}
