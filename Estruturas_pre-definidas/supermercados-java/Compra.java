import java.util.Scanner;
import java.util.ArrayList;

public class Compra {
    private ArrayList<Produto> produtos;
    private Usuario user;
    private ArrayList<Integer> quantidades;

    public Compra(Usuario user, ArrayList<Produto> prod, ArrayList<Integer> qtd){
        this.produtos = prod;
        this.quantidades = qtd;
        this.user = user;
    }

    public ArrayList<Produto> getProdutos() {
        return this.produtos;
    }

    public ArrayList<Integer> getQuantidades() {
        return this.quantidades;
    }   

    public Usuario getUsuario(){
        return this.user;
    }
}