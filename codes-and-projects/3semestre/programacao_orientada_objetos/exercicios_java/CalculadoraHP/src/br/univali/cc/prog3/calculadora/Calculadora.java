/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.calculadora;

import br.univali.cc.prog3.calculadora.excecoes.DivisaoPorZeroException;
import br.univali.cc.prog3.calculadora.excecoes.OperacaoInvalidaException;

/**
 *
 * @author 1978233
 */
public class Calculadora {
    private double oper1;
    private double oper2;

    public Calculadora(double oper1, double oper2) {
        this.oper1 = oper1;
        this.oper2 = oper2;
    }

    public Calculadora() {
    }
    
    
    
    

    public void setOper1(double oper1) {
        this.oper1 = oper1;
    }

    public void setOper2(double oper2) {
        this.oper2 = oper2;
    }
    
    public double calcular(char operacao) throws OperacaoInvalidaException, DivisaoPorZeroException {
        double resultado;
        switch (operacao) {
            case '+': resultado = oper1+oper2;break;
            case '-': resultado = oper1-oper2;break;
            case '/': 
                if (oper2 == 0) {
                    throw new DivisaoPorZeroException();
                }
                resultado = oper1/oper2;
                break;
            case '*': resultado = oper1*oper2;break;
            default: throw new OperacaoInvalidaException();
        }
        return resultado;
    }
}
