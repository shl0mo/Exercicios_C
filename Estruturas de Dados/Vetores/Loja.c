# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

/* Estruturas de dados */
// Vetor de lista de produtos da loja: guarda as informações sobre o tipo, a marca, o modelo, o valor, o estoque e o valor do frete para cada produto
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

// Vetor de lista de produtos no carrinho: guarda o nome do produto adicionado ao nó do carrinho
typedef struct Carrinho {
	char nome_produto[100];
	struct Carrinho* prox;
} CARRINHO;

typedef CARRINHO* CARRINHOptr;

// Vetor de informações e carrinho do cliente: guarda a soma dos valores dos produtos e fretes, totalizando o valor do carrinho; a identificação e o endereço do cliente
typedef struct Cliente {
	float valor_carrinho;
	char tipo_pagamento[100];
	char identificacao[100];
	char endereco[100];
	struct Carrinho* carrinho;
} CLIENTE;

typedef CLIENTE* CLIENTEptr;


/* Funções */
// Apaga a palavra no vetor passado como parâmetro
void apaga_palavra(char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		palavra[i] = '\0';
	}
}

// Copia a palavra, caractere por caractere, do vetor no palavra para o vetor vetor_destino
void copia_palavra(char vetor_destino[100], char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		if (palavra[i] == '\0') break;
		vetor_destino[i] = palavra[i];
	}
}

// Insere um novo nó na instância da struct Loja, copiando os valores passados como parâmetro para os seus respectivos campos
LOJAptr insere_no_loja(LOJAptr loja, int primeiro, char tipo[100], char marca[100], char modelo[100], float valor, int quantidade_estoque, float valor_frete) {
	// Cria um novo nó para o vetor acolcando memória para a instância novo_no da struct Loja
	LOJAptr novo_no = (LOJAptr) malloc(sizeof(LOJA));
	// Copia os valores passados como parâmetro para os seus respectivos campos do novo nó
 	copia_palavra(novo_no->tipo, tipo);
	copia_palavra(novo_no->marca, marca);
	copia_palavra(novo_no->modelo, modelo);
	novo_no->valor = valor;
	novo_no->quantidade_estoque = quantidade_estoque;
	novo_no->valor_frete = valor_frete;
	// Se o nó criado for o primeiro do vetor (parâmetro primeiro  = 1), ao seu ponteiro prox é atribuído o valor NULL e o nó é retornado pela função, com os devidos valores adicionados a ele
	if (primeiro == 1) {
		novo_no->prox = NULL;
		return novo_no;
	}
	// Se o caso é inserir um nó em uma instância da struct Loja já existente (parâmetro primeiro = 0), o ponteiro caminha até o final do vetor e insere, no final do vetor, o novo nó criado
	LOJAptr p = loja;
	while (p->prox != NULL) {
		p = p->prox;
	}
	p->prox = novo_no;
	novo_no->prox = NULL;
	return NULL;
}

