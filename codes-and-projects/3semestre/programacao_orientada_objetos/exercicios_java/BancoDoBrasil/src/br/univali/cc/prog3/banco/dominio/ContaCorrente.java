/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

/**
 *
 * @author 1978233
 */
public class ContaCorrente {
    private boolean especial;
    private double limite;
    private int numero;
    private double saldo;
    private Movimentacao[] movimentacoes = new Movimentacao[999];

    public ContaCorrente(int numero, double saldoInicial) {
        this.especial = false;
        this.limite = 0;
        this.numero = numero;
        this.saldo = saldoInicial;
        this.criarMovimentacao("Saldo inicial", 'C', saldoInicial);
    }

    public ContaCorrente(int numero, double saldoInicial, double limite) {
        this.especial = true;
        this.limite = limite;
        this.numero = numero;
        this.saldo = saldoInicial;
        this.criarMovimentacao("Saldo inicial", 'C', saldoInicial);
    }
    
    public int getNumeroConta() {
        return this.numero;
    }
    
    protected boolean depositar(double valor) {
        if (valor > 0) {
            this.saldo+=valor;
            this.criarMovimentacao("Depósito", 'C', valor);
            return true;
        }
        return false;
    }
    
    protected boolean sacar(double valor) {
        if (this.saldo+this.limite >= valor) {
            this.saldo -= valor;
            this.criarMovimentacao("Saque", 'D', valor);
            return true;
        }
        return false;
    }
    
    private void criarMovimentacao(String descricao, char tipo, double valor) {
        for(int x=0; x < movimentacoes.length; x++) {
            if (movimentacoes[x] == null) {
                movimentacoes[x] = new Movimentacao(descricao, tipo, valor);
                break;
            }
        }
    }
    
    protected String emitirExtrato() {
        String extrato = "Extrato bancário C/C "+numero;
        for(Movimentacao movimentacao:movimentacoes){
            if (movimentacao == null) {
                break;
            }
            extrato += "\n"+movimentacao.getMovimentacao();
        }
        extrato += "\n Saldo final R$ "+this.saldo;
        if (especial) {
            extrato += "\n Limite R$ "+this.limite;
        }
        return extrato;
    }

    
    
    
}
