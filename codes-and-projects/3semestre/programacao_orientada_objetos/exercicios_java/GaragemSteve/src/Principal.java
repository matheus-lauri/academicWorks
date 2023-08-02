
import br.univali.cc.prog3.m2.dominio.Caminhao;
import br.univali.cc.prog3.m2.dominio.Carro;
import br.univali.cc.prog3.m2.dominio.Galpao;
import br.univali.cc.prog3.m2.dominio.Helicoptero;
import br.univali.cc.prog3.m2.dominio.Iate;
import br.univali.cc.prog3.m2.dominio.Veiculo;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

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
        Map<String,Veiculo> veiculos = new HashMap<>();
        veiculos.put("xxx", new Iate("dfasdf"));
        veiculos.put("yyy",new Caminhao(250, "modelo", "ssdfsa"));
        
        
        for(String chave:veiculos.keySet()){
            System.out.println("chave "+chave+" "+veiculos.get(chave).obterDescricaoVeiculo());
        }
        
        for(Veiculo veiculo:veiculos.values()){
            System.out.println(veiculo.obterDescricaoVeiculo());
        }
        
                
        
        /*
        SortedSet<Veiculo> veiculos = new TreeSet<>();
        //List<Veiculo> veiculos = new LinkedList<>();
        veiculos.add(new Caminhao(2000, "scania", "xxx1111"));
        veiculos.add(new Caminhao(2500, "scania", "xxx1111"));
        veiculos.add(new Carro(1200, "um superesportivo eletrico qualquer", "aaa8888"));
        veiculos.add(new Helicoptero("Aguia", "xpt 111"));
        
        Iate iate = new Iate("Javai tarde");
        iate.setCapitao("Joao");
        veiculos.add(iate);
        
        for(Veiculo veiculo:veiculos){
            System.out.println(veiculo.obterDescricaoVeiculo());
        }
        */
        /*
        Galpao galpao = new Galpao();
        galpao.adicionarVeiculo(new Caminhao(2000, "scania", "xxx1111"));
        galpao.adicionarVeiculo(new Carro(1200, "um superesportivo eletrico qualquer", "aaa8888"));
        galpao.adicionarVeiculo(new Helicoptero("Aguia", "xpt 111"));
        
        Iate iate = new Iate("Javai tarde");
        iate.setCapitao("Joao");
        galpao.adicionarVeiculo(iate);
       
        System.out.println(galpao.imprimirRelacaoVeiculos());
*/        
    }
    
}
