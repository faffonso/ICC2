# Aula 01 - Notação Assintótica

---
No campo da computação existem diferentes tipos de notações assintóticas, com o objetivo de classificar e comparar a complexidade de algoritmos, assim podemos ter uma ideia do custo operacional e tempo gasto para executar determinados algoritmos.

## Notação Big O

A notação Big 0, de modo simplificado o limite inferior da complexidade de um algoritmo.

$f(x) \in O(g(x))\text{, se } \exists x_0,c\text{ ,tal }\forall x>x_0, f(x) < c\cdot g(x)  $

## Notação Big $\Omega$

A notação Big $\Omega$, de modo simplificado o limite superior da complexidade de um algoritmo.

$f(x) \in \Omega(g(x))\text{ ,se e somente se, } f(x) \in O(g(x))$

## Notação Big $\Theta$

A notação $\Theta$, de modo simplificado representa a intersecção da complexidade das notações Big O e Big $\Omega$.

$f(x) \in \Theta(g(x))\text{ ,se e somente se, } f(x) \in O(g(x)) \text{ e } f(x) \in \Omega(g(x))$

## Características gerais

Primeiro as notações possuem as seguintes possibilidades:

- Constante (1)
- Ackermann
- $log(log(n))$
- $log(n)$
- Linear ($n$)
- Linearítmica ($nlog(n)$)
- Quadrática ($n^2$)

Para determinar essa complexidade temos algumas regras:

- É considerado apenas o grau de maior complexidade
- Constantes podem ser desconsideradas



Exemplificando a aplicação das notações assintóticas, temos que caso $f(x) = 4\cdot nlog(n) + 20n + 10$, teríamos a seguinte complexidade:

|           | Big O | Big $\Omega$ | Big $\Theta$ |
|:---------:|:-----:|:------------:|:------------:|
|    $n!$   |  Sim  |      Não     |      Não     |
|   $2^n$   |  Sim  |      Não     |      Não     |
|   $n^2$   |  Sim  |      Não     |      Não     |
| $nlog(n)$ |  Sim  |      Sim     |      Sim     |
|     n     |  Não  |      Sim     |      Não     |
|   log(n)  |  Não  |      Sim     |      Não     |
|     1     |  Não  |      Sim     |      Não     |