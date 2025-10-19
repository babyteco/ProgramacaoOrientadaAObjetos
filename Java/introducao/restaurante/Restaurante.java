
public class Restaurante {
    private String nome;
    private Produto prod1;
    private Produto prod2;
    private Produto prod3;

    public Restaurante(String nome, Produto prod1, Produto prod2, Produto prod3){
        this.nome = nome;
        this.prod1 = prod1;
        this.prod2 = prod2;
        this.prod3 = prod3;
    }

    public String get_Nome(){
        return this.nome;
    }

    public float valor_vendas(){
        return this.prod1.valor_vendas() + this.prod2.valor_vendas() + this.prod3.valor_vendas();
    }

    public float custo(){
        return this.prod1.custoProducao() + this.prod2.custoProducao() + this.prod3.custoProducao();
    }

    public float lucro(){
        return this.prod1.lucro() + this.prod2.lucro() + this.prod3.lucro();
    }

    public Produto mais_vendido(){
        int p1, p2, p3;
        p1 = this.prod1.qtdVendas();
        p2 = this.prod2.qtdVendas();
        p3 = this.prod3.qtdVendas();

        if(p1 > p2){
            if(p1 > p3){
                return this.prod1;
            } else return this.prod3;
        } else if(p2 > p3){
            return this.prod2;
        } else return this.prod3;
    }
}
