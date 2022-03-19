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
	return linha;
}

MATRIZptr inicializa_matriz() {
	MATRIZptr matriz = (MATRIZptr) malloc(sizeof(MATRIZ));
	matriz->indice = -1;
	matriz->linha = NULL;
	matriz->ant = NULL;
	matriz->prox = NULL;
	return matriz;
}

int insere_elemento_linha(LINHAptr linha, int elemento, int indice) {
	if (linha->prox == NULL) {
		LINHAptr nova_linha = (LINHAptr) malloc(sizeof(LINHA));
		nova_linha->indice = indice;
		nova_linha->valor = elemento;
		nova_linha->ant = linha;
		nova_linha->prox = NULL;
		linha->prox = nova_linha;
		return 1;
	}
	linha = linha->prox;
	insere_elemento_linha(linha, elemento, indice);
}

int insere_linha_matriz(MATRIZptr matriz, LINHAptr linha, int indice) {
	if (matriz->prox == NULL) {
		MATRIZptr nova_linha_matriz = (MATRIZptr) malloc(sizeof(MATRIZ));
		nova_linha_matriz->indice = indice;
		nova_linha_matriz->linha = linha;
		nova_linha_matriz->ant = matriz;
		nova_linha_matriz->prox = NULL;
		matriz->prox = nova_linha_matriz;
		return 1;
	}
	matriz = matriz->prox;
	insere_linha_matriz(matriz, linha, indice);
}

int imprime_linha(LINHAptr linha) {
	if (linha == NULL) return 1;
	printf("%i ", linha->valor);
	imprime_linha(linha->prox);
}

int imprime_matriz(MATRIZptr matriz) {
	if (matriz == NULL) return 1;
	imprime_linha(matriz->linha);
	matriz = matriz->prox;
	imprime_matriz(matriz);
}

int soma_linha(LINHAptr linha, int resultado) {
	if (linha == NULL) {
		return resultado;
	}
	if (linha->indice != -1) {
		resultado = resultado + linha->valor;		
	}
	linha = linha->prox;
	soma_linha(linha, resultado);
}

int somatorio_matriz(MATRIZptr matriz, int resultado) {
	if (matriz == NULL) return resultado;
	if (matriz->indice != -1) {
		resultado = soma_linha(matriz->linha, resultado);	
	}
	matriz = matriz->prox;
	somatorio_matriz(matriz, resultado);
}

int leitura_linha(int M, LINHAptr linha, int i) {
	if (M == 0) return 1;
	int elemento = 0;
	scanf("%i", &elemento);
	insere_elemento_linha(linha, elemento, i);
	M = M - 1;
	i = i + 1;
	return leitura_linha(M, linha, i);
}

int leitura_matriz(int N, int M, MATRIZptr matriz, int indice) {
	if (N == 0) return 1;
	LINHAptr nova_linha = inicializa_linha();
	leitura_linha(M, nova_linha, 0);
	insere_linha_matriz(matriz, nova_linha, indice);
	int novo_indice = indice + 1;
	N = N - 1;
	return leitura_matriz(N, M, matriz, novo_indice);
}

int main(void) {
	int N, M, i, j;
	MATRIZptr matriz = inicializa_matriz();
	scanf("%i", &N);
	scanf("%i", &M);
	leitura_matriz(N, M, matriz, 0);
	int somatorio = somatorio_matriz(matriz, 0);
	printf("%i", somatorio);
}
