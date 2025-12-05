import java.util.Scanner;
import java.util.ArrayList;

public class Produto {
    private String nome;
    private float preco;
    private int qtd_estoque;

    public Produto(String nome, float preco){
        this.nome = nome;
        this.preco = preco;
        this.qtd_estoque = 0;
    }

    public Produto(){
    }

    public void incrementaQtd(int qtd) {
        this.qtd_estoque += qtd;
    }

    public String getNomeProduto(){
        return this.nome;
    }

    public float getPreco(){
        return this.preco;
    }

    public int getQtdEstoque(){
        return this.qtd_estoque;
    }
}