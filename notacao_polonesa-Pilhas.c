#include <stdio.h>
#include <stdlib.h>

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
}

void remove_pilha(PILHAptr pilha) {
	pilha->cabeca = pilha->cabeca->prox;
}

void imprime_pilha(PILHAptr pilha) {
	NOptr percorre_pilha = pilha->cabeca;
	while (percorre_pilha->prox != NULL) {
		printf("%s ", percorre_pilha->caractere);
		percorre_pilha = percorre_pilha->prox;
	}
}

PILHAptr inverte_pilha(PILHAptr pilha) {
	PILHAptr pilha_invertida = (PILHAptr) malloc(sizeof(PILHA));
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
	imprime_pilha(pilha_invertida);
	NOptr percorre_pilha = pilha_invertida->cabeca;
	while (percorre_pilha->prox != NULL) {
		if (percorre_pilha->caractere[0] == '#') {
			float soma = 0;
			NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
			while (percorre_pilha_inicio->caractere[0] != '#') {
				soma = soma + atof(percorre_pilha_inicio->caractere);
				remove_pilha(pilha_invertida);
				percorre_pilha_inicio = pilha_invertida->cabeca;
			}
			remove_pilha(pilha_invertida);
			char soma_string[30];
			sprintf(soma_string, "%g", soma);
			insere_pilha(pilha_invertida, soma_string);
		} else if (percorre_pilha->caractere[0] == '-') {
			printf("Vamos subtrair");
			float subtracao = 0;
			printf("ok1");
			NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
			printf("ok2");
			int j = 0;
			while (percorre_pilha_inicio->caractere[0] != '-') {
				if (j == 0) {
					subtracao = atof(percorre_pilha_inicio->caractere) - subtracao;
				} else {
					subtracao = subtracao - atof(percorre_pilha_inicio->caractere);
				}
				remove_pilha(pilha_invertida);		
				percorre_pilha_inicio = pilha_invertida->cabeca;
				j++;
			}
			printf("ok6");
			remove_pilha(pilha_invertida);
			printf("ok7");
			char subtracao_string[30];
			sprintf(subtracao_string, "%g", subtracao);
			insere_pilha(pilha_invertida, subtracao_string);
		}
		percorre_pilha = percorre_pilha->prox;
	}
	printf("\n");
	imprime_pilha(pilha_invertida);
}
