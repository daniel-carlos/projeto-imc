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

#pragma region STUCK
struct Nodo
{
    User dado;
    struct Nodo *prox;
};
typedef struct Nodo nodo;

void instancia(User *, char *, int, float);
void iniciar(nodo *);
void inserirInicio(nodo *, User *);
void excluirInicio(nodo *);
void inserirFinal(nodo *, User *);
void imprimir(nodo *);
void liberar(nodo *);

void instancia(User *User, char *name, int height, float weight)
{
    strcpy(User->name, name);
    User->height = height;
    User->weight = weight;
}

void iniciar(nodo *L) { L->prox = NULL; }

void inserirInicio(nodo *L, User *dado)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    strcpy(novo->dado.name, dado->name);
    novo->dado.height = dado->height;
    novo->dado.weight = dado->weight;
    novo->prox = L->prox;
    L->prox = novo;
}

void inserirmeio(nodo *L, User *dado, char *User)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    strcpy(novo->dado.name, dado->name);
    novo->dado.height = dado->height;
    novo->dado.weight = dado->weight;

    if (estaVazia(L))
        L->prox = novo;
    else
    {
        nodo *tmp = NULL;
        nodo *no = L->prox;
        while (no != NULL)
        {
            if (strcmp(no->dado.name, User) == 0)
            {
                tmp = no->prox;
                no->prox = novo;
                novo->prox = tmp;
            }

            no = no->prox;
        }
    }
}

void inserirFinal(nodo *L, User *dado)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    strcpy(novo->dado.name, dado->name);
    novo->dado.height = dado->height;
    novo->dado.weight = dado->weight;
    if (estaVazia(L))
    {
        L->prox = novo;
    }
    else
    {
        nodo *no = L->prox;
        while (no->prox != NULL)
            no = no->prox;
        novo->prox = no->prox;
        no->prox = novo;
    }
}

void imprimir(nodo *L)
{
    if (estaVazia(L))
    {
        printf("\nLista Vazia\n");
        return;
    }
    nodo *no = L->prox;
    while (no != NULL)
    {
        printf("%d \t%s \t%.2f\n", no->dado.height, no->dado.name, no->dado.weight);
        no = no->prox;
    }
    printf("\n\n");
}

void liberar(nodo *L)
{
    nodo *proximo;
    nodo *atual;
    atual = L;
    while (atual->prox != NULL)
    {
        proximo = atual->prox;
        atual->prox = NULL;
        free(atual);
        atual = proximo;
    }
}

int estaVazia(nodo *L)
{
    if (L->prox == NULL)
        return 1;
    else
        return 0;
}

void excluirMeio(nodo *L, char *User)
{
    nodo *noAnterior = L;
    nodo *noAtual = L->prox;
    while (noAtual != NULL)
    {
        if (strcmp(noAtual->dado.name, User) == 0)
        {
            noAnterior->prox = noAtual->prox;
            free(noAtual);
            return;
        }
        noAnterior = noAtual;
        noAtual = noAtual->prox;
    }
}

void excluirInicio(nodo *L)
{
    if (estaVazia(L))
    {
        printf("\nLista Vazia\n");
        return;
    }
    nodo *noPrimeiro = L->prox;
    L->prox = noPrimeiro->prox;
    free(noPrimeiro);
}
void excluirFinal(nodo *L)
{
    nodo *noAnterior = L;
    nodo *noAtual = L->prox;
    while (noAtual->prox != NULL)
    {
        noAnterior = noAtual;
        noAtual = noAtual->prox;
    }
    noAnterior->prox = NULL;
    free(noAtual);
}

#pragma endregion

int main()
{
    printf(COLOR_RESET "\n\n\n");

    struct User user01;
    strcpy(user01.name, "Daniel");
    user01.height = 170;
    user01.weight = 85;

    struct User user02;
    strcpy(user02.name, "Sansão");
    user02.height = 192;
    user02.weight = 126.2;

    ShowUser(user01);
    ShowUser(user02);

    printf(COLOR_RESET "\n\n");
}