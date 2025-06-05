
#include <stdio.h>  // Para entrada/saída padrão (printf, scanf, getchar)
#include <string.h> // Para manipulação de strings (strcpy)
#include <stdlib.h> // Para exit() (embora return 1 em main seja preferível)

// Definição da estrutura para representar uma carta de país do Super Trunfo
typedef struct {
    char codigo[5];         // Código da carta (ex: "A1")
    char nome_pais[50];     // Nome do país
    long long populacao;    // População (usar long long para países)
    double area;            // Área em km² (usar double para maior precisão)
    double pib;             // Produto Interno Bruto em USD (usar double)
    int pontos_turisticos;  // Número de pontos turísticos (índice ou valor)
    double densidade_demografica; // Calculado: População / Área
    double pib_per_capita;      // Calculado: PIB / População (em USD por habitante)
} CartaSuperTrunfo;

// --- Funções Auxiliares ---

// Retorna o nome do atributo como string (usando const para segurança)
const char* obter_nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area (km2)";
        case 3: return "PIB (USD)";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica (hab/km2)";
        default: return "Desconhecido";
    }
}

// Retorna o valor do atributo (convertido para double para facilitar a soma)
// ATENÇÃO: Pode haver perda de precisão para valores muito grandes de população ou PIB
double obter_valor_atributo(CartaSuperTrunfo carta, int atributo) {
     switch (atributo) {
        case 1: return (double)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (double)carta.pontos_turisticos;
        case 5: return carta.densidade_demografica;
        default: return 0.0; // Não deve acontecer devido à validação prévia
    }
}

// Compara as cartas para um atributo específico usando operador ternário
// Retorna 1 se carta1 vence, -1 se carta2 vence, 0 para empate
int comparar_atributo_individual(CartaSuperTrunfo c1, CartaSuperTrunfo c2, int atributo) {
    double val1 = obter_valor_atributo(c1, atributo);
    double val2 = obter_valor_atributo(c2, atributo);

    // Regra especial para Densidade Demográfica (menor vence)
    if (atributo == 5) {
        return (val1 < val2) ? 1 : ((val2 < val1) ? -1 : 0);
    } else { // Regra geral (maior vence)
        return (val1 > val2) ? 1 : ((val2 > val1) ? -1 : 0);
    }
}

// Função para exibir o menu dinâmico
void exibir_menu(int atributo_excluido) {
    printf("\n--- Escolha um atributo para comparar: ---\n");
    if (atributo_excluido != 1) printf("1. %s\n", obter_nome_atributo(1));
    if (atributo_excluido != 2) printf("2. %s\n", obter_nome_atributo(2));
    if (atributo_excluido != 3) printf("3. %s\n", obter_nome_atributo(3));
    if (atributo_excluido != 4) printf("4. %s\n", obter_nome_atributo(4));
    if (atributo_excluido != 5) printf("5. %s (Menor vence!)\n", obter_nome_atributo(5));
    printf("Digite o numero da sua escolha: ");
}

