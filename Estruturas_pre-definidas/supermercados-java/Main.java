import java.util.Scanner;

public class Main {

    public static void main (String[] args) {
        Supermercado jonson = new Supermercado();


        Scanner sc = new Scanner(System.in);

        String oprecao = sc.next();
        while (!oprecao.equals("ENCERRAR")) {
            if (oprecao.equals("REGISTRAR_PRODUTO")) {
                String nome = sc.next();
                float preco = sc.nextFloat();
                jonson.registrarProduto(nome, preco);
            } else if (oprecao.equals("REGISTRAR_CLIENTE")) {
                String nome = sc.next();
                String cpf = sc.next();
                jonson.registrarCliente(nome, cpf);
            } else if (oprecao.equals("ADQUIRIR_PRODUTO")) {
                String nome = sc.next();
                int qtd = sc.nextInt();
                jonson.incrementaProduto(nome, qtd);
            } else if (oprecao.equals("INICIAR_COMPRA")) {
                String cpf = sc.next();
                jonson.registraCompra(cpf, sc);
            } else if (oprecao.equals("REVENUE")) {
                jonson.revenue();
            } else if (oprecao.equals("MAIS_VENDIDO")) {
                jonson.maisVendido();
            } else if (oprecao.equals("MELHOR_CLIENTE")) {
                jonson.melhorCliente();
            } else if (oprecao.equals("EM_FALTA")) {
                jonson.emFalta();
            }

            oprecao = sc.next();
        }


        sc.close();
    }
}