
import java.util.Scanner;
import josue.Ficha;

/**
 *
 * @author 1978233
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*
        System.out.println(Ficha.totalFichas());

        Ficha[] fichas = new Ficha[10];
        System.out.println(Ficha.totalFichas());
        fichas[0] = new Ficha("Maria",5000);
        System.out.println(Ficha.totalFichas());
        fichas[1] = new Ficha("Joao",2500);
        System.out.println(Ficha.totalFichas());
*/

        Ficha[] fichas = new Ficha[4];
        for(int x = 0; x < fichas.length; x++) {
            Scanner leitor = new Scanner(System.in);
            String nome = leitor.nextLine();
            double salario = leitor.nextDouble();
            fichas[x] = new Ficha(nome,salario);
        }

        for(Ficha ficha:fichas) {
            if (ficha != null) {
                System.out.println(ficha.detalhar());
            }
        }
        
        /*
        Ficha ficha1 = new Ficha();
        Ficha ficha2 = new Ficha("Carlos", 500);
        Ficha ficha3 = new Ficha();
        */
        /*
        System.out.println(ficha2.detalhar());
        System.out.println(ficha3.detalhar());
        */
/*        
        // TODO code application logic here
        String nome = "Carlos Henrique Bughi";
        System.out.println(nome.toUpperCase());
        System.out.println(nome.charAt(5));
        System.out.println(nome.concat(" bonitao"));
        //System.out.println(nome.split("e").length);
        String[] partes = nome.split(" ");
        
        
        for (int x=0; x < partes.length; x++){
            String parte = partes[x];
            System.out.println(parte);
        }
        
        for (String parte:partes){
            System.out.println(parte);
        }
  */      
        
    }
    
}
