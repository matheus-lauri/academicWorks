/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.univali.cc.mundoanimal;

/**
 *
 * @author 1978233
 */
abstract public class Animal {
    
    String nome;
    int idade;

    public Animal(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }
    
    abstract public void emitirSom();
    
}
