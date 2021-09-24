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
	PILHAptr resultado = inicializa_pilha();
	char numero_operador[30];
	while (1) {
		scanf("%s", &numero_operador);
		if (numero_operador[0] == '.') {
			break;
		}
		insere_pilha(pilha, numero_operador);
	}
	int quantidade_operacoes = 0;
	pilha_invertida = inverte_pilha(pilha);
	NOptr percorre_pilha = pilha_invertida->cabeca;
	while (percorre_pilha->prox != NULL) {
		if (percorre_pilha->prox->prox != NULL) {
			if (percorre_pilha->prox->prox->caractere[0] == '#') {
				printf("ok 1");
				float soma = 0;
				printf("ok 2");
				NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
				printf("ok 3");
				soma = atof(percorre_pilha->caractere) + atof(percorre_pilha->prox->caractere);
				printf("ok 4");
				PILHAptr pilha_provisoria = inicializa_pilha();
				printf("ok 5");
				int j = 0;
				printf("ok 6");
				while (pilha_invertida->cabeca->caractere[0] != '#') {
					printf("ok 7");
					if (j == 0) {
						insere_pilha(pilha_provisoria, pilha_invertida->cabeca->caractere);
					}
					remove_pilha(pilha_invertida);
					printf("ok 8");
					j++;
				}
				printf("ok 9");
				remove_pilha(pilha_invertida);
				printf("ok 10");
				char soma_string[30];
				printf("ok 11");
				sprintf(soma_string, "%g", soma);
				printf("ok 12");
				insere_pilha(pilha_invertida, soma_string);
				printf("ok 13");
				if (quantidade_operacoes > 0) {
					printf("ok 14");
					NOptr percorre_pilha_provisoria = pilha_provisoria->cabeca;
					printf("ok 15");
					while (percorre_pilha_provisoria->prox != NULL) {
						printf("ok 16");
						insere_pilha(pilha_invertida, percorre_pilha_provisoria->caractere);
						printf("ok 17");
						percorre_pilha_provisoria = percorre_pilha_provisoria->prox;
						printf("ok 18");
					}
					printf("ok 19");
				}
				printf("ok 20");
				if (pilha_invertida->tamanho == 1) {
					printf("ok 21");
					imprime_pilha(pilha_invertida, 0);
					printf("ok 22");
				}
				printf("ok 23");
				if (pilha_invertida->tamanho == 3) {
					printf("ok 24");
					char soma_final_string[30];
					printf("ok 25");
					float soma_final = 0;
					printf("ok 26");
					soma_final = atof(pilha_invertida->cabeca->caractere) + atof(pilha_invertida->cabeca->prox->caractere);
					printf("ok 27");
					sprintf(soma_final_string, "%g", soma_final);
					printf("ok 28");
					while (pilha_invertida->cabeca->caractere[0] != '#') {
						printf("ok 29");
						remove_pilha(pilha_invertida);
					}
					printf("\n\n AQUI!!! \n\n");
					printf("ok 31");
					remove_pilha(pilha_invertida);
					printf("ok 32");
					insere_pilha(pilha_invertida, soma_final_string);
					printf("ok 33");
					imprime_pilha(pilha_invertida, 0);
					printf("ok 34");
					break;
					printf("ok 35");
				} else {
					printf("ok 36");
					percorre_pilha = pilha_invertida->cabeca;
					printf("ok 37");
				}
				printf("ok 38");
				quantidade_operacoes++;
				printf("ok 39");
			} else if (percorre_pilha->prox->prox->caractere[0] == '-') {
				printf("Subtrair");
				float subtracao = 0;
				NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
				subtracao = atof(percorre_pilha->caractere) - atof(percorre_pilha->prox->caractere);
				PILHAptr pilha_provisoria = inicializa_pilha();
				int j = 0;
				while (pilha_invertida->cabeca->caractere[0] != '-') {
					if (j == 0) {
						insere_pilha(pilha_provisoria, pilha_invertida->cabeca->caractere);
					}
					remove_pilha(pilha_invertida);
					j++;
				}
				remove_pilha(pilha_invertida);
				char subtracao_string[30];
				sprintf(subtracao_string, "%g", subtracao);
				insere_pilha(pilha_invertida, subtracao_string);
				if (quantidade_operacoes > 0) {					
					NOptr percorre_pilha_provisoria = pilha_provisoria->cabeca;
					while (percorre_pilha_provisoria->prox != NULL) {
						insere_pilha(pilha_invertida, percorre_pilha_provisoria->caractere);
						percorre_pilha_provisoria = percorre_pilha_provisoria->prox;
					}
				}
				if (pilha_invertida->tamanho == 1) {
					imprime_pilha(pilha_invertida, 0);
				}
				if (pilha_invertida->tamanho == 3) {
					char subtracao_final_string[30];
					float subtracao_final = atof(pilha_invertida->cabeca->caractere) - atof(pilha_invertida->cabeca->prox->caractere);
					sprintf(subtracao_final_string, "%g", subtracao_final);
					while (pilha_invertida->cabeca->caractere[0] != '-') {
						remove_pilha(pilha_invertida);
					}
					remove_pilha(pilha_invertida);
					insere_pilha(pilha_invertida, subtracao_final_string);
					imprime_pilha(pilha_invertida, 0);
					break;
				} else {
					percorre_pilha = pilha_invertida->cabeca;
				}
				quantidade_operacoes++;
			} else if (percorre_pilha->prox->prox->caractere[0] == '*') {
				float multiplicacao = 0;
				NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
				multiplicacao = atof(percorre_pilha->caractere) * atof(percorre_pilha->prox->caractere);
				PILHAptr pilha_provisoria = inicializa_pilha();
				int j = 0;
				while (pilha_invertida->cabeca->caractere[0] != '*') {
					if (j == 0) {
						insere_pilha(pilha_provisoria, pilha_invertida->cabeca->caractere);
					}
					remove_pilha(pilha_invertida);
					j++;
				}
				remove_pilha(pilha_invertida);
				char multiplicacao_string[30];
				sprintf(multiplicacao_string, "%g", multiplicacao);
				insere_pilha(pilha_invertida, multiplicacao_string);
				if (quantidade_operacoes > 0) {
					NOptr percorre_pilha_provisoria = pilha_provisoria->cabeca;
					while (percorre_pilha_provisoria->prox != NULL) {
						insere_pilha(pilha_invertida, percorre_pilha_provisoria->caractere);
						percorre_pilha_provisoria = percorre_pilha_provisoria->prox;
					}
				}
				if (pilha_invertida->tamanho == 1) {
					imprime_pilha(pilha_invertida, 0);
				}
				if (pilha_invertida->tamanho == 3) {
					char multiplicacao_final_string[30];
					float multiplicacao_final = atof(pilha_invertida->cabeca->caractere) * atof(pilha_invertida->cabeca->prox->caractere);
					sprintf(multiplicacao_final_string, "%g", multiplicacao_final);
					while (pilha_invertida->cabeca->caractere[0] != '*') {
						remove_pilha(pilha_invertida);
					}
					remove_pilha(pilha_invertida);
					insere_pilha(pilha_invertida, multiplicacao_final_string);
					imprime_pilha(pilha_invertida, 0);
					break;
				} else {
					percorre_pilha = pilha_invertida->cabeca;
				}
				quantidade_operacoes++;
			} else if (percorre_pilha->prox->prox->caractere[0] == '/') {
				float divisao = 1;
				NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
				divisao = atof(percorre_pilha->caractere) / atof(percorre_pilha->prox->caractere);
				PILHAptr pilha_provisoria = inicializa_pilha();
				int j = 0;
				while (pilha_invertida->cabeca->caractere[0] != '/') {
					if (j == 0) {
						insere_pilha(pilha_provisoria, pilha_invertida->cabeca->caractere);
					}
					remove_pilha(pilha_invertida);
					j++;
				}
				remove_pilha(pilha_invertida);
				char divisao_string[30];
				sprintf(divisao_string, "%g", divisao);
				insere_pilha(pilha_invertida, divisao_string);
				if (quantidade_operacoes > 0) {
					NOptr percorre_pilha_provisoria = pilha_provisoria->cabeca;
					while (percorre_pilha_provisoria->prox != NULL) {
						insere_pilha(pilha_invertida, percorre_pilha_provisoria->caractere);
						percorre_pilha_provisoria = percorre_pilha_provisoria->prox;
					}
				}
				if (pilha_invertida->tamanho == 1) {
					imprime_pilha(pilha_invertida, 0);
				}
				if (pilha_invertida->tamanho == 3) {
					char divisao_final_string[30];
					float divisao_final = atof(pilha_invertida->cabeca->caractere) / atof(pilha_invertida->cabeca->prox->caractere);
					sprintf(divisao_final_string, "%g", divisao_final);
					while (pilha_invertida->cabeca->caractere[0] != '/') {
						remove_pilha(pilha_invertida);
					}
					remove_pilha(pilha_invertida);
					insere_pilha(pilha_invertida, divisao_final_string);
					imprime_pilha(pilha_invertida, 0);
					break;
				} else {
					percorre_pilha = pilha_invertida->cabeca;
				}
				quantidade_operacoes++;
			}
//			imprime_pilha(pilha_invertida, 0);
			//percorre_pilha = pilha_invertida->cabeca;
		}
		percorre_pilha = percorre_pilha->prox;
		printf("Passou por aqui");
	}
}
