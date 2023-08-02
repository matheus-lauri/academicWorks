/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.m2.dominio;

import com.sun.jmx.remote.internal.ArrayQueue;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

/**
 *
 * @author 1978233
 */
public class Galpao {
    //private List<Veiculo>  veiculos = new LinkedList();
    private Set<Veiculo>  veiculos = new HashSet<>();
    
    public void adicionarVeiculo(Veiculo veiculo){
        this.veiculos.add(veiculo);
    }
    
    public String imprimirRelacaoVeiculos() {
        String relacao = "";
        for(Veiculo veiculo:veiculos){
            if (veiculo != null) {
                relacao += "\n"+veiculo.obterDescricaoVeiculo();
            }
        }
        return relacao;
    }
}
