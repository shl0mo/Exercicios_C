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

int imprime_no(VETORptr no, int maior_valor) {
	VETORptr percorre_no = no;
	int imprimiu_maior = 0;
	while (percorre_no) {
		printf("%i ",  percorre_no->chave);
		if (percorre_no->chave == maior_valor) {
			imprimiu_maior = 1;
		}
		percorre_no = percorre_no->prox;
	}
	printf("\n");
	return imprimiu_maior;
}

void imprime_vetor(VETORptr vetor, int numero_chaves, int maior_valor) {
	int i;
	int imprimiu_maior = 0;
	for (i = 0; i < numero_chaves; i++) {
		printf("%i ", i);
		if (vetor[i].chave != -1) {
			imprimiu_maior = imprime_no(&vetor[i], maior_valor);
			if (imprimiu_maior) {
				break;
			}
		} else {
			printf("NULL\n");
		}
		
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
				VETORptr p_vetor_inicio = posicao_insercao;
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
		}
	}
}


int define_indice(int chave, int numero_baldes, int valor_maximo) {
	return floor((chave*numero_baldes)/(valor_maximo + 1));
}


int main (void) {
	int numero_baldes, numero_chaves, valor_maximo, i;
	int maior_valor = 0;
	scanf("%i", &numero_baldes);
	scanf("%i", &numero_chaves);
	scanf("%i", &valor_maximo);
	VETORptr vetor = inicializa_vetor(numero_chaves);
	i = 0;
	while (i < numero_chaves) {
		int chave;
		scanf("%i", &chave);
		if (chave > maior_valor) {
			maior_valor = chave;
		}
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
	int vetor_ordenado[numero_chaves];
	int j = 0;
	for (i = 0; i < numero_chaves; i++) {
		if (vetor[i].chave != -1) {
			VETORptr p_vetor = &vetor[i];
			while (p_vetor) {
				vetor_ordenado[j] = p_vetor->chave;
				j++;
				p_vetor = p_vetor->prox;
			}
		}
	}
	imprime_vetor(vetor, numero_chaves, maior_valor);
	for (i = 0; i < numero_chaves; i++) {
		printf("%i ", vetor_ordenado[i]);
	}
}
