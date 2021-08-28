#include <stdio.h>
#include <stdlib.h>

typedef struct linha {
	int indice;
	int valor;
	struct linha *prox, *ant;
}LINHA;

typedef LINHA* LINHAptr;

typedef struct matriz {
	int indice;
	LINHAptr linha;
	struct matriz *prox, *ant;
}MATRIZ;

typedef MATRIZ* MATRIZptr;

LINHAptr inicializa_linha() {
	LINHAptr linha = (LINHAptr) malloc(sizeof(LINHA));
	linha->indice = -1;
	linha->valor = -1;
	linha->ant = NULL;
	linha->prox = NULL;
}

MATRIZptr inicializa_matriz() {
	MATRIZptr matriz = (MATRIZptr) malloc(sizeof(MATRIZ));
	matriz->indice = -1;
	matriz->linha = NULL;
	matriz->ant = NULL;
	matriz->prox = NULL;
}

void insere_elementos_linha(LINHAptr linha, int elemento, int indice) {
	LINHAptr percorre_linha = linha;
	while (percorre_linha->prox != NULL) {
		percorre_linha = percorre_linha->prox;
	}
	LINHAptr nova_linha = (LINHAptr) malloc(sizeof(LINHA));
	nova_linha->indice = indice;
	nova_linha->valor = elemento;
	nova_linha->ant = percorre_linha;
	nova_linha->prox = NULL;
	percorre_linha->prox = nova_linha;
}

void insere_linha_matriz(MATRIZptr matriz, LINHAptr linha, int indice) {
	MATRIZptr percorre_matriz = matriz;
	while (percorre_matriz->prox != NULL) {
		percorre_matriz = percorre_matriz->prox;
	}
	MATRIZptr nova_linha_matriz = (MATRIZptr) malloc(sizeof(MATRIZ));
	nova_linha_matriz->indice = indice;
	nova_linha_matriz->linha = linha;
	nova_linha_matriz->ant = percorre_matriz;
	nova_linha_matriz->prox = NULL;
	percorre_matriz->prox = nova_linha_matriz;
}

void imprime_linha(LINHAptr linha) {
	LINHAptr percorre_linha = linha;
	while (percorre_linha) {
		if (percorre_linha->indice != -1) {
			printf("%i ", percorre_linha->valor);
		}
		percorre_linha = percorre_linha->prox;
	}
}

void imprime_matriz(MATRIZptr matriz) {
	MATRIZptr percorre_matriz = matriz;
	while (percorre_matriz) {
		imprime_linha(percorre_matriz->linha);
		printf("\n");
		percorre_matriz = percorre_matriz->prox;
	}
}

MATRIZptr soma_matrizes(MATRIZptr matriz1, MATRIZptr matriz2) {
	MATRIZptr matriz_resultante = inicializa_matriz();
	MATRIZptr percorre_matriz1 = matriz1;
	MATRIZptr percorre_matriz2 = matriz2;
	int indice_matriz = 0;
	while (percorre_matriz1) {
		LINHAptr linha_resultante = inicializa_linha();
		LINHAptr percorre_linha1 = percorre_matriz1->linha;
		LINHAptr percorre_linha2 = percorre_matriz2->linha;
		int indice_linha = 0;
		while (percorre_linha1) {
			if (percorre_linha1->indice != -1) {
				int soma = percorre_linha1->valor + percorre_linha2->valor;
				insere_elementos_linha(linha_resultante, soma, indice_linha);
				indice_linha++;
			}
			percorre_linha1 = percorre_linha1->prox;
			percorre_linha2 = percorre_linha2->prox;
		}
		insere_linha_matriz(matriz_resultante, linha_resultante, indice_matriz);
		indice_matriz++;
		percorre_matriz1 = percorre_matriz1->prox;
		percorre_matriz2 = percorre_matriz2->prox;
	}
	return matriz_resultante;
}

int main(void) {
	int N, M, i, j;
	MATRIZptr matriz1 = inicializa_matriz();
	MATRIZptr matriz2 = inicializa_matriz();
	scanf("%i", &N);
	scanf("%i", &M);
	for (i = 0; i < N; i++) {
		LINHAptr linha = inicializa_linha();
		for (j = 0; j < M; j++) {
			int elemento;
			scanf("%i", &elemento);
			insere_elementos_linha(linha, elemento, j);
		}
		insere_linha_matriz(matriz1, linha, i);
	}
	for (i = 0; i < N; i++) {
		LINHAptr linha = inicializa_linha();
		for (j = 0; j < M; j++) {
			int elemento;
			scanf("%i", &elemento);
			insere_elementos_linha(linha, elemento, j);
		}
		insere_linha_matriz(matriz2, linha, i);
	}
	MATRIZptr matriz_soma = soma_matrizes(matriz1, matriz2);
	imprime_matriz(matriz_soma);
}
