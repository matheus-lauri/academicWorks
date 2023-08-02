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
abstract public class VeiculoTerrestre implements Veiculo, Comparable<VeiculoTerrestre>{
    protected String modelo;
    protected String placa;
    protected String motorista;

    public VeiculoTerrestre(String modelo, String placa) {
        this.modelo = modelo;
        this.placa = placa;
    }

    public void setMotorista(String motorista) {
        this.motorista = motorista;
    }

    public String getPlaca() {
        return placa;
    }
    
    abstract public String detalhar();

    @Override
    public String obterDescricaoVeiculo() {
        return this.detalhar();
    }

    @Override
    public int compareTo(VeiculoTerrestre other) {
        return this.obterDescricaoVeiculo().toLowerCase().compareTo(other.obterDescricaoVeiculo().toLowerCase());
    }
    
    
    
    
    
}
