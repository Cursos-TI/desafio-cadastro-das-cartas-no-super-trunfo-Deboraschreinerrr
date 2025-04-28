#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }
}

// Função para verificar se o navio cabe no tabuleiro sem ultrapassar os limites
int verificarEspacoValido(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int horizontal) {
    if (horizontal) { // Navio horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) { // Já tem navio
                return 0;
            }
        }
    } else { // Navio vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) { // Já tem navio
                return 0;
            }
        }
    }
    return 1;
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // Navio
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // Navio
    }
}

// Função para posicionar um navio diagonalmente (cima direita ou baixo direita)
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tipoDiagonal) {
    if (tipoDiagonal == 1) { // Diagonal para cima e direita
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha - i][coluna + i] = 3; // Navio
        }
    } else { // Diagonal para baixo e direita
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = 3; // Navio
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e orientações dos navios
    int linhaHorizontal = 2, colunaHorizontal = 1; // Navio horizontal
    int linhaVertical = 5, colunaVertical = 6; // Navio vertical
    int linhaDiagonal1 = 3, colunaDiagonal1 = 3; // Navio diagonal para baixo e direita
    int linhaDiagonal2 = 7, colunaDiagonal2 = 7; // Navio diagonal para cima e direita

    // Posicionar os navios
    if (verificarEspacoValido(tabuleiro, linhaHorizontal, colunaHorizontal, 1)) {
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    }
    if (verificarEspacoValido(tabuleiro, linhaVertical, colunaVertical, 0)) {
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    }
    if (verificarEspacoValido(tabuleiro, linhaDiagonal1, colunaDiagonal1, -1)) {
        posicionarNavioDiagonal(tabuleiro, linhaDiagonal1, colunaDiagonal1, -1); // Diagonal para baixo
    }
    if (verificarEspacoValido(tabuleiro, linhaDiagonal2, colunaDiagonal2, 1)) {
        posicionarNavioDiagonal(tabuleiro, linhaDiagonal2, colunaDiagonal2, 1); // Diagonal para cima
    }

    // Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}