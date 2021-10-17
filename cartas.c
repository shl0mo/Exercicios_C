#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int numero;
	struct no *prox, *ant;
}NO;

typedef NO* NOptr;

typedef struct lista_circular {
	int tamanho;
	NOptr cabeca;
}LISTA_CIRCULAR;

typedef LISTA_CIRCULAR* LISTA_CIRCULARptr;

LISTA_CIRCULARptr inicializa_lista() {
	LISTA_CIRCULARptr nova_lista = (LISTA_CIRCULARptr) malloc(sizeof(LISTA_CIRCULAR));
	NOptr no_lista = (NOptr) malloc(sizeof(NO));
	no_lista->ant = no_lista;
	no_lista->prox = no_lista;
	nova_lista->cabeca = no_lista;
	nova_lista->tamanho = 0;
	return nova_lista;
}

void insere_lista(LISTA_CIRCULARptr lista, int numero) {
	NOptr percorre_lista = lista->cabeca;
	while (percorre_lista->prox != lista->cabeca) {
		percorre_lista = percorre_lista->prox;
	}
	NOptr nova_lista = (NOptr) malloc(sizeof(NO));
	nova_lista->numero = numero;
	nova_lista->ant = percorre_lista;
	nova_lista->prox = lista->cabeca;
	percorre_lista->prox = nova_lista;
	lista->tamanho++;
}

int remove_lista(LISTA_CIRCULARptr lista) {
	int numero = lista->cabeca->prox->numero;
	NOptr no_lista = lista->cabeca->prox;
	no_lista->ant->prox = no_lista->prox;
	no_lista->prox->ant = no_lista->ant;
	lista->tamanho--;
	return numero;
}

void imprime_lista(LISTA_CIRCULARptr lista) {
	NOptr percorre_lista = lista->cabeca->prox;
	while (percorre_lista != lista->cabeca) {
		printf("%i", percorre_lista->numero);
		if (percorre_lista->prox != lista->cabeca) {
			printf(", ", percorre_lista->numero);
		}
		percorre_lista = percorre_lista->prox;
	}
}

typedef struct vetor {
	LISTA_CIRCULARptr lista_circular;
	struct vetor * prox;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor() {
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	novo_vetor->prox = NULL;
	return novo_vetor;
}

void insere_vetor(VETORptr vetor, LISTA_CIRCULARptr lista_circular) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor->prox != NULL) {
		percorre_vetor = percorre_vetor->prox;
	}
	VETORptr novo_elemento = (VETORptr) malloc(sizeof(VETOR));
	novo_elemento->lista_circular = lista_circular;
	novo_elemento->prox = NULL;
	percorre_vetor->prox = novo_elemento;
}

void imprime_vetor(VETORptr vetor, VETORptr vetor_descartadas) {
	VETORptr percorre_vetor = vetor->prox;
	VETORptr percorre_descartadas = vetor_descartadas->prox;
	int i = 0;
	while (percorre_vetor) {
		if (i > 0) {
			printf("\n");
		}
		printf("Descartadas: ");
		imprime_lista(percorre_vetor->lista_circular);
		printf("\nRestou: ");
		printf("%i", percorre_descartadas->lista_circular->cabeca->prox->numero);
		percorre_vetor = percorre_vetor->prox;
		percorre_descartadas = percorre_descartadas->prox;
		i++;
	}
}

int main(void) {
	int N;
	VETORptr lista_listas_descartadas = inicializa_vetor();
	VETORptr lista_listas_restante = inicializa_vetor();
	while (1) {
		LISTA_CIRCULARptr lista = inicializa_lista();
		LISTA_CIRCULARptr lista_descartadas = inicializa_lista();
		LISTA_CIRCULARptr lista_restante = inicializa_lista();
		scanf("%i", &N);
		if (N == 0) {
			break;
		}
		int i = 1;
		for (i = 1; i <= N; i++) {
			insere_lista(lista, i);
		}
		while (lista->tamanho != 1) {
			int descartada = remove_lista(lista);
			insere_lista(lista_descartadas, descartada);
			int final_lista = remove_lista(lista);
			insere_lista(lista, final_lista);
		}
		insere_lista(lista_restante, lista->cabeca->prox->numero);
		insere_vetor(lista_listas_descartadas, lista_descartadas);
		insere_vetor(lista_listas_restante, lista_restante);
	};
	imprime_vetor(lista_listas_descartadas, lista_listas_restante);
}
