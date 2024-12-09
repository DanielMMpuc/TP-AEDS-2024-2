#include <stdio.h>
#include "pizza.h"
#include "ingrediente.h"

int main() {
    Pizza pizzas[MAX_PIZZAS];
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int qtd_pizzas = 0, qtd_ingredientes = 0;
    int opcao;

    do {
        printf("\n--- Sistema de Gerenciamento de Pizzaria ---\n");
        printf("1. Gerenciar Pizzas\n");
        printf("2. Gerenciar Ingredientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("1. Adicionar Pizza\n2. Listar Pizzas\n3. Editar Pizza\n4. Remover Pizza\n");
                scanf("%d", &opcao);
                if (opcao == 1) adicionarPizza(pizzas, qtd_pizzas, ingredientes, qtd_ingredientes);
                else if (opcao == 2) listarPizzas(pizzas, qtd_pizzas);
                else if (opcao == 3) editarPizza(pizzas, qtd_pizzas, ingredientes, qtd_ingredientes);
                else if (opcao == 4) removerPizza(pizzas, qtd_pizzas);
                break;

            case 2:
                printf("1. Adicionar Ingrediente\n2. Listar Ingredientes\n3. Editar Ingrediente\n4. Remover Ingrediente\n");
                scanf("%d", &opcao);
                if (opcao == 1) adicionarIngrediente(ingredientes, qtd_ingredientes);
                else if (opcao == 2) listarIngredientes(ingredientes, qtd_ingredientes);
                else if (opcao == 3) editarIngrediente(ingredientes, qtd_ingredientes);
                else if (opcao == 4) removerIngrediente(ingredientes, qtd_ingredientes);
                break;

            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
    return 0;
}
