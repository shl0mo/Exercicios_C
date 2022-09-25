# include <stdio.h>
# include <stdlib.h>

typedef struct vetor {
	char tipo[100];
	char marca[100];
	char modelo[100];
	double valor;
	int quantidade_estoque;
	double valor_frete;
	struct vetor* prox;
} VETOR;

typedef VETOR* VETORptr;

void apaga_palavra(char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		palavra[i] = '\0'
	}
}

VETORptr inicializa_vetor () {
	VETORptr novo_vetor = VETORptr malloc(sizeof(VETOR));
	
	return novo_vetor;
}

int main () {
	printf("Ola, mundo!");
}
