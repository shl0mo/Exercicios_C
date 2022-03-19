#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	char caractere[50];
	int qtde_caracteres;
	struct no *prox;
}NO;

typedef NO* NOptr;

typedef struct pilha {
	int tamanho;
	NOptr cabeca;
}PILHA;

typedef PILHA* PILHAptr;

PILHAptr inicializa_pilha () {
	PILHAptr nova_pilha = (PILHAptr) malloc(sizeof(PILHAptr));
	nova_pilha->tamanho = 0;
	nova_pilha->cabeca = NULL;
	return nova_pilha;
}

void insere_pilha(PILHAptr pilha, char caractere[50], int qtde_caracteres) {
	NOptr novo_no = (NOptr) malloc(sizeof(NO));
	int i = 0;
	int j = 0;
	int passou_espaco = 0;
	while (caractere[i] != '\0') {
		if (caractere[i] == ' ') {
			passou_espaco = 1;
		}
		if (passou_espaco == 1) {
			novo_no->caractere[j] = caractere[i];
			j++;
		}
		i++;
	}
	novo_no->qtde_caracteres = qtde_caracteres;
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

int imprime_pilha(NOptr no, int tipo_impressao) {
	NOptr percorre_no = no;
	while (percorre_no) {
		int qtde_caracteres = percorre_no->qtde_caracteres;
		int i = 1;
		while (i < qtde_caracteres) {
			printf("%c", percorre_no->caractere[i]);
			i++;
		}
		printf("\n");
		if (tipo_impressao == 1) {
			break;
		} else {
			percorre_no = percorre_no->prox;	
		}
	}
}

typedef struct vetor {
	char acao;
	struct vetor * prox;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor() {
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	novo_vetor->prox = NULL;
	return novo_vetor;
}

void insere_vetor(VETORptr vetor, char acao) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor->prox != NULL) {
		percorre_vetor = percorre_vetor->prox;
	}
	VETORptr novo_elemento = (VETORptr) malloc(sizeof(VETOR));
	novo_elemento->acao = acao;
	novo_elemento->prox = NULL;
	percorre_vetor->prox = novo_elemento;
}


int main(void) {
	PILHAptr pilha = inicializa_pilha();
	PILHAptr pilha_impressao = inicializa_pilha();
	VETORptr vetor_acoes = inicializa_vetor();
	while (1) {
		char acao[50];
		scanf("%[^\n]", &acao);
		if (acao[0] == 'S') {
			break;
		}
		int qtde_caracteres = 0;
		while (acao[qtde_caracteres] != '\0') {
			qtde_caracteres++;
		}
		if (acao[0] == 'A') {
			insere_pilha(pilha, acao, qtde_caracteres);
			NOptr percorre_pilha_impressao = pilha_impressao->cabeca;
			while (percorre_pilha_impressao) {
				remove_pilha(pilha_impressao);
				percorre_pilha_impressao = percorre_pilha_impressao->prox;
			}
			NOptr percorre_pilha = pilha->cabeca;
			while (percorre_pilha) {
				insere_pilha(pilha_impressao, percorre_pilha->caractere, percorre_pilha->qtde_caracteres);
				percorre_pilha = percorre_pilha->prox;
			}
		}
		if (acao[0] == 'Q' || acao[0] == 'D' || acao[0] == 'L' || acao[0] == 'P') {
			insere_vetor(vetor_acoes, acao[0]);
		}
		scanf("%*[^\n]");
		scanf("%*c");
	}
	VETORptr percorre_vetor_acoes = vetor_acoes;
	while (percorre_vetor_acoes) {
		if (percorre_vetor_acoes->acao == 'Q') {
			printf("%i\n", pilha->tamanho);
		} else if (percorre_vetor_acoes->acao == 'D') {
			remove_pilha(pilha_impressao);
		} else if (percorre_vetor_acoes->acao == 'L') {
			imprime_pilha(pilha_impressao->cabeca, 0);
		} else if (percorre_vetor_acoes->acao == 'P') {
			imprime_pilha(pilha_impressao->cabeca, 1);
		}
		percorre_vetor_acoes = percorre_vetor_acoes->prox;
	}
	return 0;
}
