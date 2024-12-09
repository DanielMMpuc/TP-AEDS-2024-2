#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_INGREDIENTES 50
#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
    int removido;
} Ingrediente;

void adicionarIngrediente(Ingrediente ingredientes[], int qtd);
void listarIngredientes(Ingrediente ingredientes[], int qtd);
void editarIngrediente(Ingrediente ingredientes[], int qtd);
void removerIngrediente(Ingrediente ingredientes[], int qtd);

#endif
