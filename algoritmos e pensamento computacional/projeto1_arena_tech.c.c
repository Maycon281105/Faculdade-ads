#include <stdio.h>
#include <math.h>

int main() {

    int participantes, jogadoresPorTime, computadores;
    int times, filtrosLinha;
    int capacidadeFiltro;

    float potencia, duracao, precoKwh, precoKit, outrosCustos;
    float aluguelComputador;

    float consumoEnergia, custoEnergia, custoAlimentacao;
    float custoComputadores, custoTotal, custoPorParticipante;

    float duracaoCenario2;
    float consumoCenario2, custoEnergiaCenario2;
    float diferencaConsumo, diferencaCusto;

    printf("Digite a quantidade de participantes: ");
    scanf("%d", &participantes);

    printf("Digite a quantidade de jogadores por time: ");
    scanf("%d", &jogadoresPorTime);

    printf("Digite a quantidade de computadores: ");
    scanf("%d", &computadores);

    printf("Digite a potencia media de cada computador (W): ");
    scanf("%f", &potencia);

    printf("Digite a duracao do evento (horas): ");
    scanf("%f", &duracao);

    printf("Digite o preco do kWh (R$): ");
    scanf("%f", &precoKwh);

    printf("Digite o preco do kit de alimentacao por participante (R$): ");
    scanf("%f", &precoKit);

    printf("Digite os outros custos do evento (R$): ");
    scanf("%f", &outrosCustos);

    printf("Digite o valor do aluguel de cada computador (R$): ");
    scanf("%f", &aluguelComputador);

    printf("Digite quantos computadores cabem em cada filtro de linha: ");
    scanf("%d", &capacidadeFiltro);

    times = (int)ceil((float)participantes / jogadoresPorTime);

    consumoEnergia = (computadores * potencia * duracao) / 1000;

    custoEnergia = consumoEnergia * precoKwh;

    custoAlimentacao = participantes * precoKit;

    custoComputadores = computadores * aluguelComputador;

    filtrosLinha = (int)ceil((float)computadores / capacidadeFiltro);

    custoTotal = custoEnergia + custoAlimentacao +
                 outrosCustos + custoComputadores;

    custoPorParticipante = custoTotal / participantes;

    duracaoCenario2 = duracao * 2;

    consumoCenario2 = (computadores * potencia * duracaoCenario2) / 1000;

    custoEnergiaCenario2 = consumoCenario2 * precoKwh;

    diferencaConsumo = consumoCenario2 - consumoEnergia;
    diferencaCusto = custoEnergiaCenario2 - custoEnergia;

    printf("\n");
    printf("========================================\n");
    printf("             ARENA TECH\n");
    printf("       PLANEJADOR DE MARATONA\n");
    printf("========================================\n");

    printf("\nDADOS DO EVENTO\n");
    printf("Participantes: %d\n", participantes);
    printf("Jogadores por time: %d\n", jogadoresPorTime);
    printf("Times necessarios: %d\n", times);
    printf("Computadores: %d\n", computadores);
    printf("Potencia por computador: %.2f W\n", potencia);
    printf("Duracao do evento: %.2f horas\n", duracao);
    printf("Preco do kWh: R$ %.2f\n", precoKwh);
    printf("Kit de alimentacao: R$ %.2f\n", precoKit);
    printf("Outros custos: R$ %.2f\n", outrosCustos);
    printf("Aluguel por computador: R$ %.2f\n", aluguelComputador);

    printf("\n----------------------------------------\n");
    printf("CONSUMO DE ENERGIA\n");
    printf("Consumo estimado: %.2f kWh\n", consumoEnergia);
    printf("Custo da energia: R$ %.2f\n", custoEnergia);

    printf("\n----------------------------------------\n");
    printf("ALIMENTACAO\n");
    printf("Custo da alimentacao: R$ %.2f\n", custoAlimentacao);

    printf("\n----------------------------------------\n");
    printf("ESTRUTURA\n");
    printf("Capacidade por filtro de linha: %d\n", capacidadeFiltro);
    printf("Filtros de linha necessarios: %d\n", filtrosLinha);

    printf("\n----------------------------------------\n");
    printf("CUSTOS\n");
    printf("Custo dos computadores: R$ %.2f\n", custoComputadores);
    printf("Outros custos: R$ %.2f\n", outrosCustos);
    printf("CUSTO TOTAL: R$ %.2f\n", custoTotal);
    printf("CUSTO POR PARTICIPANTE: R$ %.2f\n", custoPorParticipante);

    printf("\n----------------------------------------\n");
    printf("COMPARACAO DE CENARIOS\n");

    printf("Cenario 1 - %.2f horas\n", duracao);
    printf("Consumo: %.2f kWh\n", consumoEnergia);
    printf("Custo de energia: R$ %.2f\n", custoEnergia);

    printf("\nCenario 2 - %.2f horas\n", duracaoCenario2);
    printf("Consumo: %.2f kWh\n", consumoCenario2);
    printf("Custo de energia: R$ %.2f\n", custoEnergiaCenario2);

    printf("\nDiferenca de consumo: %.2f kWh\n", diferencaConsumo);
    printf("Diferenca no custo: R$ %.2f\n", diferencaCusto);

    printf("\n========================================\n");
    printf("        FIM DO PLANEJAMENTO\n");
    printf("========================================\n");

    return 0;
}
