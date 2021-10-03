#include <stdio.h>
#include <stdlib.h>

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

typedef struct vetor {
	PILHAptr pilha;
	int status;
	struct vetor * prox;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor() {
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	novo_vetor->prox = NULL;
	return novo_vetor;
}

void insere_vetor(VETORptr vetor, PILHAptr pilha, int status) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor->prox != NULL) {
		percorre_vetor = percorre_vetor->prox;
	}
	VETORptr novo_elemento = (VETORptr) malloc(sizeof(VETOR));
	novo_elemento->pilha = pilha;
	novo_elemento->status = status;
	novo_elemento->prox = NULL;
	percorre_vetor->prox = novo_elemento;
}

PILHAptr inicializa_pilha () {
	PILHAptr nova_pilha = (PILHAptr) malloc(sizeof(PILHAptr));
	nova_pilha->tamanho = 0;
	nova_pilha->cabeca = NULL;
	return nova_pilha;
}

void insere_pilha(PILHAptr pilha, char caractere) {
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	novo_no->caractere = caractere;
	novo_no->prox = pilha->cabeca;
	pilha->cabeca = novo_no;
	pilha->tamanho++;
}

int remove_pilha(PILHAptr pilha) {
	if (pilha->tamanho == 0) {
		return 0;
	} else {
		NOptr cabeca = pilha->cabeca;
		pilha->cabeca = pilha->cabeca->prox;
		free(cabeca);
		pilha->tamanho--;
		return 1;
	}
}

void desempilha_remove(PILHAptr pilha, char caractere) {
	NOptr percorre_pilha = pilha->cabeca;
	PILHAptr pilha_provisoria = inicializa_pilha();
	while (percorre_pilha->caractere != caractere) {
		insere_pilha(pilha_provisoria, percorre_pilha->caractere);
		percorre_pilha = percorre_pilha->prox;
		remove_pilha(pilha);
	}
	remove_pilha(pilha);
	NOptr percorre_provisoria = pilha_provisoria->cabeca;
	while (percorre_provisoria) {
		insere_pilha(pilha, percorre_provisoria->caractere);
		percorre_provisoria = percorre_provisoria->prox;
	}
}

int imprime_pilha(NOptr no) {
	if (no == NULL) {
		return 1;
	}
	printf("%c ", no->caractere);
	imprime_pilha(no->prox);
}

int disposicao_caracteres(PILHAptr pilha) {
	PILHAptr pilha_caracteres = inicializa_pilha();
	VETORptr vetor_status = inicializa_vetor();
	NOptr percorre_pilha = pilha->cabeca;
	int status = 1;
	while (percorre_pilha) {
		char caractere;
		if (percorre_pilha->caractere == ')' || percorre_pilha->caractere == ']' || percorre_pilha->caractere == '}') {
			caractere = percorre_pilha->caractere;
			insere_pilha(pilha_caracteres, caractere);
		}
		if (caractere == ')') {
			if (percorre_pilha->caractere == '[' || percorre_pilha->caractere == '{') {
				status = 0;
				return status;
			} else if (percorre_pilha->caractere == '(') {
				remove_pilha(pilha_caracteres);
				if (pilha_caracteres->tamanho > 0) {
					caractere = pilha_caracteres->cabeca->caractere;	
				}
			}
		} else if (caractere == ']') {
			if (percorre_pilha->caractere == '(' || percorre_pilha->caractere == '{') {
				imprime_pilha(pilha_caracteres->cabeca);
				status = 0;
				return status;
			} else if (percorre_pilha->caractere == '[') {
				remove_pilha(pilha_caracteres);
				if (pilha_caracteres->tamanho > 0) {
					caractere = pilha_caracteres->cabeca->caractere;	
				}
			}
		} else if (caractere == '}') {
			if (percorre_pilha->caractere == '(' || percorre_pilha->caractere == '[') {
				status = 0;
				return status;
			} else if (percorre_pilha->caractere == '{') {
				remove_pilha(pilha_caracteres);
				if (pilha_caracteres->tamanho > 0) {
					caractere = pilha_caracteres->cabeca->caractere;	
				}
			}
		}
		percorre_pilha = percorre_pilha->prox;
	}
	return status;
}

int main(void) {
	PILHAptr pilha = inicializa_pilha();
	PILHAptr pilha_invertida = inicializa_pilha();
	PILHAptr pilha_verificacao = inicializa_pilha();
	char string[50];
	while (1) {
		scanf("%s", &string);
		if (string[0] == '#' && string[1] == '#' && string[2] == '#') {
			break;
		}
		int i = 0;
		int tamanho_pilha = 0;
		while (string[i] != '\0') {
			if (string[i] != ')' && string[i] != ']' && string[i] != '}') {
				insere_pilha(pilha, string[i]);
			}
			tamanho_pilha++;
			i++;
		}
		i = 0;
		while (string[i] != '\0') {
			insere_pilha(pilha_verificacao, string[i]);
			i++;
		}
		printf("\n");
		imprime_pilha(pilha_verificacao->cabeca);
		printf("\n");
		int verificacao = disposicao_caracteres(pilha_verificacao);
		printf("Verificacao: %i", verificacao);
		return 0;
		imprime_pilha(pilha->cabeca);
		i = 0;
		while (string[i] != '\0') {
			if (string[i] == ')') {
				desempilha_remove(pilha, '(');
			} else if (string[i] == ']') {
				desempilha_remove(pilha, '[');
			} else if (string[i] == '}') {
				desempilha_remove(pilha, '{');
			}
			if (pilha->tamanho == 0 && i != (tamanho_pilha - 1)) {
				printf("\nNAo\n");
				break;
			} else if (pilha->tamanho == 0 && i == (tamanho_pilha - 1)) {
				printf("\nSIM\n");
			}
			i++;
		}
		printf("Tamanho pilha: %i", pilha->tamanho);
	}
	//printf("\n");
	/*NOptr percorre_pilha = pilha->cabeca;
	while (pilha) {
		/*if (percorre_pilha->caractere != ')' && percorre_pilha->caractere != ']' && percorre_pilha->caractere != '}') {
			insere_pilha(pilha_invertida, percorre_pilha->caractere);
		}
		printf("%c ", percorre_pilha->caractere);
		if (percorre_pilha->caractere == ')') {
			desempilha_remove(pilha, ')');
			desempilha_remove(pilha, '(');
		} else if (percorre_pilha->caractere == ']') {
			desempilha_remove(pilha, ']');
			desempilha_remove(pilha, '[');
		} else if (percorre_pilha->caractere == '}') {
			desempilha_remove(pilha, '}');
			desempilha_remove(pilha, '{');
		}
		percorre_pilha = pilha->cabeca;
	}*/
	/*percorre_pilha = pilha->cabeca;
	while (percorre_pilha) {
		printf("\n");
		imprime_pilha(pilha_invertida->cabeca);
		if (pilha_invertida->tamanho > 0) {
			if (percorre_pilha->caractere == ')') {
				desempilha_remove(pilha_invertida, '(');
			} else if (percorre_pilha->caractere == ']') {
				desempilha_remove(pilha_invertida, '[');
			} else if (percorre_pilha->caractere == '}') {
				desempilha_remove(pilha_invertida, '{');
			}	
		}
		percorre_pilha = percorre_pilha->prox;
	}*/
	//imprime_pilha(pilha->cabeca);
}
