/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author 1978233
 */
public class Banco {
    private String nome;
    private int numero;
    private List<ContaCorrente> contas;
    
    private int numeroConta = 0;
    
    public Banco(String nome, int numero) {
        this.nome = nome;
        this.numero = numero;
        this.contas = new ArrayList<>();
    }
    
    public void criarConta(double saldoInicial) {
        int novoNumero = this.numeroConta++;
        //this.contas[novoNumero] = new ContaCorrente(novoNumero+1, saldoInicial);
        contas.add(new ContaCorrente(novoNumero+1,saldoInicial));
    }

    public void criarConta(double saldoInicial, double limite) {
        int novoNumero = this.numeroConta++;
        //this.contas[novoNumero] = new ContaCorrente(novoNumero+1, saldoInicial, limite);
        contas.add(new ContaCorrente(novoNumero+1,saldoInicial, limite));
    }

    private ContaCorrente localizarConta(int numero) {
        /*for (ContaCorrente conta:this.contas){
            if (conta != null && conta.getNumeroConta() == numero) {
                return conta;
            }
        }*/
        numero--;
        return contas.get(numero);
        
    }
    
    public void depositar(int numero, double valor) {
        ContaCorrente contaCorrente = this.localizarConta(numero);
        if (contaCorrente != null) {
            contaCorrente.depositar(valor);
        }
    }
    
    public void sacar(int numero, double valor) {
        ContaCorrente contaCorrente = this.localizarConta(numero);
        if (contaCorrente != null) {
            contaCorrente.sacar(valor); 
        }
    }
    
    public void transferir(int numeroOrigem, int numeroDestino, double valor) {
        ContaCorrente origem = this.localizarConta(numeroOrigem);
        ContaCorrente destino = this.localizarConta(numeroDestino);
        if (origem != null && destino != null) {
            if (origem.sacar(valor)) {
                destino.depositar(valor);
            }
        }
    }
    
    public String emitirExtrato(int numero) {
        ContaCorrente contaCorrente = this.localizarConta(numero);
        if (contaCorrente != null) {
            return contaCorrente.emitirExtrato();
        }
        return "";
    }

    public String getNome() {
        return nome;
    }
    
    
    
    
}
