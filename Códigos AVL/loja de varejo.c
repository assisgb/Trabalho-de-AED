#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "avl.h"

typedef struct produto_do_estoque {
    int product_id;
    char name[100];
    char category[61];
    int quantity;
    double price;
} product;

product* criar_produto(int id, char *nome, char *categoria, double preco, int quantidade) {
    product* novo = (product*)malloc(sizeof(product));
    novo->product_id = id;
    strcpy(novo->name, nome);
    strcpy(novo->category, categoria);
    novo->price = preco;
    novo->quantity = quantidade;
    return novo;
}

void imprimir_produto(product *pd) {
    if (pd) {
        printf("ID: %d\nCATEGORIA: %s\nNOME: %s\nPREÇO: %.2lf\nQUANTIDADE: %d\n", pd->product_id, pd->category, pd->name, pd->price, pd->quantity);
    }
}

int comparar_produto(product* pd1, product* pd2) {
    return pd1->product_id - pd2->product_id;
}

void insert(t_avl *estoque) {
    int product_id, quantidade;
    char nome[100];
    char categoria[61];
    double preco;
    printf("ID: ");
    scanf("%d", &product_id);
    printf("NOME: ");
    scanf("%s", nome);
    printf("CATEGORIA: ");
    scanf("%s", categoria);
    printf("PREÇO: ");
    scanf("%lf", &preco);
    printf("QUANTIDADE: ");
    scanf("%d", &quantidade);
    product *produto = criar_produto(product_id, nome, categoria, preco, quantidade);
    inserir_avl(estoque, produto);
}

product* search(t_avl *estoque, int id) {
    product temp;
    temp.product_id = id;
    return (product*) buscar_avl(estoque, &temp);
}

void update_quantity(t_avl *estoque, int id, int delta) {
    product *prod = search(estoque, id);
    if (prod) {
        prod->quantity += delta;
        if (prod->quantity < 0) prod->quantity = 0;
        atualizar_avl(estoque, prod);  // Função hipotética para atualizar o nó na AVL
    } else {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

void delete(t_avl *estoque, int id) {
    product temp;
    temp.product_id = id;
    remover_avl(estoque, &temp);
}

int main(int argc, char const *argv[]) {
    t_avl* estoque = criar_avl(imprimir_produto, comparar_produto);

    int opcao, id, delta;
    while (1) {
        printf("1. Inserir produto\n");
        printf("2. Buscar produto\n");
        printf("3. Atualizar quantidade\n");
        printf("4. Deletar produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                insert(estoque);
                break;
            case 2:
                printf("ID do produto a buscar: ");
                scanf("%d", &id);
                product* prod = search(estoque, id);
                if (prod) {
                    imprimir_produto(prod);
                } else {
                    printf("Produto não encontrado.\n");
                }
                break;
            case 3:
                printf("ID do produto a atualizar: ");
                scanf("%d", &id);
                printf("Delta de quantidade: ");
                scanf("%d", &delta);
                update_quantity(estoque, id, delta);
                break;
            case 4:
                printf("ID do produto a deletar: ");
                scanf("%d", &id);
                delete(estoque, id);
                break;
            case 5:
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
