/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 1978233
 */
public class Nota {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        for (int x = 0; x < args.length; x++) {
            int nota = Integer.parseInt(args[x]);
            String grafico = "";
            for (int y=0; y < nota; y++){
                grafico += "*";
            }
            System.out.println("Aluno "+(x+1)+" "+grafico);           
        }
    }
    
}
