#include <stdio.h>

int main() {
    int casasTorre = 5;
    printf("Movimento da Torre:\n");
    for(int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    int casasBispo = 5;
    int j = 0;
    printf("\nMovimento do Bispo:\n");
    while(j < casasBispo) {
        printf("Cima Direita\n");
        j++;
    }

    int casasRainha = 8;
    int k = 0;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        k++;
    } while(k < casasRainha);

    int movimentosCavalo = 1;
    printf("\nMovimento do Cavalo:\n");
    
    for (int m = 0; m < movimentosCavalo; m++) {
        int passosBaixo = 0;
        while (passosBaixo < 2) {
            printf("Baixo\n");
            passosBaixo++;
        }
        printf("Esquerda\n");
    }

    return 0;
