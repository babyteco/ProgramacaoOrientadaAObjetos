import java.util.Scanner;

public class Main {

    public static void main (String[] args) {

        List lista = new List();

        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        for (int i = 0; i < num; i++) {

            int value = sc.nextInt();

            lista.push_front(value);
        }

        lista.print();

        sc.close();
    }
}