/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.univali.cc.mundoanimal;

/**
 *
 * @author 1978233
 */
public class Cavalo extends Animal implements Corredor{

    public Cavalo(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public void emitirSom() {
        System.out.println("uiiiii");
    }

    @Override
    public void correr() {
        System.out.println("Galopando... lindamente...");
    }
    
}
