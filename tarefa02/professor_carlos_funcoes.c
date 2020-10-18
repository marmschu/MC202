// Marina Mileny RA 221979

#include <stdio.h>
#include "professor_carlos.h"


// função para medir o tamanho de uma palavra
int len (char nome[]){
	int tamanho = 0;
	while (nome[tamanho] != '\0'){
		tamanho++;
	}
	return tamanho;
};


// função para comparar idade entre dois alunos
// return = 1 aluno A é mais velho
// return = 0 possuem a mesma idade
// return = -1 aluno B é mais novo
int compara_ano_alunos (Aluno aluno1, Aluno aluno2){
	if (aluno1.nascimento.ano < aluno2.nascimento.ano){
		return -1;
	}
	else if (aluno1.nascimento.ano == aluno2.nascimento.ano){
		return 0;
	}
	else if {
		return 1;
	}
};

int compara_mes_alunos (Aluno aluno1, Aluno aluno2){
	if (aluno1.nascimento.mes < aluno2.nascimento.mes){
		return -1;
	}
	else if (aluno1.nascimento.mes == aluno2.nascimento.mes){
		return 0;
	}
	else if {
		return 1;
	}
};

int compara_dia_alunos (Aluno aluno1, Aluno aluno2){
	if (aluno1.nascimento.dia < aluno2.nascimento.dia){
		return -1;
	}
	else if (aluno1.nascimento.dia == aluno2.nascimento.dia){
		return 0;
	}
	else if {
		return 1;
	}
};

int compara_tamanho_nome_alunos (Aluno aluno1, Aluno aluno2){
		if (len(aluno1.nome) < len(aluno2.nome)){
			return -1;
		}
		else if (len(aluno1.nome) == len(aluno2.nome)){
			return 0;
		}
		else {
			return 1;
		}
};

int compara_tamanho_sobrenome_alunos (Aluno aluno1, Aluno aluno2){
	if (len(aluno1.sobrenome) < len(aluno2.sobrenome)){
		return -1;
	}
	else if {
		return 1;
	}
};



Aluno alunomaisnovo;
Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j) {
	alunomaisnovo = t[j].alunos[0];
	for (int i = 0; i < t[j].qtd; ++i){
		if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
			alunomaisnovo = t[j].alunos[i];
		}
		else if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
			if (compara_mes_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
			alunomaisnovo = t[j].alunos[i];
			}
			else if (compara_mes_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
				if (compara_dia_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
					alunomaisnovo = t[j].alunos[i];
				}
				else if (compara_dia_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
					if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
						alunomaisnovo = t[j].alunos[i];
					}
					else if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
						if (compara_tamanho_sobrenome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
							alunomaisnovo = t[j].alunos[i];
						}
						else {
							alunomaisnovo = t[j].alunos[i+1];
						}
					}
				}
			}
		}
	};
	return alunomaisnovo.nome;
};

Aluno alunomaisnovoturmas;
Aluno procura_novo_todas_turmas(Turma t[], int qtd_turmas) {
	alunomaisnovoturmas = t[0].alunos[0];
	for (int j = 0; j < qtd_turmas; ++j){
		for (int i = 0; i < t[j].qtd; ++i){
			if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
				alunomaisnovoturmas = t[j].alunos[i];
			}
			else if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
				if (compara_mes_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
				alunomaisnovoturmas = t[j].alunos[i];
				}
				else if (compara_mes_alunos(Turma t[], int qtd_turmas, int j, int i) == 0){
					if (compara_dia_alunos(Turma t[], int qtd_turmas, int j, int i) == -1){
						alunomaisnovoturmas = t[j].alunos[i];
					}
					else if (compara_dia_alunos(Turma t[], int qtd_turmas, int j, int i) == 0){
						if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
							alunomaisnovoturmas = t[j].alunos[i];
						}
						else if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
							if (compara_tamanho_sobrenome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
								alunomaisnovoturmas = t[j].alunos[i];
							}
							else {
								alunomaisnovoturmas = t[j].alunos[i+1];
							}
						}
					}
				}
			}
		};
	};
	return alunomaisnovoturmas.sobrenome;
};

Aluno alunomaisvelho;
Aluno procura_velho_na_turma(Turma t[], int qtd_turmas, int j) {
	alunomaisnovo = t[j].alunos[0];
	for (int i = 0; i < t[j].qtd; ++i){
		if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
			alunomaisnovo = t[j].alunos[i];
		}
		else if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
			if (compara_mes_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
			alunomaisnovo = t[j].alunos[i];
			}
			else if (compara_mes_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
				if (compara_dia_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
					alunomaisnovo = t[j].alunos[i];
				}
				else if (compara_dia_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
					if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
						alunomaisnovo = t[j].alunos[i];
					}
					else if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
						if (compara_tamanho_sobrenome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
							alunomaisnovo = t[j].alunos[i];
						}
						else {
							alunomaisnovo = t[j].alunos[i+1];
						}
					}
				}
			}
		}
	};
	return alunomaisnovo.sobrenome;
};

Aluno alunomaisvelhoturmas;
Aluno procura_velho_todas_turmas(Turma t[], int qtd_turmas) {
	alunomaisnovoturmas = t[0].alunos[0];
	for(int j = 0; j < qtd_turmas; ++j){
		for (int i = 0; i < t[j].qtd; ++i){
			if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
				alunomaisnovoturmas = t[j].alunos[i];
			}
			else if (compara_ano_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
				if (compara_mes_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
				alunomaisnovoturmas = t[j].alunos[i];
				}
				else if (compara_mes_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
					if (compara_dia_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
						alunomaisnovoturmas = t[j].alunos[i];
					}
					else if (compara_dia_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
						if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 1){
							alunomaisnovoturmas = t[j].alunos[i];
						}
						else if (compara_tamanho_nome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == 0){
							if (compara_tamanho_sobrenome_alunos(t[j].alunos[i], t[j].alunos[i+1]) == -1){
								alunomaisnovoturmas = t[j].alunos[i];
							}
							else {
								alunomaisnovoturmas = t[j].alunos[i+1];
							}
						}
					}
				}
			}
		};
	};
	return alunomaisnovo.nome;
}


int conta_substrings(Turma t[], int qtd_turmas, char *padrao) {
	int contagem = 0;
	for (int i = 0, i < qtd_turmas, ++i){
		for (int j = 0, j < t[i].qtd, j++){
			for(int k, t[j].alunos[i].nome[k] != '\0', k++){
				if (t[j].alunos[i].nome[k] = *padrao){
					contagem++;
				}
			};

		};
	};
	return contagem;
};


int add_aluno(Turma t[], Aluno A, int j){
	int espaco = t[j].qtd;
	t[j].alunos[espaco] = A;
	t[j].qtd = t[j].qtd++;
	return t[j].qtd;
};


int remove_aluno(Turma t[], int j){
	t[j].qtd = t[j].qtd--;
	return t[j].qtd;
};