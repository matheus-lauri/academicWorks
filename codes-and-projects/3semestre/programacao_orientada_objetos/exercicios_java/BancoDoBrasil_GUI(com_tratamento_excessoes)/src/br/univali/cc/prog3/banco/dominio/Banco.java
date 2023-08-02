/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

import br.univali.cc.prog3.banco.dominio.excecoes.ContaInexistenteException;
import br.univali.cc.prog3.banco.dominio.excecoes.SaldoInsuficienteException;
import br.univali.cc.prog3.banco.dominio.excecoes.ValorIncorretoException;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author 1978233
 */
public class Banco {
    private String nome;
    private int numero;
    private Map<Integer,ContaCorrente> contas;
    
    private static Banco instance;
    
    public static Banco getInstance() {
        if (instance == null) {
            instance = new Banco();
        }
        return instance;
    }
    
    private Banco() {
        this.nome = "Banco do Brasil";
        this.numero = 1;
        this.contas = new HashMap<>();
    }
    
    public int criarConta(double saldoInicial) {
        int novoNumero = this.obterNumeroConta();
        this.contas.put(novoNumero, new ContaCorrente(novoNumero, saldoInicial));
        return novoNumero;
    }

    public int criarConta(double saldoInicial, double limite) {
        int novoNumero = this.obterNumeroConta();
        this.contas.put(novoNumero, new ContaCorrente(novoNumero+1, saldoInicial, limite));
        return novoNumero;
    }

    private ContaCorrente localizarConta(int numero) {
        return this.contas.get(numero);
    }
    
    public void depositar(int numero, double valor) throws ValorIncorretoException, ContaInexistenteException {
        ContaCorrente contaCorrente = this.localizarConta(numero);
        if (contaCorrente == null) {
            throw new ContaInexistenteException();
        }
        contaCorrente.depositar(valor);
    }
    
    public void sacar(int numero, double valor) throws ContaInexistenteException, SaldoInsuficienteException{
        ContaCorrente contaCorrente = this.localizarConta(numero);
        if (contaCorrente  == null) {
            throw new ContaInexistenteException();
        }
        contaCorrente.sacar(valor); 
    }
    
    public void transferir(int numeroOrigem, int numeroDestino, double valor) throws ValorIncorretoException, SaldoInsuficienteException, ContaInexistenteException {
        ContaCorrente origem = this.localizarConta(numeroOrigem);
        ContaCorrente destino = this.localizarConta(numeroDestino);
        if (origem != null && destino != null) {
            origem.sacar(valor);
            destino.depositar(valor);
        } else {
            throw new ContaInexistenteException();
        }
    }
    
    public String emitirExtrato(int numero) throws ContaInexistenteException {
        ContaCorrente contaCorrente = this.localizarConta(numero);
        if (contaCorrente != null) {
            return contaCorrente.emitirExtrato();
        }
        throw new ContaInexistenteException();
    }

    public String getNome() {
        return nome;
    }
    
    private int obterNumeroConta() {
        int min = 100000;
        int max = 999999;
        int conta = (int) ((Math.random() * (max - min)) + min);
        return conta;
    }
    
    
}
