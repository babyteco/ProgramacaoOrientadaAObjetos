//para compilar: 
//javac exercicio2.java
//java exercicio2

import java.util.Scanner;
import java.util.Arrays;

public class exercicio2{
    static class Estudante{
        private int[] notas;
        private String nome;
        private float cp;
        public Estudante(String nome, float cp, int[] n){
            this.nome = nome;
            this.cp = cp;
            this.notas = Arrays.copyOf(n, 3);
        }
        public String getNome(){
            return this.nome;
        }
        public float getCoeficiente(){
            return this.cp;
        }
        public int[] getArrayNotas(){
            return this.notas;
        }
        public float media(){
            int soma = 0;
            for(int i = 0; i < this.notas.length; i++){
                soma += this.notas[i];
            }
            return soma / this.notas.length;
        }
        public boolean foiAprovado(){
            if(this.cp >= 0.75 && this.media() >= 7){
                return true;
            } else return false;
        }
    }

    static public void main(String[] args){
        System.out.println("Digite o nome, percentual de presenca e as 3 notas:");
        Scanner sc = new Scanner(System.in);

        String nome = sc.nextLine();
        float cp = sc.nextFloat();
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int n3 = sc.nextInt();
        int[] vet = new int[3];
        vet[0] = n1;
        vet[1] = n2;
        vet[2] = n3;
        
        Estudante est = new Estudante(nome, cp, vet);

        int[] copia = Arrays.copyOf(est.getArrayNotas(), est.getArrayNotas().length);
        System.out.printf("O nome do estudante eh: %s\n", est.getNome());
        System.out.printf("Coeficiente de presenca do estudante eh %.02f\n", est.getCoeficiente());
        System.out.printf("Media de notas do estudante eh %.02f\n", est.media());
        System.out.printf("Nota da prova 1: %d\n", copia[0]);
        System.out.printf("Nota da prova 2: %d\n", copia[1]);
        System.out.printf("Nota da prova 3: %d\n", copia[2]);
        System.out.print("Situação: ");
        if(est.foiAprovado()){
            System.out.println("APROVADO");
        } else{
            System.out.println("REPROVADO");
        }

        sc.close();
    }
}