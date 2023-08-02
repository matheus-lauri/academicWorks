/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.gastos.dominio;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

/**
 *
 * @author 1978233
 */
public class Aplicacao {

    public  FormaPagamento[] formas  = new FormaPagamento[5];
    private Gasto[] gastos           = new Gasto[999];
    public  TipoGasto[] tipos        = new TipoGasto[999];

    private int contadorForma        = 0;
    private int contadorTipoGasto    = 0;
    private int contadorGasto        = 0;

    public void adicionarFormaPagamento(FormaPagamento forma) {
        this.formas[contadorForma++] = forma;
    }

    public void adicionarTipoGasto(TipoGasto gasto) {
        this.tipos[contadorTipoGasto++] = gasto;
    }

    public void novoGasto(String descricao, 
            LocalDate data, 
            double valor, 
            TipoGasto tipo, 
            FormaPagamento forma) {
        
        this.gastos[contadorGasto++] = new Gasto(
                data, 
                descricao, 
                valor, 
                tipo, 
                forma
        );
    }

    public String listarGastos(int mes, int ano) {
        LocalDate dataInicial = LocalDate
                .of(
                        ano, 
                        mes, 
                        1
                );
        LocalDate dataFinal = dataInicial
                .withDayOfMonth(dataInicial
                        .getMonth()
                        .length(dataInicial
                                .isLeapYear()
                        )
                );
        
        String retorno = "";
        for (Gasto gasto : this.gastos) {
            if (gasto != null 
                    && gasto
                            .data
                            .isAfter(dataInicial) 
                    && gasto
                            .data
                            .isBefore(dataFinal)
                ) {
                retorno += "\n" + gasto.obterDescricao();
            }
        }
        return retorno;
    }

    public FormaPagamento[] getFormas() {
        return formas;
    }

    public TipoGasto[] getTipos() {
        return tipos;
    }
    
    
    class Gasto {

        LocalDate data;
        String descricao;
        double valor;
        TipoGasto tipo;
        FormaPagamento forma;

        public Gasto(LocalDate data, 
                String descricao, 
                double valor, 
                TipoGasto tipo, 
                FormaPagamento forma) {
            this.data = data;
            this.descricao = descricao;
            this.valor = valor;
            this.tipo = tipo;
            this.forma = forma;
        }

        public String obterDescricao() {
            return String
                    .format("%s %s R$%.2f (%s %s)",  
                            this.data.format(
                                    DateTimeFormatter
                                            .ofPattern("d/M/Y")
                            ),
                            this.descricao, 
                            this.valor,
                            this.forma, 
                            this.tipo
                            );
        }

    }

}
