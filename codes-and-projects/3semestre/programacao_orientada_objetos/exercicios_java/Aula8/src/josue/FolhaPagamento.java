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
public class FolhaPagamento {

    public FolhaPagamento() {
        Ficha ficha = new Ficha();
        String detalhe = ficha.detalhar();
    }
    
}
