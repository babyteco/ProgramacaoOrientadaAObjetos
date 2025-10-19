
import java.util.Scanner;

public class Rede {
    private String nome;
    Restaurante rest1;
    Restaurante rest2;

    public Rede(String nome, Restaurante r1, Restaurante r2){
        this.nome = nome;
        this.rest1 = r1;
        this.rest2 = r2;
    }

    public float valor_vendas(){
        return this.rest1.valor_vendas() + this.rest2.valor_vendas();
    }

    public float custo(){
        return this.rest1.custo() + this.rest2.custo();
    }

    public float lucro(){
        return this.rest1.lucro() + this.rest2.lucro();
    }

    public Restaurante mais_lucrativo(){
        float r1, r2;
        r1 = this.rest1.lucro();
        r2 = this.rest2.lucro();

        if(r1 > r2){
            return this.rest1;
        } 
        return this.rest2;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
    
        String nomeRede = sc.next();
        
        //restaurante 1
        String nomeRestaurante1 = sc.next();
    
        //produtos do restaurante 1
        String nomeProd1 = sc.next();
        int estoque1 = sc.nextInt();
        int num_vendas1 = sc.nextInt();
        float custo1 = sc.nextFloat();
        float preco1 = sc.nextFloat();
    
        Produto prod1 = new Produto(nomeProd1, estoque1, num_vendas1, custo1, preco1);
        
        nomeProd1 = sc.next();
        estoque1 = sc.nextInt();
        num_vendas1 = sc.nextInt();
        custo1 = sc.nextFloat();
        preco1 = sc.nextFloat();
        
        Produto prod2 = new Produto(nomeProd1, estoque1, num_vendas1, custo1, preco1);
        
        nomeProd1 = sc.next();
        estoque1 = sc.nextInt();
        num_vendas1 = sc.nextInt();
        custo1 = sc.nextFloat();
        preco1 = sc.nextFloat();
        
        Produto prod3 = new Produto(nomeProd1, estoque1, num_vendas1, custo1, preco1);
    
        Restaurante rest1 = new Restaurante(nomeRestaurante1, prod1, prod2, prod3);
    
    
        //restaurante 2
        String nomeRestaurante2 = sc.next();
    
        //produtos do restaurante 1
        nomeProd1 = sc.next();
        estoque1 = sc.nextInt();
        num_vendas1 = sc.nextInt();
        custo1 = sc.nextFloat();
        preco1 = sc.nextFloat();
    
        Produto prod4 = new Produto(nomeProd1, estoque1, num_vendas1, custo1, preco1);
        
        nomeProd1 = sc.next();
        estoque1 = sc.nextInt();
        num_vendas1 = sc.nextInt();
        custo1 = sc.nextFloat();
        preco1 = sc.nextFloat();
        
        Produto prod5 = new Produto(nomeProd1, estoque1, num_vendas1, custo1, preco1);
        
        nomeProd1 = sc.next();
        estoque1 = sc.nextInt();
        num_vendas1 = sc.nextInt();
        custo1 = sc.nextFloat();
        preco1 = sc.nextFloat();
        
        Produto prod6 = new Produto(nomeProd1, estoque1, num_vendas1, custo1, preco1);
    
        Restaurante rest2 = new Restaurante(nomeRestaurante2, prod4, prod5, prod6);
    
    
        Rede rede = new Rede(nomeRede, rest1, rest2);
    
    
        Produto prodVendido1 = rest1.mais_vendido();
        Produto prodVendido2 = rest2.mais_vendido();
    
        int a = prodVendido1.qtdVendas();
        int b = prodVendido2.qtdVendas();
    
        if (a > b) {
            System.out.printf("%s %d\n", prodVendido1.getNome(), a);
        } else {
            System.out.printf("%s %d\n", prodVendido2.getNome(), b);
        }
    
        Restaurante maislucrativo = rede.mais_lucrativo();
    
        System.out.printf("%s %.2f\n", maislucrativo.get_Nome(), maislucrativo.lucro());
        
        System.out.printf("%.2f\n", rede.valor_vendas());
        System.out.printf("%.2f\n", rede.custo());
        System.out.printf("%.2f\n", rede.lucro());
        
    
        sc.close();
    }
}
