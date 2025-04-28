#include <stdio.h>

void movimentoTorre(int casas, int contador) {
    if (contador >= casas) return;
    printf("Direita\n");
    movimentoTorre(casas, contador + 1);
}

void movimentoBispo(int casas, int contadorVertical, int contadorHorizontal) {
    if (contadorVertical >= casas) return;
    for (int i = 0; i < casas; i++) {
        printf("Cima Direita\n");
    }
    movimentoBispo(casas, contadorVertical + 1, contadorHorizontal + 1);
}

void movimentoRainha(int casas, int contador) {
    if (contador >= casas) return;
    printf("Esquerda\n");
    movimentoRainha(casas, contador + 1);
}

void movimentoCavalo(int movimentos, int contadorVertical, int contadorHorizontal) {
    for (int i = 0; i < movimentos; i++) {
        int vert = 0;
        for (int j = 0; j < movimentos; j++) {
            if (vert < 2) {
                printf("Cima\n");
                vert++;
            }
        }
        if (vert >= 2) {
            printf("Direita\n");
            return;
        }
    }
}

int main() {
    int casasTorre = 5;
    printf("Movimento da Torre:\n");
    movimentoTorre(casasTorre, 0);

    int casasBispo = 5;
    printf("\nMovimento do Bispo:\n");
    movimentoBispo(casasBispo, 0, 0);

    int casasRainha = 8;
    printf("\nMovimento da Rainha:\n");
    movimentoRainha(casasRainha, 0);

    int movimentosCavalo = 1;
    printf("\nMovimento do Cavalo:\n");
    movimentoCavalo(movimentosCavalo, 0, 0);

    return 0;
}