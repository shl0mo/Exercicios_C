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
	LISTAptr lista;
	struct pilha *prox;	
}PILHA;

typedef PILHA* PILHAptr;

typedef struct fila {
	LISTAptr lista;
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
	j = 0;
	k = 0;
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


LISTAptr no_insercao_1 (LISTAptr lista, char placa[6], int indice) {
	LISTAptr p = lista;
	while (p->prox) {
		if (p->prox->placa[0] == placa[0] && p->placa[indice] <= placa[indice] && p->prox->placa[indice] > placa[indice]) {
			return p;
		} 
		if (p->placa[0] == placa[0] && placa[indice] > p->placa[indice]) {
			lista = p;
		}
		p = p->prox;
	}
	return lista;
}

LISTAptr no_insercao_2 (LISTAptr lista, char placa[6], int indice) {
	LISTAptr p = lista;
	while (p->prox) {
		if (p->prox->placa[0] == placa[0] && p->prox->placa[1] == placa[1] && p->prox->placa[indice] < placa[indice]) {
			return p->prox;
		}
		if (p->placa[0] == placa[0] && p->placa[1] == placa[1] && placa[indice] > p->placa[indice]) {
			lista = p;
		}
		p = p->prox;
	}
	return lista;
}


void imprimir_lista_info (LISTAptr lista) {
	LISTAptr p = lista->prox;
	while (p) {
		printf("%s\n", p->info);
		p = p->prox;
	}
}

int define_tipo_insercao (LISTAptr lista, char placa[6]) {
	int tipo_insercao = 0;
	LISTAptr p = lista->prox;
       	while (p) {
		if (placa[0] < p->placa[0]) {
			tipo_insercao = 1;
		} 
		if (p->placa[0] == placa[0] && p->placa[1] != placa[1]) {
			tipo_insercao = 2;
		} 
		if (p->placa[0] == placa[0] && p->placa[1] == placa[1] && p->placa[2] != p->placa[2]) {
			tipo_insercao = 3;
		}
		p = p->prox;
	}
	return tipo_insercao;
}

void inserir_lista (LISTAptr lista, char info[100]) {
	LISTAptr p = lista;
	LISTAptr nova_lista = inicializa_lista(info, 1);
	int tipo_insercao = define_tipo_insercao(lista, nova_lista->placa);
	while (p->prox != NULL) {
		if (nova_lista->placa[0] < p->prox->placa[0]) { //inserção antes
			nova_lista->prox = p->prox;
			p->prox = nova_lista;
			return;
		}
		if (nova_lista->placa[0] == p->prox->placa[0] && nova_lista->placa[1] != p->prox->placa[1]) {
			if (no_insercao_1(p->prox, nova_lista->placa, 1) == p->prox) {
				if (nova_lista->placa[1] < p->prox->placa[1]) { //inserção antes
					nova_lista->prox = p->prox;
					p->prox = nova_lista;
					return;
				} else { //inserção depois
					nova_lista->prox = p->prox->prox;
					p->prox->prox = nova_lista;
					return;
				}
			} else {
				LISTAptr no_insercao = no_insercao_1(p->prox, nova_lista->placa, 1);
				if (nova_lista->placa[1] < no_insercao->placa[1]) { //inserção antes
					nova_lista->prox = no_insercao;
					no_insercao = nova_lista;
					return;
				} else { //inserção depois
					nova_lista->prox = no_insercao->prox;
					no_insercao->prox = nova_lista;
					return;
				}
			}
		}
		if (nova_lista->placa[0] == p->prox->placa[0] && nova_lista->placa[1] == p->prox->placa[1] && nova_lista->placa[2] != p->prox->placa[2]) {
			if (no_insercao_2(p->prox, nova_lista->placa, 2) == p->prox) {
				if (nova_lista->placa[2] < p->prox->placa[2]) { //inserção antes
					nova_lista->prox = p->prox;
					p->prox = nova_lista;
					return;
				} else { //inserção depois
					nova_lista->prox = p->prox->prox;
					p->prox->prox = nova_lista;
					return;
				}
			} else {
				printf("Aqui");
				LISTAptr no_insercao = no_insercao_2(p->prox, nova_lista->placa, 2);
				if (nova_lista->placa[2] < no_insercao->placa[2]) { //inserção antes
					nova_lista->prox = no_insercao;
					no_insercao = nova_lista;
					return;
				} else { //inserção depois
					nova_lista->prox = no_insercao->prox;
					no_insercao->prox = nova_lista;
					return;
				}
			}

		} else if (nova_lista->placa[0] == p->prox->placa[0] && nova_lista->placa[1] == p->prox->placa[1] && nova_lista->placa[2] == p->prox->placa[2] && nova_lista->placa[3] != p->prox->placa[3]) {
			printf("caso 1");
			if (nova_lista->placa[3] < p->prox->placa[3]) { //inserção antes
				nova_lista->prox = p->prox;
				p->prox = nova_lista;
				return;
			} else { //inserção depois
				nova_lista->prox = p->prox->prox;
				p->prox->prox = nova_lista;
				return;
			}
		} else if (nova_lista->placa[0] == p->prox->placa[0] && nova_lista->placa[1] == p->prox->placa[1] && nova_lista->placa[2] == p->prox->placa[2] && nova_lista->placa[3] == p->prox->placa[3] && nova_lista->placa[4] != p->prox->placa[4]) {
			printf("caso 2");
			if (nova_lista->placa[4] < p->prox->placa[4]) { //inserção antes
				nova_lista->prox = p->prox;
				p->prox = nova_lista;
				return;
			} else { //inserção depois
				nova_lista->prox = p->prox->prox;
				p->prox->prox = nova_lista;
				return;
			}
		} else if (nova_lista->placa[0] == p->prox->placa[0] && nova_lista->placa[1] == p->prox->placa[1] && nova_lista->placa[2] == p->prox->placa[2] && nova_lista->placa[3] == p->prox->placa[3] && nova_lista->placa[4] == p->prox->placa[4] && nova_lista->placa[5] != p->prox->placa[5]) {
			printf("caso 3");
			if (nova_lista->placa[5] < p->prox->placa[5]) { //inserção antes
				nova_lista->prox = p->prox;
				p->prox = nova_lista;
				return;
			} else { //inserção depois
				nova_lista->prox = p->prox->prox;
				p->prox->prox = nova_lista;
				return;
			}
		}
		p = p-> prox;
	}
	p->prox = nova_lista;
	//imprimir_lista_info(lista);
	//printf("%s\n", nova_lista->placa);
}

int tamanho_lista (LISTAptr lista) {
	LISTAptr p = lista->prox;
	int tamanho_lista = 0;
	while (p) {
		tamanho_lista++;
		p = p->prox;
	}
	return tamanho_lista;
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
	LISTAptr p = lista->prox;
	FILE *arq = fopen("arquivo.txt", "r");
	rewind(arq);
	while (!feof(arq)) {
		char linha[100];
		int i = 0;
		char linha_anterior[100];
		for (i = 0; i < 100; i++) {
			linha_anterior[i] = linha[i];	
		}
		fgets(linha, 100, arq);
		if (!strcmp(linha_anterior, linha)) {
			break;
		}
		fgets(linha, 100, arq);
		int excluido = 0;
		p_excluidos = excluidos->prox;
		while (p_excluidos) {
			if (!strcmp(p_excluidos->info, linha)) {
				excluido = 1;
			}
			p_excluidos = p_excluidos->prox;
		}
		if (!excluido && linha[0] != '#' && linha[0] != ' ') {
			inserir_lista(nova_lista, linha);
		}
	}
	return nova_lista;
}

PILHAptr inicializa_pilha (LISTAptr lista) {
	PILHAptr nova_pilha = (PILHAptr) malloc(sizeof(PILHA));
	nova_pilha->lista = lista;
	nova_pilha->prox = NULL;
	return nova_pilha;
}

void inserir_pilha (PILHAptr pilha, LISTAptr lista) {
	PILHAptr p = pilha;
	while (p->prox != NULL) {
		p = p->prox;
	}
	PILHAptr novo_no = inicializa_pilha(lista);
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
		printf("%s\n", p->lista->info);
		p = p->prox;
	}
}

