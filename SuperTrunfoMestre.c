#include <stdio.h>
#include <string.h>

// Definição da estrutura das cartas
typedef struct {
    char nome[30];
    int populacao;         // em milhões
    int area;              // em mil km²
    int pib;               // em bilhões de dólares
    int densidade;         // hab/km²
} Carta;

// Função para exibir o menu de atributos
void mostrarMenuAtributos(int atributoEscolhido) {
    printf("Escolha um atributo:\n");
    if (atributoEscolhido != 1) printf("1 - População\n");
    if (atributoEscolhido != 2) printf("2 - Área\n");
    if (atributoEscolhido != 3) printf("3 - PIB\n");
    if (atributoEscolhido != 4) printf("4 - Densidade Demográfica\n");
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213, 8516, 1445, 25};
    Carta carta2 = {"Japão", 126, 378, 5081, 336};

    int atributo1, atributo2;
    int valor1_carta1, valor2_carta1;
    int valor1_carta2, valor2_carta2;

    // Primeiro atributo
    do {
        mostrarMenuAtributos(0);
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 4)
            printf("Opção inválida! Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 4);

    // Segundo atributo, diferente do primeiro
    do {
        mostrarMenuAtributos(atributo1);
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1)
            printf("Opção inválida! Tente novamente.\n");
    } while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1);

    // Captura dos valores para cada carta baseado nos atributos escolhidos
    switch (atributo1) {
        case 1: valor1_carta1 = carta1.populacao; valor1_carta2 = carta2.populacao; break;
        case 2: valor1_carta1 = carta1.area;      valor1_carta2 = carta2.area;      break;
        case 3: valor1_carta1 = carta1.pib;       valor1_carta2 = carta2.pib;       break;
        case 4: valor1_carta1 = carta1.densidade; valor1_carta2 = carta2.densidade; break;
        default: printf("Erro no atributo 1\n"); return 1;
    }

    switch (atributo2) {
        case 1: valor2_carta1 = carta1.populacao; valor2_carta2 = carta2.populacao; break;
        case 2: valor2_carta1 = carta1.area;      valor2_carta2 = carta2.area;      break;
        case 3: valor2_carta1 = carta1.pib;       valor2_carta2 = carta2.pib;       break;
        case 4: valor2_carta1 = carta1.densidade; valor2_carta2 = carta2.densidade; break;
        default: printf("Erro no atributo 2\n"); return 1;
    }

    // Exibição dos dados
    printf("\n--- COMPARAÇÃO DAS CARTAS ---\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    // Mostrar valores dos atributos
    printf("Atributo 1: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Demográfica\n"); break;
    }
    printf("  %s: %d\n", carta1.nome, valor1_carta1);
    printf("  %s: %d\n", carta2.nome, valor1_carta2);

    printf("Atributo 2: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Demográfica\n"); break;
    }
    printf("  %s: %d\n", carta1.nome, valor2_carta1);
    printf("  %s: %d\n", carta2.nome, valor2_carta2);

    // Lógica de pontuação por atributo
    int pontos_carta1 = 0, pontos_carta2 = 0;

    // Atributo 1
    if (atributo1 == 4) {
        valor1_carta1 < valor1_carta2 ? pontos_carta1++ : (valor1_carta1 > valor1_carta2 ? pontos_carta2++ : 0);
    } else {
        valor1_carta1 > valor1_carta2 ? pontos_carta1++ : (valor1_carta1 < valor1_carta2 ? pontos_carta2++ : 0);
    }

    // Atributo 2
    if (atributo2 == 4) {
        valor2_carta1 < valor2_carta2 ? pontos_carta1++ : (valor2_carta1 > valor2_carta2 ? pontos_carta2++ : 0);
    } else {
        valor2_carta1 > valor2_carta2 ? pontos_carta1++ : (valor2_carta1 < valor2_carta2 ? pontos_carta2++ : 0);
    }

    int soma_carta1 = valor1_carta1 + valor2_carta1;
    int soma_carta2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos atributos:\n");
    printf("  %s: %d\n", carta1.nome, soma_carta1);
    printf("  %s: %d\n", carta2.nome, soma_carta2);

    // Resultado final
    printf("\nResultado da rodada: ");
    if (soma_carta1 > soma_carta2) {
        printf("%s venceu!\n", carta1.nome);
    } else if (soma_carta2 > soma_carta1) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}