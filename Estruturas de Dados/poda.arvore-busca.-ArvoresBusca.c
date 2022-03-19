#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_busca {
	int numero;
	struct arvore_busca *esq, *dir;
}ARVORE_BUSCA;

typedef ARVORE_BUSCA* ARVORE_BUSCAptr;

ARVORE_BUSCAptr insere_arvore(ARVORE_BUSCAptr arvore, int numero) {
	if (arvore ==  NULL) {
		arvore = (ARVORE_BUSCAptr) malloc(sizeof(ARVORE_BUSCA));
		arvore->numero = numero;
		arvore->esq = NULL;
		arvore->dir = NULL;
	} else if (numero < arvore->numero) {
		arvore->esq = insere_arvore(arvore->esq, numero);
	} else {
		arvore->dir = insere_arvore(arvore->dir, numero);
	}
	return arvore;
}

void imprime_arvore(ARVORE_BUSCAptr arvore) {
	if (arvore != NULL) {
		imprime_arvore(arvore->esq);
		printf("%i\n", arvore->numero);
		imprime_arvore(arvore->dir);
	}
}

ARVORE_BUSCAptr busca_arvore(ARVORE_BUSCAptr arvore, int numero) {
	if (arvore == NULL) {
		return NULL;
	}
	if (arvore->numero == numero) {
		arvore->dir = NULL;
		free(arvore->dir);
		return arvore;
	}
	busca_arvore(arvore->esq, numero);
	busca_arvore(arvore->dir, numero);
}

int main(void) {
	int numero;
	int raiz_poda;
	scanf("%i", &numero);
	if (numero == 0) {
		return 0;
	}
	ARVORE_BUSCAptr arvore_busca = insere_arvore(NULL, numero);
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			scanf("%i", &raiz_poda);
			break;
		}
		insere_arvore(arvore_busca, numero);
	}
	ARVORE_BUSCAptr resultado_busca = busca_arvore(arvore_busca, raiz_poda);
	//printf("Raiz poda: %i", raiz_poda);
	imprime_arvore(arvore_busca);
}
