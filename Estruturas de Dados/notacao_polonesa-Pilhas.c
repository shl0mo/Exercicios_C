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
	int j = 0;
	while (percorre_pilha->prox != NULL) {
		if (percorre_pilha->prox->prox != NULL) {
			if (percorre_pilha->prox->prox->caractere[0] == '#' || percorre_pilha->prox->caractere[0] == '#') {
				float soma = 0;
				NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
				soma = atof(percorre_pilha->caractere) + atof(percorre_pilha->prox->caractere);
				PILHAptr pilha_provisoria = inicializa_pilha();
				int j = 0;
				while (pilha_invertida->cabeca->caractere[0] != '#') {
					if (j == 0) {
						insere_pilha(pilha_provisoria, pilha_invertida->cabeca->caractere);
					}
					remove_pilha(pilha_invertida);
					j++;
				}
				if (pilha_invertida->tamanho > 1) {
					remove_pilha(pilha_invertida);	
				}
				char soma_string[30];
				sprintf(soma_string, "%g", soma);
				insere_pilha(pilha_invertida, soma_string);
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
				if (pilha_invertida->tamanho == 2 && percorre_pilha->prox->prox->caractere[0] == '#') {
					printf("%s", pilha_invertida->cabeca->caractere);
				}
				int tem_sinal = 0;
				NOptr percorre_pilha_invertida = pilha_invertida->cabeca;
				while (percorre_pilha_invertida->prox != NULL) {
					if (percorre_pilha_invertida->caractere[0] == '#') {
						tem_sinal = 1;
					}
					percorre_pilha_invertida = percorre_pilha_invertida->prox;
				}
				if (tem_sinal == 1) {
					if (pilha_invertida->tamanho == 3) {
						char soma_final_string[30];
						float soma_final = 0;
						soma_final = atof(pilha_invertida->cabeca->caractere) + atof(pilha_invertida->cabeca->prox->caractere);
						sprintf(soma_final_string, "%g", soma_final);
						while (pilha_invertida->cabeca->caractere[0] != '#') {
							remove_pilha(pilha_invertida);
						}
						remove_pilha(pilha_invertida);
						insere_pilha(pilha_invertida, soma_final_string);
						imprime_pilha(pilha_invertida, 0);					
						break;
					} else {
						percorre_pilha = pilha_invertida->cabeca;
					}
				} else {
					percorre_pilha = pilha_invertida->cabeca;
				}
				quantidade_operacoes++;
			} else if (percorre_pilha->prox->prox->caractere[0] == '-' || percorre_pilha->prox->caractere[0] == '-') {
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
				if (pilha_invertida->tamanho > 1) {
					remove_pilha(pilha_invertida);	
				}
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
				if (pilha_invertida->tamanho == 2 && percorre_pilha->prox->prox->caractere[0] == '-') {
					printf("%s", pilha_invertida->cabeca->caractere);
				}
				int tem_sinal = 0;
				NOptr percorre_pilha_invertida = pilha_invertida->cabeca;
				while (percorre_pilha_invertida) {
					if (percorre_pilha_invertida->caractere[0] == '-') {
						tem_sinal = 1;
					}
					percorre_pilha_invertida = percorre_pilha_invertida->prox;
				}
				if (tem_sinal == 1) {
					if (pilha_invertida->tamanho == 3) {
						char subtracao_final_string[30];
						float subtracao_final = atof(pilha_invertida->cabeca->caractere) - atof(pilha_invertida->cabeca->prox->caractere);
						sprintf(subtracao_final_string, "%g", subtracao_final);
						while (pilha_invertida->cabeca->caractere[0] != '-') {
							printf("%s", pilha_invertida->cabeca->caractere);
							remove_pilha(pilha_invertida);
						}
						remove_pilha(pilha_invertida);
						insere_pilha(pilha_invertida, subtracao_final_string);
						imprime_pilha(pilha_invertida, 0);
						break;
					} else {
						percorre_pilha = pilha_invertida->cabeca;
					}	
				} else {
					percorre_pilha = pilha_invertida->cabeca;
				}
				quantidade_operacoes++;
			} else if (percorre_pilha->prox->prox->caractere[0] == '*' || percorre_pilha->prox->caractere[0] == '*') {
				float multiplicacao = 1;
				NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
				multiplicacao = atof(percorre_pilha->caractere) * atof(percorre_pilha->prox->caractere);
				PILHAptr pilha_provisoria = inicializa_pilha();
				NOptr percorre_pilha_invertida_1 = pilha_invertida->cabeca;
				while (percorre_pilha_invertida_1->caractere[0] != '*') {
					insere_pilha(pilha_provisoria, percorre_pilha_invertida_1->caractere);
					percorre_pilha_invertida_1 = percorre_pilha_invertida_1->prox;
				}
				while (pilha_invertida->cabeca->caractere[0] != '*') {
					remove_pilha(pilha_invertida);
				}
				if (pilha_invertida->tamanho > 1) {
					remove_pilha(pilha_invertida);	
				}
				char multiplicacao_string[30];
				sprintf(multiplicacao_string, "%g", multiplicacao);
				if (percorre_pilha->prox->prox->caractere[0] == '*') {
					insere_pilha(pilha_invertida, multiplicacao_string);	
				}
				if (quantidade_operacoes > 0) {
					NOptr percorre_pilha_provisoria = pilha_provisoria->cabeca;
					while (percorre_pilha_provisoria) {
						insere_pilha(pilha_invertida, percorre_pilha_provisoria->caractere);
						percorre_pilha_provisoria = percorre_pilha_provisoria->prox;
					}
				}
				if (pilha_invertida->tamanho == 1) {
					imprime_pilha(pilha_invertida, 0);
				}
				if (pilha_invertida->tamanho == 2 && percorre_pilha->prox->prox->caractere[0] == '*') {
					printf("%s", pilha_invertida->cabeca->caractere);
				}
				int tem_sinal = 0;
				NOptr percorre_pilha_invertida = pilha_invertida->cabeca;
				while (percorre_pilha_invertida->prox != NULL) {
					if (percorre_pilha_invertida->caractere[0] == '*') {
						tem_sinal = 1;
					}
					percorre_pilha_invertida = percorre_pilha_invertida->prox;
				}
				if (tem_sinal == 1) {
					if (pilha_invertida->tamanho == 4) {
						char multiplicacao_final_string[30];
						float multiplicacao_final = 0;
						multiplicacao_final = atof(pilha_invertida->cabeca->prox->caractere) * atof(pilha_invertida->cabeca->prox->prox->caractere);
						NOptr percorre_pilha_invertida = pilha_invertida->cabeca;
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
				} else {
					percorre_pilha = pilha_invertida->cabeca;
				}
				quantidade_operacoes++;
			} else if (percorre_pilha->prox->prox->caractere[0] == '/' || percorre_pilha->prox->caractere[0] == '/') {
				float divisao = 1;
				NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
				divisao = atof(percorre_pilha->caractere) / atof(percorre_pilha->prox->caractere);
				PILHAptr pilha_provisoria = inicializa_pilha();
				while (pilha_invertida->cabeca->caractere[0] != '/') {
					if (j == 0) {
						insere_pilha(pilha_provisoria, pilha_invertida->cabeca->caractere);
					}
					remove_pilha(pilha_invertida);
					j++;
				}
				if (pilha_invertida->tamanho > 1) {
					remove_pilha(pilha_invertida);	
				}
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
				if (pilha_invertida->tamanho == 2 && percorre_pilha->prox->prox->caractere[0] == '/') {
					printf("%s", pilha_invertida->cabeca->caractere);
				}
				int tem_sinal = 0;
				NOptr percorre_pilha_invertida = pilha_invertida->cabeca;
				while (percorre_pilha_invertida) {
					if (percorre_pilha_invertida->caractere[0] == '/') {
						tem_sinal = 1;
					}
					percorre_pilha_invertida = percorre_pilha_invertida->prox;
				}
				if (tem_sinal == 1) {
					if (pilha_invertida->tamanho == 3) {
						char divisao_final_string[30];
						float divisao_final = atof(pilha_invertida->cabeca->caractere) / atof(pilha_invertida->cabeca->prox->caractere);
						printf("Divisao final: %f, %f", atof(pilha_invertida->cabeca->caractere), atof(pilha_invertida->cabeca->prox->caractere));
						sprintf(divisao_final_string, "%g", divisao_final);
						while (pilha_invertida->cabeca->caractere[0] != '/') {
							remove_pilha(pilha_invertida);
						}
						remove_pilha(pilha_invertida);
						insere_pilha(pilha_invertida, divisao_final_string);
						printf("Imprimindo aqui\n");
						imprime_pilha(pilha_invertida, 0);
						break;
					} else {
						percorre_pilha = pilha_invertida->cabeca;
					}
				} else {
					percorre_pilha = pilha_invertida->cabeca;
				}
				quantidade_operacoes++;
			}
//			imprime_pilha(pilha_invertida, 0);
			//percorre_pilha = pilha_invertida->cabeca;
		}
		percorre_pilha = percorre_pilha->prox;
	}
}
