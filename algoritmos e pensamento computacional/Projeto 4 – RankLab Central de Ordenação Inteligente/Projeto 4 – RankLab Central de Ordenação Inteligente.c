
#include <stdio.h>

void exibirCabecalho(void);
void lerPontuacoes(int v[], int n);
void copiarVetor(int origem[], int destino[], int n);
void exibirVetor(int v[], int n);

int bubbleSort(int v[], int n);
int selectionSort(int v[], int n);
int insertionSort(int v[], int n);

int vetoresIguais(int a[], int b[], int n);

int main() {

    int pontuacoes[10];
    int bubble[10];
    int selection[10];
    int insertion[10];

    int compBubble, compSelection, compInsertion;

    exibirCabecalho();

    lerPontuacoes(pontuacoes, 10);

    copiarVetor(pontuacoes, bubble, 10);
    copiarVetor(pontuacoes, selection, 10);
    copiarVetor(pontuacoes, insertion, 10);

    compBubble = bubbleSort(bubble, 10);
    compSelection = selectionSort(selection, 10);
    compInsertion = insertionSort(insertion, 10);

    printf("\nOriginal: ");
    exibirVetor(pontuacoes, 10);

    printf("Bubble: ");
    exibirVetor(bubble, 10);

    printf("Selection: ");
    exibirVetor(selection, 10);

    printf("Insertion: ");
    exibirVetor(insertion, 10);

    if (vetoresIguais(bubble, selection, 10) &&
        vetoresIguais(bubble, insertion, 10)) {

        printf("\nResultados equivalentes: SIM\n");

    } else {

        printf("\nResultados equivalentes: NAO\n");
    }

    printf("\nMenor pontuacao: %d\n", bubble[0]);
    printf("Maior pontuacao: %d\n", bubble[9]);

    printf("Mediana: %.2f\n", (bubble[4] + bubble[5]) / 2.0);

    printf("\nComparacoes:\n");
    printf("Bubble Sort: %d\n", compBubble);
    printf("Selection Sort: %d\n", compSelection);
    printf("Insertion Sort: %d\n", compInsertion);

    printf("\n=============================\n");

    return 0;
}


void exibirCabecalho(void) {

    printf("========== RANKLAB ==========\n");
    printf("Sistema de Ordenacao de Pontuacoes\n\n");
}


void lerPontuacoes(int v[], int n) {

    int i;

    for (i = 0; i < n; i++) {

        do {

            printf("Digite a pontuacao %d (0 a 100): ", i + 1);
            scanf("%d", &v[i]);

            if (v[i] < 0 || v[i] > 100) {
                printf("Valor invalido! Digite novamente.\n");
            }

        } while (v[i] < 0 || v[i] > 100);
    }
}


void copiarVetor(int origem[], int destino[], int n) {

    int i;

    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}


void exibirVetor(int v[], int n) {

    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}


int bubbleSort(int v[], int n) {

    int i, j, aux;
    int comparacoes = 0;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - 1 - i; j++) {

            comparacoes++;

            if (v[j] > v[j + 1]) {

                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }

    return comparacoes;
}


int selectionSort(int v[], int n) {

    int i, j, menor, aux;
    int comparacoes = 0;

    for (i = 0; i < n - 1; i++) {

        menor = i;

        for (j = i + 1; j < n; j++) {

            comparacoes++;

            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }

    return comparacoes;
}


int insertionSort(int v[], int n) {

    int i, j, chave;
    int comparacoes = 0;

    for (i = 1; i < n; i++) {

        chave = v[i];
        j = i - 1;

        while (j >= 0) {

            comparacoes++;

            if (v[j] > chave) {

                v[j + 1] = v[j];
                j--;

            } else {

                break;
            }
        }

        v[j + 1] = chave;
    }

    return comparacoes;
}

int vetoresIguais(int a[], int b[], int n) {

    int i;

    for (i = 0; i < n; i++) {

        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}
