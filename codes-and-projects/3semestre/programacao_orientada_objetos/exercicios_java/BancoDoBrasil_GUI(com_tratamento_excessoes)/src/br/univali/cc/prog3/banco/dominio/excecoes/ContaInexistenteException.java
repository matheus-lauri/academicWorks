/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio.excecoes;

/**
 *
 * @author 1978233
 */
public class ContaInexistenteException extends Exception{

    public ContaInexistenteException() {
        super("Conta informada não existe");
    }
 
    
}