FILAptr inicializa_fila (LISTAptr lista) {
	FILAptr nova_fila = (FILAptr) malloc(sizeof(FILA));
	nova_fila->lista = lista;
	nova_fila->prox = NULL;
	return nova_fila;
}

void inserir_fila (FILAptr fila, LISTAptr lista) {	
	FILAptr p = fila;
	while (p->prox != NULL) {
		p = p->prox;
	}
		FILAptr novo_no = inicializa_fila(lista);
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
		printf("%s\n", p->lista->info);
		p = p->prox;
	}
}

LISTAptr busca (LISTAptr lista, char info[100], int estrutura_busca, PILHAptr pilha, FILAptr fila) {
	LISTAptr p = lista->prox;
	while (p) {
		int encontrou = 1;
		int i = 0;
		while (info[i] != '\0') {
			if (p->info[i] != info[i]) {
				encontrou = 0;
				break;
			}
			i++;
		}
		if (encontrou == 1) {
			if (estrutura_busca == 1) {
				inserir_pilha(pilha, p);
			} else if (estrutura_busca == 2) {
				inserir_fila(fila, p);
			}
			return p;
		}
		p = p->prox;
	}
	return NULL;
}

int main () {
	FILE* arq = fopen("arquivo.txt", "r");
	int escolha = 0;
	int i = 0;
	int tipo_estrutura = 0;
	char vetor_null[100], dados[100];
	LISTAptr excluidos = inicializa_lista(vetor_null, 0);
	LISTAptr lista_inicial = inicializa_lista(vetor_null, 0);
	LISTAptr lista = inicializa_lista(vetor_null, 0);
	PILHAptr pilha_busca = inicializa_pilha(NULL);
	FILAptr fila_busca = inicializa_fila(NULL);
	while (!feof(arq)) {
		char linha[100];
		char linha_anterior[100];
		for (i = 0; i < 100; i++) {
			linha_anterior[i] = linha[i];	
		}
		fgets(linha, 100, arq);
		if (!strcmp(linha_anterior, linha)) {
			break;
		}
		if (linha[0] != '#' && linha[0] != ' ' && linha[0] != '\n') {	
			inserir_lista(lista, linha);
			inserir_lista(lista_inicial, linha);
		}
	}
	while (1) {
		do {
			printf("\nEscolha uma das opções abaixo: \n\n");
			printf("1 - Inserção\n");
			printf("2 - Exclusão\n");
			printf("3 - Busca\n");
			printf("4 - Relatório\n");
			printf("5 - Sair\n");
			scanf("%i", &escolha);
		} while (escolha < 1 || escolha > 6);
		if (escolha == 5) {
			return 0;
		}
		if (escolha == 1) {
			printf("Informe os dados a serem inseridos:\n");
			char dados[100];
			scanf(" %99[^\n]", dados);
			FILE* arquivo = fopen("arquivo.txt", "a");
			fprintf(arquivo, "%s\n", dados);
			fclose(arquivo);
			lista_inicial = inicializa_lista(vetor_null, 0);
			lista = inicializa_lista(vetor_null, 0);
			rewind(arq);
			while (!feof(arq)) {
				char linha[100];
				char linha_anterior[100];
				for (i = 0; i < 100; i++) {
					linha_anterior[i] = linha[i];	
				}
				fgets(linha, 100, arq);
				if (!strcmp(linha_anterior, linha)) {
					break;
				}
				fgets(linha, 100, arq);
				if (linha[0] != '#' && linha[0] != ' ') {
					inserir_lista(lista_inicial, linha);
					inserir_lista(lista, linha);
				}
			}
			LISTAptr nova_lista = excluir(lista, excluidos);
			lista_inicial = nova_lista;
		} else if (escolha == 2) {
			printf("Informe a placa do veículo que deseja excluir:\n");
			char placa[6];
			scanf("%s", placa);
			lista_excluidos(lista, excluidos, placa);
			LISTAptr nova_lista = excluir(lista, excluidos);
			lista_inicial = nova_lista;
			imprimir_lista_info(lista_inicial);
		} else if (escolha == 3) {
			if (tipo_estrutura == 0) {
				do {
					printf("\nEscolha o tipo de busca: \n\n");
					printf("1 - Busca por pilha\n");
					printf("2 - Busca por fila\n");
					scanf("%i", &tipo_estrutura);
				} while (tipo_estrutura < 1 || tipo_estrutura > 2);
			}
			if (tipo_estrutura == 1) { //Pilha
				printf("Informe todos os dados do veículo a ser buscado (o tipo escolhido foi pilha - todas as buscas serão armazenadas em uma pilha):\n");
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
				printf("Informe todos os dados do veículo a ser buscado (o tipo escolhido foi fila - todas as buscas serão armazenadas em uma fila):\n");
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
			imprimir_lista_info(lista_inicial);
			//printf("%i\n", tamanho_lista(lista_inicial));
		}
	}
}
