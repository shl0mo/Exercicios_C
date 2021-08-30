#include <stdio.h>
#include <math.h>

int quantidade_letras(char *palavra, int numero_letras, int i) {
	if (palavra[i] == '\0') {
		return numero_letras;	
	}
	numero_letras = numero_letras + 1;
	i = i + 1;
	quantidade_letras(palavra, numero_letras, i);
}

int palindromo(char *palavra, int numero_letras, int i) {
	if (numero_letras % 2 == 0) {
		if (i == (numero_letras / 2) - 1) {
			if (palavra[i] == palavra[i + 1]) {
				return 1;
			} else {
				return 0;
			}
		}
	} else if (numero_letras % 2 != 0 && i == (int) ceil(7/2))  {
		return 1;
	}
	if (palavra[i] != palavra[numero_letras - (i + 1)]) {
		return 0;
	}
	i = i + 1;
	palindromo(palavra, numero_letras, i);
}

int minuscula(char *palavra, int numero_letras, char *palavra_minuscula, int i) {
	if (palavra[i] == '\0') {
		return 1;
	}
	int valor_ascii = (int) palavra[i];
	if (valor_ascii < 97) {
		int soma_ascii = valor_ascii + 32;
		char caractere = (char)soma_ascii;
		palavra_minuscula[i] = caractere;
	} else {
		palavra_minuscula[i] = palavra[i];
	}
	i = i + 1; 
	minuscula(palavra, numero_letras, palavra_minuscula, i);
}

int main (void) {
	char palavra[200];
	scanf("%s", &palavra);
	int numero_letras = quantidade_letras(palavra, 0, 0);
	char palavra_minuscula[numero_letras];
	minuscula(palavra, numero_letras, palavra_minuscula, 0);
	int e_palindromo = palindromo(palavra_minuscula, numero_letras, 0);
	if (e_palindromo == 1) {
		printf("sim");
	} else {
		printf("nao");
	}
}
