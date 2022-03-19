w#include <stdio.h>
#include <stdlib.h>


int	num_PRTY = 1;

/*Estrutura de dados - Lista Circular:*/
typedef struct no{
	char pal[20];
	int urg;
	struct no *prox;
}Elem;

typedef Elem *Elemptr;


typedef struct lista_circular {
	Elemptr r;
	Elemptr w;
	Elemptr cabeca;
}LISTA_CIRCULAR;

typedef LISTA_CIRCULAR *LISTA_CIRCULARptr;


/*Funções para a análise e manipulação dos elementos da lista:*/
void inicializa_lista(LISTA_CIRCULARptr l) {
	Elemptr cabeca = (Elemptr) malloc(sizeof(Elem));
	l->cabeca = cabeca;
	cabeca->prox = cabeca;
	l->r = cabeca;
	l->w = cabeca;
}

void insere_lista(LISTA_CIRCULARptr l, char *pal, int urg) {
	Elemptr novo_elem = (Elemptr) malloc(sizeof(Elem));
	int i = 0;
	for (i = 0; i < 20; i++) {
		novo_elem->pal[i] = '\0';
	}
	i = 0;
	while (pal[i] != '\0') {
		novo_elem->pal[i] = pal[i];
		i++;
	}
	novo_elem->urg = urg;
	Elemptr cabeca = l->cabeca;
	Elemptr end = l->cabeca;
	
	while (end->prox != cabeca) {
		end = end->prox;
	}
	end->prox = novo_elem;
	novo_elem->prox = cabeca;
}

int conta_remocoes(FILE *pacotes, int *num_PRTY) {
	rewind(pacotes);
	int n = 0;
	int tem_PRTY = 0;
	int numero_remocoes = 0;
	while (n < *num_PRTY && !feof(pacotes)) {
		char str_PRTY[20];
		fgets(str_PRTY, 20, pacotes);
		if (str_PRTY[2] == 'P' && str_PRTY[3] == 'R' && str_PRTY[4] == 'T' && str_PRTY[5] == 'Y' ) {
			tem_PRTY = 1;
			n++;
		}
	}
	if (tem_PRTY == 1) {
		*num_PRTY = *num_PRTY + 1;
		while (!feof(pacotes)) {
			char str_pal[20];
			fgets(str_pal, 20, pacotes);
			if (str_pal[0] == '1') numero_remocoes++;
		}
	}
	return numero_remocoes;
}

int remocao_leitura(Elemptr w, FILE *pacotes, FILE *lidos, Elemptr primeiro_elem, int *num_PRTY) {
	fprintf(lidos, "%s\n", w->pal);
	if (w->pal[0] == 'P' && w->pal[1] == 'R' && w->pal[2] == 'T' && w->pal[3] == 'Y') {
		Elemptr ponteiro_escrita = w;
		Elemptr ponteiro_maximo = w;
		int maximo = 0;
		while (ponteiro_maximo->prox != primeiro_elem) {
			maximo++;
			ponteiro_maximo = ponteiro_maximo->prox;
		}
		int num_remocoes = conta_remocoes(pacotes, num_PRTY);
		maximo = (maximo - 2 - num_remocoes);
		if (maximo >= w->urg) {
			return w->urg;
		} else {
			return maximo;
		}
	} else {
		return 1;
	}
}


/*Início do programa:*/
int main(void) {
	FILE *pacotes;
	FILE *lidos;
	
	pacotes = fopen("pacotes.dat", "r");
	lidos = fopen("lidos.dat", "w");
	
	LISTA_CIRCULAR lista;
	LISTA_CIRCULARptr lista_ptr = &lista;
	inicializa_lista(lista_ptr);
	
	
	while (!feof(pacotes)){
		char pal[20];
		char str_pal[20];
		char str_urg[3];
		fgets(pal, 20, pacotes);
		int i = 0;
		int j = 2;
		
		while (pal[j] != ' ') {
			str_pal[i] = pal[j];
			i++;
			j++;
		}
		j++;
		i = 0;
		while (pal[j] != '\0') {
			str_urg[i] = pal[j];
			j++;
			i++;
		}
		int num_urg = atoi(str_urg);
		insere_lista(lista_ptr, str_pal, num_urg);
		for (i = 0; i < 20; i++) {
			str_pal[i] = '\0';
		}
	}	
	
	
	char str_linha_escrita[20];
	FILE *linha_escrita = fopen("pacotes.dat", "r");
	fgets(str_linha_escrita, 20, linha_escrita);
	FILE *pacotes_conta_remocoes = fopen("pacotes.dat", "r");
	
	rewind(pacotes);
	lista_ptr->r = lista_ptr->r->prox;
	lista_ptr->w = lista_ptr->w->prox;
	Elemptr primeiro_elem = lista_ptr->r;
	while (!feof(pacotes)) {
		char pal[20];
		fgets(pal, 20, pacotes);
		if (pal[0] == '1') {
			int linhas_percorridas = 0;
			int posicao_ponteiro_escrita = remocao_leitura(lista_ptr->w, pacotes_conta_remocoes, lidos, primeiro_elem, &num_PRTY);
			while (linhas_percorridas < posicao_ponteiro_escrita) {
				fgets(str_linha_escrita, 20, linha_escrita);
				while (str_linha_escrita[0] == '1') {
					fgets(str_linha_escrita, 20, linha_escrita);
					lista_ptr->w = lista_ptr->w->prox;
				}
				if (str_linha_escrita[0] != '1') {
					lista_ptr->w = lista_ptr->w->prox;
					linhas_percorridas++;
				}
			}
		}
		lista_ptr->r = lista_ptr->r->prox;
		if ((lista_ptr->r->pal[0] == 'N' && lista_ptr->r->pal[1] == 'U' && lista_ptr->r->pal[2] == 'L' && lista_ptr->r->pal[3] == 'L') || (lista_ptr->w->pal[0] == 'N' && lista_ptr->w->pal[1] == 'U' && lista_ptr->w->pal[2] == 'L' && lista_ptr->w->pal[3] == 'L')) {
			fclose(pacotes);  
			fclose(lidos);
			fclose(linha_escrita);
			fclose(pacotes_conta_remocoes);
			
			
			FILE *lidos_final = fopen("lidos.dat", "r");
	
			while (!feof(lidos_final)) {
				printf("%c", getc(lidos_final));
			}
			
			fclose(pacotes_conta_remocoes);
			
			
			return 1;
		}
	}
}
