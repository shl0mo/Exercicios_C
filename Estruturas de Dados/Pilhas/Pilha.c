# include <stdio.h>
# include <stdlib.h>

// Estruturas de dados
typedef struct no_pilha {
	int chave;
	struct no_pilha* prox;
}NO_PILHA;

typedef NO_PILHA* NO_PILHAptr;


typedef struct pilha {
	struct no_pilha* cabeca;
}PILHA;

typedef PILHA* PILHAptr;

// Funções
NO_PILHAptr insere_no_pilha (int chave) {
	NO_PILHAptr novo_no_pilha = (NO_PILHAptr) malloc(sizeof(NO_PILHA));
	novo_no_pilha->chave = chave;
	novo_no_pilha->prox = NULL;
	return novo_no_pilha;
}

PILHAptr inicializa_pilha (int chave) {
	PILHAptr nova_pilha = (PILHAptr) malloc(sizeof(PILHA));
	nova_pilha->cabeca = insere_no_pilha(chave);
	return nova_pilha;
}

void insere_pilha (PILHAptr pilha, int chave) {
	NO_PILHAptr novo_no_pilha = insere_no_pilha(chave);
	novo_no_pilha->prox = pilha->cabeca;
	pilha->cabeca = novo_no_pilha;
}

void remove_pilha (PILHAptr pilha) {
	pilha->cabeca = pilha->cabeca->prox;
}

void imprime_pilha (PILHAptr pilha) {
	NO_PILHAptr p = pilha->cabeca;
	while (p) {
		printf("%i ", p->chave);
		p = p->prox;
	}
	printf("\n");
}


// Função que retorna uma cópia da pilha
PILHAptr copiar_pilha (PILHAptr pilha) {
	PILHAptr pilha_reversa = inicializa_pilha(pilha->cabeca->chave);
	NO_PILHAptr p = pilha->cabeca->prox;
	while (p) {
		insere_pilha(pilha_reversa, p->chave);
		p = p->prox;
	}
	PILHAptr pilha_copia = inicializa_pilha(pilha_reversa->cabeca->chave);
	p = pilha_reversa->cabeca->prox;
	while (p) {
		insere_pilha(pilha_copia, p->chave);
		p = p->prox;
	}
	return pilha_copia;
}



int main () {
	PILHAptr pilha = inicializa_pilha(1);
	insere_pilha(pilha, 3);
	insere_pilha(pilha, 5);
	insere_pilha(pilha, 9);
	insere_pilha(pilha, 50);
	insere_pilha(pilha, 350);
	insere_pilha(pilha, 1000);
	printf("Pilha original: ");
	imprime_pilha(pilha);
	
	printf("\n");
	printf("Copia da pilha: ");
	PILHAptr pilha_copia = copiar_pilha(pilha);
	imprime_pilha(pilha_copia);
}

