
package com.atividade.principal;

import com.atividade.campeonato.Organizador;
import com.atividade.view.View;
import java.text.ParseException;

/**
 *
 * @author Master
 */
public class Principal {
    
    public static void main(String[] args) throws ParseException {
        
        Organizador org = new Organizador();
        View menu = new View(org);
        menu.menuPrincipal();
        
    }
}
