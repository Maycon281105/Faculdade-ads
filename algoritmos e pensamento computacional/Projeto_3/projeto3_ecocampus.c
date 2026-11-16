/*
 * Projeto 3 - EcoCampus: Monitor de Consumo Inteligente
 * Disciplina: Algoritmos e Pensamento Computacional
 * Professor: Vinicius Alves
 *
 * O programa le o arquivo consumo_campus.txt (local, consumo, limite),
 * calcula alguns indicadores e mostra o resultado no terminal e
 * tambem grava no arquivo relatorio_consumo.txt.
 */

#include <stdio.h>
#include <string.h>

/* Imprime o relatorio em qualquer "saida": pode ser stdout (tela)
 * ou um arquivo. Assim o texto fica igual nos dois lugares. */
void imprimir_relatorio(FILE *saida, int quantidade, float total, float media,
                        char nome_maior[], float maior,
                        char nome_menor[], float menor, int alertas)
{
    fprintf(saida, "========== ECOCAMPUS ==========\n");
    fprintf(saida, "Locais analisados: %d\n", quantidade);
    fprintf(saida, "Consumo total: %.2f litros\n", total);
    fprintf(saida, "Consumo medio: %.2f litros\n", media);
    fprintf(saida, "Maior consumo: %s - %.2f litros\n", nome_maior, maior);
    fprintf(saida, "Menor consumo: %s - %.2f litros\n", nome_menor, menor);
    fprintf(saida, "Locais em alerta: %d\n", alertas);
    fprintf(saida, "================================\n");
}

int main()
{
    FILE *entrada;   /* ponteiro para o arquivo de dados */
    FILE *relatorio; /* ponteiro para o arquivo do relatorio */

    char nome[50];       /* nome do local lido */
    float consumo;       /* consumo lido */
    float limite;        /* limite recomendado lido */

    int quantidade = 0;  /* contador de locais */
    int alertas = 0;     /* contador de locais acima do limite */
    float total = 0;     /* acumulador do consumo */
    float media = 0;

    char nome_maior[50] = "";
    char nome_menor[50] = "";
    float maior = 0;
    float menor = 0;

    /* abre o arquivo no modo leitura */
    entrada = fopen("consumo_campus.txt", "r");

    /* se nao abriu, o ponteiro fica NULL: avisa e encerra */
    if (entrada == NULL)
    {
        printf("Erro: nao foi possivel abrir o arquivo consumo_campus.txt\n");
        return 1;
    }

    /* o fscanf devolve quantos campos conseguiu ler.
     * Se for 3, a linha esta completa; no fim do arquivo devolve EOF,
     * entao o laco para sozinho e funciona com qualquer numero de linhas. */
    while (fscanf(entrada, "%49s %f %f", nome, &consumo, &limite) == 3)
    {
        quantidade++;
        total = total + consumo;

        /* na primeira linha, ela mesma e o maior e o menor */
        if (quantidade == 1)
        {
            maior = consumo;
            strcpy(nome_maior, nome);
            menor = consumo;
            strcpy(nome_menor, nome);
        }
        else
        {
            if (consumo > maior)
            {
                maior = consumo;
                strcpy(nome_maior, nome);
            }
            if (consumo < menor)
            {
                menor = consumo;
                strcpy(nome_menor, nome);
            }
        }

        /* conta o alerta quando passou do limite */
        if (consumo > limite)
        {
            alertas++;
        }
    }

    fclose(entrada);

    /* evita divisao por zero se o arquivo estiver vazio */
    if (quantidade == 0)
    {
        printf("Nenhum registro valido encontrado em consumo_campus.txt\n");
        return 1;
    }

    media = total / quantidade;

    /* mostra na tela */
    imprimir_relatorio(stdout, quantidade, total, media,
                       nome_maior, maior, nome_menor, menor, alertas);

    /* grava o mesmo texto no arquivo */
    relatorio = fopen("relatorio_consumo.txt", "w");
    if (relatorio == NULL)
    {
        printf("Erro: nao foi possivel criar relatorio_consumo.txt\n");
        return 1;
    }

    imprimir_relatorio(relatorio, quantidade, total, media,
                       nome_maior, maior, nome_menor, menor, alertas);

    fclose(relatorio);

    printf("Relatorio salvo em relatorio_consumo.txt\n");
    return 0;
}
