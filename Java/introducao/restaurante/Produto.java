
public class Produto {
    private String nome;
    private int estoque;
    private int num_vendas;
    private float custo;
    private float preco;

    public Produto(String nome, int estoque, int num_vendas, float custo, float preco){
        this.nome = nome;
        this.estoque = estoque;
        this.num_vendas = num_vendas;
        this.custo = custo;
        this.preco = preco;
    }

    public String getNome(){
        return this.nome;
    }

    public int qtdVendas(){
        return this.num_vendas;
    }

    
    public float valor_vendas(){
        return this.num_vendas * this.preco;
    }

    public float custoProducao(){
        return this.custo * this.estoque;
    }

    public float lucro(){
        return (this.valor_vendas() - this.custoProducao());
    }
}