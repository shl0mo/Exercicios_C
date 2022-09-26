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

LOJAptr insere_no_loja (LOJAptr loja, int primeiro; char tipo[100], char marca[100], char modelo[100], double valor, int quantidade_estoque, double valor_frete) {
	LOJAptr novo_no = LOJAptr malloc(sizeof(LOJA));
	copia_palavra(novo_no->tipo, tipo);
	copia_palavra(novo_no->marca, marca);
	copia_palavra(novo_no->modelo, modelo);
	novo_no->valor = valor;
	novo_no->quantidade_estoque = quantidade_estoque;
	novo_no->valor_frete = valor_frete;
	if (primeiro == 1) {
		novo_no->prox = NULL;
		return novo_vetor;
	}
	LOJAptr p = loja;
	while (p->prox != NULL) {
		p = p->prox;
	}
	p->prox = novo_vetor;
	novo_vetor->prox = NULL;
	return NULL;
}

int main () {
	printf("Ola, mundo!");
}
