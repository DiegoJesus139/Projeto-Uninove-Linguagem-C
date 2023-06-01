#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int *numProdutos) {
    if (*numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novoProduto;

    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto.nome);

    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    produtos[*numProdutos] = novoProduto;
    (*numProdutos)++;

    printf("Produto cadastrado com sucesso.\n");
}

void consultarProduto(Produto produtos[], int numProdutos) {
    char nome[50];
    printf("Digite o nome do produto que deseja consultar: ");
    scanf("%s", nome);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            printf("Produto: %s\nPreco: R$%.2f\n", produtos[i].nome, produtos[i].preco);
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

void excluirProduto(Produto produtos[], int *numProdutos) {
    char nome[50];
    printf("Digite o nome do produto que deseja excluir: ");
    scanf("%s", nome);

    for (int i = 0; i < *numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            for (int j = i; j < *numProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*numProdutos)--;
            printf("Produto excluido com sucesso.\n");
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    int opcao;

    do {
        printf("\nLoja de Auto Pecas\n");
        printf("1. Cadastrar produto\n");
        printf("2. Consultar produto\n");
        printf("3. Excluir produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &numProdutos);
                break;
            case 2:
                consultarProduto(produtos, numProdutos);
                break;
            case 3:
                excluirProduto(produtos, &numProdutos);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}