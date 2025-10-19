//para compilar:
//javac Programa.java
//java Programa

import java.util.Scanner;

public class produto {
    static class Produto {
        public String nome;
        public int estoque;
        public double valor;
        public double desconto;
        public int total_vendas;

        public Produto(String nome, int estoque, double valor, double desconto){
            this.nome = nome;
            this.estoque = estoque;
            if(valor < 0) {
                System.out.println("VALOR INVALIDO");
            } else {
                this.valor = valor;
            }
            this.desconto = desconto;
            this.total_vendas = 0;
        }

        public void compra(int qtd){
            if(qtd < 0) {
                System.out.println("VALOR INVALIDO");
            } else {
                this.estoque += qtd;
            }
        }

        public void venda(int qtd){
            if ((this.estoque - qtd < 0) || (qtd < 0)) {
                System.out.println("VALOR INVALIDO");
                return;
            } else {
                this.estoque -= qtd;
                this.total_vendas += qtd;
            }
        }

        public double preco(){
            if((desconto >= 0) && (desconto < 1)){
                return this.valor - (this.desconto * this.valor);
            } else {
                System.out.println("VALOR INVALIDO");
                return -1;
            }
        }
    
        public double valor_vendas(){
            return this.total_vendas * this.preco();
        }
    }

    public static void main(String[] args){     
        Scanner sc = new Scanner(System.in);
        String nome = sc.nextLine();
        int estoque = sc.nextInt();
        double valor = sc.nextDouble();
        double desconto = sc.nextDouble();
        
        Produto product = new Produto(nome, estoque, valor, desconto);
        
        int n = sc.nextInt();
        for(int i = 0; i < n; i++){
            String operacao = sc.next();
            int qtd = sc.nextInt();
            if ("C".equals(operacao)) {
                product.compra(qtd);
            } else if ("V".equals(operacao)) {
                product.venda(qtd);
            }
        }

        System.out.printf("%s\n", product.nome);
        System.out.printf("%d\n", product.estoque);
        System.out.printf("%.2f\n", product.valor);
        System.out.printf("%.2f\n", product.desconto);
        System.out.printf("%.2f\n", product.preco());
        System.out.printf("%.2f\n", product.valor_vendas());

        sc.close();;
    }
}

/*
agua de coco
10
5
0.1
5
V 5
V 3
V 2
C 1
C 10

Descrição:
Crie uma classe Produto no arquivo Produto.java contendo os seguintes atributos privados e métodos públicos:

As seguintes regras de negócio devem ser seguidas:
- estoque deve ser maior ou igual a zero.
- valor deve ser maior que zero.
- desconto deve estar ser maior ou igual a zero e menor que 1.
- argumentos dos métodos compra e venda devem ser maiores que zero.

Se uma das regras for invalidada, mostre na tela a mensagem VALOR INVALIDO e não atualize o valor do atributo. Os testes não precisam ser realizados no construtor.

Crie uma classe Programa no arquivo Programa.java contendo o método main.
Neste método, leia os dados do produto e use estes dados para criar um objeto do tipo Produto.
Em seguida, leia um número n representando o número de interações com o sistema. Cada interação é dada em uma linha e consiste em uma letra seguida de um número. A letra "C" indica uma compra e a letra "V" indica um venda. A cada interação, invoque os métodos associados de produto.
Ao final, mostre na tela os dados dos produtos (nome, estoque, valor, desconto e preço) e o valor total em vendas. Todos os doubles devem ser exibidos com 2 casas depois da vírgula.
*/