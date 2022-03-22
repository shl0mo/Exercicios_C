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
	struct pilha *prox;	
}PILHA;

typedef PILHA* PILHAptr;

typedef struct fila {
	char info[100];
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
		//printf("%i\n", a);
		if (p->placa[0] == placa[0] && p->placa[1] == placa[1] && p->placa[2] == placa[2] && p->placa[3] == placa[3] && p->placa[4] == placa[4] && p->placa[5] == placa[5]) {
			inserir_lista(excluidos, p->info);
		}
		p = p->prox;
	}
	/*while (p_excluidos) {
		p = lista->prox;
		while (p) {
			if (p_excluidos->placa[0] == p->placa[0] && p_excluidos->placa[1] == p_placa[1] && p_excluidos->placa[2] == p_placa[2] && p_excluidos->placa[3] == p_placa[3] && p_excluidos->placa[4] == p_placa[4] && p_excluidos->placa[5] == p_placa[5]) {
				continue;
			} else {
				inserir_lista(nova_lista, );
			}
			p = p->prox;
		}
		p_excluidos = p_excluidos->prox;
	}*/
}

LISTAptr excluir (LISTAptr lista, LISTAptr excluidos) {	
	char vetor_nulo[100];
	LISTAptr nova_lista = inicializa_lista(vetor_nulo, 0);
	LISTAptr p = lista->prox;
	while (p) {
		int excluido = 0;
		LISTAptr p_excluidos = excluidos->prox;
		while (p_excluidos) {
			if (p_excluidos->placa[0] == p->placa[0] && p_excluidos->placa[1] == p->placa[1] && p_excluidos->placa[2] == p->placa[2] && p_excluidos->placa[3] == p->placa[3] && p_excluidos->placa[4] == p->placa[4] && p_excluidos->placa[5] == p->placa[5]) {
				printf("Excluido: %s\n", p->placa);
				excluido = 1;
			}
			p_excluidos = p_excluidos->prox;
		}
		if (!excluido) {
			inserir_lista(nova_lista, p->info);
			//printf("Inserir %s\n", p->info);
		}
		p = p->prox;
	}
	return nova_lista;
}

int main () {
	printf("%i", strcmp("aba","ab"));
	FILE* arq = fopen("arquivo.txt", "r");
	int escolha, i;
	char vetor_null[100], dados[100];
	LISTAptr excluidos = inicializa_lista(vetor_null, 0);
	LISTAptr lista = inicializa_lista(vetor_null, 0);
	while (!feof(arq)) {
		char linha[100];
		/*for (i = 0; i < 100; i++) {
			linha[i] = ' ';
		}*/
		fgets(linha, 100, arq);
		if (linha[0] != '#' && linha[0] != ' ') {
			inserir_lista(lista, linha);
		}
	}
	//imprimir_lista_info(lista);
	while (1) {
		do {
			printf("Escolha uma das opções abaixo: \n\n");
			printf("1 - Inserção\n");
			printf("2 - Busca\n");
			printf("3 - Exclusão\n");
			printf("4 - Relatório\n");
			printf("5 - Sair\n");
			scanf("%i", &escolha);
		} while (escolha < 1 || escolha > 5);
		if (escolha == 5) {
			break;
		}
		if (escolha == 1) {
			printf("Informe os dados a serem inseridos\n");
			char dados[100], c;
			int i = 0;
			scanf(" %99[^\n]", dados);
			inserir_lista(lista, dados);
		} else if (escolha == 2) {
			escolha = 0;
			do {
				printf("\nEscolha o tipo de busca: \n\n");
				printf("1 - Busca por pilha\n");
				printf("2 - Busca por fila\n");
				scanf("%i", &escolha);
			} while (escolha < 1 || escolha > 2);
		} else if (escolha == 3) {
			printf("Informe a placa do veículo que deseja excluir\n");
			char placa[6];
			scanf("%s", placa);
			lista_excluidos(lista, excluidos, placa);
			LISTAptr nova_lista = excluir(lista, excluidos);
			//imprimir_lista_info(nova_lista);
			//imprimir_lista_info(nova_lista);
			//printf("%s\n", placa);
		}
	}
	//imprimir_lista_info(lista);
}
