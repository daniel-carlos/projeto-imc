#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Node *top;

// Função para criar um novo nó
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Função para verificar se a pilha está vazia
int isEmpty()
{
    return top == NULL;
}

// Função para empilhar um elemento
void push(int data)
{
    Node *new_node = newNode(data);
    new_node->next = top;
    top = new_node;
}

// Função para desempilhar um elemento
int pop()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }

    Node *temp = top;
    top = top->next;
    int popped_data = temp->data;
    free(temp);
    return popped_data;
}

// Função para obter o topo da pilha
int topElement()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Função para imprimir a pilha
void printStack()
{
    Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}