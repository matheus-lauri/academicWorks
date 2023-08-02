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
public class Caminhao extends VeiculoTerrestre{
    
    private double capacidadeCarga;

    public Caminhao(double capacidadeCarga, String modelo, String placa) {
        super(modelo, placa);
        this.capacidadeCarga = capacidadeCarga;
    }

    @Override
    public String detalhar() {
        return this.modelo+" "+this.capacidadeCarga;
    }
    
}
