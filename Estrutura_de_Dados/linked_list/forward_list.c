#include <stdio.h>
#include <stdlib.h>

#include "forward_list.h"


typedef struct Node
{
    int value;
    struct Node *next;
} Node;

struct ForwardList
{
    Node *head;
    int size;
};

Node *node_construct(int value, Node *next)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = next;
    return n;
}

void node_destroy(Node *n)
{
    free(n);
}

ForwardList *forward_list_construct()
{
    ForwardList *l = (ForwardList *)calloc(1, sizeof(ForwardList));

    l->head = NULL;
    l->size = 0;

    return l;
}

int forward_list_size(ForwardList *l)
{
    return l->size;
}

void forward_list_push_front(ForwardList *l, int data)
{
    l->head = node_construct(data, l->head);
    l->size++;
}

void forward_list_print(ForwardList *l)
{
    Node *n = l->head;

    printf("[");

    while (n != NULL)
    {
        printf("%d", n->value);
        n = n->next;

        if (n != NULL)
            printf(", ");
    }

    printf("]");
}

int forward_list_pop_front(ForwardList *l)
{
    if (l->head == NULL)
        exit(printf("Error: forward_list_pop_front(): list is empty."));

    Node *n = l->head;
    l->head = l->head->next;
    int data = n->value;
    node_destroy(n);
    l->size--;
    return data;
}

ForwardList* forward_list_clone(ForwardList *l)
{
    ForwardList* copy = forward_list_construct();

    Node *n = l->head;
    while (n != NULL)
    {
        forward_list_push_front(copy, n->value);
        n = n->next;
    }

    return copy;
}

void forward_list_destroy(ForwardList *l)
{
    Node *n = l->head;
    while (n != NULL)
    {
        Node *next = n->next;
        node_destroy(n);
        n = next;
    }

    free(l);
}