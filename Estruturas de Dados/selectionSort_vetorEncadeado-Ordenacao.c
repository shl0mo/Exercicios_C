#include <stdio.h>
#include <stdlib.h>

typedef struct vetor {
	char pais[20];
	int ouro;
	int prata;
	int bronze;
	struct vetor *prox, *ant;
}VETOR;

typedef VETOR* VETORptr;

VETORptr inicializa_vetor() {
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	int i;
	for (i = 0; i < 20; i++) {
		novo_vetor->pais[i] = '\0';
	}
	novo_vetor->ouro = -1;
	novo_vetor->prata = -1;
	novo_vetor->bronze = -1;
	novo_vetor->ant = NULL;
	novo_vetor->prox = NULL;
	return novo_vetor;
}

void insere_vetor(VETORptr vetor, char pais[20], int ouro, int prata, int bronze) {
	VETORptr percorre_vetor = vetor;
	while (percorre_vetor->prox != NULL) {
		percorre_vetor = percorre_vetor->prox;
	}
	VETORptr novo_vetor = (VETORptr) malloc(sizeof(VETOR));
	int i;
	for (i = 0; i < 20; i++) {
		novo_vetor->pais[i] = pais[i];
	}
	novo_vetor->ouro = ouro;
	novo_vetor->prata = prata;
	novo_vetor->bronze = bronze;
	novo_vetor->ant = percorre_vetor;
	novo_vetor->prox = NULL;
	percorre_vetor->prox = novo_vetor;
}

void imprime_vetor(VETORptr vetor) {
	VETORptr percorre_vetor = vetor->prox;
	while (percorre_vetor) {
		printf("%s %i %i %i\n", percorre_vetor->pais, percorre_vetor->ouro, percorre_vetor->prata, percorre_vetor->bronze);
		percorre_vetor = percorre_vetor->prox;
	}
}

void remove_vetor(VETORptr no) {
	no->ant->prox = no->prox;
	no->prox->ant = no->ant;
}

void troca_1(VETORptr posicao_insercao, VETORptr percorre_vetor) {
	char aux_pais[20];
	int i;
	for (i = 0; i < 20; i++) {
		aux_pais[i] = posicao_insercao->pais[i];
	}
	int aux_ouro = posicao_insercao->ouro;
	int aux_prata = posicao_insercao->prata;
	int aux_bronze = posicao_insercao->bronze;
	for (i = 0; i < 20; i++) {
		posicao_insercao->pais[i] = percorre_vetor->pais[i];
	}
	posicao_insercao->ouro = percorre_vetor->ouro;
	posicao_insercao->prata = percorre_vetor->prata;
	posicao_insercao->bronze = percorre_vetor->bronze;
	for (i = 0; i < 20; i++) {
		percorre_vetor->pais[i] = aux_pais[i];
	}
	percorre_vetor->ouro = aux_ouro;
	percorre_vetor->prata = aux_prata;
	percorre_vetor->bronze = aux_bronze;
	posicao_insercao = posicao_insercao->prox;
}

