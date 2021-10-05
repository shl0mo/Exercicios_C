#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int T;
	int tempo_execucao;
	int passou;
	char n[80];
	struct no *prox, *ant;
}NO;

typedef NO* NOptr;

typedef struct lista_circular {
	int tamanho;
	NOptr cabeca;
}LISTA_CIRCULAR;

typedef LISTA_CIRCULAR* LISTA_CIRCULARptr;

LISTA_CIRCULARptr inicializa_lista() {
	LISTA_CIRCULARptr nova_lista = (LISTA_CIRCULARptr) malloc(sizeof(LISTA_CIRCULAR));
	NOptr no_lista = (NOptr) malloc(sizeof(NO));
	no_lista->ant = no_lista;
	no_lista->prox = no_lista;
	nova_lista->cabeca = no_lista;
	nova_lista->tamanho = 0;
	return nova_lista;
}

int insere_lista(LISTA_CIRCULARptr lista, int T, char n[80], int inserir_tempo, int tempo_execucao) {
	/*NOptr nova_lista = (NOptr) malloc(sizeof(NO));
	nova_lista->T = T;
	int i = 0;
	for (i = 0; i < 80; i++) {
		nova_lista->n[i] = n[i];
	}
	nova_lista->passou = 0;
	NOptr percorre_lista = lista->cabeca;
	while (percorre_lista->prox != lista->cabeca) {
		if (T <= percorre_lista->T) {
			nova_lista->prox = percorre_lista;
			nova_lista->ant = percorre_lista->ant;
			percorre_lista->ant = nova_lista;
			lista->tamanho++;
			return 1;
		}
		percorre_lista = percorre_lista->prox;
	}
	nova_lista->ant = percorre_lista;
	nova_lista->prox = lista->cabeca;
	percorre_lista->prox = nova_lista;
	lista->tamanho++;
	return 1;*/
	NOptr percorre_lista = lista->cabeca;
	while (percorre_lista->prox != lista->cabeca) {
		percorre_lista = percorre_lista->prox;
	}
	NOptr nova_lista = (NOptr) malloc(sizeof(NO));
	nova_lista->T = T;
	int i = 0;
	for (i = 0; i < 80; i++) {
		nova_lista->n[i] = n[i];
	}
	nova_lista->passou = 0;
	if (inserir_tempo == 1) {
		nova_lista->tempo_execucao = tempo_execucao;
	}
	nova_lista->ant = percorre_lista;
	nova_lista->prox = lista->cabeca;
	percorre_lista->prox = nova_lista;
	lista->tamanho++;
}

void remove_no_lista(LISTA_CIRCULARptr lista, NOptr no) {
	no->ant->prox = no->prox;
	no->prox->ant = no->ant;
	lista->tamanho--;	
}

void imprime_lista(LISTA_CIRCULARptr lista) {
	NOptr percorre_lista = lista->cabeca->prox;
	while (percorre_lista != lista->cabeca) {
		printf("%d us: %s finalizou", percorre_lista->tempo_execucao, percorre_lista->n);
		if (percorre_lista->prox != lista->cabeca) {
			printf("\n");	
		}
		percorre_lista = percorre_lista->prox;
	}
}

LISTA_CIRCULARptr ordena_lista(LISTA_CIRCULARptr lista) {
	//imprime_lista(lista);
	LISTA_CIRCULARptr nova_lista = inicializa_lista();
	NOptr percorre_lista = lista->cabeca;
	while (percorre_lista) {
		if (percorre_lista != lista->cabeca) {
			int tem_menor =  0;
			NOptr percorre_lista_inicio = lista->cabeca->prox;
			while (percorre_lista_inicio) {
				if (percorre_lista_inicio != lista->cabeca) {
					if (percorre_lista_inicio->tempo_execucao < percorre_lista->tempo_execucao) {
						tem_menor = 1;
					}
				}
				if (percorre_lista_inicio == lista->cabeca) {
					break;
				}
				percorre_lista_inicio = percorre_lista_inicio->prox;
			}
			if (tem_menor == 0) {
				insere_lista(nova_lista, percorre_lista->T, percorre_lista->n, 1, percorre_lista->tempo_execucao);
				remove_no_lista(lista, percorre_lista);
				if (lista->tamanho == 0) {
					imprime_lista(nova_lista);
					return nova_lista;
				}
			}
		}
		percorre_lista = percorre_lista->prox;
	}
}

int main(void) {
	LISTA_CIRCULARptr lista_circular = inicializa_lista();
	int T, n, i;
	scanf("%i", &T);
	scanf("%i", &n);
	int tempo;
	i = 0;
	while (i < n) {
		char n[80];
		scanf("%s", &n);
		scanf("%d", &tempo);
		insere_lista(lista_circular, tempo, n, 0, 0);
		i++;
		int j = 0;
		for (j = 0; j < 80; j++) {
			n[j] = '\0';
		}
	}
	NOptr percorre_lista = lista_circular->cabeca;
	int tempo_execucao = 0;
	int numero_zeros = 0;
	while (percorre_lista) {
		if (percorre_lista != lista_circular->cabeca) {
			if (percorre_lista->T > T) {
				tempo_execucao = tempo_execucao + (T);
			} else {
				if (percorre_lista->T > 0) {
					tempo_execucao = tempo_execucao + percorre_lista->T;	
				}
			}
			int diferenca = percorre_lista->T - T;
			percorre_lista->T = percorre_lista->T - T;
			if (percorre_lista->passou == 0 && diferenca <= 0) {
				percorre_lista->T = 0;
				percorre_lista->passou = 1;
				percorre_lista->tempo_execucao = tempo_execucao;
				numero_zeros++;
			}
			if (numero_zeros == (n)) {
				break;
			}
		}
		percorre_lista = percorre_lista->prox;
	}
	LISTA_CIRCULARptr lista_ordenada = ordena_lista(lista_circular);
	//imprime_lista(lista_ordenada);
}
