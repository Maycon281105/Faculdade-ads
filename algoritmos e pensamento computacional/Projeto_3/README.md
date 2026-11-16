# Projeto 3 - EcoCampus: Monitor de Consumo Inteligente

**Disciplina:** Algoritmos e Pensamento Computacional
**Professor:** Vinicius Alves
**Curso:** Análise e Desenvolvimento de Sistemas - 2º semestre

## Integrantes

Nome: maycon Sousa Lima
RGM: 47135379

## Sobre o projeto

A ideia do projeto é ajudar a universidade a acompanhar o consumo de água de vários
ambientes do campus (biblioteca, laboratórios, cantina, blocos...). O programa em C lê um
arquivo de texto com o nome do local, o consumo medido e o limite recomendado, calcula alguns
indicadores e mostra quais locais passaram do limite.

## Arquivos

- `projeto3_ecocampus.c`: código-fonte do programa
- `consumo_campus.txt`: arquivo de entrada com 20 registros
- `relatorio_consumo.txt`: relatório gerado pelo programa
- `README.md`: este arquivo
- capturas de tela: execução do programa e conteúdo do relatório

## Como compilar e executar

```
gcc projeto3_ecocampus.c -o ecocampus
./ecocampus
```

No Windows, o executável fica `ecocampus.exe`. O arquivo `consumo_campus.txt` precisa estar
na mesma pasta do programa.

## Como a solução funciona

1. **Abertura do arquivo:** declarei um ponteiro `FILE *entrada` e usei `fopen()` no modo `"r"`.
   Se o arquivo não existir, o `fopen()` devolve `NULL`, então o programa mostra uma
   mensagem de erro e encerra.
2. **Leitura:** usei `fscanf()` dentro de um `while`, lendo nome (`%s`), consumo (`%f`) e limite (`%f`).
   O `fscanf()` devolve a quantidade de campos lidos com sucesso, então o laço continua enquanto
   o retorno for `3`. Quando chega ao fim do arquivo ele devolve `EOF` e o laço para. Por isso o
   programa funciona com qualquer quantidade de linhas, sem número fixo.
3. **Cálculos feitos dentro do laço:**
   - contador `quantidade`: soma 1 a cada registro lido;
   - acumulador `total`: soma o consumo de cada linha;
   - `maior` e `nome_maior`: se o consumo atual for maior que o guardado, atualizo os dois
     juntos (com `strcpy()` para copiar o nome), assim o nome sempre corresponde ao valor;
   - `alertas`: soma 1 quando `consumo > limite`.
4. **Média:** calculada depois do laço, `total / quantidade`. Antes disso o programa
   verifica se `quantidade` é maior que zero, para não dividir por zero com arquivo vazio.
5. **Relatório:** criei a função `imprimir_relatorio()`, que recebe um `FILE *` como destino.
   Chamando com `stdout` ela escreve na tela, e chamando com o arquivo ela escreve no
   `relatorio_consumo.txt`. Assim o conteúdo é exatamente o mesmo nos dois lugares.
6. **Fechamento:** os dois arquivos são fechados com `fclose()`.

Como desafio extra, também incluí o **local de menor consumo** no relatório.

## Testes realizados

**Teste mínimo (5 registros do enunciado):**

```
Locais analisados: 5
Consumo total: 3946.50 litros
Consumo medio: 789.30 litros
Maior consumo: Laboratorio1 - 925.00 litros
Locais em alerta: 3
```

Bateu com a saída esperada no PDF (alertas: Laboratorio1, Cantina e BlocoB).

**Base com 20 registros:**

```
Locais analisados: 20
Consumo total: 14922.70 litros
Consumo medio: 746.14 litros
Maior consumo: Refeitorio - 1450.75 litros
Menor consumo: Almoxarifado - 120.75 litros
Locais em alerta: 9
```

Para conferir, fiz a conta de outra forma (planilha/calculadora) e os valores coincidiram.

## Uso de Inteligência Artificial

Usei IA para gerar os dados do `consumo_campus.txt`, com o prompt sugerido pelo professor:

> Crie 20 registros fictícios para um arquivo chamado consumo_campus.txt. Cada linha deve conter
> exatamente: nome_do_local consumo_em_litros limite_em_litros. Use nomes sem espaços, valores
> positivos com ponto decimal e não inclua cabeçalho, numeração, explicações ou blocos de código.
> Faça com que alguns locais ultrapassem o limite e outros permaneçam dentro dele.

Depois conferi se todas as linhas tinham 3 campos, se os nomes não tinham espaços ou acentos e se
havia locais acima e abaixo do limite (9 em alerta e 11 dentro do limite). Os 5 primeiros registros
são os do teste mínimo do enunciado.
A IA também foi usada como apoio para tirar dúvidas, mas revisei e testei o código, e consigo
explicar o uso de `FILE`, `fopen()`, `fscanf()` e o laço de leitura.
