
import br.com.xingling.radio.RadioDeCabeceira;
import br.com.xingling.radio.Relogio;
import br.com.xingling.radio.XingLing;

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
        RadioDeCabeceira radio = new RadioDeCabeceira("xpto 2023", "123456/2023");
        radio.ligar();
        radio.ajustarHora(13, 45);
        radio.sintonizar(102.7);
        System.out.println(radio.getNumeroSerie());
        radio.desligar();
        
        System.out.println(radio instanceof RadioDeCabeceira);
        System.out.println(radio instanceof Relogio);
        System.out.println(radio instanceof br.univali.cc.bughi.radio.Radio);
        System.out.println(radio instanceof XingLing);
        System.out.println(radio instanceof Object); //Deus
        
    }
    
}
