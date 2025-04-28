#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5 // Tamanho fixo para as habilidades

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");
            } else if (tabuleiro[i][j] == 3) {
                printf(" 3 ");
            } else if (tabuleiro[i][j] == 5) {
                printf(" 5 ");
            }
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3; // Navio
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 3; // Navio
    }
}

// Função para criar a habilidade Cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaOrigem, int colunaOrigem) {
    int tamanho = TAMANHO_HABILIDADE;
    for (int i = 0; i < tamanho; i++) {
        for (int j = -i; j <= i; j++) {
            int linha = linhaOrigem + i;
            int coluna = colunaOrigem + j;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                tabuleiro[linha][coluna] = 5; // Marca a área afetada pela habilidade
            }
        }
    }
}

// Função para criar a habilidade Cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaOrigem, int colunaOrigem) {
    for (int i = -2; i <= 2; i++) {
        if (linhaOrigem + i >= 0 && linhaOrigem + i < TAMANHO_TABULEIRO) {
            tabuleiro[linhaOrigem + i][colunaOrigem] = 5; // Marca a linha vertical
        }
        if (colunaOrigem + i >= 0 && colunaOrigem + i < TAMANHO_TABULEIRO) {
            tabuleiro[linhaOrigem][colunaOrigem + i] = 5; // Marca a linha horizontal
        }
    }
}

// Função para criar a habilidade Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaOrigem, int colunaOrigem) {
    int tamanho = TAMANHO_HABILIDADE;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {
                int linha = linhaOrigem + i;
                int coluna = colunaOrigem + j;
                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada pela habilidade
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    posicionarNavioHorizontal(tabuleiro, 2, 1);
    posicionarNavioVertical(tabuleiro, 5, 6);

    // Aplicar habilidades
    aplicarHabilidadeCone(tabuleiro, 2, 2);        // Habilidade cone
    aplicarHabilidadeCruz(tabuleiro, 5, 5);        // Habilidade cruz
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);    // Habilidade octaedro

    // Exibir o tabuleiro com os efeitos das habilidades
    printf("Tabuleiro com Habilidades Aplicadas:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}