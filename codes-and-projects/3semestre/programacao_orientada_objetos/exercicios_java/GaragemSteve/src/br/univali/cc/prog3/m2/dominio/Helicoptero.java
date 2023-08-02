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
public class Helicoptero implements Veiculo, Comparable<Veiculo>{
    
    private String modelo;
    private String sigla;
    private String piloto;

    public Helicoptero(String modelo, String sigla) {
        this.modelo = modelo;
        this.sigla = sigla;
    }

    public void setPiloto(String piloto) {
        this.piloto = piloto;
    }
    
    
    public String detalhar() {
        return this.modelo+" "+this.sigla;
    }

    @Override
    public String obterDescricaoVeiculo() {
        return this.detalhar();
    }

    @Override
    public int compareTo(Veiculo other) {
        return this.obterDescricaoVeiculo().toLowerCase().compareTo(other.obterDescricaoVeiculo().toLowerCase());
    }
    
}
