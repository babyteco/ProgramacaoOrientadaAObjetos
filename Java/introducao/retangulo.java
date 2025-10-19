//para compilar:
//javac Programa.java
//java Programa

import java.util.Scanner;

public class retangulo {
    static class Retangulo {
        private int altura;
        private int largura;


        public Retangulo(int altura, int largura){
            this.altura = altura;
            this.largura = largura;
        }

        public int getAltura(){
            return this.altura;
        }

        public int getLargura(){
            return this.largura;
        }

        public int perimetro(){
            return (2 * this.altura) + (2 * this.largura);
        }

        public int area(){
            return this.altura * this.largura;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int altura = sc.nextInt();
        int largura = sc.nextInt();
        
        Retangulo ret = new Retangulo(altura, largura);

        System.out.printf("%d\n", ret.getAltura());
        System.out.printf("%d\n", ret.getLargura());
        System.out.printf("%d\n", ret.area());
        System.out.printf("%d\n", ret.perimetro());

        sc.close();
    }
}

/*- construtor(int altura, int largura)
- area() -> int
- perimetro() -> int
- getAltura() -> int
- getLargura() -> int */