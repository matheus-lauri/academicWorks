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
public class Carro extends VeiculoTerrestre{
    
    private double potencia;

    public Carro(double potencia, String modelo, String placa) {
        super(modelo, placa);
        this.potencia = potencia;
    }
    
    

    @Override
    public String detalhar() {
        return this.modelo+" "+this.placa+" Potencia: "+this.potencia;
    }
    
}
