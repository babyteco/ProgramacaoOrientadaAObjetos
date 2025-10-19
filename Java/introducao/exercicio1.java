//para compilar: 
//javac Programa.java
//java Programa

import java.util.Scanner;

public class exercicio1{
    static class Retangulo{
        private int largura;
        private int altura;

        public Retangulo(int altura, int largura){
            this.altura = altura;
            this.largura = largura;
        }

        public float Area(){
            return this.altura * this.largura;
        }

        public float Perimetro(){
            return 2 * this.altura + 2 * this.largura;
        }
    }
    
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Digite os valores da altura e largura:");
        
        int altura, largura;
        altura = sc.nextInt();
        largura = sc.nextInt();

        Retangulo ret = new Retangulo(altura, largura);

        System.out.printf("O valor da area eh: %.02f\nO valor do perimetro eh: %.02f\n", ret.Area(), ret.Perimetro());
        
        sc.close(); 
    }
}