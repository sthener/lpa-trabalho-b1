# Trabalho B1 - Lógica de Programação

**Nome:** Sthener Mello  
**Curso:** Engenharia de Software  
**Instituição:** Universidade Católica de Brasília (UCB)  

---

## Simulador de Custo de Entrega

Programa em C desenvolvido para calcular o valor final do frete de entregas, considerando distância, peso, modalidade de transporte, proteção de carga e tentativas anteriores.

### Estrutura do Projeto
- `src/main.c`: Código-fonte com as funções de validação, cálculos e menu interativo.
- `README.md`: Informações gerais sobre o projeto.

### Funções Principais
- `ler_float_positivo()`: Valida se o número digitado é maior que zero.
- `ler_opcao_valida()`: Garante que o usuário escolha uma opção válida no menu.
- `calcular_subtotal_distancia()`: Calcula o valor base e a taxa por km.
- `calcular_valor_entrega()`: Aplica os adicionais e calcula o valor final.

### Como Compilar e Executar
```bash
gcc src/main.c -o simulador
./simulador
