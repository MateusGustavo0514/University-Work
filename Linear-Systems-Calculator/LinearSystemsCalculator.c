#include <stdio.h>

void EscalonamentoMatrizes(int linhas, int colunas, float matriz[linhas][colunas]) {

    for (int k = 0; k < linhas; k++) {
        if (matriz[k][k] == 0) {
            int trocou = 0;
            for (int i = k + 1; i < linhas; i++) {
                if (matriz[i][k] != 0) { 
                    for (int j = 0; j < colunas; j++) {
                        float temp = matriz[k][j];
                        matriz[k][j] = matriz[i][j];
                        matriz[i][j] = temp;
                    }
                    trocou = 1;
                    break;
                }
            }
            if (!trocou) continue; 
        }

        float pivo = matriz[k][k];
        for (int j = 0; j < colunas; j++) {
            matriz[k][j] /= pivo;
        }

        for (int i = k + 1; i < linhas; i++) {
            float fator = matriz[i][k];  
            for (int j = 0; j < colunas; j++) {
                matriz[i][j] -= fator * matriz[k][j];
            }
        }
    }


    printf("\nMatriz escalonada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f\t ", matriz[i][j]);
        }
        printf("\n");
    }

   
    int sistemaImpossivel = 0, sistemaIndeterminado = 0;

    for (int i = 0; i < linhas; i++) {
        int todosZeros = 1;
        for (int j = 0; j < colunas - 1; j++) {
            if (matriz[i][j] != 0) {
                todosZeros = 0;
                break;
            }
        }
        if (todosZeros && matriz[i][colunas - 1] != 0) {
            sistemaImpossivel = 1; // SI: 0x + 0y + 0z = b (b ≠ 0)
            break;
        } else if (todosZeros && matriz[i][colunas - 1] == 0) {
            sistemaIndeterminado = 1; // SPI: 0x + 0y + 0z = 0
        }
    }

    if (sistemaImpossivel) {
        printf("\nO sistema é impossivel (SI), pois ha uma linha da forma 0x + 0y + 0z = b (b ≠ 0).\n");
        return;
    } else if (sistemaIndeterminado) {
        printf("\nO sistema possui infinitas solucoes (SPI), pois ha pelo menos uma linha nula.\n");
        return;
    }

    float solucoes[linhas];
    for (int i = linhas - 1; i >= 0; i--) {
        solucoes[i] = matriz[i][colunas - 1];
        for (int j = i + 1; j < colunas - 1; j++) {
            solucoes[i] -= matriz[i][j] * solucoes[j]; 
        }
    }

    printf("\n\nSolucoes do sistema:\n");
    for (int i = 0; i < linhas; i++) {
        printf("x%d = %.2f\n", i + 1, solucoes[i]);
    }
}

int main() {
    int linhas, colunas;

    printf("<<< Calculadora de Sistemas de Equacao >>>\n");

    printf("Numero de Linhas: ");
    scanf("%d", &linhas);

    printf("Numero de Colunas (coeficientes + termos independentes): ");
    scanf("%d", &colunas);

    float matriz[linhas][colunas];

    printf("\nDigite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\nA matriz nao escalonada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    EscalonamentoMatrizes(linhas, colunas, matriz);

    return 0;
}