package myFirstJavaCode;

//Classe Main
public class Main {
 public static void main(String[] args) {
     Cachorro cachorro = new Cachorro("Bolinha", 3);
     Gato gato = new Gato("Mel", 2);
     Veterinario veterinario = new Veterinario();

     cachorro.emitirSom();
     cachorro.correr();

     gato.emitirSom();
     gato.arranhar();

     veterinario.examinar(cachorro);
     veterinario.examinar(gato);
 }
}