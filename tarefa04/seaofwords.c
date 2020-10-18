// Marina Mileny RA 221979

#include <stdio.h>
#include <stdlib.h>


// Para armazenar a matriz de letrar, criei uma matriz lista_palavras;
// Para verificar se a célula que vou checar a continuidade de uma palavra, já foi utilizada nesta mesma palavra, criei uma matriz_visitados;
// Nessa matriz, toda vez que eu passar por uma célula e der paridade ccom a letra k da minha palavra, irei transformar a celula dela em 1;
char lista_palavras[100][100];
int matriz_visitados[100][100];
int n, m, q;

// Medir o tamanho de uma string
int len (char * nome)
{
	int tamanho = 0;
	while (nome[tamanho] != '\0')
	{
		tamanho++;
	}
	return tamanho;
};

// Função para zerar as células já visitadas da minha matriz_visitados;
void zerar(){
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			matriz_visitados[i][j] = 0;
};

// i e j coordenadas da célula em questão, k a letra da palavra em questão;
int verifica_adjacente(int i, int j, int k, char *palavra)
{
	if(k == len(palavra))
		return 1;
	if((palavra[k] != lista_palavras[i][j]) || matriz_visitados[i][j] == 1)
		return 0;
	matriz_visitados[i][j] = 1;
	if(i != 0 && verifica_adjacente(i - 1, j, k + 1, palavra))
		return 1;
	if(j != 0 && verifica_adjacente(i, j - 1, k + 1, palavra))
		return 1;
	if(i != n - 1 && verifica_adjacente(i + 1, j, k + 1, palavra))
		return 1;
	if(j != m - 1 && verifica_adjacente(i, j + 1, k + 1, palavra))
		return 1;
	return 0;	
}


int main()
{
	scanf("%i%i%i", &n, &m, &q);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf(" %c", &lista_palavras[i][j]);
	while(q--)
	{
		int x = 0;
		char palavra[20];
		scanf("%s", palavra);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				zerar();
				if(verifica_adjacente(i, j, 0, palavra) == 1)
				{
					printf("sim\n");
					x++;
					break;
				}
			}
			if(x != 0)
				break;
		}
		if(x == 0)
			printf("nao\n");
	}

}