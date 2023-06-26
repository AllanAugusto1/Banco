#include <stdio.h>
#include <stdlib.h>

struct Fila{
    int num;
    struct Fila *prox;
};
typedef struct Fila node;

int vazia(node* FILA){
    if(FILA->prox == NULL)
        return 1;
    else 
        return 0;
}

node* aloca(){
    node* novo = (node*) malloc(sizeof(node));
    if(!novo){
        printf("Espaco insuficiente\n");
        exit(1);
    }
    else{
        printf("Insira o valor a ser inserido: ");
        scanf("%d", &novo->num);
        novo->prox = NULL;
    }
}

void adicionar(node* FILA){
    printf("Adicionando na fila\n");
    node* novo = aloca();
    if(vazia(FILA)){
        FILA->prox = novo;
    }
    else{
        node* tmp = FILA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}

void remover(node* FILA){
    if(vazia(FILA)){
        printf("Lista Vazia");
    }
    else{
        node* tmp = FILA->prox;
        node* a = tmp->prox;
        FILA->prox = NULL;
        printf("Valor sendo removido: %d\n", tmp->num);
        free(tmp);
        FILA->prox = a;
    }
    printf("VALOR REMOVIDO\n");
}

void imprimir(node *FILA){
    if(vazia(FILA)){
        printf("Lista Vazia\n");
    }
    else{
        node* tmp = FILA->prox;
        while(tmp != NULL){
            printf("%d, ", tmp->num);
            tmp = tmp->prox;
        }
        printf("\n\n");
    }
}

void liberalista(node* FILA){
    if(vazia(FILA)){
        printf("Lista Vazia\n");
    }
    else{
        node* tmp = FILA->prox;
        while(tmp != NULL){
            node* a = tmp->prox;
            free(tmp);
            tmp = a;
        }
        FILA->prox = NULL;
        printf("LISTA VAZIA\n");
    }
}

int main(){
    node* FILA = (node*) malloc(sizeof(node));
    FILA->prox = NULL;
    int opt;
    do{
        printf("1- Exibir fila\n");
        printf("2- Inserir\n");
        printf("3- Remover\n");
        printf("4- Liberar fila\n");
        printf("0- Para sair\n");
        scanf("%d", &opt);
        switch(opt){

            case 1:
            imprimir(FILA);
            printf("\n\n");
            break;

            case 2:
            adicionar(FILA);
            printf("\n\n");
            break;

            case 3:
            remover(FILA);
            printf("\n\n");
            break;

            case 4:
            liberalista(FILA);
            printf("\n\n");
            break;
            default:
            printf("OPCAO INVALIDA\n");
        }
    }
    while(opt != 0);


    return 0;
}
