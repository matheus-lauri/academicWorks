/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.visao;

import br.univali.cc.prog3.banco.dominio.Banco;
import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 *
 * @author 1978233
 */
public class CaixaEletronicoGUI {
    private Banco banco;
    
    public String lerValor(String rotulo) {
        return JOptionPane.showInputDialog(null,rotulo);
    }

    public String lerValor(String rotulo, String[] opcoes) {
        return (String) JOptionPane.showInputDialog(null, null, rotulo, JOptionPane.QUESTION_MESSAGE,null, opcoes,null);
    }
    
    public void escreverValor(String valor) {
        JOptionPane.showMessageDialog(null, valor);
    }
    
    public CaixaEletronicoGUI(Banco banco) {
        this.banco = banco;
    }
    
    public void menu() {
        char opcao;
        do {
            String[] opcoes = {
                "1 - Criar conta simples",
                "2 - Criar conta especial",
                "3 - Depositar",
                "4 - Sacar",
                "5 - Transferir",
                "6 - Extrato",
                "S - Sair"
            };
            String valorSelecionado = this.lerValor("Selecione uma opção",opcoes);
            if (valorSelecionado == null) {
                opcao = 'S';
            } else {
                opcao = valorSelecionado.toUpperCase().charAt(0);
            }
            
            switch (opcao) {
                case '1': criarContaSimples();break;
                case '2': criarContaEspecial();break;
                case '3': depositar();break;
                case '4': sacar();break;
                case '5': transferir();break;
                case '6': extrato();break;
            }
        } while (opcao != 'S');
    }

    private void criarContaSimples() {
        double saldoInicial = Double.parseDouble(lerValor("Informe o saldo inicial"));
        this.banco.criarConta(saldoInicial);
    }
    
    private void criarContaEspecial() {
        double saldoInicial = Double.parseDouble(lerValor("Informe o saldo inicial"));
        double limite = Double.parseDouble(lerValor("Informe o limite da conta"));
        this.banco.criarConta(saldoInicial, limite);
    }
    
    private void depositar() {
        int numero = Integer.parseInt(lerValor("Informe o numero da conta"));
        double valor = Double.parseDouble(lerValor("Informe o valor para depósito"));
        this.banco.depositar(numero, valor);
    }
    
    private void sacar() {
        int numero = Integer.parseInt(lerValor("Informe o numero da conta"));
        double valor = Double.parseDouble(lerValor("Informe o valor para saque"));
        this.banco.sacar(numero, valor);
    }    
    
    private void transferir() {
        int numeroOrigem = Integer.parseInt(lerValor("Informe o numero da conta de origem"));
        int numeroDestino = Integer.parseInt(lerValor("Informe o numero da conta de destino"));
        double valor = Double.parseDouble(lerValor("Informe o valor para transferência"));
        this.banco.transferir(numeroOrigem, numeroDestino, valor);
    }    
    
    private void extrato(){
        int numero = Integer.parseInt(lerValor("Informe o numero da conta"));
        this.escreverValor(this.banco.emitirExtrato(numero));
        //System.out.println(this.banco.emitirExtrato(numero));
    }
    
}
