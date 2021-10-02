#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct no {
	char caractere;
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

void insere_pilha(PILHAptr pilha, char caractere) {
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	novo_no->caractere = caractere;
	printf("Caractere inserido: %c ", novo_no->caractere);
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
	int j = 0;
	while (percorre_pilha) {
		if (j == pilha->tamanho) {
			break;
		}
		printf("%c ", percorre_pilha->caractere);
		percorre_pilha = percorre_pilha->prox;
		j++;
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

typedef struct vetor {
	PILHAptr pilha;
	int tem_caractere;
	struct vetor * prox;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor() {
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	novo_vetor->tem_caractere = -2;
	novo_vetor->prox = NULL;
	return novo_vetor;
}

void insere_vetor(VETORptr vetor, PILHAptr pilha) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor->prox != NULL) {
		percorre_vetor = percorre_vetor->prox;
	}
	VETORptr novo_elemento = (VETORptr) malloc(sizeof(VETOR));
	novo_elemento->tem_caractere = -1;
	novo_elemento->pilha = pilha;
	novo_elemento->prox = NULL;
	percorre_vetor->prox = novo_elemento;
}

insere_tem_caractere(VETORptr vetor, int tem_caractere) {
	VETORptr percorre_vetor = vetor->prox;
	while (percorre_vetor) {
		if (percorre_vetor->tem_caractere == -1) {
			percorre_vetor->tem_caractere = tem_caractere;
		}
		percorre_vetor = percorre_vetor->prox;
	}
}

remove_caractere_pilha(PILHAptr pilha, char caractere) {
	printf("Antes do problema");
	if (pilha->tamanho > 0) {
		printf("Problema 1");
		NOptr percorre_pilha = pilha->cabeca;
		printf("Problema 2");
		PILHAptr pilha_provisoria = inicializa_pilha();
		printf("Problema 3");
		int tamanho_pilha = pilha->tamanho;
		int i = 0;
		while (percorre_pilha->caractere != caractere) {
			printf("Problema 4");
			if (i == tamanho_pilha) {
				break;
			}
			insere_pilha(pilha_provisoria, percorre_pilha->caractere);
			remove_pilha(pilha);
			percorre_pilha = percorre_pilha->prox;
			i++;
		}
		remove_pilha(pilha);
		NOptr percorre_pilha_provisoria = pilha_provisoria->cabeca->prox;
		if (pilha->tamanho > 2) {
			printf("Problema 5");
			while (percorre_pilha_provisoria) {
				printf("Problema 6");
				insere_pilha(pilha, percorre_pilha_provisoria->caractere);
				percorre_pilha_provisoria = percorre_pilha_provisoria->prox;
			}
		}
		printf("Problema 7");
	}
}

imprime_tem_caractere(VETORptr vetor) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor) {
		printf("%i ", percorre_vetor->tem_caractere);
		/*if (percorre_vetor->tem_caractere) {
			printf("SIM");
		} else {
			printf("NAO");
		}*/
		percorre_vetor = percorre_vetor->prox;
	}
}

void imprime_vetor(VETORptr vetor) {
	VETORptr percorre_vetor = vetor->prox;
	while (percorre_vetor) {
		imprime_pilha(percorre_vetor->pilha, 0);
		printf("\n");
		percorre_vetor = percorre_vetor->prox;
	}
}

void verifica_pilha(VETORptr vetor) {
	printf("\n");
	VETORptr percorre_vetor = vetor->prox;
	while (percorre_vetor) {
		PILHAptr pilha_invertida = inverte_pilha(percorre_vetor->pilha);
		printf("Antes de tudo: ");
		imprime_pilha(pilha_invertida, 1);
		NOptr percorre_pilha = pilha_invertida->cabeca->prox;
		int tamanho_pilha = percorre_vetor->pilha->tamanho;
		int i = 0;
		int tem_caractere = 0;
		while (percorre_pilha) {
			if (i == tamanho_pilha || pilha_invertida->tamanho == 0) {
				break;
			}
			char caractere = percorre_pilha->caractere;
			//printf("Caractere: %c", caractere);
			NOptr percorre_pilha_inicio = pilha_invertida->cabeca;
			int j = 0;
			while (1){
				printf("ANTES DO PROBLEMA: %c", caractere);
				printf("\n");
				printf("Tamanho antes do problema: %i", pilha_invertida->tamanho);
				printf("\n");
				imprime_pilha(pilha_invertida, 0);
				printf("\n");
				if (j == tamanho_pilha || pilha_invertida->tamanho == 0) {
					break;
				}
				if (caractere == '(') {
					if (percorre_pilha_inicio->caractere == ')') {
						remove_pilha(pilha_invertida);
						remove_caractere_pilha(pilha_invertida, ')');
						break;
					}
				} else if (caractere == '[') {
					if (percorre_pilha_inicio->caractere == ']') {
						remove_pilha(pilha_invertida);
						remove_caractere_pilha(pilha_invertida, ']');
						break;
					}
				} else if (caractere == '{') {
					if (percorre_pilha_inicio->caractere == '}') {
						remove_pilha(pilha_invertida);
						remove_caractere_pilha(pilha_invertida, '}');
						break;
					}
				}
				j++;
				percorre_pilha_inicio = percorre_pilha_inicio->prox;
			}
			percorre_pilha = percorre_pilha->prox;
			i++;
		}
		//imprime_pilha(pilha_invertida, 0);
		printf("Tamanho: %i %i", pilha_invertida->tamanho, pilha_invertida->tamanho);
		if (pilha_invertida->tamanho <= 0) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
		percorre_vetor = percorre_vetor->prox;
	}
}

int main(void) {
	VETORptr vetor_pilhas = inicializa_vetor();
	while (1) {
		PILHAptr pilha = inicializa_pilha();
		char numero_operador[50];
		scanf("%s", &numero_operador);
		if (numero_operador[0] == '#' && numero_operador[1] == '#' && numero_operador[2] == '#') {
			break;
		}
		int i = 0;
		while (numero_operador[i] != '\0') {
			insere_pilha(pilha, numero_operador[i]);
			i++;
		}
		printf("AANTES ANTESS DE TUDO: \n");
		imprime_pilha(pilha, 0);
		printf("\n\n");
		insere_vetor(vetor_pilhas, pilha);
	}
	//imprime_vetor(vetor_pilhas);
	verifica_pilha(vetor_pilhas);
}
