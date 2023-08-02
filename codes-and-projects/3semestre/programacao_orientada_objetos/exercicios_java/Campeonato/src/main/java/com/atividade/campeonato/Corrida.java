
package com.atividade.campeonato;

import java.util.Date;

public class Corrida {
    
    
    private Date data;
    public Autodromo autodromo;
    
    public Corrida(Autodromo autodromo, Date data ){
        this.data = data;
        this.autodromo = autodromo;
    }
}
