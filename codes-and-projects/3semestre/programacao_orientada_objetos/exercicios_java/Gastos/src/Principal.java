
import br.univali.cc.prog3.gastos.dominio.Aplicacao;
import br.univali.cc.prog3.gastos.visao.ControleGastos;
import java.util.Calendar;

/**
 *
 * @author 1978233
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ControleGastos cc = new ControleGastos(new Aplicacao());
        cc.menu();
    }
    
}
