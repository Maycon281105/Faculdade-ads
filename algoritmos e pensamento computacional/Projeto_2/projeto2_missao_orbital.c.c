#include <stdio.h>

/*
    Projeto 2 - Missão Orbital
    Nome: Maycon Sousa Lima
    RGM:47135379
*/

int main() {

    int pontuacao;
    int total;
    double media;
    int etapa;
    int continuar;

    do {

        total = 0;

        printf("\n=== MISSAO ORBITAL ===\n");

        for (etapa = 1; etapa <= 3; etapa++) {

            printf("Digite a pontuacao da etapa %d (0 a 100): ", etapa);
            scanf("%d", &pontuacao);

            while (pontuacao < 0 || pontuacao > 100) {
                printf("Pontuacao invalida! Digite novamente: ");
                scanf("%d", &pontuacao);
            }

            total = total + pontuacao;
        }

        media = total / 3.0;

        printf("\n=== RESULTADO ===\n");
        printf("Pontuacao total: %d\n", total);
        printf("Media: %.2lf\n", media);

        if (total == 300) {
            printf("PONTUACAO MAXIMA!\n");
        }

        if (media >= 90) {
            printf("Comandante da missao\n");
        }
        else if (media >= 70) {
            printf("Piloto aprovado\n");
        }
        else {
            printf("Treinamento reiniciado\n");
        }

        printf("\nDeseja avaliar outro cadete? (1-Sim / 0-Nao): ");
        scanf("%d", &continuar);

        while (continuar != 0 && continuar != 1) {
            printf("Resposta invalida! Digite 1 para Sim ou 0 para Nao: ");
            scanf("%d", &continuar);
        }

    } while (continuar == 1);

    printf("\nPrograma encerrado!\n");

    return 0;
}