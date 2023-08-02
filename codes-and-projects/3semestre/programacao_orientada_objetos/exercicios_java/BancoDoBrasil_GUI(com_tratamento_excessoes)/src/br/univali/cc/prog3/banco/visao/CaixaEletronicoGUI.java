/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.visao;

import br.univali.cc.prog3.banco.dominio.Banco;
import br.univali.cc.prog3.banco.dominio.excecoes.ContaInexistenteException;
import br.univali.cc.prog3.banco.dominio.excecoes.SaldoInsuficienteException;
import br.univali.cc.prog3.banco.dominio.excecoes.ValorIncorretoException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author 1978233
 */
public class CaixaEletronicoGUI {
    
    public String lerValor(String rotulo) {
        return JOptionPane.showInputDialog(null,rotulo);
    }

    public String lerValor(String rotulo, String[] opcoes) {
        return (String) JOptionPane.showInputDialog(null, null, rotulo, JOptionPane.QUESTION_MESSAGE,null, opcoes,null);
    }
    
    public void escreverValor(String valor) {
        JOptionPane.showMessageDialog(null, valor);
    }
    
    public CaixaEletronicoGUI() {
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
        this.escreverValor("numero: "+Banco.getInstance().criarConta(saldoInicial));
    }
    
    private void criarContaEspecial() {
        double saldoInicial = Double.parseDouble(lerValor("Informe o saldo inicial"));
        double limite = Double.parseDouble(lerValor("Informe o limite da conta"));
        this.escreverValor("numero: "+Banco.getInstance().criarConta(saldoInicial, limite));
    }
    
    private void depositar() {
        try {
            int numero = Integer.parseInt(lerValor("Informe o numero da conta"));
            double valor = Double.parseDouble(lerValor("Informe o valor para depósito"));
            Banco.getInstance().depositar(numero, valor);
        }catch(ContaInexistenteException ex) {
            this.escreverValor("A conta informada não existe");
        }catch(ValorIncorretoException ex) {
            this.escreverValor("O valor informado para depósito está incorreto");
        }catch(NumberFormatException ex) {
            this.escreverValor("Ocorreu um erro ao tentar obter o número e/ou valor digitado pelo usuário");
        }
    }
    
    private void sacar() {
        try {
            int numero = Integer.parseInt(lerValor("Informe o numero da conta"));
            double valor = Double.parseDouble(lerValor("Informe o valor para saque"));
            Banco.getInstance().sacar(numero, valor);
        } catch (ContaInexistenteException ex) {
            this.escreverValor("A conta informada não existe");
        } catch (SaldoInsuficienteException ex) {
            this.escreverValor("Saldo insuficiente, pense bem antes de gastar mais do que deve!!!!!");
        }catch(NumberFormatException ex) {
            this.escreverValor("Ocorreu um erro ao tentar obter o número e/ou valor digitado pelo usuário");
        }
    }    
    
    private void transferir() {
        try {
            int numeroOrigem = Integer.parseInt(lerValor("Informe o numero da conta de origem"));
            int numeroDestino = Integer.parseInt(lerValor("Informe o numero da conta de destino"));
            double valor = Double.parseDouble(lerValor("Informe o valor para transferência"));
            Banco.getInstance().transferir(numeroOrigem, numeroDestino, valor);
        } catch (ContaInexistenteException ex) {
            this.escreverValor("A conta informada não existe");
        } catch (SaldoInsuficienteException ex) {
            this.escreverValor("Saldo insuficiente, pense bem antes de gastar mais do que deve!!!!!");
        }catch(NumberFormatException ex) {
            this.escreverValor("Ocorreu um erro ao tentar obter o número e/ou valor digitado pelo usuário");
        }catch(ValorIncorretoException ex) {
            this.escreverValor("Valor informado não pode ser depositado");
        }catch(Exception ex) {
            this.escreverValor("Ops. Ocorreu um erro interno, contacte o administrador do sistema");
        }
    }    
    
    private void extrato(){
        try{
            int numero = Integer.parseInt(lerValor("Informe o numero da conta"));
            this.escreverValor(Banco.getInstance().emitirExtrato(numero));
        }catch(ContaInexistenteException ex) {
            this.escreverValor(ex.getMessage());
        } catch(NumberFormatException ex) {
            this.escreverValor("Ocorreu um erro ao tentar obter o número e/ou valor digitado pelo usuário");
        }
    }
    
}
