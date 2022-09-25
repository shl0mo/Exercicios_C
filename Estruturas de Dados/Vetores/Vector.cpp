# include <stdio.h>
# include <stdlib.h>

typedef struct Loja {
	char tipo[100];
	char marca[100];
	char modelo[100];
	double valor;
	int quantidade_estoque;
	double valor_frete;
	struct Loja* prox;
} LOJA;

typedef LOJA* LOJAptr;

void apaga_palavra(char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		palavra[i] = '\0'
	}
}

void copia_palavra(char vetor_loja[100], char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		vetor_loja[i] = palavra[i];
	}
}

LOJAptr insere_no_loja (char tipo[100], char marca[100], char modelo[100], int quantidade_estoque, int valor_frete) {
	LOJAptr novo_no = LOJAptr malloc(sizeof(LOJA));
	
	novo_no->valor = 0;
	novo_no->quantidade_estoque = 0;
	novo_no->valor_frete = 0;
	return novo_vetor;
}

int main () {
	printf("Ola, mundo!");
}
