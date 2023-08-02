
import br.univali.cc.mundoanimal.Animal;
import br.univali.cc.mundoanimal.Cachorro;
import br.univali.cc.mundoanimal.Cavalo;
import br.univali.cc.mundoanimal.Corredor;
import br.univali.cc.mundoanimal.Preguica;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author 1978233
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Animal[] jaula = new Animal[4];
        jaula[0] = new Cachorro("toto", 3);
        jaula[1] = new Preguica("zenaide", 45);
        jaula[2] = new Cavalo("alazao", 15);
        jaula[3] = new Cachorro("simba", 1);
        
        for(Animal animal:jaula) {
            animal.emitirSom();
            if (animal instanceof Corredor) {
                ((Corredor)animal).correr();
            }
        }
                
    }
    
}
