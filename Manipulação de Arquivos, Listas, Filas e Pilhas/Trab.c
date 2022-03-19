#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	char carro[100];
	struct lista *prox;
}LISTA;

typedef LISTA* LISTAptr;

typedef struct pilha {
	
}PILHA;

typedef PILHA* PILHAptr;

typedef struct fila {
	
}FILA;

typedef FILA* FILAptr;

LISTAptr inicializa_lista (char carro[100]) {
	LISTAptr nova_lista = (LISTAptr) malloc(sizeof(LISTA));
	int i = 0;
	for (i = 0; i < 100; i++) {
		nova_lista->carro[i] = carro[i];
	}
	nova_lista->prox = NULL;
	return nova_lista;
}

LISTAptr inserir_lista (LISTAptr lista, char carro[100]) {
	LISTAptr p = lista;
	while (p->prox != NULL) {
		p = p->prox;
	}
	LISTAptr nova_lista = inicializa_lista(carro);
	p->prox = nova_lista;
}

LISTAptr imprimir_lista (LISTAptr lista) {
	LISTAptr p = lista->prox;
	while (p != NULL) {
		printf("%s", p->carro);
		p = p->prox;
	}
}

int main () {
	FILE* arq = fopen("arquivo.txt", "r");
	int escolha;
	char vetor_null[100];
	LISTAptr lista = inicializa_lista(vetor_null);
	while (!feof(arq)) {
		char linha[100];
		fgets(linha, 100, arq);
		if (linha[0] != '#' && linha[0] != ' ') {
			inserir_lista(lista, linha);
		}
	}
	imprimir_lista(lista);
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
