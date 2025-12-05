import java.util.Scanner;

public class List {
    
    private class Node {

        int value;
        Node next;

        Node (int value, Node next) {

            this.value = value;
            this.next = next;
        }
    }

    private Node head;
    private int size;

    public List () {

        this.head = null;
        this.size = 0;
    }

    public int size () {

        return this.size;
    }

    public void push_front (int value) {

        head = new Node(value, head);
        this.size++;
    }

    public void print () {

        Node printar = head;

        while (printar != null) {

            System.out.println(printar.value);
            printar = printar.next;
        }
    }

    public void pop_front () {

        if (this.head != null) {

            this.head = this.head.next;
            this.size--;
        }

        else {

            return;
        }
    }

    public List clone () {

        List novaLista = new List();

        if (this.head == null) {

            return novaLista;
        }

        Node n = this.head;

        while (n != null) {

            novaLista.push_front(n.value);
            n = n.next;
        }

        return novaLista;
    }
}
