#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	char info[100];
	char placa[6];
	struct lista *prox;
}LISTA;

typedef LISTA* LISTAptr;

typedef struct pilha {
	char info[100];
	char placa[6];
	struct pilha *prox;	
}PILHA;

typedef PILHA* PILHAptr;

typedef struct fila {
	char info[100];
	char placa[6];
	struct fila *prox;
}FILA;

typedef FILA* FILAptr;

LISTAptr percorre_lista = NULL;

LISTAptr inicializa_lista (char info[100], int insere) {
	LISTAptr nova_lista = (LISTAptr) malloc(sizeof(LISTA));
	int i, j, k = 0;
	for (i = 0; i < 100; i++) {
		nova_lista->info[i] = info[i];
	}
	if (insere == 1) {
		for (i = 0; i <= 100; i++) {
			if (info[i] == ' ') {
				j++;	
			}
			if (j == 11) {
				nova_lista->placa[k] = info[i + 1];
				k++;
			}
			if (info[i] == '\0') {
				break;
			}
		}
	}
	nova_lista->prox = NULL;
	return nova_lista;
}

void inserir_lista (LISTAptr lista, char info[100]) {
	LISTAptr p = lista;
	LISTAptr nova_lista = inicializa_lista(info, 1);
	while (p->prox != NULL) {
		if (nova_lista->placa[0] < p->prox->placa[0]) {
			//inserção antes
			nova_lista->prox = p->prox;
			p->prox = nova_lista;
			return;
		} else if (nova_lista->placa[0] == p->prox->placa[0] && nova_lista->placa[1] != p->prox->placa[1]) {
			if (nova_lista->placa[1] < p->prox->placa[1]) {
				//inserção antes
				nova_lista->prox = p->prox;
				p->prox = nova_lista;
				return;
			} else {
				//inserção depois
				nova_lista->prox = p->prox->prox;
				p->prox->prox = nova_lista;
				return;
			}
		} else if (nova_lista->placa[0] == p->prox->placa[0] && nova_lista->placa[1] == p->prox->placa[1]) {	
			if (nova_lista->placa[2] < p->prox->placa[2]) {
				//inserção antes
				nova_lista->prox = p->prox;
				p->prox = nova_lista;
				return;
			} else {
				//inserção depois
				nova_lista->prox = p->prox->prox;
				p->prox->prox = nova_lista;
				return;
			}
		}
		p = p-> prox;
	}
	p->prox = nova_lista;
}

void imprimir_lista_info (LISTAptr lista) {
	LISTAptr p = lista->prox;
	while (p != NULL) {
		printf("%s\n", p->info);
		p = p->prox;
	}
}

void imprimir_lista_placa (LISTAptr lista) {
	LISTAptr p = lista->prox;
	int i = 0;
	while (p != NULL) {
		for (i = 0; i < 6; i++) {
			printf("%c", p->placa[i]);
		}
		printf("\n");
		p = p->prox;
	}
}

void lista_excluidos (LISTAptr lista, LISTAptr excluidos, char placa[6]) {
	LISTAptr p = lista->prox;
	while (p != NULL) {
		int a = strcmp(p->placa, placa);
		if (p->placa[0] == placa[0] && p->placa[1] == placa[1] && p->placa[2] == placa[2] && p->placa[3] == placa[3] && p->placa[4] == placa[4] && p->placa[5] == placa[5]) {
			inserir_lista(excluidos, p->info);
		}
		p = p->prox;
	}
}

LISTAptr excluir (LISTAptr lista, LISTAptr excluidos) {
	char vetor_nulo[100];
	LISTAptr nova_lista = inicializa_lista(vetor_nulo, 0);
	LISTAptr p_excluidos = excluidos->prox;
	printf("ok %s\n", excluidos->prox->placa);
	LISTAptr p = lista->prox;
	while (p) {
		int excluido = 0;
		p_excluidos = excluidos->prox;
		while (p_excluidos) {
			if (!strcmp(p_excluidos->info, p->info)) {
				excluido = 1;
			}
			p_excluidos = p_excluidos->prox;
		}
		if (!excluido) {
			inserir_lista(nova_lista, p->info);
		}
		p = p->prox;
	}
	return nova_lista;
}

PILHAptr inicializa_pilha (char info[100], int insere) {
	PILHAptr nova_pilha = (PILHAptr) malloc(sizeof(PILHA));
	int i, j, k = 0;
	for (i = 0; i < 100; i++) {
		nova_pilha->info[i] = info[i];
	}
	if (insere == 1) {
		for (i = 0; i <= 100; i++) {
			if (info[i] == ' ') {
				j++;
			}
			if (j == 11) {
				nova_pilha->placa[k] = info[i + 1];
				k++;
			}
			if (info[i] == '\0') {
				break;
			}
		}
	}
	nova_pilha->prox = NULL;
	return nova_pilha;
}

void inserir_pilha (PILHAptr pilha, char info[100]) {
	PILHAptr p = pilha;
	while (p->prox != NULL) {
		p = p->prox;
	}
	PILHAptr novo_no = inicializa_pilha(info, 1);
	p->prox = novo_no;
}

