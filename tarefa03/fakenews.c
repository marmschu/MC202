// Marina Mileny RA 221979

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T 25


// Struct para guardar os dados para analise
typedef struct dados
{
    char *termo;
    double *dias_de_analise;
    double valor_maximo, valor_minimo, valor_medio, valor_desvio_padrao;
} Dados;

// Struct para guardar os resultados da analise
typedef struct analise
{
    char *bots, *surpreendentes, *normais, *locais, *irrelevantes;
    int num_bots, num_surpreendentes, num_normais, num_locais, num_irrelevantes;
} Analisx;

// Funções para a manipulação dos dados requisitada
// x = termo a ser analisado, y = numero de dias de analise
double calcula_maximo(Dados *dado, int x, int y)
{
    double maior_porcentagem;
    maior_porcentagem = dado[x].dias_de_analise[0];
    for(int i = 1; i < y; ++i)
    {
        if(maior_porcentagem < dado[x].dias_de_analise[i])
        {
            maior_porcentagem = dado[x].dias_de_analise[i];
        }
    }
    return maior_porcentagem;
}

double calcula_minimo(Dados *dado, int x, int y)
{
    double menor_porcentagem;
    menor_porcentagem = dado[x].dias_de_analise[0];
    for(int i = 1; i < y; ++i)
    {
        if(menor_porcentagem > dado[x].dias_de_analise[i])
        {
            menor_porcentagem = dado[x].dias_de_analise[i];
        }
    }
    return menor_porcentagem;
}

double calcula_media(Dados *dado, int x, int y)
{
    double porcentagem_media;
    double soma = 0;
    for(int i = 0; i < y; ++i)
    {
        soma = soma + dado[x].dias_de_analise[i];
    }
    porcentagem_media = soma / y;
    return porcentagem_media;
}

double calcula_desvio_padrao(Dados *dado, int x, int y)
{
    double media = calcula_media(dado, x, y);
    double desvio_sem_media = 0;
    double desvio;
    for(int i = 0; i < y; ++i)
    {
        desvio_sem_media =
                desvio_sem_media + ((dado[x].dias_de_analise[i] - media) * (dado[x].dias_de_analise[i] - media));
    }
    desvio = sqrt(desvio_sem_media / y);
    return desvio;
}

int main( )
{
    int n, d;
    Dados *informacoes;
    Analisx *analise;
    int j, k, l, m, p, q;

    // Entrada do número de termos e dias de análise
    scanf("%i%i", &n, &d);

    // Malloc para os dados da struct Dados
    informacoes = malloc(n * sizeof(Dados));
    for(int i = 0; i < n; ++i)
    {
        informacoes[i].termo = malloc(T * sizeof(char));
        informacoes[i].dias_de_analise = malloc(d * sizeof(double));
    }

    // Malloc para os dados da struct Analises
    analise = malloc(1 * sizeof(Analisx));
    int mult = n * T;
    analise[0].bots = malloc(mult * sizeof(char));
    analise[0].surpreendentes = malloc(mult * sizeof(char));
    analise[0].normais = malloc(mult * sizeof(char));
    analise[0].locais = malloc(mult * sizeof(char));
    analise[0].irrelevantes = malloc(mult * sizeof(char));

    // Entrada dos termos e valores
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", &informacoes[i].termo[0]);
        for(int j = 0; j < d; ++j)
            scanf("%lf", &informacoes[i].dias_de_analise[j]);
    }

    // Vamos dar a 1ª saída: Termo + os dados calculados
    for(int i = 0; i < n; ++i)
    {
        double maximo_rapido = calcula_maximo(informacoes, i, d);
        double minimo_rapido = calcula_minimo(informacoes, i, d);
        double media_rapido = calcula_media(informacoes, i, d);
        double desvio_rapido = calcula_desvio_padrao(informacoes, i, d);
        printf("%s %.2f %.2f %.2f %.2f\n", informacoes[i].termo, maximo_rapido, minimo_rapido, media_rapido,
               desvio_rapido);
        informacoes[i].valor_maximo = maximo_rapido;
        informacoes[i].valor_minimo = minimo_rapido;
        informacoes[i].valor_medio = media_rapido;
        informacoes[i].valor_desvio_padrao = desvio_rapido;
    }

    // Manipulação com os dados para a 2ª saída
    analise[0].num_bots = 0;
    analise[0].num_surpreendentes = 0;
    analise[0].num_normais = 0;
    analise[0].num_locais = 0;
    analise[0].num_irrelevantes = 0;
    k = 0;
    l = 0;
    m = 0;
    p = 0;
    q = 0;
    for(int i = 0; i < n; ++i)
    {
        if(informacoes[i].valor_medio >= 60)
        {
            if(informacoes[i].valor_desvio_padrao > 15)
            {
                j = 0;
                analise[0].num_bots++;
                while(informacoes[i].termo[j] != '\0')
                    analise[0].bots[k++] = informacoes[i].termo[j++];
                analise[0].bots[k++] = ' ';
            }
            else
            {
                j = 0;
                analise[0].num_surpreendentes++;
                while(informacoes[i].termo[j] != '\0')
                    analise[0].surpreendentes[l++] = informacoes[i].termo[j++];
                analise[0].surpreendentes[l++] = ' ';
            }
        }
        else
        {
            if(informacoes[i].valor_maximo >= 80)
            {
                if(informacoes[i].valor_minimo > 20)
                {
                    j = 0;
                    analise[0].num_normais++;
                    while(informacoes[i].termo[j] != '\0')
                        analise[0].normais[m++] = informacoes[i].termo[j++];
                    analise[0].normais[m++] = ' ';
                }
                else
                {
                    j = 0;
                    analise[0].num_locais++;
                    while(informacoes[i].termo[j] != '\0')
                        analise[0].locais[p++] = informacoes[i].termo[j++];
                    analise[0].locais[p++] = ' ';
                }
            }
            else
            {
                j = 0;
                analise[0].num_irrelevantes++;
                while(informacoes[i].termo[j] != '\0')
                    analise[0].irrelevantes[q++] = informacoes[i].termo[j++];
                analise[0].irrelevantes[q++] = ' ';
            }
        }
    }
    analise[0].bots[(k != 0) ? k - 1 : 0] = '\0';
    analise[0].surpreendentes[(l != 0) ? l - 1 : 0] = '\0';
    analise[0].normais[(m != 0) ? m - 1 : 0] = '\0';
    analise[0].locais[(p != 0) ? p - 1 : 0] = '\0';
    analise[0].irrelevantes[(q != 0) ? q - 1 : 0] = '\0';

    // 2ª saída
    printf("\n");
    printf("RESULTADO:\n");

    printf("Bot (%i): %s\n",
           analise[0].num_bots, &analise[0].bots[0]);

    printf("Surpreendente (%i): %s\n", analise[0].num_surpreendentes, &analise[0].surpreendentes[0]);

    printf("Normal (%i): %s\n", analise[0].num_normais, &analise[0].normais[0]);

    printf("Local (%i): %s\n", analise[0].num_locais, &analise[0].locais[0]);

    printf("Irrelevante (%i): %s\n", analise[0].num_irrelevantes, &analise[0].irrelevantes[0]);
    // free
    for(int i = 0; i < n; ++i)
    {
        free(informacoes[i].termo);
        free(informacoes[i].dias_de_analise);
    }
    free(informacoes);

    free(analise[0].bots);
    free(analise[0].surpreendentes);
    free(analise[0].normais);
    free(analise[0].locais);
    free(analise[0].irrelevantes);
    free(analise);

    return 0;
}