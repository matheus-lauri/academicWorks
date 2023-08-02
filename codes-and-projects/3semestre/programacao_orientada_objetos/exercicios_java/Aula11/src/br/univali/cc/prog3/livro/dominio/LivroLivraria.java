/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.univali.cc.prog3.livro.dominio;

/**
 *
 * @author 1978233
 */
public class LivroLivraria extends Livro{
    
    private int estoque;
    private double valor;

    public LivroLivraria(int estoque, double valor, String isbn, String nome, Autor... autores) {
        super(isbn, nome, autores);
        this.estoque = estoque;
        this.valor = valor;
    }

    public int getEstoque() {
        return estoque;
    }

    @Override
    public String getDescricao() {
        return estoque+" "+valor;
    }
    
    
    
    
}
