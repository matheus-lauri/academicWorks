package myFirstJavaCode;

//Classe Cachorro - Herança
public class Cachorro extends Animal {
 public Cachorro(String nome, int idade) {
     super(nome, idade, "Au Au");
 }

 @Override
 public void emitirSom() {
     System.out.println(getSom());
 }

 public void correr() {
     System.out.println("O cachorro está correndo");
 }
}