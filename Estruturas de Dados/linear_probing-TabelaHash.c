#include <stdio.h>
#include <stdlib.h>

typedef struct tabela_hash {
	int* vetor;
	int tamanho_tabela;
}TABELA_HASH;

typedef TABELA_HASH* TABELA_HASHptr;

TABELA_HASHptr inicializa_tabela(int tam_vetor, int* vetor) {
	TABELA_HASHptr nova_tabela = (TABELA_HASHptr) malloc(sizeof(TABELA_HASH));
	int i;
	int tamanho_tabela = 0;
	for (i = 0; i < tam_vetor; i++) {
		vetor[i] = -1;
		tamanho_tabela++;
	}
	nova_tabela->vetor = vetor;
	nova_tabela->tamanho_tabela = tamanho_tabela;
	return nova_tabela;
}

void imprime_tabela(TABELA_HASHptr tabela, int tam_vetor) {
	int i;
	for (i = 0; i < tam_vetor; i++) {
		if (tabela->vetor[i] == -1) {
			printf("%i null\n", i);
		} else {
			printf("%i %i\n", i, tabela->vetor[i]);	
		}
	}
}

int h(int k, int m) {
	return k % m;
}

int main(void) {
	int tam_vetor;
	scanf("%i", &tam_vetor);
	int vetor[tam_vetor], numero;
	TABELA_HASHptr tabela = inicializa_tabela(tam_vetor, vetor);
	while (1) {
		scanf("%i", &numero);
		if (numero == 0) {
			break;
		}
		int indice_insercao = h(numero, tam_vetor);
		while (tabela->vetor[indice_insercao] != -1) {
			indice_insercao++;
			if (indice_insercao == tam_vetor) {
				indice_insercao = 0;
			}
		}
		tabela->vetor[indice_insercao] = numero;
	}
	imprime_tabela(tabela, tam_vetor);
	return 0;
}
