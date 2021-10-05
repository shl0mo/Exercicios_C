#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_generica {
	char caractere;
	struct arvore_generica *prim, *prox;
}ARVORE_GENERICA;

typedef ARVORE_GENERICA* ARVORE_GENERICAptr;

ARVORE_GENERICAptr inicializa_arvore(char caractere) {
	ARVORE_GENERICAptr avr = (ARVORE_GENERICAptr) malloc(sizeof(ARVORE_GENERICA));
	avr->caractere = caractere;
	avr->prim = NULL;
	avr->prox = NULL;
	return avr;
}

int insere_arvore(ARVORE_GENERICAptr arvore_pai, ARVORE_GENERICAptr arvore_filha) {
	if (arvore_pai->prim == NULL) {
		arvore_pai->prim = arvore_filha;
		return 1;
	} else if (arvore_filha->caractere <= arvore_pai->prim->caractere) {
		arvore_filha->prox = arvore_pai->prim;
		arvore_pai->prim = arvore_filha;
		return 1;
	} else {
		ARVORE_GENERICAptr p = arvore_pai->prim;
		while (p->prox != NULL) {
			if (arvore_filha->caractere <= p->prox->caractere) {
				arvore_filha->prox = p->prox;
				p->prox = arvore_filha;
				return 1;
			}
			p = p->prox;
		}
		p->prox = arvore_filha;
		return 1;
	}
	/*if (arvore_pai->prim == NULL) {
		arvore_pai->prim = arvore_filha;
	} else {
		ARVORE_GENERICAptr p = arvore_pai->prim;
		while (p->prox != NULL) {
			p = p->prox;
		}
		p->prox = arvore_filha;
		arvore_filha->prox = NULL;
	}*/
}

ARVORE_GENERICAptr busca_arvore(ARVORE_GENERICAptr arv, char caractere) {
	ARVORE_GENERICAptr p;
	if (arv->caractere == caractere) {
		return arv;
	} else {
		for (p = arv->prim; p != NULL; p = p->prox) {
			if (busca_arvore(p, caractere)) {
				return p;
			}
		}
	}
	return NULL;
}

void imprime_arvore(ARVORE_GENERICAptr arvore) {
	ARVORE_GENERICAptr p;
	printf("%c\n", arvore->caractere);
	for (p = arvore->prim; p != NULL; p = p->prox) {
		imprime_arvore(p);
	}
}

int main(void) {
	char caractere[2];
	scanf("%s", &caractere);
	if (caractere[0] == '#' && caractere[1] == '#') {
		return 0;
	}
	ARVORE_GENERICAptr arvore = inicializa_arvore(caractere[0]);
	while (1) {
		scanf("%s", &caractere);
		if (caractere[0] == '#' && caractere[1] == '#') {
			break;
		}
		ARVORE_GENERICAptr arvore_filha = inicializa_arvore(caractere[0]);
		scanf("%s", &caractere);
		ARVORE_GENERICAptr arvore_pai = busca_arvore(arvore, caractere[0]);
		insere_arvore(arvore_pai, arvore_filha);
	}
	imprime_arvore(arvore);
	return 0;
}
