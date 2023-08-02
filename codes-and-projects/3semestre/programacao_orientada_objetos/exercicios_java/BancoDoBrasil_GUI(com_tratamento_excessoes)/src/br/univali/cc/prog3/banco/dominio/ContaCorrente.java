/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

import br.univali.cc.prog3.banco.dominio.excecoes.SaldoInsuficienteException;
import br.univali.cc.prog3.banco.dominio.excecoes.ValorIncorretoException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author 1978233
 */
public class ContaCorrente {
    private boolean especial;
    private double limite;
    private int numero;
    private double saldo;
    private List<Movimentacao> movimentacoes = new ArrayList<>();

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
    
    protected  void depositar(double valor) throws ValorIncorretoException {
        if (valor > 0) {
            this.saldo+=valor;
            this.criarMovimentacao("Depósito", 'C', valor);
        } else {
            throw new ValorIncorretoException();
        }
    }
    
    protected void sacar(double valor) throws SaldoInsuficienteException {
        if (this.saldo+this.limite >= valor) {
            this.saldo -= valor;
            this.criarMovimentacao("Saque", 'D', valor);
        } else {
            throw new SaldoInsuficienteException();
        }
    }
    
    private void criarMovimentacao(String descricao, char tipo, double valor) {
        this.movimentacoes.add(new Movimentacao(descricao, tipo, valor));
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