void remover_pilha (PILHAptr pilha) {
	PILHAptr p = pilha;
	if (pilha->prox == NULL) {
		return;
	}
	while (p->prox->prox != NULL) {
		p = p->prox;
	}
	p->prox = NULL;
}

void imprimir_pilha_info (PILHAptr pilha) {
	PILHAptr p = pilha->prox;
	while (p != NULL) {
		printf("%s\n", p->info);
		p = p->prox;
	}
}

FILAptr inicializa_fila (char info[100], int insere) {
	FILAptr nova_fila = (FILAptr) malloc(sizeof(FILA));
	int i, j, k = 0;
	for (i = 0; i < 100; i++) {
		nova_fila->info[i] = info[i];
	}
	if (insere == 1) {
		for (i = 0; i <= 100; i++) {
			if (info[i] == ' ') {
				j++;	
			}
			if (j == 11) {
				nova_fila->placa[k] = info[i + 1];
				k++;
			}
			if (info[i] == '\0') {
				break;
			}
		}
	}
	nova_fila->prox = NULL;
	return nova_fila;
}

void inserir_fila (FILAptr fila, char info[100]) {	
	FILAptr p = fila;
	while (p->prox != NULL) {
		p = p->prox;
	}
	FILAptr novo_no = inicializa_fila(info, 1);
	p->prox = novo_no;
}

void remover_fila (FILAptr fila) {
	FILAptr p = fila;
	if (p->prox == NULL) {
		return;
	}
	p->prox = p->prox->prox;
}


void imprimir_fila_info (FILAptr fila) {
	FILAptr p = fila->prox;
	while (p != NULL) {
		printf("%s\n", p->info);
		p = p->prox;
	}
}

LISTAptr busca (LISTAptr lista, char info[100], int estrutura_busca, PILHAptr pilha, FILAptr fila) {
	LISTAptr p = lista->prox;
	while (p) {
		if (strcmp(p->info, info) == 0) {
			if (estrutura_busca == 1) {
				inserir_pilha(pilha, info);
			} else if (estrutura_busca == 2) {
				inserir_fila(fila, info);
			}
			return p;
		}
		p = p->prox;
	}
	return NULL;
}

int main () {
	FILE* arq = fopen("arquivo.txt", "r");
	int escolha, i;
	char vetor_null[100], dados[100];
	LISTAptr excluidos = inicializa_lista(vetor_null, 0);
	LISTAptr lista_inicial = inicializa_lista(vetor_null, 0);
	LISTAptr lista = inicializa_lista(vetor_null, 0);
	PILHAptr pilha_busca = inicializa_pilha(vetor_null, 0);
	FILAptr fila_busca = inicializa_fila(vetor_null, 0);
	while (!feof(arq)) {
		char linha[100];
		fgets(linha, 100, arq);
		if (linha[0] != '#' && linha[0] != ' ') {
			inserir_lista(lista, linha);
			inserir_lista(lista_inicial, linha);
		}
	}
	//imprimir_lista_info(lista);
	while (1) {
		do {
			printf("Escolha uma das opções abaixo: \n\n");
			printf("1 - Inserção\n");
			printf("2 - Exclusão\n");
			printf("3 - Busca\n");
			printf("4 - Relatório\n");
			printf("5 - Sair\n");
			scanf("%i", &escolha);
		} while (escolha < 1 || escolha > 5);
		if (escolha == 5) {
			break;
		}
		if (escolha == 1) {
			printf("Informe os dados a serem inseridos\n");
			char dados[100];
			int i = 0;
			scanf(" %99[^\n]", dados);
			inserir_lista(lista, dados);
			inserir_lista(lista_inicial, dados);
		} else if (escolha == 2) {
			printf("Informe todos os dados do veículo que deseja excluir\n");
			char placa[6];
			scanf("%s", placa);
			lista_excluidos(lista, excluidos, placa);
			LISTAptr nova_lista = excluir(lista, excluidos);
			lista_inicial = nova_lista;
			imprimir_lista_info(lista_inicial);
		} else if (escolha == 3) {
			escolha = 0;
			do {
				printf("\nEscolha o tipo de busca: \n\n");
				printf("1 - Busca por pilha\n");
				printf("2 - Busca por fila\n");
				scanf("%i", &escolha);
			} while (escolha < 1 || escolha > 2);
			printf("Escolha todos os dados do veículo a ser buscado\n");
			if (escolha == 1) { //Pilha
				char dados_busca[100];
				scanf(" %99[^\n]", dados_busca);
				LISTAptr resultado_busca = busca(lista_inicial, dados_busca, 1, pilha_busca, NULL);
				if (resultado_busca != NULL) {
					printf("\n");
					imprimir_pilha_info(pilha_busca);
					printf("\n");
				} else {
					printf("\nNenhum resultado encontrado\n\n");
				}
			} else { //Fila
				char dados_busca[100];
				scanf(" %99[^\n]", dados_busca);
				LISTAptr resultado_busca = busca(lista_inicial, dados_busca, 2, NULL, fila_busca);
				if (resultado_busca != NULL) {
					printf("\n");
					imprimir_fila_info(fila_busca);
					printf("\n");
				} else {
					printf("\nNenhum resultado encontrado\n\n");
				}
			}
		} else if (escolha == 4) {
			printf("Relatório\n");
		}
	}
	//imprimir_lista_info(lista);
}
