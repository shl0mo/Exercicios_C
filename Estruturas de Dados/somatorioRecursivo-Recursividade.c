#include <stdio.h>
#include <stdlib.h>

typedef struct vetor {
	int numero;
	struct vetor *prox;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor() {
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	novo_vetor->numero = -1;
	novo_vetor->prox = NULL;
}

int insere_vetor(VETORptr vetor, int numero) {
	if (vetor == NULL) 1; 
	if (vetor->prox == NULL) {
		VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
		novo_vetor->numero = numero;
		novo_vetor->prox = NULL;
		vetor->prox = novo_vetor;
		return 1;
	}
	vetor = vetor->prox;	
	return insere_vetor(vetor, numero);
}

int imprime_vetor(VETORptr vetor) {
	if (vetor == NULL) return 1;
	printf("%i\n", vetor->numero);
	vetor = vetor->prox;
	imprime_vetor(vetor);
}

typedef VETOR* VETORptr;

int zero (int numero) {
	if (numero == 0) {
		return 1;
	} else {
		return 0;
	}
}

int incr (int numero) {
	int novo_numero = numero + 1;
	return novo_numero;
}

int decr (int numero) {
	int novo_numero = numero - 1;
	return novo_numero;
}

int negativo(int a) {
	if (a < 0) return 1;
	else return 0;
}

int soma(int num1, int num2) {
	if (num1 == 0) return num2;
	if (negativo(num1)) {
		num1 = incr(num1);
		num2 = decr(num2);
	} else {
		num1 = decr(num1);
		num2 = incr(num2);
	}
	soma(num1, num2);
}

int somatorio_recursivo(VETORptr vetor, int resultado) {
	if (vetor == NULL) return resultado;
	resultado = soma(resultado, vetor->numero);
	somatorio_recursivo(vetor->prox, resultado);
}

int leitura_numeros(VETORptr vetor, int N, int i) {
	if (i == N) return 1; 
	int numero;
	scanf("%i", &numero);
	insere_vetor(vetor, numero);
	i = i + 1;
	leitura_numeros(vetor, N, i);
}


int main(void) {
	int N;
	scanf("%i", &N);
	VETORptr vetor = inicializa_vetor();
	leitura_numeros(vetor, N, 0);
	int somatorio = somatorio_recursivo(vetor->prox, 0);
	printf("%i", somatorio);
}
