/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 1978233
 */
public class Numero {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //5 10 34 2 7 50 25
        int maior = 0;
        int menor = 0;
        double soma = 0;
        for (int x=0; x < args.length; x++) {
            int numero = Integer.parseInt(args[x]);
            soma += numero;
            
            if (x==0){
                maior = numero;
                menor = numero;
                continue;
            }
            
            if (numero > maior) {
                maior = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
            
        }
        System.out.println("Media "+(soma/args.length));
        System.out.println("Menor "+menor);
        System.out.println("Maior "+maior);
    }
    
}
