# Máquinas de Turing

Este repositório contém a implementação de uma Máquina de Turing (com uma e três fitas) que reconheça a Linguagem $0^k1^k2^k$, para $k>=0$.

## Build

```
mkdir build
cmake -S . -B build/
cmake --build build/
```

## Execução

Caso queira executar todos os testes disponíveis com diversas palavras de entrada, basta executar o programa passando o parâmetro `-t`.

Caso queira fornecer uma palavra de entrada, basta executar o programa e passar a palavra como primeiro argumento na linha de comando:

```
./turing-machines <palavra>
```

## Lógica

A lógica para reconhecer as palavras é diferente para cada máquina.

### Uma fita

```
1) Escreva a entrada na fita.
2) Se o primeiro elemento for branco, ACEITE.
3) Senão, se o elemento atual for 0:
    4) Marque com X e avance para a direita até encontrar algo diferente de 0 e Y.
    5) Se o elemento encontrado for diferente de 1, REJEITE.
    6) Senão, marque com Y e avance para a direita até encontrar algo diferente de 1 e Z.
    7) Se o elemento encontrado for diferente de 2, REJEITE.
    8) Senão, marque com Z e volte para a esquerda enquanto o elemento atual for diferente de X.
    9) Vá para a direita e volte para o passo 3). 
10) Senão, se o elemento atual for diferente de Y, REJEITE.
11) Senão, avance para a direita até encontrar algo diferente de Y e Z.
12) Se o elemento encontrado for branco, ACEITE, senão, REJEITE.
```

### Três fitas

```
1) Escreva a entrada na fita 1.
2) Se o primeiro elemento for branco, ACEITE.
3) Senão, enquanto o elemento atual na fita 1 for 0:
    4) Escreva 0 na fita 2 e avance para a direita
    5) Escreva branco na fita 1 e avance para a direita.
6) Se o elemento atual for diferente de 1, REJEITE.
7) Senão, enquanto o elemento atual na fita 1 for 1:
    8) Escreva 1 na fita 3 e avance para a direita
    9) Escreva branco na fita 1 e avance para a direita.
10) Se o elemento atual for diferente de 2, REJEITE.
11) Mova a fita 2 para a esquerda.
12) Mova a fita 3 para a esquerda.
13) Enquanto não parar:
    14) Se o elemento atual da fita 1 for 2, da fita 2 for 0 e da fita 3 for 1:
        15) Escreva Z na fita 1 e avance para a direita.
        16) Escreva X na fita 2 e vá para a esquerda.
        17) Escreva Y na fita 3 e vá para a esquerda.
        18) Volte para o passo 14).
    19) Senão, se o elemento atual da fita 1 for branco, da fita 2 for X e da fita 3 for Y, ACEITE, senão, REJEITE.
```

