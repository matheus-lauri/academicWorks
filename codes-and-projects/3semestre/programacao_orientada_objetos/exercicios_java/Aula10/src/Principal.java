
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

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

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");
            Date data1;
            data1 = format.parse("08/05/2023");
            System.out.println(data1.getTime());
            System.out.println(data1);

            Date data2;
            data2 = format.parse("01/05/2023");
            System.out.println(data2.getTime());
            System.out.println(data2);
            
            System.out.println(data1.getTime() > data2.getTime());
            
            
        } catch (ParseException ex) {
            Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
