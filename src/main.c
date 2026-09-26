#include <stdio.h>


float ler_float_positivo(const char *mensagem);
int ler_opcao_valida(const char *mensagem, int min, int max);
float calcular_subtotal_distancia(float distancia);
float calcular_valor_entrega(float distancia, float peso, int modalidade, int protecao, int tentativas);

int main(void) {
    printf("=== SIMULADOR DE ENTREGAS ===\n");
    return 0;
}

float ler_float_positivo(const char *mensagem) {
    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor <= 0.0f) {
            printf("[ERRO] O valor deve ser maior que zero. Tente novamente.\n");
        }
    } while (valor <= 0.0f);
    return valor;
}

int ler_opcao_valida(const char *mensagem, int min, int max) {
    int valor;
    do {
        printf("%s", mensagem);
        scanf("%d", &valor);
        if (valor < min || valor > max) {
            printf("[ERRO] Entrada invalida. Digite um valor valido.\n");
        }
    } while (valor < min || valor > max);
    return valor;
}

float calcular_subtotal_distancia(float distancia) {
    float valor_base;
    if (distancia <= 5.0f) valor_base = 8.00f;
    else if (distancia <= 15.0f) valor_base = 12.00f;
    else if (distancia <= 30.0f) valor_base = 18.00f;
    else valor_base = 25.00f;

    return valor_base + (distancia * 1.20f);
}

float calcular_valor_entrega(float distancia, float peso, int modalidade, int protecao, int tentativas) {
    float subtotal = calcular_subtotal_distancia(distancia);

    float perc_peso = 0.0f;
    if (peso > 10.0f) perc_peso = 0.20f;
    else if (peso > 5.0f) perc_peso = 0.10f;
    else if (peso > 2.0f) perc_peso = 0.05f;

    float adic_peso = subtotal * perc_peso;

    float perc_mod = 0.0f;
    if (modalidade == 2) perc_mod = 0.15f;
    else if (modalidade == 3) perc_mod = 0.30f;

    float adic_mod = subtotal * perc_mod;

    float adic_prot = (protecao == 1) ? 7.50f : 0.0f;
    float adic_tentativas = tentativas * 4.00f;

    return subtotal + adic_peso + adic_mod + adic_prot + adic_tentativas;
}
