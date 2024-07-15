#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }

    Product p;
    p.id = productCount + 1;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p.name);
    
    printf("Digite a quantidade do produto: ");
    scanf("%d", &p.quantity);

    products[productCount++] = p;
    printf("Produto adicionado com sucesso!\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("Nenhum produto no estoque.\n");
        return;
    }

    printf("Produtos no estoque:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Nome: %s | Quantidade: %d\n", products[i].id, products[i].name, products[i].quantity);
    }
}

void updateProduct() {
    int id;
    printf("Digite o ID do produto que deseja atualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Digite a nova quantidade para %s: ", products[i].name);
            scanf("%d", &products[i].quantity);
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }

    printf("Produto com ID %d não encontrado.\n", id);
}

void removeProduct() {
    int id;
    printf("Digite o ID do produto que deseja remover: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }

    printf("Produto com ID %d não encontrado.\n", id);
}

int main() {
    int option;

    do {
        printf("\nSistema de Gerenciamento de Estoque\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Atualizar Produto\n");
        printf("4. Remover Produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                listProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (option != 5);

    return 0;
}
