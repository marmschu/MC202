// Marina Mileny RA 221979

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define T 25


// Struct para guardar os dados para analise
typedef struct dados{
	char *termo;	
	double *dias_de_analise;
	double valor_maximo, valor_minimo, valor_medio, valor_desvio_padrao;
} Dados;

typedef struct analise{
	char *bots;
	char *surpreendentes;
	char *normais;
	char *locais;
	char *irrelevantes;
	int num_bots;
	int num_surpreendentes;
	int num_normais;
	int num_locais;
	int num_irrelevantes;
} Analise;

// Funções para a manipulação dos dados requisitada
// x = termo a ser analisado, y = numero de dias de analise
double calcula_maximo(Dados *dado, int x, int y){
	double maior_porcentagem;
	maior_porcentagem = dado[x].dias_de_analise[0];
	for (int i = 1; i < y; ++i)
	{
		if (maior_porcentagem < dado[x].dias_de_analise[i]){
			maior_porcentagem = dado[x].dias_de_analise[i];
		}
	}
	return maior_porcentagem;
}

double calcula_minimo(Dados *dado, int x, int y){
	double menor_porcentagem;
	menor_porcentagem = dado[x].dias_de_analise[0];
	for (int i = 1; i < y; ++i)
	{
		if (menor_porcentagem > dado[x].dias_de_analise[i]){
			menor_porcentagem = dado[x].dias_de_analise[i];
		}
	}
	return menor_porcentagem;
}

double calcula_media(Dados *dado, int x, int y){
	double porcentagem_media;
	double soma = 0;
	for (int i = 0; i < y; ++i)
	{
		soma = soma + dado[x].dias_de_analise[i];
	}
	porcentagem_media = soma / y;
	return porcentagem_media;
}

double calcula_desvio_padrao(Dados *dado, int x, int y){
	double media = calcula_media(dado, x, y);
	double desvio_sem_media = 0;
	double desvio;
	for (int i = 0; i < y; ++i)
	{
		desvio_sem_media = desvio_sem_media + ( (dado[x].dias_de_analise[i] - media) * (dado[x].dias_de_analise[i] - media) );
	}
	desvio = sqrt( desvio_sem_media / y );
	return desvio;
}


int main(){

	int n, d;
	Dados *informacoes;
	Analise analise;
	analise.num_bots = 0;
	analise.num_surpreendentes = 0;
	analise.num_normais = 0;
	analise.num_locais = 0;
	analise.num_irrelevantes = 0;

	// Entrada do número de termos e dias de análise
	scanf("%i%i", &n, &d);

	// Malloc para os dados da struct Dados
	informacoes = malloc(n * sizeof(Dados));
	for (int i = 0; i < n; ++i){
		informacoes[i].termo = malloc(T * sizeof(char));
		informacoes[i].dias_de_analise = malloc(d * sizeof(double));
	}

	// Malloc para os dados da struct Analises
	analise.bots = malloc( n * T * sizeof(char));
	analise.surpreendentes = malloc( n * T * sizeof(char));
	analise.normais = malloc( n * T * sizeof(char));
	analise.locais = malloc( n * T * sizeof(char));
	analise.irrelevantes = malloc( n * T * sizeof(char));

	// Entrada dos termos e valores
	for (int i = 0; i < n; ++i){
		scanf("%s", &informacoes[i].termo[0]);
		for (int j = 0; j < d; ++j)
			scanf("%lf", &informacoes[i].dias_de_analise[j]);
	}

	// Vamos dar a 1ª saída: Termo + os dados calculados
	for (int i = 0; i < n; ++i){
		double maximo_rapido = calcula_maximo(informacoes, i, d);
		double minimo_rapido = calcula_minimo(informacoes, i, d);
		double media_rapido = calcula_media(informacoes, i, d);
		double desvio_rapido = calcula_desvio_padrao(informacoes, i, d);
		printf("%s %.2f %.2f %.2f %.2f\n", informacoes[i].termo, maximo_rapido, minimo_rapido, media_rapido, desvio_rapido);
		informacoes[i].valor_maximo = maximo_rapido;
		informacoes[i].valor_minimo = minimo_rapido;
		informacoes[i].valor_medio = media_rapido;
		informacoes[i].valor_desvio_padrao = desvio_rapido;
	}

	// Agora a 2ª saída com as análises
	for (int i = 0; i < n; ++i)
	{
		char espaco[1];
		espaco[0] = ' ';
		if (informacoes[i].valor_medio >= 60)
		{
			if (informacoes[i].valor_desvio_padrao > 15)
			{
				analise.num_bots++;
				strcat(analise.bots, espaco);
				strcat(analise.bots, informacoes[i].termo);
			}
			else
			{
				analise.num_surpreendentes++;
				strcat(analise.surpreendentes, espaco);
				strcat(analise.surpreendentes, informacoes[i].termo);
			}	
		}
		else
		{
			if (informacoes[i].valor_maximo >= 80)
			{
				if (informacoes[i].valor_minimo > 20)
				{
					analise.num_normais++;
					strcat(analise.normais, espaco);
					strcat(analise.normais, informacoes[i].termo);
				}
				else
				{
					analise.num_locais++;
					strcat(analise.locais, espaco);
					strcat(analise.locais, informacoes[i].termo);
				}
			}
			else
			{
				analise.num_irrelevantes++;
				strcat(analise.irrelevantes, espaco);
				strcat(analise.irrelevantes, informacoes[i].termo);
			}
		}
	}

	/*for (int i = 0; i < n; ++i){
		printf("%s\n", &informacoes[i].termo[0]);
		for (int j = 0; j < d; ++j){
			printf("%f\n", informacoes[i].dias_de_analise[j]);
		}
		printf("\n");
	}*/

	printf("\n");
	printf("RESULTADO:\n");

	printf("Bot (%i):%s\nSurpreendente (%i):%s\nNormal (%i):%s\nLocal (%i):%s\nIrrelevante (%i):%s\n",
		analise.num_bots, &analise.bots[0], analise.num_surpreendentes, &analise.surpreendentes[0],
		analise.num_normais, &analise.normais[0], analise.num_locais, &analise.locais[0],
		analise.num_irrelevantes, &analise.irrelevantes[0]);

/*	printf("%f\n%f\n%f\n%f\n", informacoes[0].valor_maximo, informacoes[0].valor_minimo, informacoes[0].valor_medio,
		informacoes[0].valor_desvio_padrao );*/

// free
	for (int i = 0; i < n; ++i)
	{
		free(informacoes[i].termo);
		free(informacoes[i].dias_de_analise);
	}
	free(informacoes);

	free(analise.bots);
	free(analise.surpreendentes);
	free(analise.normais);
	free(analise.locais);
	free(analise.irrelevantes);
	return 0;
}