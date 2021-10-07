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

ARVORE_BUSCAptr busca_arvore(ARVORE_BUSCAptr arvore, ARVORE_BUSCAptr arvore_enxertada, int numero) {
	if (arvore == NULL) {
		return NULL;
	}
	if (arvore->numero == numero) {
		if (numero > arvore_enxertada->numero) {
			arvore->esq = arvore_enxertada;
		} else {
			arvore->dir = arvore_enxertada;
		}
		return arvore;
	}
	busca_arvore(arvore->esq, arvore_enxertada, numero);
	busca_arvore(arvore->dir, arvore_enxertada, numero);
}

int main(void) {
	int numero;
	int raiz_enxerto;
	scanf("%i", &numero);
	if (numero == 0) {
		return 0;
	}
	ARVORE_BUSCAptr ABB1 = insere_arvore(NULL, numero);
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			break;
		}
		insere_arvore(ABB1, numero);
	}
	scanf("%i", &numero);
	if (numero == 0) {
		return 0;
	}
	ARVORE_BUSCAptr ABB = insere_arvore(NULL, numero);
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			scanf("%i", &raiz_enxerto);
			break;
		}
		insere_arvore(ABB, numero);
	}
	busca_arvore(ABB1, ABB, raiz_enxerto);
	imprime_arvore(ABB1);
}
