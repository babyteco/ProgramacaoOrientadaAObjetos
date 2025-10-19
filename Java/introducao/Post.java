import java.util.Scanner;

public class Post {
    String nome;
    String conteudo;
    int likes;
    int dislikes;

    Post(String nome, String titulo){
        this.dislikes = 0;
        this.likes = 0;
        this.nome = nome;
        this.conteudo = titulo;
    }

    void Like(){
        this.likes++;
    }

    void Dislike(){
        this.dislikes++;
    }

    String get_autor(){ return this.nome;}

    String get_conteudo(){ return this.conteudo;}

    int n_likes(){ return this.likes;}

    int n_dislikes(){ return this.dislikes;}

    int sentimento(){
        if (this.likes > this.dislikes) {
            return 1;
        }
        return 0;
    }

    static public void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String nome = sc.next();
        String conteudo = sc.next();

        Post post = new Post(nome, conteudo);

        int n = sc.nextInt();
        for(int i = 0; i < n; i++){
            int operacao = sc.nextInt();

            if (operacao == 1) {
                post.Like();
            } else {
                post.Dislike();
            }
        }

        System.out.printf("%s\n%s\n", post.get_conteudo(), post.get_autor());
        System.out.printf("%d\n%d\n%d\n", post.n_likes(), post.n_dislikes(), post.sentimento());

        sc.close();
    }
}