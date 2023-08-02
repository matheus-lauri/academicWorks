/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.gastos.visao;

import br.univali.cc.prog3.gastos.dominio.Aplicacao;
import br.univali.cc.prog3.gastos.dominio.FormaPagamento;
import br.univali.cc.prog3.gastos.dominio.TipoGasto;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import javax.swing.JOptionPane;

/**
 *
 * @author 1978233
 */
public class ControleGastos {
    private Aplicacao aplicacao;
    
    public String lerValor(String rotulo) {
        return JOptionPane
                .showInputDialog(null,rotulo);
    }

    public Object lerValor(String rotulo, Object[] opcoes) {
        return JOptionPane
                .showInputDialog(
                        null, 
                        null, 
                        rotulo, 
                        JOptionPane.QUESTION_MESSAGE,
                        null, 
                        opcoes,
                        null
                );
    }
    
    public void escreverValor(String valor) {
        JOptionPane
                .showMessageDialog(
                        null, 
                        valor
                );
    }

    public ControleGastos(Aplicacao aplicacao) {
        this.aplicacao = aplicacao;
    }
    
    public void menu() {
        char opcao;
        do {
            String[] opcoes = {
                "1 - Adicionar tipo gasto",
                "2 - Adicionar forma pagamento",
                "3 - Novo gasto",
                "4 - Relatorio",
                "S - Sair"
            };
            String valorSelecionado = (String) this.lerValor(
                    "Selecione uma opção",
                    opcoes
            );
            if (valorSelecionado == null) {
               break;
            }
            
            opcao = valorSelecionado
                    .toUpperCase()
                    .charAt(0);

            
            switch (opcao) {
                case '1': adicionarTipoGasto();break;
                case '2': adicionarFormaPagamento();break;
                case '3': novoGasto();break;
                case '4': relatorio();break;
            }
        } while (true);
    }

    private void adicionarTipoGasto() {
        String descricao = lerValor("Informe a descrição");
        TipoGasto tipo = new TipoGasto(descricao);
        this.aplicacao.adicionarTipoGasto(tipo);
    }
    
    private void adicionarFormaPagamento() {
        String descricao = lerValor("Informe a descricao");
        FormaPagamento forma = new FormaPagamento(descricao);
        this.aplicacao.adicionarFormaPagamento(forma);
    }
    
    private void novoGasto() {
        String descricao = lerValor("Informe a descricao");
        double valor = Double.parseDouble(
                lerValor("Informe o valor ")
        );
        LocalDate data = LocalDate.parse(
                lerValor("Informe a data"), 
                DateTimeFormatter
                        .ofPattern("d/M/y")
        );
        TipoGasto tipo = (TipoGasto) lerValor(
                "Selecione o tipo de gasto", 
                aplicacao
                        .getTipos()
        );
        FormaPagamento forma = (FormaPagamento) lerValor(
                "Selecione a forma", 
                aplicacao
                        .getFormas()
        );
        aplicacao.novoGasto(descricao, data, valor, tipo, forma);
    }
    
    private void relatorio(){
        int mes = Integer.parseInt(
                lerValor("Informe o mês")
        );
        int ano = Integer.parseInt(
                lerValor("Informe o ano")
        );
        this.escreverValor(
                this.aplicacao.listarGastos(
                        mes, 
                        ano
                )
        );
    }
    
}
