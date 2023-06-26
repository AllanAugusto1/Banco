#include<stdio.h>
#include<stdlib.h>

struct Banco {
	int numero_conta;
	char nome_cliente[30];
	float saldo;
	struct Banco *prox;
};
typedef struct Banco node;

void adicionar_inicio(node* CABECA) {
	
    node* novo = (node *) malloc(sizeof(node));
    if(!novo) {
       printf("Espaco insuficiente!\n");
       exit(1);
    }else{
       	if(CABECA->prox == NULL) {
           	CABECA->prox = novo;
           	novo->prox = NULL;
			printf("Informe numero da conta: \n");
       		scanf("%d", &novo->numero_conta);
       		printf("Informe nome do cliente: \n");
       		scanf("%s", &novo->nome_cliente);
       		printf("Informe saldo do cliente: \n");
       		scanf("%f", &novo->saldo);
}
       	else{
           	node* aux = CABECA->prox;
           	CABECA->prox = novo;
           	novo->prox = aux;
           	printf("Inserindo no! \n\n");
			printf("Informe numero da conta: \n");
       		scanf("%d", &novo->numero_conta);
       		node* auxb = aux;
       		int verdade = 0;
       		while (auxb != NULL) {
       			if(novo->numero_conta == auxb->numero_conta) {
       		printf("JA EXISTE ESSE NUMERO DE CONTA!\n");
           	novo = NULL;
           	free(novo);
           	verdade = 1;
           	CABECA->prox = aux;
           	break;
} 
			else {
			auxb = auxb->prox;
				   }
			   }
       		if (verdade == 1) {
} 
			   	else {
			printf("Informe nome do cliente: ");
       		scanf("%s", &novo->nome_cliente);
       		printf("Informe saldo do cliente: ");
       		scanf("%f", &novo->saldo);
			   }
       	}
	}
}


void adicionar_fim(node* CABECA) {
	
	node* novo = (node *) malloc(sizeof(node));
    if(!novo){
        printf("Espaco insuficiente!\n");
        exit(1);
    }else{
    	if(CABECA->prox == NULL) {
        	CABECA->prox = novo;
        	novo->prox = NULL;
        	printf("\n\n");
        	printf("Inserindo no! \n\n");
			printf("Informe numero da conta: ");
       		scanf("%d", &novo->numero_conta);
       		printf("Informe nome do cliente: ");
       		scanf("%s", &novo->nome_cliente);
       		printf("Informe saldo do cliente: ");
       		scanf("%f", &novo->saldo);
		} else {
			node* aux = CABECA->prox;
			
			while(aux->prox != NULL) {
				aux = aux->prox;
			}
			
			aux->prox = novo;
			novo->prox = NULL;
			
		printf("\n\n");
		printf("Inserindo no! \n\n");
		printf("Informe numero da conta: \n");
       	scanf("%d", &novo->numero_conta);
       	node* auxb = CABECA->prox;
       	int verdade = 0;
       	while (auxb->prox != NULL) {
       	if(novo->numero_conta == auxb->numero_conta) {
       		printf("JA EXISTE ESSE NUMERO DE CONTA!\n");
           	novo = NULL;
           	free(novo);
           	verdade = 1;
           	aux->prox = NULL;
           	break;
		}      else {
			  auxb = auxb->prox;
	}
}
			if (verdade == 1) {
	}       
	        else {
			   	
		    printf("Informe nome do cliente: \n");
       		scanf("%s", &novo->nome_cliente);
       		printf("Informe saldo do cliente: \n");
       		scanf("%f", &novo->saldo);
			   }
		}
	}
}

void imprimir(node *CABECA) {
    if(CABECA->prox == NULL){
        printf("Lista vazia!!\n");
    }
    else{
        node* aux = CABECA->prox;
        while(aux != NULL){
        	printf("Conta do cliente: %d\n", aux->numero_conta);
        	printf("Nome do cliente: %s\n", aux->nome_cliente);
        	printf("Saldo do cliente: %.2f\n", aux->saldo);
            printf("Endereco do node: %x\n Endereco do node prox: %x", aux, aux->prox);
            aux = aux->prox;
        }
        printf("\n\n");
    }
}

void remover(node* CABECA) {
    if(CABECA->prox == NULL){
        printf("Lista vazia!\n\n");
    }else{
        int valor;
        printf("\n\nInforme o node a ser removido: ");
        scanf("%d", &valor);
        node* aux = CABECA->prox;
        node* antaux = CABECA;
        while(aux != NULL && aux->numero_conta != valor){
            antaux = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            printf("Node nao encontrado\n");
        }else{
        	printf("Node a ser removido:\n");
        	printf("Conta do cliente: %d\n", aux->numero_conta);
        	printf("Nome do cliente: %s\n", aux->nome_cliente);
        	printf("Saldo do cliente: %.2f\n", aux->saldo);
               antaux->prox = aux->prox;
               free(aux);
        }
    }
}

void liberar_lista(node* CABECA) {
	
	if(CABECA->prox == NULL) {
		printf("Lista vazia!\n");
	} else {
		node* aux = CABECA->prox;
		while(aux != NULL) {
			node* a = aux->prox;
			free(aux);
			aux = a;
		}
		CABECA->prox = NULL;
        printf("Lista liberada!\n");
	}
}

int main() {
    node* CABECA = (node *) malloc(sizeof(node));
    CABECA->prox = NULL;
    int opt;
    do{
    	printf("Escola a opcao\n");
        printf("0. Sair\n");
        printf("1. Exibir lista\n");
        printf("2. Adicionar node no inicio\n");
        printf("3. Adicionar node no final\n");
        printf("4. Remove node da lista\n");
        printf("5. Liberar toda lista\n");
        printf("Opcao: ");
        scanf("%d", &opt);
        switch(opt)
        {
        	case 0:
        		break;
            case 1:
                imprimir(CABECA);
                printf("\n\n");
                break;
            case 2:
            	adicionar_inicio(CABECA);
            	printf("\n\n");
            	break;
            case 3:
                adicionar_fim(CABECA);
                printf("\n\n");
                break;
            case 4:
                remover(CABECA);
                printf("\n\n");
                break;
            case 5:
            	liberar_lista(CABECA);
            	break;
            default:
                printf("Opcao Invalida...\n");
        }
    }
    while(opt != 0);
    return 0;
}
