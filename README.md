# Sistema de Controle de Campeonato

Programa em C para analisar a campanha das equipes de um campeonato. O sistema funciona por menu no terminal, valida as entradas, calcula a pontuação de cada equipe e gera estatísticas do campeonato.

Trabalho prático da disciplina Práticas Profissionais II.

## Funcionalidades

- Configuração inicial com validação da quantidade de equipes (3 a 10) e de jogos por equipe (1 a 10)
- Registro de vitórias, empates e derrotas de cada equipe, com validação dos valores
- Cálculo de pontos e classificação da campanha de cada equipe
- Resumo do campeonato com totais, média e estatísticas
- Regulamento disponível a qualquer momento
- Simulação de campanhas sem alterar o resumo do campeonato

## Menu principal

```
1 - Registrar resultados do campeonato
2 - Mostrar resumo do campeonato
3 - Mostrar regulamento
4 - Simular campanha de uma equipe
5 - Encerrar sistema
```

## Regras

### Pontuação

| Resultado | Pontos |
|-----------|--------|
| Vitória   | 3      |
| Empate    | 1      |
| Derrota   | 0      |

### Situação da campanha

| Pontos     | Situação           |
|------------|--------------------|
| 15 ou mais | Excelente campanha |
| De 10 a 14 | Boa campanha       |
| De 5 a 9   | Campanha regular   |
| Menos de 5 | Campanha ruim      |

### Validações

- Nenhum resultado pode ser negativo
- A soma de vitórias, empates e derrotas deve ser igual à quantidade de jogos configurada
- Valores inválidos fazem o programa solicitar a entrada novamente

## Resumo do campeonato

A opção 2 apresenta as informações do último registro completo:

- Quantidade de equipes e de jogos por equipe
- Total de vitórias, empates e derrotas
- Soma e média de pontos (duas casas decimais)
- Quantidade de equipes em cada situação
- Maior e menor pontuação, com o número da primeira equipe que a atingiu
- Quantidade de equipes empatadas na maior e na menor pontuação

Se nenhum registro foi feito, o sistema informa que é preciso registrar os resultados primeiro. Ao executar a opção 1 novamente, o resumo anterior é substituído.

## Simulação

A opção 4 permite simular de 1 a 5 campanhas, com as mesmas validações do registro. Os resultados são exibidos na tela e não afetam o resumo do campeonato. Pode ser usada mesmo sem resultados registrados.

## Restrições do projeto

O programa foi desenvolvido apenas com variáveis simples e as estruturas `if`, `else if`, `else`, `switch`, `for` e `while`. Não são utilizados vetores, matrizes, structs, arquivos, alocação dinâmica nem funções próprias além da `main`.

## Como compilar e executar

É necessário ter um compilador C instalado, como o GCC.

```bash
gcc main.c -o main
./main
```

No Windows:

```bash
gcc main.c -o main.exe
main.exe
```

Substitua `main.c` pelo nome do arquivo-fonte do repositório, caso seja diferente.

## Exemplo de saída

Com 6 jogos por equipe:

```
Equipe 1: 3 vitórias, 2 empates e 1 derrota
Pontuação: 11 pontos
Situação: Boa campanha
```

## Autores

- Matheus Vieira Rocha
- Letícia ...
- Kauã ...

Professor: Sidney de Castro Lima
