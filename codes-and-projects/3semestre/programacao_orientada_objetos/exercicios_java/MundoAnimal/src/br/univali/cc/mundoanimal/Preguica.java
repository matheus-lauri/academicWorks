/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.univali.cc.mundoanimal;

/**
 *
 * @author 1978233
 */
public class Preguica extends Animal{

    public Preguica(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public void emitirSom() {
        System.out.println("zzzzzZZ");
    }
    
}
