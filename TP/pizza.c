#include <stdio.h>
#include <string.h>
#include "pizza.h"

void adicionarPizza(Pizza pizzas[], int qtd, Ingrediente ingredientes[], int qtdin){

    Pizza nova;
    nova.id = qtd + 1;
    nova.removido = 0;
    printf("Nome da pizza: ");
    fgets(nova.nome, sizeof(nova.nome), stdin);
    printf("Tamanho (P/M/G): ");
    scanf(" %c", &nova.tamanho);
    printf("Preço: ");
    scanf("%f", &nova.preco);

    printf("Quantos ingredientes serão necessários? ");
    scanf("%d", &nova.qtd_ingredientes);

    printf("Selecione os ingredientes digitando os IDs:\n ");

    for(int i = 0; i < qtdin; i++){
        if(ingredientes[i].removido != 1)
            printf("ID: %d | Nome: %s\n", ingredientes[i].id, ingredientes[i].nome);
    }

    int select;
    for(int i = 0; i < nova.qtd_ingredientes; i++){
        printf("Ingrediente %d", i + 1);
        scanf("%d", select);
        nova.ingredientes[i] = ingredientes[select];
    }

    pizzas[qtd] = nova;
    qtd++;
}

void listarPizzas(Pizza pizzas[], int qtd){
    if(qtd == 0){
        printf("Nenhuma pizza cadastrada!");
        return;
    }
    printf("Pizzas cadastradas:\n");
    for(int i = 0; i < qtd; i++){
        if(pizzas[i].removido != 1){
            printf("ID: %d | Nome: %s | Tamanho: %c | Preço: %.2f", pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco);
            printf("\nIngredientes:");
            for(int j = 0; j < pizzas[i].qtd_ingredientes; j++){
                printf("\n%d - %s", j + 1, pizzas[i].ingredientes[j]);
            }
            printf("-----------------------------");
        }
    }
}

void editarPizza(Pizza pizzas[], int qtd, Ingrediente ingredientes[], int qtdin){
    int id;
    printf("Insira o ID da pizza a ser editada: ");
    scanf("%d", &id);
    Pizza edit;
    int aux;
    for(int i = 0; i < qtd; i++){
        if(id == pizzas[i].id){
            edit = pizzas[i];
            aux = i;
        }
    }
    printf("\nNovo nome: ");
    fgets(edit.nome, sizeof(edit.nome), stdin);
    printf("Novo tamanho: ");
    scanf(" %c", &edit.tamanho);
    printf("Novo preço: ");
    scanf("%f", &edit.preco);
    printf("Quantos ingredientes serão necessários? ");
    scanf("%d", &edit.qtd_ingredientes);

    printf("Novos ingredientes: ");
    for(int i = 0; i < qtdin; i++){
        printf("\nID: %d | Nome: %s\n", ingredientes[i].id, ingredientes[i].nome);
    }

    int select;
    for(int i = 0; i < edit.qtd_ingredientes; i++){
        printf("Ingrediente %d\n", i + 1);
        scanf("%d", select);
        edit.ingredientes[i] = ingredientes[select];
    }
    pizzas[aux] = edit;
    printf("Pizza editada com sucesso!");
}

void removerPizza(Pizza pizzas[], int qtd){
    int id;
    printf("Insira o ID da pizza a ser removida: ");
    scanf("%d", &id);

    for(int i = 0; i < qtd; i++){
        if(id == pizzas[i].id){
            pizzas[i].removido = 1;
        }
    }
    printf("\nPizza removida com sucesso!");
}