package myFirstJavaCode;

//Classe Animal - Abstração e Encapsulamento
public abstract class Animal {
 private String nome;
 private int idade;
 private String som;

 public Animal(String nome, int idade, String som) {
     this.nome = nome;
     this.idade = idade;
     this.som = som;
 }

 public String getNome() {
     return nome;
 }

 public int getIdade() {
     return idade;
 }

 public String getSom() {
     return som;
 }

 public abstract void emitirSom();
}