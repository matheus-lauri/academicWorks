
import br.univali.cc.prog3.banco.dominio.Banco;
import br.univali.cc.prog3.banco.visao.BancoGUI;

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
        Banco bb = new Banco("Banco do Brasil", 1);
        BancoGUI banco = new BancoGUI(bb);
        banco.menu();
    }
    
}