// Função para limpar o buffer de entrada (útil após scanf falhar)
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // --- Cadastro das Cartas de Países Pré-definidas ---
    CartaSuperTrunfo carta1, carta2;

    // Carta 1: Brasil
    strcpy(carta1.codigo, "C1");
    strcpy(carta1.nome_pais, "Brasil");
    carta1.populacao = 214300000; // População aproximada 2023
    carta1.area = 8510345.538;   // Área em km²
    carta1.pib = 1920000000000.0; // PIB nominal 2022 em USD (aproximado)
    carta1.pontos_turisticos = 8; // Valor fictício

    // Carta 2: Japão
    strcpy(carta2.codigo, "D2");
    strcpy(carta2.nome_pais, "Japao"); // Usar sem acento para simplificar
    carta2.populacao = 125700000; // População aproximada 2023
    carta2.area = 377975.24;     // Área em km²
    carta2.pib = 4231000000000.0; // PIB nominal 2022 em USD (aproximado)
    carta2.pontos_turisticos = 10; // Valor fictício

    // --- Cálculo da Densidade Demográfica e PIB per capita ---
    // Cálculo para Carta 1 (Brasil)
    carta1.densidade_demografica = (carta1.area > 0) ? (double)carta1.populacao / carta1.area : 0.0;
    carta1.pib_per_capita = (carta1.populacao > 0) ? carta1.pib / carta1.populacao : 0.0;

    // Cálculo para Carta 2 (Japão)
    carta2.densidade_demografica = (carta2.area > 0) ? (double)carta2.populacao / carta2.area : 0.0;
    carta2.pib_per_capita = (carta2.populacao > 0) ? carta2.pib / carta2.populacao : 0.0;

    // --- Escolha dos Dois Atributos para Comparação ---
    int escolha1 = 0, escolha2 = 0;
    int scanf_result;

    printf("Bem-vindo ao Super Trunfo de Países!\n");

    // --- Escolha do Primeiro Atributo ---
    do {
        exibir_menu(0); // Mostra todas as opções
        scanf_result = scanf("%d", &escolha1);
        if (scanf_result != 1) {
            printf("Entrada invalida! Por favor, digite um NUMERO.\n");
            limpar_buffer_entrada();
            escolha1 = 0; // Força a repetição do loop
        } else if (escolha1 < 1 || escolha1 > 5) {
            printf("Opcao invalida! Escolha um numero entre 1 e 5.\n");
        }
    } while (escolha1 < 1 || escolha1 > 5);
    limpar_buffer_entrada(); // Limpa o buffer caso tenha sobrado algo (ex: \n)

    // --- Escolha do Segundo Atributo (diferente do primeiro) ---
    printf("\n--- Escolha o SEGUNDO atributo (diferente do primeiro): ---");
    do {
        exibir_menu(escolha1); // Exclui a primeira escolha
        scanf_result = scanf("%d", &escolha2);
        if (scanf_result != 1) {
            printf("Entrada invalida! Por favor, digite um NUMERO.\n");
            limpar_buffer_entrada();
            escolha2 = 0; // Força a repetição do loop
        } else if (escolha2 < 1 || escolha2 > 5) {
            printf("Opcao invalida! Escolha um numero valido.\n");
        } else if (escolha2 == escolha1) {
            printf("Atributo ja escolhido! Escolha um atributo diferente.\n");
        }
    } while (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1);
    limpar_buffer_entrada();

    // --- Comparação com base nos dois atributos escolhidos ---
    printf("\n========================================");
    printf("\n--- Comparacao Detalhada ---\n");
    printf("Carta 1: %s\n", carta1.nome_pais);
    printf("Carta 2: %s\n", carta2.nome_pais);

    // Obtenção dos nomes e valores dos atributos
    const char* nome_atr1 = obter_nome_atributo(escolha1);
    double valor1_atr1 = obter_valor_atributo(carta1, escolha1);
    double valor2_atr1 = obter_valor_atributo(carta2, escolha1);

    const char* nome_atr2 = obter_nome_atributo(escolha2);
    double valor1_atr2 = obter_valor_atributo(carta1, escolha2);
    double valor2_atr2 = obter_valor_atributo(carta2, escolha2);

    // Comparação e exibição do primeiro atributo
    printf("\nAtributo 1: %s\n", nome_atr1);
    // Exibição formatada corretamente
    if (escolha1 == 1) { printf("  %s: %lld\n  %s: %lld\n", carta1.nome_pais, carta1.populacao, carta2.nome_pais, carta2.populacao); }
    else if (escolha1 == 4) { printf("  %s: %d\n  %s: %d\n", carta1.nome_pais, carta1.pontos_turisticos, carta2.nome_pais, carta2.pontos_turisticos); }
    else { printf("  %s: %.2f\n  %s: %.2f\n", carta1.nome_pais, valor1_atr1, carta2.nome_pais, valor2_atr1); }

    int resultado1 = comparar_atributo_individual(carta1, carta2, escolha1);
    printf("  Resultado Atributo 1: %s\n", (resultado1 == 1) ? carta1.nome_pais : ((resultado1 == -1) ? carta2.nome_pais : "Empate"));

    // Comparação e exibição do segundo atributo
    printf("\nAtributo 2: %s\n", nome_atr2);
    if (escolha2 == 1) { printf("  %s: %lld\n  %s: %lld\n", carta1.nome_pais, carta1.populacao, carta2.nome_pais, carta2.populacao); }
    else if (escolha2 == 4) { printf("  %s: %d\n  %s: %d\n", carta1.nome_pais, carta1.pontos_turisticos, carta2.nome_pais, carta2.pontos_turisticos); }
    else { printf("  %s: %.2f\n  %s: %.2f\n", carta1.nome_pais, valor1_atr2, carta2.nome_pais, valor2_atr2); }

    int resultado2 = comparar_atributo_individual(carta1, carta2, escolha2);
    printf("  Resultado Atributo 2: %s\n", (resultado2 == 1) ? carta1.nome_pais : ((resultado2 == -1) ? carta2.nome_pais : "Empate"));

    // --- Soma dos Atributos e Determinação do Vencedor Final ---
    // Nota: A soma direta de atributos com unidades diferentes pode não ter um significado prático claro,
    // mas está implementada conforme o requisito do desafio.
    double soma_carta1 = valor1_atr1 + valor1_atr2;
    double soma_carta2 = valor2_atr1 + valor2_atr2;

    printf("\n----------------------------------------");
    printf("\n--- Resultado Final (Soma dos Atributos Escolhidos) ---\n");
    printf("Soma %s (%s + %s): %.2f\n", carta1.nome_pais, nome_atr1, nome_atr2, soma_carta1);
    printf("Soma %s (%s + %s): %.2f\n", carta2.nome_pais, nome_atr1, nome_atr2, soma_carta2);

    printf("\n========================================");
    if (soma_carta1 > soma_carta2) {
    printf("\n>>> VENCEDOR DA RODADA: %s! <<<", carta1.nome_pais);
    } else if (soma_carta2 > soma_carta1) {
    printf("\n>>> VENCEDOR DA RODADA: %s! <<<", carta2.nome_pais);
    } else {
    printf("\n>>> RESULTADO DA RODADA: EMPATE! <<<");
    }
    printf("========================================\n");

    return 0; // Indica sucesso
}

