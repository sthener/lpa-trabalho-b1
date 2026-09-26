#include <stdio.h>


float ler_float_positivo(const char *mensagem);
int ler_opcao_valida(const char *mensagem, int min, int max);
float calcular_subtotal_distancia(float distancia);
float calcular_valor_entrega(float distancia, float peso, int modalidade, int protecao, int tentativas);

int main(void) {
    int total_simulacoes = 0;
    float soma_valores_finais = 0.0f;
    float maior_valor = -1.0f;
    float menor_valor = -1.0f;

    int continuar = 1;

    printf("=========================================\n");
    printf("   SIMULADOR DE CUSTO DE ENTREGA ENVIAR  \n");
    printf("=========================================\n\n");

    while (continuar == 1) {
        total_simulacoes++;
        printf("--- SIMULACAO #%d ---\n", total_simulacoes);

        float distancia = ler_float_positivo("Digite a distancia da entrega (em km): ");
        float peso = ler_float_positivo("Digite o peso do pacote (em kg): ");

        printf("\nSelecione a modalidade de transporte:\n");
        printf("  1 - Terrestre Padrao\n");
        printf("  2 - Expressa\n");
        printf("  3 - Aerea / Prioritaria\n");
        int modalidade = ler_opcao_valida("Opcao (1 a 3): ", 1, 3);

        printf("\nDeseja servico de protecao de carga?\n");
        printf("  0 - Nao\n");
        printf("  1 - Sim (+ R$ 7.50)\n");
        int protecao = ler_opcao_valida("Opcao (0 ou 1): ", 0, 1);

        printf("\nDigite a quantidade de tentativas anteriores de entrega frustradas:\n");
        int tentativas = ler_opcao_valida("Quantidade de tentativas (0 ou mais): ", 0, 100);

        float subtotal_dist = calcular_subtotal_distancia(distancia);

        float perc_peso = 0.0f;
        if (peso > 10.0f) perc_peso = 0.20f;
        else if (peso > 5.0f) perc_peso = 0.10f;
        else if (peso > 2.0f) perc_peso = 0.05f;
        float adic_peso = subtotal_dist * perc_peso;

        float perc_mod = 0.0f;
        if (modalidade == 2) perc_mod = 0.15f;
        else if (modalidade == 3) perc_mod = 0.30f;
        float adic_mod = subtotal_dist * perc_mod;

        float adic_prot = (protecao == 1) ? 7.50f : 0.0f;
        float adic_tentativas = tentativas * 4.00f;

        float valor_final = calcular_valor_entrega(distancia, peso, modalidade, protecao, tentativas);

        soma_valores_finais += valor_final;

        if (maior_valor < 0.0f || valor_final > maior_valor) {
            maior_valor = valor_final;
        }
        if (menor_valor < 0.0f || valor_final < menor_valor) {
            menor_valor = valor_final;
        }

        printf("\n-----------------------------------------\n");
        printf("         DETALHAMENTO DO CUSTO          \n");
        printf("-----------------------------------------\n");
        printf("Subtotal Distancia:      R$ %8.2f\n", subtotal_dist);
        printf("Adicional Peso:          R$ %8.2f\n", adic_peso);
        printf("Adicional Modalidade:    R$ %8.2f\n", adic_mod);
        printf("Adicional Protecao:      R$ %8.2f\n", adic_prot);
        printf("Adicional Re-tentativas: R$ %8.2f\n", adic_tentativas);
        printf("-----------------------------------------\n");
        printf("VALOR FINAL DA ENTREGA:  R$ %8.2f\n", valor_final);
        printf("-----------------------------------------\n\n");

        printf("Deseja realizar outra simulacao?\n");
        printf("  1 - Sim\n");
        printf("  0 - Nao / Sair\n");
        continuar = ler_opcao_valida("Opcao (0 ou 1): ", 0, 1);
        printf("\n");
    }

    printf("=========================================\n");
    printf("           RESUMO DA SESSAO              \n");
    printf("=========================================\n");
    printf("Total de simulacoes realizadas: %d\n", total_simulacoes);
    if (total_simulacoes > 0) {
        printf("Valor medio das entregas:       R$ %.2f\n", soma_valores_finais / total_simulacoes);
        printf("Maior valor calculado:          R$ %.2f\n", maior_valor);
        printf("Menor valor calculado:          R$ %.2f\n", menor_valor);
    }
    printf("=========================================\n");
    printf("Obrigado por utilizar o simulador!\n");

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
