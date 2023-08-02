/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.m2.dominio;

/**
 *
 * @author 1978233
 */
public class Iate implements Veiculo, Comparable<Veiculo>{
    private String nome;
    private String capitao;

    public Iate(String nome) {
        this.nome = nome;
    }

    public void setCapitao(String nome) {
        this.capitao = nome;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public String obterDescricaoVeiculo() {
        return "IATE "+this.nome+" "+this.capitao;
    }
    
        @Override
    public int compareTo(Veiculo other) {
        return this.obterDescricaoVeiculo().toLowerCase().compareTo(other.obterDescricaoVeiculo().toLowerCase());
    }
    
}
