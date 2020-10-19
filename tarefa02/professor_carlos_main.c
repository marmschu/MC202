#include <stdio.h>
#include "professor_carlos.h"

/*1. Ler número de turmas
2. Ler o número de operações
3. Ler o número de alunos
4. Ler os dados dos alunos
5. Ler as operações
6. Executar as operações com os dados fornecidos*/

int main( )
{
    Turma t[50];
    int qtd_turmas;
    int k_operations;
    scanf("%i%i", &qtd_turmas, &k_operations);

    for(int i = 0; i < qtd_turmas; i++)
    {
        scanf("%i ", &t[i].qtd);
        for(int j = 0; j < t[i].qtd; j++)
        {
            Aluno aluno_info;
            scanf("%s %s %i %i %i ", aluno_info.nome, aluno_info.sobrenome, &aluno_info.nascimento.dia,
                  &aluno_info.nascimento.mes, &aluno_info.nascimento.ano);
            t[i].alunos[j] = aluno_info;
        }
    }

    for(int i = 0; i < k_operations; ++i)
    {
        int operacao;
        scanf("%i", &operacao);
        if(operacao == 1)
        {
            int condicao;
            scanf("%i", &condicao);
            printf("%s\n", procura_novo_na_turma(t, qtd_turmas, condicao).nome);
        }
        else
            if(operacao == 2)
            {
                int condicao;
                scanf("%i", &condicao);
                printf("%s\n", procura_velho_na_turma(t, qtd_turmas, condicao).sobrenome);
            }
            else
                if(operacao == 3)
                {
                    printf("%s\n", procura_velho_todas_turmas(t, qtd_turmas).nome);
                }
                else
                    if(operacao == 4)
                    {
                        printf("%s\n", procura_novo_todas_turmas(t, qtd_turmas).sobrenome);
                    }
                    else
                        if(operacao == 5)
                        {
                            char padrao[3];
                            scanf("%s", padrao);
                            printf("%d\n", conta_substrings(t, qtd_turmas, padrao));
                        }
                        else
                            if(operacao == 6)
                            {
                                Aluno alunonovo;
                                int turmaescolhida;
                                scanf("%i%s%s%i%i%i", &turmaescolhida, alunonovo.nome,
                                      alunonovo.sobrenome, &alunonovo.nascimento.dia,
                                      &alunonovo.nascimento.mes, &alunonovo.nascimento.ano);
                                printf("%d\n", add_aluno(t, alunonovo, turmaescolhida));
                            }
                            else
                                if(operacao == 7)
                                {
                                    int turmaescolhida;
                                    scanf("%i", &turmaescolhida);
                                    printf("%d\n", remove_aluno(t, turmaescolhida));
                                }

    }


}