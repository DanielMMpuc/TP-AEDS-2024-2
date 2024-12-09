#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

#define MAX_INGREDIENTES 10
#define MAX_PIZZAS 50
#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    char tamanho;
    float preco;
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int qtd_ingredientes;
    int removido;
} Pizza;

void adicionarPizza(Pizza pizzas[], int qtd, Ingrediente ingredientes[], int qtdin);
void listarPizzas(Pizza pizzas[], int qtd);
void editarPizza(Pizza pizzas[], int qtd, Ingrediente ingredientes[], int qtdin);
void removerPizza(Pizza pizzas[], int qtd);

#endif
