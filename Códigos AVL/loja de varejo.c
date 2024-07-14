#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "avl.h"

typedef struct produto_do_estoque{

int product_id;
char name[100];
char category[61];
int quantity;
double price;


}product;

product* criar_produto(int id, char *nome, char *categoria, double preco, int quantidade){
    product* novo = malloc(sizeof(product));
    novo->product_id = id;
    strcpy(novo->name, nome);
    strcpy(novo->category, categoria);
    novo->price = preco;
    novo->quantity = quantidade;

    return novo;
}

void imprimir_produto(product *pd){
    if (pd){
        printf("ID: %d\nCATEGORIA: %s\nNOME: %s\nPREÇO: %.3lf\nQUANTIDADE: %d \n", pd->product_id, pd->category, pd->name, pd->price, pd->quantity);
    }
}

int comparar_produto(product* pd1, product* pd2){
    return (pd1->product_id - pd2->product_id);
}


void insert(t_avl *estoque ,product *produto){ 

    int product_id, quantidade;
    char nome[60];
    char categoria[60];
    double preco;
    scanf("ID: %d", &product_id);
    scanf("NOME: %s", nome);
    scanf("CATEGORIA: %s", categoria);
    scanf("PREÇO: %lf", &preco);
    scanf("QUANTIDADE: %d", &quantidade);
    produto = criar_produto(product_id, nome, categoria,preco,quantidade);
    inserir_avl(estoque, produto);
    

};


product* search(t_avl *estoque,int id){

};

update_quantity(int id, int delta){


};

void delete(int id){

};


int main(int argc, char const *argv[])
{    
t_avl* estoque = criar_avl(imprimir_produto,comparar_produto);




}
