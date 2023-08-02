/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.univali.cc.prog3.livro.dominio;

/**
 *
 * @author 1978233
 */
public class LivroBiblioteca extends Livro{
    private String localizacao;
    private int numeroExemplares;

    public LivroBiblioteca(String localizacao, int numeroExemplares, String isbn, String nome, Autor... autores) {
        super(isbn, nome, autores);
        this.localizacao = localizacao;
        this.numeroExemplares = numeroExemplares;
    }

    public String getLocalizacao() {
        return localizacao;
    }

    @Override
    public String getDescricao() {
        return localizacao+" "+numeroExemplares;
    }
    
    
    
    
    
    
}
