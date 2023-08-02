package br.univali.cc.prog3.banco.visao;

import br.univali.cc.prog3.banco.dominio.Banco;
import java.util.Scanner;

/**
 *
 * @author 1978233
 */
public class BancoGUI {
    private Banco banco;
    
    public String lerValor(String rotulo) {
        System.out.print(rotulo+": ");
        Scanner leitor = new Scanner(System.in);
        return leitor.nextLine();
    }

    public BancoGUI(Banco banco) {
        this.banco = banco;
    }
    
    public void menu() {
        char opcao;
        do {
            System.out.println("Menu do "+this.banco.getNome());
            System.out.println("1 - Criar conta simples");
            System.out.println("2 - Criar conta especial");
            System.out.println("3 - Depositar");
            System.out.println("4 - Sacar");
            System.out.println("5 - Transferir");
            System.out.println("6 - Extrato");
            opcao = this.lerValor("Selecione uma opção").toUpperCase().charAt(0);
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
        System.out.println(this.banco.emitirExtrato(numero));
    }
}
