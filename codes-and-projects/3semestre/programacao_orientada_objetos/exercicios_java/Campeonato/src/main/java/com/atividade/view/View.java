
package com.atividade.view;

import com.atividade.campeonato.Piloto;
import com.atividade.campeonato.Mecanico;
import com.atividade.campeonato.Organizador;
import com.atividade.campeonato.Autodromo;
import com.atividade.campeonato.Carro;
import com.atividade.campeonato.Equipe;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.JOptionPane;

public class View {
    
    private Organizador org;
    
    public String lerValor(String rotulo) {
        return JOptionPane.showInputDialog(null,rotulo);
    }
    public String lerValor(String rotulo, String[] opcoes) {
        return (String) JOptionPane.showInputDialog(null, null, rotulo, JOptionPane.QUESTION_MESSAGE,null, opcoes,null);
    }
    public void escreverValor(String valor) {
        JOptionPane.showMessageDialog(null, valor);
    }
    public View(Organizador org) {
        this.org = org;
    }
    public void menuPrincipal() throws ParseException {
        char opcao;
        do {
            String[] opcoes = {"1 - Criar Campeonato",
                               "2 - Inscrever uma Equipe para um Campeonato",
                               "3 - Definir uma corrida"
            };
            String valorSelecionado = this.lerValor("Selecione uma opção:",opcoes);
            if (valorSelecionado == null) {
                opcao = 'S';
            } else {
                opcao = valorSelecionado.toUpperCase().charAt(0);
            }
            switch (opcao) {
                case '1': criarCamp();break;
                case '2': inscreverEq();break;
                case '3': definirCorrida();break;
            }
        } while (opcao != 'S');
    }
    
    public void criarCamp(){
        String nome = lerValor("Informe o nome do Campeonato");
        int ano = Integer.parseInt(lerValor("Informe o ano do Campeonato"));
        this.org.criarCampeonato(ano, nome);
    }
    
    public void inscreverEq(){
        //Pegando o nome da equipe
        String nomeEquipe = lerValor("Informe o nome da Equipe");
        Equipe equipe = new Equipe(nomeEquipe);
        
        //pegando o piloto 1 e o carro desse piloto
        String nomePiloto1 = lerValor("Informe o nome do piloto 1");
        int licencaPiloto1 = Integer.parseInt(lerValor("Informe o número da licença do piloto 1"));
        Piloto piloto1 = new Piloto(nomePiloto1, licencaPiloto1);
        int numCarroPiloto1 = Integer.parseInt(lerValor("Informe o número do carro do piloto 1"));
        Carro carroPiloto1 = new Carro(numCarroPiloto1, piloto1);
        equipe.addCarro(carroPiloto1);
        
        //pegando o piloto 2 e o carro desse piloto
        String nomePiloto2 = lerValor("Informe o nome do piloto 2");
        int licencaPiloto2 = Integer.parseInt(lerValor("Informe o número da licença do piloto 2"));
        Piloto piloto2 = new Piloto(nomePiloto2, licencaPiloto2);
        int numCarroPiloto2 = Integer.parseInt(lerValor("Informe o número do carro do piloto 2"));
        Carro carroPiloto2 = new Carro(numCarroPiloto2, piloto2);
        equipe.addCarro(carroPiloto2);
        
        //pegando os mecanicos da equipe
        int qtdMecanico = Integer.parseInt(lerValor("Informe a quantidade de mecãnicos(vetor declarado com 10 posições)"));
        for(int i = 0; i < qtdMecanico; i++){
            String nomeMecanico = lerValor("Informe o nome do mecanico");
            Mecanico mecanico = new Mecanico(nomeMecanico);
            equipe.addMecanico(mecanico);
        }
        
        //adicionando a equipe no campeonato desejado
        int numCampeonato = Integer.parseInt(lerValor("Informe o número do campeonato que esta equipe será inscrita"));
        if(this.org.inscreverEquipe(equipe, numCampeonato)){
            escreverValor("Equipe inscrita");
        }else{
            escreverValor("Erro: Equipe não inscrita");
        }
        
    }
    
    public void definirCorrida() throws ParseException{
        int idCampeonato = Integer.parseInt(lerValor("Informe o id do Campeonato"));
        String local = lerValor("Informe o local da corrida");
        Autodromo autodromo = new Autodromo(local);
        String input = lerValor("Digite uma data no formato DD/MM/AAAA para a corrida:");
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        Date data = formatter.parse(input);
        
        if(this.org.adicionarCorrida(autodromo, data, idCampeonato)){
            String dataFormatada = formatter.format(data);
            escreverValor("Corrida confirmada para a data "+ dataFormatada + " no autódromo " + local);
        }else{
            escreverValor("Erro ao adicionar a corrida, tente novamente!");
        }
    }

}
