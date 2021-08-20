# Aula 01 - Notação Big O

---

No campo da computação a notação Big O existe para determinar a complexidade dos algoritmos. Teoricamente existem infinitos tipos de complexidade, mas na prática alguns são utilizados os quais serão listados agora:

- Constante - O(1): Quando a complexidade se mantém constante
- Linear - O(n): Quando a complexidade aumenta de forma linear
- Quadrático - O(n²): Quando a complexidade aumenta de forma quadrática
- Logarítmica - O(log n): Quando a complexidade aumenta de forma logarítmica
- Logarítmica linear - O(n log n): Quando a complexidade aumenta de forma linearmente logarítmica

Vale ressaltar que ao analisar a complexidade de um algoritmo o grau maior sempre é determinante. Assim podemos desconsiderar constantes e graus de menores complexidades:

- O(n) = O(1 + n) 
- O(n²) = O(2n²)

Por fim, ao escolher uma complexidade para resolver um problema percebemos que cada caso tem que ser analisado separadamente, haja vista, que cada caso possui uma complexidade melhor para resolver o problema. Tal fato, é visto na escolha de um método de ordenação.
