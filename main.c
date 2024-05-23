#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/console_utils.c"

#pragma region GLOBAL_STRUCTS
struct User
{
    char name[20];
    float weight; // in Kg
    int height;   // in centimeters
};
typedef struct User User;

void instancia(User *user, char *nome, int height, float weight)
{
    strcpy(user->name, nome);
    user->height = height;
    user->weight = weight;
}

#pragma endregion

#pragma region GLOBAL_FUNCTIONS
float IMC(int height, float weight);
float IMC(int height, float weight)
{
    return weight / ((height / 100.0) * (height / 100.0));
}

char *classify(float imc)
{
    if (imc < 17)
        return COLOR_RED "MUITO ABAIXO DO PESO" COLOR_RESET;
    if (imc < 18.5)
        return COLOR_YELLOW "ABAIXO DO PESO" COLOR_RESET;
    if (imc < 25)
        return COLOR_GREEN "NORMAL" COLOR_RESET;
    if (imc < 30)
        return COLOR_YELLOW "ACIMA DO PESO" COLOR_RESET;
    if (imc < 35)
        return COLOR_YELLOW "OBESIDADE I" COLOR_RESET;
    if (imc < 40)
        return COLOR_RED "OBESIDADE II" COLOR_RESET;
    else
        return COLOR_RED "OBESIDADE III" COLOR_RESET;
}
void ShowUser(struct User user)
{
    float imc = IMC(user.height, user.weight);
    printf(COLOR_BRIGHT_CYAN TEXT_BOLD "%s" COLOR_RESET " %.2fm / %.1fKg \tIMC=[%.2f - %s]\n", user.name, (user.height / 100.0), user.weight, imc, classify(imc));
}
#pragma endregion

#pragma region STACK
struct Nodo
{
    User dado;
    struct Nodo *prox;
};
typedef struct Nodo nodo;

typedef struct Pilha
{
    nodo *topo;
} Pilha;

Pilha *criarPilha()
{
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    return novaPilha;
}

void empilhar(Pilha *pilha, User *dado)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    instancia(&(novo->dado), dado->name, dado->height, dado->weight);
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

User *desempilhar(Pilha *pilha)
{
    if (pilhaVazia(pilha))
    {
        return NULL;
    }

    nodo *topo = pilha->topo;
    User *dado = &(topo->dado);
    pilha->topo = topo->prox;
    free(topo);
    return dado;
}

void imprimirPilha(Pilha *pilha)
{
    if (pilhaVazia(pilha))
    {
        printf("\nPilha Vazia\n");
        return;
    }

    nodo *no = pilha->topo;
    while (no != NULL)
    {
        ShowUser(no->dado);
        no = no->prox;
    }
    printf("\n\n");
}

void liberarPilha(Pilha *pilha)
{
    nodo *atual, *anterior;
    atual = pilha->topo;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }
    free(pilha);
}

int pilhaVazia(Pilha *pilha)
{
    return pilha->topo == NULL;
}
#pragma endregion

int main()
{
    printf(COLOR_RESET "\n\n\n");

    struct User user01;
    strcpy(user01.name, "1 Daniel");
    user01.height = 170;
    user01.weight = 85;

    struct User user02;
    strcpy(user02.name, "2 Sansão");
    user02.height = 192;
    user02.weight = 126.2;

    struct User user03;
    strcpy(user03.name, "3 Larissa");
    user03.height = 162;
    user03.weight = 80;

    Pilha *pilha = criarPilha();
    empilhar(pilha, &user01);
    empilhar(pilha, &user02);
    empilhar(pilha, &user03);

    imprimirPilha(pilha);
    printf(COLOR_RESET "\n\n");
}