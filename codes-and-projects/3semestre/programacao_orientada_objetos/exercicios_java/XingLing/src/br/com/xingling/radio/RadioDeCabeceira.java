/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.xingling.radio;

import br.univali.cc.bughi.radio.Radio;

/**
 *
 * @author 1978233
 */
public class RadioDeCabeceira extends XingLing implements Radio, Relogio{

    public RadioDeCabeceira(String modelo, String numeroSerie) {
        super(modelo, numeroSerie);
    }
    

    @Override
    public void ligar() {
        System.out.println("ligado");
    }

    @Override
    public void desligar() {
        System.out.println("desligado");
    }

    @Override
    public void volume(double d) {
        System.out.println("volume "+d);
    }

    @Override
    public void sintonizar(double d) {
        System.out.println("Frequencia "+d);
    }

    @Override
    public void ajustarHora(int hora, int minuto) {
        System.out.println("hora "+hora+":"+minuto);
    }

    @Override
    public String obterHora() {
        return "aqui vai a hora atual";
    }
    
}
