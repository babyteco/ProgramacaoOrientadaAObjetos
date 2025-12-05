import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Vetor{
    public static void main(String[] args){
        ArrayList<Integer> numeros = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int qtd;
        for(int i = 0; i < n; i++){
            String jerry = sc.next();
            if (jerry.equals("INSERIR")){
                qtd = sc.nextInt();
                numeros.add(qtd);
            } else if(jerry.equals("REMOVER")){
                System.out.printf("%d\n", numeros.get(numeros.size() - 1));
                numeros.remove(numeros.size() - 1);
            } else if(jerry.equals("VER")){
                qtd = sc.nextInt();
                System.out.printf("%d\n", numeros.get(qtd));
            } else if(jerry.equals("MOSTRAR")){
                for (int tam : numeros){
                    System.out.printf("%d\n", tam);
                } 
            } else if(jerry.equals("TAMANHO")){
                    System.out.printf("%d\n", numeros.size());    
            } else if(jerry.equals("ORDENAR")){
                Collections.sort(numeros);
            } else if(jerry.equals("BUSCAR")){
                qtd = sc.nextInt();
                int indice = numeros.indexOf(qtd);
                System.out.printf("%d\n", indice);    
            }
        }

        sc.close();
    }
}