// Inicializa a loja criando o vetor de lista de produtos
LOJAptr inicializa_loja() {
	// A quantidade do estoque de cada produto é definida aleatoriamente e o valor do frete é fixado em 15 para qualquer produto
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

// Percorre a lista de produtos da loja e imprime as informações cadastradas para cada produto
void imprime_loja (LOJAptr loja) {
	LOJAptr p = loja;
	int i = 1;
	while (p != NULL) {
		printf("Produto %i:\n", i);
		printf("TIPO: %s\n", p->tipo);
		printf("MARCA: %s\n", p->marca);
		printf("MODELO: %s\n", p->modelo);
		printf("VALOR: %.2f\n", p->valor);
		printf("ESTOQUE: %i\n", p->quantidade_estoque);
		printf("FRETE: %.2f\n", p->valor_frete);
		printf("\n\n");
		p = p->prox;
		i = i + 1;
	}
}

// Cria uma instância da struct Carrinho com valores nulos, retornando o nó resultante
CARRINHOptr inicializa_carrinho() {
	CARRINHOptr novo_carrinho = (CARRINHOptr) malloc(sizeof(CARRINHO));
	apaga_palavra(novo_carrinho->nome_produto);
	novo_carrinho->prox = NULL;
	return novo_carrinho;
}

// Cria uma instância da struct Cliente com valores nulos, retornando o nó resultante
CLIENTEptr inicializa_cliente() {
	CLIENTEptr novo_cliente	= (CLIENTEptr) malloc(sizeof(CLIENTE));
	// O valor  inicial do carrinho é 0
	novo_cliente->valor_carrinho = 0;
	// O endereço inicialmente é uma string vazia
	apaga_palavra(novo_cliente->endereco);
	// O carrinho inicial é vazio, definido pelo resultado retornado da função inicializa_carrinho(), isso é, uma instância de Carrinho com valores incialmente nulos
	novo_cliente->carrinho = inicializa_carrinho();
  return novo_cliente;
}

// Adiciona produto ao carrinho
void adiciona_carrinho(LOJAptr loja, CLIENTEptr cliente, char nome_produto[100]) {
	// A variável p_loja percorre o vetor de lista de produtos da loja
	LOJAptr p_loja = loja;
	while (p_loja) {
		// Se o produto for encontrado
		if (strcmp(p_loja->tipo, nome_produto) == 0) {
			// Verifica se o produto está disponível
			if (p_loja->quantidade_estoque < 1) {
				// Não havendo o produto no estoque, a mensagem abaixo é exibida
				printf("\n\nEstoque insuficiente\n\n");
				return;
			}
			/* Se o produto estiver em estoque, a soma do produto e do frete será adicionada ao valor do carrinho, a quantidade de itens do produto adicionado 
			   ao carrinho será subtraído em uma unidade na lista e o produto será adicionado ao carrinho
			*/
			printf("\n\nAdicionando 1 produto tipo %s, modelo %s, marca %s - valor: %.2f + %.2f = %.4f (produto + frete) \n\n", p_loja->tipo, p_loja->modelo, p_loja->marca, p_loja->valor, p_loja->valor_frete, p_loja->valor + p_loja->valor_frete);
			// Adiciona o valor do produto e do frete ao carrinho do cliente
			cliente->valor_carrinho = cliente->valor_carrinho + p_loja->valor + p_loja->valor_frete;
			// Subtrai na lista uma unidade do produto adicionado ao carrinho pelo cliente
			p_loja->quantidade_estoque = p_loja->quantidade_estoque - 1;
			// Adiciona produto ao carrinho:
			// Move o ponteiro para o último elemento da lista
			CARRINHOptr p_carrinho = cliente->carrinho;
			while (p_carrinho->prox != NULL) {
				p_carrinho = p_carrinho->prox;
			}
			// Cria um novo nó para o carrinho no qual será adicionado o produto adquirido
			CARRINHOptr novo_carrinho = (CARRINHOptr) malloc(sizeof(CARRINHO));
			// Adiciona o produto no novo nó
			copia_palavra(novo_carrinho->nome_produto, nome_produto);
			// Insere o produto no final do vetor do carrinho
			novo_carrinho->prox = NULL;
			p_carrinho->prox = novo_carrinho;
			return;
		}
		p_loja = p_loja->prox;
	}
	// Se o nome de produto inserido não for encontrado, a mensagem abaixo é exibida
	printf("\n\nProduto nao encontrado\n\n");
}

// Imprime o valor e os produtos no carrinho
void imprime_valor_carrinho(CLIENTEptr cliente) {	
	printf("\nVALOR: %.5f\n", cliente->valor_carrinho);
	int qtd_produtos = 0;
	CARRINHOptr p_carrinho = cliente->carrinho;
	while (p_carrinho) {
		if (qtd_produtos == 1) printf("PRODUTOS NO CARRINHO:\n");
		if (qtd_produtos != 0) printf(" - ");
		if (strcmp(p_carrinho->nome_produto, "") != 0) printf("%s\n", p_carrinho->nome_produto);
		p_carrinho = p_carrinho->prox;
		qtd_produtos = qtd_produtos + 1;
	}
	// Se não houver produtos no carrinho, a mensagem "Carrinho vazio é exibida"
	if (qtd_produtos == 1) {
		printf("Carrinho vazio\n\n");
	}
}

int main () {
	srand(time(NULL));
	LOJAptr loja = inicializa_loja();
	CLIENTEptr cliente = inicializa_cliente();
	while (1) {
		int opcao;
		printf("\nEscolha uma das opcoes abaixo:\n\n");
		printf("1 - Ver produtos\n");
		printf("2 - Realizar compra\n");
		printf("3 - Exibir carrinho\n");
		printf("4 - Finalizar compra\n\n");
		scanf("%i", &opcao);
		while (opcao < 1 || opcao > 4) {
			printf("\nOpcao invalida. Escolha uma entre 1 e 4\n\n");
			scanf("%i", &opcao);
		}
		// Finaliza a compra caso a opção selecionada seja a 4, solicitando a idenfificação e o endereço do comprador e adicionando tais informações na estrutra de dados
		if (opcao == 4) {
			if (cliente->valor_carrinho == 0) { // Se o carrinho estiver vazio, os dados de identificação e endereço do cliente não são solicitados
				cliente = inicializa_cliente();
				continue;
			}
			int opcao_pagamento;
			char identificacao[100];
			char endereco[100];
			// Solicita a escolha do tipo de pagamento
			printf("\nEscolha uma das opcoes de pagamento abaixo: \n\n");
			printf("1 - Boleto\n");
			printf("2 - Debito\n");
			printf("3 - Credito\n");
			printf("4 - PIX\n\n");
			scanf("%i", &opcao_pagamento);
			while (opcao_pagamento < 1 || opcao_pagamento > 4) {
				printf("\nOpcao invalida. Escolha uma entre 1 e 4\n\n");
				scanf("%i", &opcao_pagamento);
			}
			// Insere na instância da struct Cliente o tipo de pagamento escolhido pelo comprador
			apaga_palavra(cliente->tipo_pagamento);
			if (opcao_pagamento == 1) {
				char tipo_pagamento[] = "Boleto";
				copia_palavra(cliente->tipo_pagamento, tipo_pagamento);
			} else if (opcao_pagamento == 2) {
				char tipo_pagamento[] = "Debito";
				copia_palavra(cliente->tipo_pagamento, tipo_pagamento);
			} else if (opcao_pagamento == 3) {
				char tipo_pagamento[] = "Credito";
				copia_palavra(cliente->tipo_pagamento, tipo_pagamento);
			} else if (opcao_pagamento == 4) {
				char tipo_pagamento[] = "PIX";
				copia_palavra(cliente->tipo_pagamento, tipo_pagamento);
			}
			printf("\nTipo de pagamento escolhido: %s", cliente->tipo_pagamento);
			printf("\nInforme sua identificacao: ");
			scanf("%s", identificacao);
			printf("Informe seu endereco: ");
			scanf("%s", endereco);
			// Adicionar identificação e endereço na instância da struct Cliente
			copia_palavra(cliente->identificacao, identificacao);
			copia_palavra(cliente->endereco, endereco);
			printf("\n\nObrigado pela compra!\n\n");
			// Reseta as informações do cliente, criando assim um novo cliente
			printf("\n -- NOVO CLIENTE --\n");
			cliente = inicializa_cliente();
			continue;
		}
		if (opcao == 1) { // Se a opção escolhida for 1, os produtos da loja são impressos
			imprime_loja(loja);
		} else if (opcao == 2) { // Se a opção escolhida for 2, o cliente deve selecionar o produto para realizar a compra
			char nome_produto[100];
			printf("\nInforme o nome do produto a ser adicionado ao carrinho: ");
			scanf("%s", nome_produto);
			adiciona_carrinho(loja, cliente, nome_produto);
		} else if (opcao == 3) { // Se a opção escolhida for 3, o carrinho do cliente é impresso
			imprime_valor_carrinho(cliente);
		}
	}
}
