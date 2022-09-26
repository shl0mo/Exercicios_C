# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct Loja {
	char tipo[100];
	char marca[100];
	char modelo[100];
	float valor;
	int quantidade_estoque;
	float valor_frete;
	struct Loja* prox;
} LOJA;

typedef LOJA* LOJAptr;

void apaga_palavra(char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		palavra[i] = '\0';
	}
}

void copia_palavra(char vetor_loja[100], char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		vetor_loja[i] = palavra[i];
	}
}

LOJAptr insere_no_loja(LOJAptr loja, int primeiro, char tipo[100], char marca[100], char modelo[100], float valor, int quantidade_estoque, float valor_frete) {
	LOJAptr novo_no = (LOJAptr) malloc(sizeof(LOJA));
 	copia_palavra(novo_no->tipo, tipo);
	copia_palavra(novo_no->marca, marca);
	copia_palavra(novo_no->modelo, modelo);
	novo_no->valor = valor;
	novo_no->quantidade_estoque = quantidade_estoque;
	novo_no->valor_frete = valor_frete;
	if (primeiro == 1) {
		novo_no->prox = NULL;
		return novo_no;
	}
	LOJAptr p = loja;
	while (p->prox != NULL) {
		p = p->prox;
	}
	p->prox = novo_no;
	novo_no->prox = NULL;
	return NULL;
}

LOJAptr inicializa_loja() {
	srand(time(NULL));
	float valor_frete = 15;
	// Produto 1 a ser inserido no vetor
	char tipo_1[] = "Contador";
	char marca_1[] = "Helmholz";
	char modelo_1[] = "600-255-7BA21";
	float valor_1 = 79.29f;
	int quantidade_estoque_1 = rand() % 15 + 5;
	// Produto 2 a ser inserido no vetor
	char tipo_2[] = "Disjuntor";
	char marca_2[] = "Soprano";
	char modelo_2[] = "ASM2-B";
	float valor_2 = 32.40f;
	int quantidade_estoque_2 = rand() % 15 + 5;
	// Produto 3 a ser inserido no vetor
	char tipo_3[] = "DR";
	char marca_3[] = "Schneider";
	char modelo_3[] = "Easy9 2P";
	float valor_3 = 144.99f;
	int quantidade_estoque_3 = rand() % 15 + 5;
	// Produto 4 a ser inserido no vetor
	char tipo_4[] = "Eletroduto";
	char marca_4[] = "Amanco";
	char modelo_4[] = "11448";
	float valor_4 = 11.90f;
	int quantidade_estoque_4 = rand() % 15 + 5;
	// Produto 5 a ser inserido no vetor
	char tipo_5[] = "Interruptor";
	char marca_5[] = "Alumbra";
	char modelo_5[] = "Inova Pro 85042";
	float valor_5 = 21.19f;
	int quantidade_estoque_5 = rand() % 15 + 5;
	// Produto 6 a ser inseido no vetor
	char tipo_6[] = "Tomada";
	char marca_6[] = "Tramontina";
	char modelo_6[] = "Aria";
	float valor_6 = 14.16f;
	int quantidade_estoque_6 = rand() % 15 + 5;
	// Produto 7 a ser inserido no vetor
	char tipo_7[] = "DPS";
	char marca_7[] = "CLAMPER";
	char modelo_7[] = "Front";
	float valor_7 = 41.90f;
	int quantidade_estoque_7 = rand() % 15 + 5;
	// Insere os produtos na loja
	LOJAptr loja = insere_no_loja(NULL, 1, tipo_1, marca_1, modelo_1, valor_1, quantidade_estoque_1, valor_frete);
	insere_no_loja(loja, 0, tipo_2, marca_2, modelo_2, valor_2, quantidade_estoque_2, valor_frete);
	insere_no_loja(loja, 0, tipo_3, marca_3, modelo_3, valor_3, quantidade_estoque_3, valor_frete);
	insere_no_loja(loja, 0, tipo_4, marca_4, modelo_4, valor_4, quantidade_estoque_4, valor_frete);
	insere_no_loja(loja, 0, tipo_5, marca_5, modelo_5, valor_5, quantidade_estoque_5, valor_frete);
	insere_no_loja(loja, 0, tipo_6, marca_6, modelo_6, valor_6, quantidade_estoque_6, valor_frete);
	insere_no_loja(loja, 0, tipo_7, marca_7, modelo_7, valor_7, quantidade_estoque_7, valor_frete);
	return loja;
}

void imprime_loja (LOJAptr loja) {
	LOJAptr p = loja;
	int i = 1;
	while (p != NULL) {
		printf("Produto %i:\n", i);
		printf("TIPO: %s\n", p->tipo);
		printf("MARCA: %s\n", p->marca);
		printf("MODELO: %s\n", p->modelo);
		printf("VALOR: %f\n", p->valor);
		printf("ESTOQUE: %i\n", p->quantidade_estoque);
		printf("FRETE: %d\n", p->valor_frete);
		printf("\n\n");
		p = p->prox;
		i = i + 1;
	}
}

int main () {
	LOJAptr loja = inicializa_loja();
	imprime_loja(loja);
}
