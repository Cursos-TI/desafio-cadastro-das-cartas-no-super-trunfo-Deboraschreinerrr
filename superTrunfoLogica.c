#include <stdio.h>
#include <string.h>

// Estrutura de dados para armazenar as informações da cidade
typedef struct {
    char estado[3];  // Para armazenar siglas como "SP", "RJ", etc.
    char codigo[5];  // Para armazenar o código da cidade
    char nomeCidade[50];  // Nome da cidade
    unsigned long int populacao;  // População
    float area;  // Área da cidade em km²
    float pib;  // PIB da cidade
    int pontosTuristicos;  // Número de pontos turísticos
    float densidadePopulacional;  // Densidade populacional
    float pibPerCapita;  // PIB per capita
} Cidade;

// Função para calcular densidade populacional e PIB per capita
void calcularDados(Cidade *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

// Função para exibir os dados de uma cidade
void exibirDados(Cidade c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
}
// Função para comparar as cartas com base no atributo escolhido
void compararCartas(Cidade c1, Cidade c2, const char* atributo) {
    printf("\nComparação de Cartas (Atributo: %s):\n", atributo);
    
    if (strcmp(atributo, "População") == 0) {
        printf("Carta 1 - %s: %lu\n", c1.nomeCidade, c1.populacao);
        printf("Carta 2 - %s: %lu\n", c2.nomeCidade, c2.populacao);
        if (c1.populacao > c2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
        } else if (c1.populacao < c2.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "Área") == 0) {
        printf("Carta 1 - %s: %.2f km²\n", c1.nomeCidade, c1.area);
        printf("Carta 2 - %s: %.2f km²\n", c2.nomeCidade, c2.area);
        if (c1.area > c2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
        } else if (c1.area < c2.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "PIB") == 0) {
        printf("Carta 1 - %s: %.2f bilhões\n", c1.nomeCidade, c1.pib);
        printf("Carta 2 - %s: %.2f bilhões\n", c2.nomeCidade, c2.pib);
        if (c1.pib > c2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
        } else if (c1.pib < c2.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "Densidade Populacional") == 0) {
        printf("Carta 1 - %s: %.2f hab/km²\n", c1.nomeCidade, c1.densidadePopulacional);
        printf("Carta 2 - %s: %.2f hab/km²\n", c2.nomeCidade, c2.densidadePopulacional);
        if (c1.densidadePopulacional < c2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
        } else if (c1.densidadePopulacional > c2.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "PIB per Capita") == 0) {
        printf("Carta 1 - %s: %.2f\n", c1.nomeCidade, c1.pibPerCapita);
        printf("Carta 2 - %s: %.2f\n", c2.nomeCidade, c2.pibPerCapita);
        if (c1.pibPerCapita > c2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
        } else if (c1.pibPerCapita < c2.pibPerCapita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else {
        printf("Atributo inválido para comparação.\n");
    }
}

int main() {
    // Cidades de exemplo
    Cidade cidade1 = {"SP", "A01", "São Paulo", 12300000, 1500.0, 2000.0, 20, 0, 0};
    Cidade cidade2 = {"RJ", "B02", "Rio de Janeiro", 6000000, 1200.0, 1500.0, 15, 0, 0};

    // Calcular densidade populacional e PIB per capita
    calcularDados(&cidade1);
    calcularDados(&cidade2);

    // Exibir as cartas
    printf("Dados da Carta 1:\n");
    exibirDados(cidade1);
    printf("\nDados da Carta 2:\n");
    exibirDados(cidade2);

    // Comparar as cartas com base no atributo escolhido
    compararCartas(cidade1, cidade2, "População");

    return 0;
}
