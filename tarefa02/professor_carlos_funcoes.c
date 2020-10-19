#include <stdio.h>
#include "professor_carlos.h"


// função para medir o tamanho de uma palavra
int len(char *nome)
{

    int tamanho = 0;
    while(nome[tamanho] != '\0')
    {
        tamanho++;
    }

    return tamanho;
};

// função para comparar idade entre dois alunos
// return = 1 aluno1 é mais velho
// return = 0 possuem a mesma idade
// return = -1 aluno2 é mais velho
int compara_idade_alunos(Aluno aluno1, Aluno aluno2)
{

    int dias_vividos_1 = aluno1.nascimento.dia + aluno1.nascimento.mes * 30 + aluno1.nascimento.ano * 365;
    int dias_vividos_2 = aluno2.nascimento.dia + aluno2.nascimento.mes * 30 + aluno2.nascimento.ano * 365;

    if(dias_vividos_1 < dias_vividos_2)
    {
        return 1;
    }
    else
        if(dias_vividos_1 == dias_vividos_2)
        {
            return 0;
        }
        else
        {
            return -1;
        }
};

int compara_nome_alunos(Aluno aluno1, Aluno aluno2)
{

    for(int i = 0; i < len(aluno1.nome); i++)
    {
        if(aluno1.nome[i] < aluno2.nome[i])
        {
            return -1;
            break;
        }
        else
            if(aluno1.nome[i] > aluno2.nome[i])
            {
                return 1;
                break;
            }
    }

    return 0;
};

int compara_sobrenome_alunos(Aluno aluno1, Aluno aluno2)
{

    for(int i = 0; i < len(aluno1.sobrenome); i++)
    {
        if(aluno1.sobrenome[i] < aluno2.sobrenome[i])
        {
            return -1;
            break;
        }
        else
            if(aluno1.sobrenome[i] > aluno2.sobrenome[i])
            {
                return 1;
                break;
            }
    }

    return 0;
};

int compara(char *string, char *substring)
{
    int y = len(string);
    int x = len(substring);
    int i = 0, j = 0;
    int eh_string = 0;
    while(i != y - x + 1)
    {
        int z = 1;
        for(j = 0; j < x; ++j)
            if(string[i + j] != substring[j])
                z = 0;
        if(z == 1)
            eh_string += 1;
        i++;
    }
    return (eh_string > 0 ? 1 : 0);
};

// Funções solicitadas pelo enunciado
Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j)
{

    Aluno aluno_mais_novo;
    aluno_mais_novo = t[j].alunos[0];

    for(int i = 1; i < t[j].qtd; ++i)
    {
        if(compara_idade_alunos(aluno_mais_novo, t[j].alunos[i]) == 1)
        {
            aluno_mais_novo = t[j].alunos[i];
        }
        else
            if(compara_idade_alunos(aluno_mais_novo, t[j].alunos[i]) == 0)
            {
                int resul_nome = compara_nome_alunos(aluno_mais_novo, t[j].alunos[i]);
                if(resul_nome == 1)
                {
                    aluno_mais_novo = t[j].alunos[i];
                }
                else
                    if(resul_nome == 0)
                    {
                        if(compara_sobrenome_alunos(aluno_mais_novo, t[j].alunos[i]) == 1)
                        {
                            aluno_mais_novo = t[j].alunos[i];
                        }
                    }
            }
    }

    return aluno_mais_novo;
};

Aluno procura_novo_todas_turmas(Turma t[], int qtd_turmas)
{

    Aluno aluno_mais_novo_todas_t;
    aluno_mais_novo_todas_t = t[0].alunos[0];
    for(int j = 0; j < qtd_turmas; ++j)
    {
        for(int i = 0; i < t[j].qtd; ++i)
        {
            if(compara_idade_alunos(aluno_mais_novo_todas_t, t[j].alunos[i]) == 1)
            {
                aluno_mais_novo_todas_t = t[j].alunos[i];
            }
            else
                if(compara_idade_alunos(aluno_mais_novo_todas_t, t[j].alunos[i]) == 0)
                {
                    if(compara_nome_alunos(aluno_mais_novo_todas_t, t[j].alunos[i]) == 1)
                    {
                        aluno_mais_novo_todas_t = t[j].alunos[i];
                    }
                    else
                        if(compara_nome_alunos(aluno_mais_novo_todas_t, t[j].alunos[i]) == 0)
                        {
                            if(compara_sobrenome_alunos(aluno_mais_novo_todas_t, t[j].alunos[i]) == 1)
                            {
                                aluno_mais_novo_todas_t = t[j].alunos[i];
                            }
                        }
                };
        };
    }

    return aluno_mais_novo_todas_t;
};

Aluno procura_velho_na_turma(Turma t[], int qtd_turmas, int j)
{

    Aluno aluno_mais_velho;
    aluno_mais_velho = t[j].alunos[0];
    for(int i = 1; i < t[j].qtd; ++i)
    {
        if(compara_idade_alunos(aluno_mais_velho, t[j].alunos[i]) == -1)
        {
            aluno_mais_velho = t[j].alunos[i];
        }
        else
            if(compara_idade_alunos(aluno_mais_velho, t[j].alunos[i]) == 0)
            {
                if(compara_nome_alunos(aluno_mais_velho, t[j].alunos[i]) == 1)
                {
                    aluno_mais_velho = t[j].alunos[i];
                }
                else
                    if(compara_nome_alunos(aluno_mais_velho, t[j].alunos[i]) == 0)
                    {
                        if(compara_sobrenome_alunos(aluno_mais_velho, t[j].alunos[i]) == 1)
                        {
                            aluno_mais_velho = t[j].alunos[i];
                        }
                    }
            }
    }

    return aluno_mais_velho;
};

Aluno procura_velho_todas_turmas(Turma t[], int qtd_turmas)
{

    Aluno aluno_mais_velho;
    aluno_mais_velho = t[0].alunos[0];
    for(int j = 0; j < qtd_turmas; j++)
    {
        for(int i = 0; i < t[j].qtd; ++i)
        {
            if(compara_idade_alunos(aluno_mais_velho, t[j].alunos[i]) == -1)
            {
                aluno_mais_velho = t[j].alunos[i];
            }
            else
                if(compara_idade_alunos(aluno_mais_velho, t[j].alunos[i]) == 0)
                {
                    if(compara_nome_alunos(aluno_mais_velho, t[j].alunos[i]) == 1)
                    {
                        aluno_mais_velho = t[j].alunos[i];
                    }
                    else
                        if(compara_nome_alunos(aluno_mais_velho, t[j].alunos[i]) == 0)
                        {
                            if(compara_sobrenome_alunos(aluno_mais_velho, t[j].alunos[i]) == 1)
                            {
                                aluno_mais_velho = t[j].alunos[i];
                            }
                        }
                }
        }
    };

    return aluno_mais_velho;
};

int conta_substrings(Turma t[], int qtd_turmas, char *padrao)
{
    int qtd_ss = 0;
    for(int i = 0; i < qtd_turmas; ++i)
    {
        for(int j = 0; j < t[i].qtd; ++j)
        {
            if(compara(t[i].alunos[j].nome, padrao) == 1)
                qtd_ss++;
        }
    }
    return qtd_ss;
};

int add_aluno(Turma t[], Aluno A, int j)
{

    int espaco = t[j].qtd;
    t[j].alunos[espaco] = A;
    t[j].qtd = t[j].qtd + 1;

    return t[j].qtd;
};

int remove_aluno(Turma t[], int j)
{

    t[j].qtd = t[j].qtd - 1;

    return t[j].qtd;
};