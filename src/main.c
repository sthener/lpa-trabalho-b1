#include <stdio.h>


float ler_float_positivo(const char *mensagem);
int ler_opcao_valida(const char *mensagem, int min, int max);

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
