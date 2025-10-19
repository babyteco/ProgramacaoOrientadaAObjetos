//para compilar: 
//javac Programa.java
//java Programa

import java.util.Scanner;

public class dobro {

    static class Dobro {
        public int Dobrar(int numero){
            return 2 * numero;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        Dobro d = new Dobro();
        num = d.Dobrar(num);
        System.out.printf("%d\n", num);

        sc.close();
    }
}