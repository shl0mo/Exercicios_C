#include <stdio.h>
#include <stdlib.h>

typedef struct vetor {
	int indice;
	int valor;
	char nome[20];
	struct vetor *prox;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor() {
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	novo_vetor->indice = -1;
	novo_vetor->valor = -1;
	novo_vetor->prox = NULL;
	return novo_vetor;
}

int insere_vetor(VETORptr vetor, int indice, int valor, char nome[20]) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor->prox != NULL) {
		percorre_vetor = percorre_vetor->prox;
	}
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	novo_vetor->indice = indice;
	novo_vetor->valor = valor;
	int i;
	for (i = 0; i < 20; i++) {
		novo_vetor->nome[i] = nome[i];
	}
	novo_vetor->prox = NULL;
	percorre_vetor->prox = novo_vetor;
	return 1;
}

void imprime_vetor(VETORptr vetor, int indice) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor) {
		printf("%i %i %s\n", indice, percorre_vetor->valor, percorre_vetor->nome);
		percorre_vetor = percorre_vetor->prox;
	}
}

typedef struct tabela_hash {
	VETORptr* vetor;
	int tamanho_tabela;
}TABELA_HASH;

typedef TABELA_HASH* TABELA_HASHptr;

TABELA_HASHptr inicializa_tabela(int tam_vetor) {
	TABELA_HASHptr nova_tabela = (TABELA_HASHptr) malloc(sizeof(TABELA_HASH));
	return nova_tabela;
}

int h(int k, int m) {
	return k % m;
}

int main(void) {
	int tam_vetor, numero;;
	char nome[20];
	scanf("%i", &tam_vetor);
	VETORptr vetor[tam_vetor];
	int i;
	for (i = 0; i < tam_vetor; i++) {
		vetor[i] = NULL;
	}
	TABELA_HASHptr tabela = inicializa_tabela(tam_vetor);
	tabela->vetor = vetor;
	VETORptr buscados = inicializa_vetor();
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			break;
		}
		scanf("%s", &nome);
		int indice_insercao = h(numero, tam_vetor);
		if (tabela->vetor[indice_insercao] == NULL) {
			VETORptr vetor_adicionado = inicializa_vetor();
			insere_vetor(vetor_adicionado, indice_insercao, numero, nome);
			tabela->vetor[indice_insercao] = vetor_adicionado->prox;
		} else {
			insere_vetor(tabela->vetor[indice_insercao], indice_insercao, numero, nome);
		}
	}
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			break;
		}
		char string[10];
		insere_vetor(buscados, 0, numero, string);
	}
	for (i = 0; i < tam_vetor; i++) {
		if (tabela->vetor[i] != NULL) {
			imprime_vetor(tabela->vetor[i], i);
		} else {
			printf("%i null null\n", i);
		}
	}
	printf("- - -\n");
	VETORptr percorre_buscados = buscados->prox;
	while (percorre_buscados) {
		int encontrado = 0;
		int indice_busca = h(percorre_buscados->valor, tam_vetor);
		if (tabela->vetor[indice_busca] != NULL) {
			VETORptr percorre_lista = tabela->vetor[indice_busca];
			while (percorre_lista) {
				if (percorre_lista->valor == percorre_buscados->valor) {
					printf("%i %i %s\n", percorre_lista->indice, percorre_lista->valor, percorre_lista->nome);
					encontrado = 1;
					break;
				}
				percorre_lista = percorre_lista->prox;
			}
		}
		if (encontrado == 0) {
			printf("%i not found\n", percorre_buscados->valor);
		}
		percorre_buscados = percorre_buscados->prox;
	}
	return 0;
}
