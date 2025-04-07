#include <stdio.h>


typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Cidade;

void entradaDados(Cidade *c) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &c->estado);
    printf("Digite o código da cidade (ex: A01): ");
    scanf(" %s", c->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %s", c->nomeCidade);
    printf("Digite a população da cidade: ");
    scanf(" %lu", &c->populacao);
    printf("Digite a área da cidade (km²): ");
    scanf(" %f", &c->area);
    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf(" %f", &c->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &c->pontosTuristicos);

    // Cálculo da densidade populacional e PIB per capita
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao;
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + c->pibPerCapita + (1.0 / c->densidadePopulacional);
}


void exibirDados(Cidade c) {
    printf("\nCarta:\n");
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

void compararCartas(Cidade c1, Cidade c2) {
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);
    printf("Área: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);
    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos ? 1 : 2, c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional ? 1 : 2, c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita ? 1 : 2, c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", c1.superPoder > c2.superPoder ? 1 : 2, c1.superPoder > c2.superPoder);
}

int main() {
    Cidade cidade1, cidade2;

    printf("Entrada de dados para a primeira cidade:\n");
    entradaDados(&cidade1);

    printf("\nEntrada de dados para a segunda cidade:\n");
    entradaDados(&cidade2);

    exibirDados(cidade1);
    exibirDados(cidade2);

    compararCartas(cidade1, cidade2);

    return 0;
}