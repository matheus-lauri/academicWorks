/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.univali.cc.prog3.livro.dominio;

/**
 *
 * @author 1978233
 */
abstract public class Livro {
    protected String isbn;
    protected String nome;
    protected Autor[] autores;

    public Livro(String isbn, String nome, Autor ... autores) {
        this.isbn = isbn;
        this.nome = nome;
        this.autores = autores;
    }

    final public String getNome() {
        return nome;
    }
    
    abstract public String getDescricao();
    
    

    
    
    
}
