/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package josue;

/**
 *
 * @author 1978233
 */
public class Ficha {
    
    private String nome;
    private double salario;
    
    private static int totalFichas = 0;

    public Ficha() {
        this.nome = "Ze ninguem";
        this.salario = 0;
        totalFichas++;
    }
    
    public Ficha(String nome, double salario){
        this.nome = nome;
        this.salario = salario;
        System.out.println("Criando uma ficha");
        totalFichas++;
    }
    
    public static int totalFichas() {
        return totalFichas;
    }
    
    /**
     * Detalha a ficha
     * @return o detalhamento da ficha
     * @deprecated 
     * @since  1.3
     */
    public String detalhar() {
        return nome+" "+salario;
    }
    
}
