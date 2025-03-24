#include <stdio.h>

int main() {
    int op, linhas, colunas;

    do {
        printf("<<< Calculadora de Sistemas de Equacao >>>\n");

        printf("Numero de Linhas: ");
        scanf("%d", &linhas);

        printf("Numero de Colunas: ");
        scanf("%d", &colunas);

        printf("Essa e a dimensao da matriz [%d][%d]?\n 1. Sim\n 2. Nao\n Insira Aqui: ", linhas, colunas);
        scanf("%d", &op);

        if (op == 1) {
            int matriz[linhas][colunas]; 
            LeituraImpressaoMatrizes(linhas, colunas, matriz);

            printf("\n\nEscalonando...\n\n");
            EscalonamentoMatrizes();
            
        } else {
            printf("\n----- Insira novamente -----\n\n");
        }

    } while (op != 1);

    return 0;
}

void LeituraImpressaoMatrizes(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("Digite os elementos da matriz:\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }


    printf("\nMatriz inserida:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


void EscalonamentoMatrizes(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("Função de escalonamento ainda não implementada.\n");
}
