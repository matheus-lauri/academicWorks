
import br.univali.cc.prog3.livro.dominio.Autor;
import br.univali.cc.prog3.livro.dominio.Livro;
import br.univali.cc.prog3.livro.dominio.LivroBiblioteca;
import br.univali.cc.prog3.livro.dominio.LivroLivraria;

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
        Livro[] livros = new Livro[99];
        
        //livros[0] = new Livro("1234", "livro 1", new Autor("jose"));
        livros[0] = new LivroBiblioteca("azul-45", 3, "4566", "livro 2", new Autor("maria"));
        livros[1] = new LivroLivraria(3, 150, "978978", "livro 3", new Autor("ze"));
        
        for (Livro livro:livros) {
            if (livro == null){
                break;
            }
            System.out.println(livro.getNome());
            
            if (livro instanceof LivroBiblioteca) {
                LivroBiblioteca livroBiblioteca = (LivroBiblioteca) livro;
                System.out.println(livroBiblioteca.getLocalizacao());
            } else if(livro instanceof LivroLivraria) {
                LivroLivraria livroLivraria = (LivroLivraria) livro;
                System.out.println(livroLivraria.getEstoque());
            }
            
            
        }
       
        /*
        Livro livro = new LivroBiblioteca(
                "Vermelho-57",
                15,
                "123456", 
                "Corte de espinho e rosas",
                new Autor("Joao"),
                new Autor("Maria"),
                new Autor("Jose")
        );
        
        System.out.println(livro.getNome());
        if (livro instanceof LivroBiblioteca){
            System.out.println(((LivroBiblioteca)livro).getLocalizacao());
        }
        if (livro instanceof LivroLivraria) {
            System.out.println(((LivroLivraria)livro).getEstoque());
        }
        System.out.println(livro instanceof Livro);
        System.out.println(livro instanceof LivroLivraria);
        System.out.println(livro instanceof LivroBiblioteca);
        
        
        System.out.println("--------------------");
        livro = new LivroLivraria(
                10,
                15.00,
                "123456", 
                "Corte de espinho e rosas 2",
                new Autor("Joao"),
                new Autor("Maria"),
                new Autor("Jose")
        );
        
        System.out.println(livro.getNome());
        if (livro instanceof LivroBiblioteca){
            System.out.println(((LivroBiblioteca)livro).getLocalizacao());
        }
        if (livro instanceof LivroLivraria) {
            System.out.println(((LivroLivraria)livro).getEstoque());
        }
        System.out.println(livro instanceof Livro);
        System.out.println(livro instanceof LivroLivraria);
        System.out.println(livro instanceof LivroBiblioteca);
*/
    }
    
}
