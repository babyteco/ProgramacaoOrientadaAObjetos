import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;

public class Supermercado {
    private ArrayList<Compra> compras;
    private ArrayList<Produto> produtos;
    private ArrayList<Usuario> clientes;

    public Supermercado(){
        this.compras = new ArrayList<>();
        this.produtos = new ArrayList<>();
        this.clientes = new ArrayList<>();
    }

    public void registrarProduto(String nome, float preco){
        Produto p = new Produto(nome, preco);
        this.produtos.add(p);
    }

    public void registrarCliente(String nome, String cpf){
        Usuario u = new Usuario(nome, cpf);
        this.clientes.add(u);
    }

    public void incrementaProduto(String nome, int qtd) {
        for (Produto p : this.produtos) {
            if (p.getNomeProduto().equals(nome)) {
                p.incrementaQtd(qtd);
                return;
            }
        }
    }

    public void registraCompra(String cpf, Scanner sc){     
        String sndComand = sc.next();
        ArrayList<Integer> qtds = new ArrayList<>();
        ArrayList<Produto> prods = new ArrayList<>();
        
        float valor = 0;
        while (!sndComand.equals("FINALIZAR_COMPRA")) {
            if (sndComand.equals("ADD_ITEM")) {
                String nome = sc.next();
                int qtd = sc.nextInt();           
                
                for (Produto p : this.produtos) {
                    if (p.getNomeProduto().equals(nome)) {
                        prods.add(p);
                        qtds.add(qtd);
                        this.incrementaProduto(nome, (-1)*qtd);
                        valor += p.getPreco() * qtd;
                        break;
                    }
                }
            }    
            
            sndComand = sc.next();
        }
        System.out.printf("%.2f\n", valor);
        
        Usuario user = null;
        for (Usuario u : this.clientes) {
            if (u.getCpf().equals(cpf)) {
                user = u;
                break;
            }
        }

        this.compras.add(new Compra(user, prods, qtds));
    }

    public void revenue(){
        float valor = 0;
        for(Compra c : this.compras){
            int index = 0;
            for(Produto p : c.getProdutos()){
                ArrayList<Integer> qtds = c.getQuantidades();

                valor += p.getPreco() * qtds.get(index); 
                index++;
            }
        }

        System.out.printf("%.2f\n", valor);
    }

    public void maisVendido(){

        HashMap<String, Integer> hash = new HashMap<>();

        for(Produto prod : this.produtos){
            hash.put(prod.getNomeProduto(), 0);
        }
        
        for(Compra compra : this.compras){
            ArrayList<Produto> listProdutos = compra.getProdutos();
            ArrayList<Integer> listQuantidades = compra.getQuantidades();

            int i = 0;
            for(Produto prod : listProdutos){
                String nomeProduto = prod.getNomeProduto();
                hash.put(nomeProduto, hash.get(nomeProduto) + listQuantidades.get(i));
                i++;
            }
        }

        Produto most = this.produtos.get(0);
        for(Produto product : this.produtos){
            if (hash.get(product.getNomeProduto()) > hash.get(most.getNomeProduto())) {
                most = product;
            }
        }

        System.out.printf("%s\n", most.getNomeProduto());
    }

    public void melhorCliente(){
        HashMap<String, Integer> hash = new HashMap<>();

        for(Usuario cliente : this.clientes){
            hash.put(cliente.getCpf(), 0);
        }

        for(Compra compra : this.compras){
            Usuario usuario = compra.getUsuario();
            String cpf = usuario.getCpf();

            hash.put(cpf, hash.get(cpf) + 1);
        }

        Usuario most = this.clientes.get(0);
        for(Usuario user : this.clientes){
            if (hash.get(user.getCpf()) > hash.get(most.getCpf())) {
                most = user;
            }
        }

        System.out.printf("%s\n", most.getNomeCliente());
    }

    public void emFalta(){
        for(Produto prod : this.produtos){
            if (prod.getQtdEstoque() < 5) {
                System.out.printf("%s\n", prod.getNomeProduto());
            }
        }
    }
}