#include <stdio.h>
#include <string.h>
#include "ingrediente.h"

void adicionarIngrediente(Ingrediente ingredientes[], int qtd){

    Ingrediente novo;
    novo.id = qtd + 1;
    novo.removido = 0;
    printf("Nome do ingrediente: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    printf("Preço: ");
    scanf("%f", &novo.preco);

    ingredientes[qtd] = novo;
    qtd++;
}

void listarIngredientes(Ingrediente ingredientes[], int qtd){
    if(qtd == 0){
        printf("Nenhum ingrediente cadastrado!");
        return;
    }

    printf("Ingredientes cadastrados:");
    for(int i = 0; i < qtd; i++){
        if(ingredientes[i].removido != 1){
            printf("\nID: %d | Nome: %s | Preço: %.2f", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
            printf("-----------------------------");
        }
    }
}

void editarIngrediente(Ingrediente ingredientes[], int qtd){
    int id;
    printf("Insira o ID da pizza a ser editada: ");
    scanf("%d", &id);
    Ingrediente edit;
    int aux;
    for(int i = 0; i < qtd; i++){
        if(id == ingredientes[i].id){
            edit = ingredientes[i];
            aux = i;
        }
    }
    printf("\nNovo nome: ");
    fgets(edit.nome, sizeof(edit.nome), stdin);
    printf("Novo preço: ");
    scanf("%f", &edit.preco);
    ingredientes[aux] = edit;
    printf("\nIngrediente editado com sucesso!");
}

void removerIngrediente(Ingrediente ingredientes[], int qtd){
    int id;
    printf("Insira o ID do ingrediente a ser removido: ");
    scanf("%d", &id);

    for(int i = 0; i < qtd; i++){
        if(id == ingredientes[i].id){
            ingredientes[i].removido = 1;
        }
    }
    printf("\nIngrediente removido com sucesso!");
}