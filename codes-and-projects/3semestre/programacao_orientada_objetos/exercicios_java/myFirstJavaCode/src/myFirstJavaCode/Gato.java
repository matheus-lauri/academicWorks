package myFirstJavaCode;

//Classe Gato - Herança e Polimorfismo
public class Gato extends Animal {
 public Gato(String nome, int idade) {
     super(nome, idade, "Miau");
 }

 @Override
 public void emitirSom() {
     System.out.println(getSom());
 }

 public void arranhar() {
     System.out.println("O gato está arranhando");
 }
}