#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *prox;	
}NO;

typedef NO* NOptr;

typedef struct lista {
	int tamanho;
	NOptr cabeca;
}LISTA;

typedef  LISTA* LISTAptr;

LISTAptr inicializa_lista() {
	LISTAptr nova_lista = (LISTAptr) malloc(sizeof(LISTA));
	nova_lista->tamanho = 0;
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	novo_no->valor = -100;
	novo_no->prox = NULL;
	nova_lista->cabeca = novo_no;
	return nova_lista;
}

int insere_lista(LISTAptr lista, int valor) {
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	novo_no->valor = valor;
	novo_no->prox = NULL;	
	NOptr percorre_lista = lista->cabeca;
	if (percorre_lista == NULL) {
		percorre_lista->prox = novo_no;
		return 1;
	}
	while (percorre_lista->prox != NULL) {
		percorre_lista = percorre_lista->prox;
	}
	percorre_lista->prox = novo_no;
	return 1;
}

NOptr busca_lista(LISTAptr lista, int valor) {
	NOptr percorre_lista = lista->cabeca->prox;
	while (percorre_lista) {
		if (percorre_lista->valor == valor) {
			return percorre_lista;
		}
		percorre_lista = percorre_lista->prox;
	}
	return NULL;
}

void imprime_lista(LISTAptr lista) {
	NOptr percorre_lista = lista->cabeca->prox;
	while (percorre_lista) {
		printf("%i\n", percorre_lista->valor);
		percorre_lista = percorre_lista->prox;
	}
}

int main(void) {
	int numero;
	LISTAptr lista1 = inicializa_lista();
	LISTAptr lista2 = inicializa_lista();
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			break;
		}
		insere_lista(lista1, numero);
	}
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			break;
		}
		insere_lista(lista2, numero);
	}
	NOptr percorre_lista = lista2->cabeca;
	while (percorre_lista) {
		NOptr resultado_busca = busca_lista(lista1, percorre_lista->valor);
		if (resultado_busca != NULL) {
			printf("SIM");
			return 1;
		}
		percorre_lista = percorre_lista->prox;
	}
	printf("NAO");
	return 0;
}
