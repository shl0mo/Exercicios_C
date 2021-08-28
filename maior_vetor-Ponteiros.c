#include <stdio.h>
#include <stdlib.h>

typedef struct vetor {
	int indice;
	int valor;
	struct vetor * prox;
}VETOR;

typedef VETOR* VETORptr;

void inicializa_vetor(VETORptr vetor) {
	vetor->indice = -1;
	vetor->valor = -1;
	vetor->prox = NULL;
}

void insere_elemento_vetor(VETORptr vetor, int elemento, int indice) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor->prox != NULL) {
		percorre_vetor = percorre_vetor->prox;
	}
	VETORptr novo_elemento = (VETORptr) malloc(sizeof(VETOR));
	novo_elemento->indice = indice;
	novo_elemento->valor = elemento;
	novo_elemento->prox = NULL;
	percorre_vetor->prox = novo_elemento;
}

void imprime_vetor(VETORptr vetor) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor) {
		printf("%i ", percorre_vetor->valor);
		percorre_vetor = percorre_vetor->prox;
	}
}

void maiorElemento(VETORptr vetor, int n, int *maior) {
	int i, j;
	VETORptr percorre_vetor = vetor->prox;
	VETORptr elemento_atual = vetor->prox;
	for (i = 0; i < n; i++) {
		int maior_elemento = 1;
		for (j = 0; j < n; j++) {
			if (percorre_vetor->valor > elemento_atual->valor) {
				maior_elemento = 0;
			}
			percorre_vetor = percorre_vetor->prox;
		}
		if (maior_elemento == 1) {
			*maior = elemento_atual->valor;
		}
		percorre_vetor = vetor->prox;
		elemento_atual = elemento_atual->prox;
	}
}

int main (void) {
	int n, i;
	int maior;
	VETOR vetor;
	inicializa_vetor(&vetor);
	scanf("%i", &n);
	for (i = 0; i < n; i++) {
		int elemento;
		scanf("%i", &elemento);
		insere_elemento_vetor(&vetor, elemento, i);
	}
	maiorElemento(&vetor, n, &maior);
	printf("%i", maior);
}
