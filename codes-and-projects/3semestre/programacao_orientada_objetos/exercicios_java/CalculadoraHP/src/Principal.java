
import br.univali.cc.prog3.calculadora.Calculadora;
import br.univali.cc.prog3.calculadora.excecoes.DivisaoPorZeroException;
import br.univali.cc.prog3.calculadora.excecoes.OperacaoInvalidaException;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 1978233
 */
public class Principal {
    
    public String lerValor(String rotulo) {
        System.out.print(rotulo+": ");
        Scanner leitor = new Scanner(System.in);
        return leitor.nextLine();
    }
    
    public void menu(){
        String resposta = "";
        try{
            Calculadora hp = new Calculadora();
            double oper1 = Double.parseDouble(this.lerValor("operando 1"));
            double oper2 = Double.parseDouble(this.lerValor("operando 2"));
            char operacao = this.lerValor("operacao").charAt(0);
            hp.setOper1(oper1);
            hp.setOper2(oper2);
            double res = hp.calcular(operacao);
            resposta = String.valueOf(res);
        } catch(OperacaoInvalidaException ex) {
            resposta = "Operacao não suportada";
        } catch(DivisaoPorZeroException ex) {
            resposta = "Quer dividir por zero maneh??";
        } catch(Exception ex) {
            resposta = "Ocorreu um erro inexperado. \nPor favor, contacte o Cesar.";
        } finally {
            System.out.println(resposta);
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Principal principal = new Principal();
        principal.menu();
    }
    
}