void selection_sort(VETORptr vetor) {
	if (vetor->prox != NULL) {
		VETORptr posicao_insercao = vetor->prox;
		VETORptr percorre_posicao_insercao = posicao_insercao;
		while (percorre_posicao_insercao) {
			VETORptr percorre_vetor = posicao_insercao;
			while (percorre_vetor) {
				int tem_maior = 0;
				VETORptr percorre_vetor_inicio = posicao_insercao;
				while (percorre_vetor_inicio) {
					if (percorre_vetor_inicio->ouro > percorre_vetor->ouro) {
						tem_maior = 1;
					}
					percorre_vetor_inicio = percorre_vetor_inicio->prox;
				}
				percorre_vetor_inicio = posicao_insercao;
				while (percorre_vetor_inicio) {
					if (percorre_vetor_inicio->ouro == percorre_vetor->ouro &&  percorre_vetor_inicio != percorre_vetor && tem_maior == 0) {
						tem_maior = 2;
						if (percorre_vetor_inicio->prata > percorre_vetor->prata) {
							//Salva a posição para a qual percorre_vetor_inicio deve ser movido
							VETORptr aux = posicao_insercao;
							//'Backup' dos valores dessa posição 
							char aux_pais[20];
							int i;
							for (i = 0; i < 20; i++) {
								aux_pais[i] = posicao_insercao->pais[i];
							}
							int aux_ouro = posicao_insercao->ouro;
							int aux_prata = posicao_insercao->prata;
							int aux_bronze = posicao_insercao->bronze;
							//Insere nessa posição os valores de percorre_vetor_inicio, 'movendo-o' para posicao_insercao
							for (i = 0; i < 20; i++) {
								posicao_insercao->pais[i] = percorre_vetor_inicio->pais[i];
							}
							posicao_insercao->ouro = percorre_vetor_inicio->ouro;
							posicao_insercao->prata = percorre_vetor_inicio->prata;
							posicao_insercao->bronze = percorre_vetor_inicio->bronze;
							//Passamos os valores do 'backup' para percorre_vetor_inicio
							for (i = 0; i < 20; i++) {
								percorre_vetor_inicio->pais[i] = aux_pais[i];
							}
							percorre_vetor_inicio->ouro = aux_ouro;
							percorre_vetor_inicio->prata = aux_prata;
							percorre_vetor_inicio->bronze = aux_bronze;
							//Atualizaçaõ de posicao insercao
							posicao_insercao = aux;
							posicao_insercao = posicao_insercao->prox;
						} else if (percorre_vetor_inicio->prata == percorre_vetor->prata && percorre_vetor_inicio != percorre_vetor) {
							if (percorre_vetor_inicio->bronze > percorre_vetor->bronze) {
								//Salva a posição para a qual percorre_vetor_inicio deve ser movido
								VETORptr aux = posicao_insercao;
								//'Backup' dos valores dessa posição 
								char aux_pais[20];
								int i;
								for (i = 0; i < 20; i++) {
									aux_pais[i] = posicao_insercao->pais[i];
								}
								int aux_ouro = posicao_insercao->ouro;
								int aux_prata = posicao_insercao->prata;
								int aux_bronze = posicao_insercao->bronze;
								//Insere nessa posição os valores de percorre_vetor_inicio, 'movendo-o' para posicao_insercao
								for (i = 0; i < 20; i++) {
									posicao_insercao->pais[i] = percorre_vetor_inicio->pais[i];
								}
								posicao_insercao->ouro = percorre_vetor_inicio->ouro;
								posicao_insercao->prata = percorre_vetor_inicio->prata;
								posicao_insercao->bronze = percorre_vetor_inicio->bronze;
								//Passamos os valores do 'backup' para percorre_vetor_inicio
								for (i = 0; i < 20; i++) {
									percorre_vetor_inicio->pais[i] = aux_pais[i];
								}
								percorre_vetor_inicio->ouro = aux_ouro;
								percorre_vetor_inicio->prata = aux_prata;
								percorre_vetor_inicio->bronze = aux_bronze;
								//Atualizaçaõ de posicao insercao
								posicao_insercao = aux;
								posicao_insercao = posicao_insercao->prox;
							} else if (percorre_vetor_inicio->bronze == percorre_vetor->bronze && percorre_vetor_inicio != percorre_vetor) {
								if (percorre_vetor_inicio->pais[0] < percorre_vetor->pais[0]) {
									//Salva a posição para a qual percorre_vetor_inicio deve ser movido
									VETORptr aux = posicao_insercao;
									//'Backup' dos valores dessa posição 
									char aux_pais[20];
									int i;
									for (i = 0; i < 20; i++) {
										aux_pais[i] = posicao_insercao->pais[i];
									}
									int aux_ouro = posicao_insercao->ouro;
									int aux_prata = posicao_insercao->prata;
									int aux_bronze = posicao_insercao->bronze;
									//Insere nessa posição os valores de percorre_vetor_inicio, 'movendo-o' para posicao_insercao
									for (i = 0; i < 20; i++) {
										posicao_insercao->pais[i] = percorre_vetor_inicio->pais[i];
									}
									posicao_insercao->ouro = percorre_vetor_inicio->ouro;
									posicao_insercao->prata = percorre_vetor_inicio->prata;
									posicao_insercao->bronze = percorre_vetor_inicio->bronze;
									//Passamos os valores do 'backup' para percorre_vetor_inicio
									for (i = 0; i < 20; i++) {
										percorre_vetor_inicio->pais[i] = aux_pais[i];
									}
									percorre_vetor_inicio->ouro = aux_ouro;
									percorre_vetor_inicio->prata = aux_prata;
									percorre_vetor_inicio->bronze = aux_bronze;
									//Atualizaçaõ de posicao insercao
									posicao_insercao = aux;
									posicao_insercao = posicao_insercao->prox;
								} else {
									VETORptr aux = posicao_insercao;
									char aux_pais[20];
									int i;
									for (i = 0; i < 20; i++) {
										aux_pais[i] = posicao_insercao->pais[i];
									}
									int aux_ouro = posicao_insercao->ouro;
									int aux_prata = posicao_insercao->prata;
									int aux_bronze = posicao_insercao->bronze;
									for (i = 0; i < 20; i++) {
										posicao_insercao->pais[i] = percorre_vetor->pais[i];
									}
									posicao_insercao->ouro = percorre_vetor->ouro;
									posicao_insercao->prata = percorre_vetor->prata;
									posicao_insercao->bronze = percorre_vetor->bronze;
									for (i = 0; i < 20; i++) {
										percorre_vetor->pais[i] = aux_pais[i];
									}
									percorre_vetor->ouro = aux_ouro;
									percorre_vetor->prata = aux_prata;
									percorre_vetor->bronze = aux_bronze;
									posicao_insercao = aux;
									posicao_insercao = posicao_insercao->prox;
								}
							} else {
								VETORptr aux = posicao_insercao;
								char aux_pais[20];
								int i;
								for (i = 0; i < 20; i++) {
									aux_pais[i] = posicao_insercao->pais[i];
								}
								int aux_ouro = posicao_insercao->ouro;
								int aux_prata = posicao_insercao->prata;
								int aux_bronze = posicao_insercao->bronze;
								for (i = 0; i < 20; i++) {
									posicao_insercao->pais[i] = percorre_vetor->pais[i];
								}
								posicao_insercao->ouro = percorre_vetor->ouro;
								posicao_insercao->prata = percorre_vetor->prata;
								posicao_insercao->bronze = percorre_vetor->bronze;
								for (i = 0; i < 20; i++) {
									percorre_vetor->pais[i] = aux_pais[i];
								}
								percorre_vetor->ouro = aux_ouro;
								percorre_vetor->prata = aux_prata;
								percorre_vetor->bronze = aux_bronze;
								posicao_insercao = aux;
								posicao_insercao = posicao_insercao->prox;
							}
						} else {
							VETORptr aux = posicao_insercao;
							char aux_pais[20];
							int i;
							for (i = 0; i < 20; i++) {
								aux_pais[i] = posicao_insercao->pais[i];
							}
							int aux_ouro = posicao_insercao->ouro;
							int aux_prata = posicao_insercao->prata;
							int aux_bronze = posicao_insercao->bronze;
							for (i = 0; i < 20; i++) {
								posicao_insercao->pais[i] = percorre_vetor->pais[i];
							}
							posicao_insercao->ouro = percorre_vetor->ouro;
							posicao_insercao->prata = percorre_vetor->prata;
							posicao_insercao->bronze = percorre_vetor->bronze;
							for (i = 0; i < 20; i++) {
								percorre_vetor->pais[i] = aux_pais[i];
							}
							percorre_vetor->ouro = aux_ouro;
							percorre_vetor->prata = aux_prata;
							percorre_vetor->bronze = aux_bronze;
							posicao_insercao = aux;
							posicao_insercao = posicao_insercao->prox;
						}
					}
					percorre_vetor_inicio = percorre_vetor_inicio->prox;
				}
				if (tem_maior == 0) {
					VETORptr aux = posicao_insercao;
					char aux_pais[20];
					int i;
					for (i = 0; i < 20; i++) {
						aux_pais[i] = posicao_insercao->pais[i];
					}
					int aux_ouro = posicao_insercao->ouro;
					int aux_prata = posicao_insercao->prata;
					int aux_bronze = posicao_insercao->bronze;
					for (i = 0; i < 20; i++) {
						posicao_insercao->pais[i] = percorre_vetor->pais[i];
					}
					posicao_insercao->ouro = percorre_vetor->ouro;
					posicao_insercao->prata = percorre_vetor->prata;
					posicao_insercao->bronze = percorre_vetor->bronze;
					for (i = 0; i < 20; i++) {
						percorre_vetor->pais[i] = aux_pais[i];
					}
					percorre_vetor->ouro = aux_ouro;
					percorre_vetor->prata = aux_prata;
					percorre_vetor->bronze = aux_bronze;
					posicao_insercao = aux;
					posicao_insercao = posicao_insercao->prox;
				}
				percorre_vetor = percorre_vetor->prox;
			}
			percorre_posicao_insercao = percorre_posicao_insercao->prox;
		}
	}
}

int main (void) {
	VETORptr vetor_medalhas = inicializa_vetor();
	int n, i;
	i = 0;
	scanf("%i", &n);
	while (i < n) {
		char pais[20];
		int ouro;
		int prata;
		int bronze;
		scanf("%s", pais);
		scanf("%i", &ouro);
		scanf("%i", &prata);
		scanf("%i", &bronze);
		insere_vetor(vetor_medalhas, pais, ouro, prata, bronze);
		i++;
	}
	selection_sort(vetor_medalhas);
	imprime_vetor(vetor_medalhas);
}
