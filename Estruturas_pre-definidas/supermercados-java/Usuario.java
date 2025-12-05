import java.util.Scanner;
import java.util.ArrayList;

public class Usuario {
    private String nome;
    private String cpf;

    public Usuario(){}

    public Usuario(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
    }

    public String getCpf(){
        return this.cpf;
    }

    public String getNomeCliente(){
        return this.nome;
    }
}