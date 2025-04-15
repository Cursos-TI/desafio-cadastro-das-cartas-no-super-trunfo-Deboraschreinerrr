#include <stdio.h>
#include <string.h>

// Estrutura da carta de país
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

int main() {
    // Duas cartas já cadastradas (conforme desafio anterior)
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1.8, 5, 25.0};
    Carta carta2 = {"Canadá", 38000000, 9984670.0, 1.6, 7, 3.8};

    int opcao;

    // Menu interativo para o jogador escolher o atributo
    printf("=========================================\n");
    printf("      SUPER TRUNFO - Atributos\n");
    printf("=========================================\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha um atributo (1 a 5): ");
    scanf("%d", &opcao);

    // Mostrar os países que estão sendo comparados
    printf("\nComparando: %s vs %s\n", carta1.nome, carta2.nome);

    // Switch para tratar a escolha do usuário
    switch (opcao) {
        case 1:
            // Comparando População
            printf("População: %d vs %d\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:
            // Comparando Área
            printf("Área: %.2f km² vs %.2f km²\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.area < carta2.area) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:
            // Comparando PIB
            printf("PIB: %.2f trilhões vs %.2f trilhões\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.pib < carta2.pib) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4:
            // Comparando número de pontos turísticos
            printf("Pontos Turísticos: %d vs %d\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.pontosTuristicos < carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5:
            // Comparando Densidade Demográfica (regra invertida: menor vence)
            printf("Densidade Demográfica: %.2f hab/km² vs %.2f hab/km²\n", carta1.densidadeDemografica, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.densidadeDemografica > carta2.densidadeDemografica) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            // Caso o jogador digite uma opção inválida
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    return 0;
}