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
	lista->tamanho++;
	return 1;
}

int insere_inicio(LISTAptr lista, int valor) {
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	novo_no->valor = valor;
	novo_no->prox = lista->cabeca;
	lista->cabeca = novo_no;
}

void imprime_lista(LISTAptr lista) {
	NOptr percorre_lista = lista->cabeca;
	while (percorre_lista->prox != NULL) {
		printf("%i ", percorre_lista->valor);
		percorre_lista = percorre_lista->prox;
	}
}

int inverte(NOptr lista, LISTAptr lista_invertida) {
	if (lista == NULL) {
		imprime_lista(lista_invertida);
		return 1;
	}
	insere_inicio(lista_invertida, lista->valor);
	inverte(lista->prox, lista_invertida);
}

int main(void) {
	int numero;
	LISTAptr lista = inicializa_lista();
	LISTAptr lista_invertida = inicializa_lista();
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			break;
		}
		insere_lista(lista, numero);
	}
	inverte(lista->cabeca->prox, lista_invertida);
}
