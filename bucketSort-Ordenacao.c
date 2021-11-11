#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vetor {
	int chave;
	struct vetor *prox;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor(int numero_chaves) {
	VETORptr novo_vetor = (VETORptr) malloc(numero_chaves * sizeof(VETOR));
	int i = 0;
	for (i = 0; i < numero_chaves; i++) {
		novo_vetor[i].chave = -1;
		novo_vetor[i].prox = NULL;
	}
	return novo_vetor;
}

void insere_vetor(VETORptr vetor, int indice, int chave) {
	vetor[indice].chave = chave;
}

void insere_lista_encadeada(VETORptr no, int chave) {
	VETORptr percorre_no = no;
	while (percorre_no->prox != NULL) {
		percorre_no = percorre_no->prox;
	}
	VETORptr novo_no = (VETORptr) malloc(sizeof(VETOR));
	novo_no->chave = chave;
	novo_no->prox = NULL;
	percorre_no->prox = novo_no;
}

void imprime_no(VETORptr no) {
	VETORptr percorre_no = no;
	while (percorre_no) {
		printf("%i ",  percorre_no->chave);
		percorre_no = percorre_no->prox;
	}
	printf("\n");
}

void imprime_vetor(VETORptr vetor, int numero_chaves) {
	int i;
	for (i = 0; i < numero_chaves; i++) {
		printf("%i ", i);
		imprime_no(&vetor[i]);
	}
}

void selection_sort(VETORptr vetor) {
	if (vetor->prox != NULL) {
		VETORptr posicao_insercao = vetor;
		VETORptr p_pos_insercao = posicao_insercao;
		while (posicao_insercao) {
			VETORptr p_vetor = posicao_insercao;
			while (p_vetor) {
				int tem_menor = 0;
				VETORptr p_vetor_inicio = vetor;
				while (p_vetor_inicio) {
					if (p_vetor_inicio->chave < p_vetor->chave) {
						tem_menor = 1;
					}
					p_vetor_inicio = p_vetor_inicio->prox;
				}
				if (tem_menor == 0) {
					VETORptr aux = posicao_insercao;
					int aux_chave = posicao_insercao->chave;
					posicao_insercao->chave = p_vetor->chave;
					p_vetor->chave = aux_chave;
					posicao_insercao = posicao_insercao->prox;
				}
				p_vetor = p_vetor->prox;
			}
			posicao_insercao = posicao_insercao->prox;
		}		
	}
}


int define_indice(int chave, int numero_baldes, int valor_maximo) {
	return floor((chave*numero_baldes)/(valor_maximo + 1));
}


int main (void) {
	int numero_baldes, numero_chaves, valor_maximo, i;
	scanf("%i", &numero_baldes);
	scanf("%i", &numero_chaves);
	scanf("%i", &valor_maximo);
	VETORptr vetor = inicializa_vetor(numero_chaves);
	i = 0;
	while (i < numero_chaves) {
		int chave;
		scanf("%i", &chave);
		int indice = define_indice(chave, numero_baldes, valor_maximo);
		if (vetor[indice].chave == -1) {
			insere_vetor(vetor, indice, chave);
		} else {
			insere_lista_encadeada(&vetor[indice], chave);
		}
		i++;
	}
	for (i = 0; i < numero_chaves; i++) {
		selection_sort(&vetor[i]);
	}
	imprime_vetor(vetor, numero_chaves);
}
