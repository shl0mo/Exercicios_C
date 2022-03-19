#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	char info[100];
	char placa[6];
	struct lista *prox;
}LISTA;

typedef LISTA* LISTAptr;

typedef struct pilha {
	char info[100];
	struct pilha *prox;	
}PILHA;

typedef PILHA* PILHAptr;

typedef struct fila {
	char info[100];
	struct fila *prox;
}FILA;

typedef FILA* FILAptr;

LISTAptr inicializa_lista (char info[100], int insere) {
	LISTAptr nova_lista = (LISTAptr) malloc(sizeof(LISTA));
	int i, j, k = 0;
	for (i = 0; i < 100; i++) {
		nova_lista->info[i] = info[i];
	}
	if (insere == 1) {
		for (i = 0; i <= 100; i++) {
			if (info[i] == ' ') {
				j++;	
			}
			if (j == 11) {
				nova_lista->placa[k] = info[i];
				k++;
			}
			if (info[i] == '\0') {
				break;
			}
		}
	}
	nova_lista->prox = NULL;
	return nova_lista;
}

LISTAptr inserir_lista (LISTAptr lista, char info[100]) {
	LISTAptr p = lista;
	while (p->prox != NULL) {
		p = p->prox;
	}
	LISTAptr nova_lista = inicializa_lista(info, 1);
	p->prox = nova_lista;
}

void imprimir_lista_info (LISTAptr lista) {
	LISTAptr p = lista->prox;
	while (p != NULL) {
		printf("%s", p->info);
		p = p->prox;
	}
}

void imprimir_lista_placa (LISTAptr lista) {
	LISTAptr p = lista->prox;
	while (p != NULL) {
		printf("%s", p->placa);
		p = p->prox;
	}
}



int main () {
	FILE* arq = fopen("arquivo.txt", "r");
	int escolha, i;
	char vetor_null[100];
	LISTAptr lista = inicializa_lista(vetor_null, 0);
	while (!feof(arq)) {
		char linha[100];
		/*for (i = 0; i < 100; i++) {
			linha[i] = ' ';
		}*/
		fgets(linha, 100, arq);
		if (linha[0] != '#' && linha[0] != ' ') {
			inserir_lista(lista, linha);
		}
	}
	imprimir_lista_placa(lista);
	while (1) {
		do {
			printf("Escolha uma das opções abaixo: \n\n");
			printf("1 - Inserção\n");
			printf("2 - Busca\n");
			printf("3 - Exclusão\n");
			printf("4 - Relatório\n");
			printf("5 - Sair\n");
			scanf("%i", &escolha);
		} while (escolha < 1 || escolha > 5);
		if (escolha == 5) {
			return 0;
		}
		if (escolha == 2) {
			escolha = 0;
			do {
				printf("\nEscolha o tipo de busca: \n\n");
				printf("1 - Busca por pilha\n");
				printf("2 - Busca por fila\n");
				scanf("%i", &escolha);
			} while (escolha < 1 || escolha > 2);
		}
	}
}
