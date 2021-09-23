#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct no {
	char caractere[30];
	struct no *prox;
}NO;

typedef NO* NOptr;

typedef struct pilha {
	int tamanho;
	NOptr cabeca;
}PILHA;

typedef PILHA* PILHAptr;

PILHAptr inicializa_pilha() {
	PILHAptr nova_pilha = (PILHAptr) malloc(sizeof(PILHA));
	nova_pilha->tamanho = 0;
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	novo_no->prox = NULL;
	nova_pilha->cabeca = novo_no;
	return nova_pilha;
}

void insere_pilha(PILHAptr pilha, char caractere[30]) {
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	int i = 0;
	for (i = 0; i < 30; i++) {
		novo_no->caractere[i] = caractere[i];
	}
	novo_no->prox = pilha->cabeca;
	pilha->cabeca = novo_no;
	pilha->tamanho = pilha->tamanho + 1;
}

void remove_pilha(PILHAptr pilha) {
	pilha->cabeca = pilha->cabeca->prox;
	pilha->tamanho = pilha->tamanho - 1;
}

void imprime_pilha(PILHAptr pilha, int i) {
	NOptr percorre_pilha = pilha->cabeca;
	if (i == 1) {
		NOptr percorre_pilha = pilha->cabeca->prox;
	}
	while (percorre_pilha->prox != NULL) {
		printf("%s ", percorre_pilha->caractere);
		percorre_pilha = percorre_pilha->prox;
	}
}

PILHAptr inverte_pilha(PILHAptr pilha) {
	PILHAptr pilha_invertida = (PILHAptr) malloc(sizeof(PILHA));
	pilha_invertida->tamanho = 0;
	NOptr percorre_pilha = pilha->cabeca;
	while (percorre_pilha->prox != NULL) {
		insere_pilha(pilha_invertida, percorre_pilha->caractere);
		percorre_pilha = percorre_pilha->prox;
	}
	return pilha_invertida;
}

int main(void) {
	PILHAptr pilha = inicializa_pilha();
	PILHAptr pilha_invertida = inicializa_pilha();
	char numero_operador[30];
	while (1) {
		scanf("%s", &numero_operador);
		if (numero_operador[0] == '.') {
			break;
		}
		insere_pilha(pilha, numero_operador);
	}
	pilha_invertida = inverte_pilha(pilha);
	//imprime_pilha(pilha_invertida);
	NOptr percorre_pilha = pilha_invertida->cabeca;
	while (percorre_pilha->prox != NULL) {
		if (percorre_pilha->prox->prox->caractere[0] == '#') {
			float soma = 0;
			soma = atof(percorre_pilha->caractere) + atof(percorre_pilha->prox->caractere);
			NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
			PILHAptr pilha_provisoria = inicializa_pilha();
			while (pilha_invertida->cabeca->caractere[0] != '#') {
				remove_pilha(pilha_invertida);
			}
			remove_pilha(pilha_invertida);
			char soma_string[30];
			sprintf(soma_string, "%g", soma);
			insere_pilha(pilha_invertida, soma_string);
			if (pilha_invertida->tamanho == 1) {
				imprime_pilha(pilha_invertida, 0);
				break;
			}
			/*
			NOptr percorre_pilha_provisoria = pilha_provisoria->cabeca;
			while (percorre_pilha_provisoria) {
				//insere_pilha(pilha_invertida, percorre_pilha_provisoria->caractere);
				percorre_pilha_provisoria = percorre_pilha_provisoria->prox;
			}*/
			//imprime_pilha(pilha_invertida);
		} else {
			
		}
	//	break;
		percorre_pilha = pilha_invertida->cabeca;
	}
	printf("\n");
}
