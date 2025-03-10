#include <stdio.h>

struct Cidade {
    char estado, codigo[5],nomeCidade[50];     // Código da carta (ex: A01, B03)   // Estado da cidade (A a H)                      
    int populacao, pontosTuristicos ;             
    float area, pib;                 // Área da cidade em km²  // PIB da cidade em bilhões de reais
                   
   
};

void imprimirCarta(struct Cidade cidade, int numeroCarta) {
    printf("\nCarta %d:\n", numeroCarta);
    printf("Estado: %c\n", cidade.estado);
    printf("Código: %s\n", cidade.codigo);
    printf("Nome da Cidade: %s\n", cidade.nomeCidade);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões de reais\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontosTuristicos);
}

int main() {
    struct Cidade carta1, carta2;

    // Coletando os dados para a primeira carta
    printf("Digite os dados para a primeira carta:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta1.estado);

    printf("Código (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf("%s", &carta1.nomeCidade);
    
    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Coletando os dados para a segunda carta
    printf("\nDigite os dados para a segunda carta:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);

    printf("Código (ex: A01): ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf("%s", &carta2.nomeCidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Exibindo os dados das cartas
    imprimirCarta(carta1, 1);
    imprimirCarta(carta2, 2);

    return 0;
}
