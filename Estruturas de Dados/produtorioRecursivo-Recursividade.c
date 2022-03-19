#include <stdio.h>
#include <stdlib.h>

typedef struct linha {
	int indice;
	int valor;
	struct linha *prox, *ant;
}LINHA;

typedef LINHA* LINHAptr;

LINHAptr inicializa_linha() {
	LINHAptr linha = (LINHAptr) malloc(sizeof(LINHA));
	linha->indice = -1;
	linha->valor = -1;
	linha->ant = NULL;
	linha->prox = NULL;
	return linha;
}

void imprime_vetor(LINHAptr vetor) {
	if (vetor == NULL) return;
	if (vetor->indice != -1) {
		printf("%i ", vetor->valor);
	}
	imprime_vetor(vetor->prox);
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

int produtorio(LINHAptr vetor, int resultado) {
	if (vetor == NULL) return resultado;
	if (vetor->indice != -1) {
		resultado = resultado * vetor->valor;
	}
	produtorio(vetor->prox, resultado);
}

int leitura_elementos(int N, LINHAptr vetor, int i) {
	if (i == N) return 1;
	int elemento = 0;
	scanf("%i", &elemento);
	insere_elemento_linha(vetor, elemento, i);
	i = i + 1;
	return leitura_elementos(N, vetor->prox, i);
}

int main(void) {
	int N;
	scanf("%i", &N);
	LINHAptr vetor = inicializa_linha();
	leitura_elementos(N, vetor, 0);
	int produto = produtorio(vetor, 1);
	printf("%i", produto);
}
