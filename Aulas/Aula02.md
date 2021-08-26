# Aula 02 - Tipos de Ordenação

---

Primeiramente, quando analisado os tipos de ordenação é importante avaliar algumas propriedades:

- Estabilidade - quando na ordenação a posição entre valores iguais é mantida
- Adaptativo - Se adequa bem a diferentes tipos de vetores (aleatórios, quase ordenados, fracionamente ordenado)

Agora, será apresentado os principais métodos de orneção suas características e um exemplo de código em c++


## Bubble

Faz a verificação de vizinhos, sendo que  caso o da direita for menor ele faz a inversão da posição entre eles.
- Quadrática
- Estável
- Adaptável

```cpp
void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1]) 
                swap(&arr[j], &arr[j+1]); 
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
```

## Selection

Faz a verificação do menor valor do vetor e inverte com a posição n (n varia do começo ao fim do vetor).
- Quadrática
- Instável
- Não adaptável

```cpp
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
    }
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
```

## Insertion

Faz a ordenação criando um subvetor ordenado e alocando os valores a direita desse vetor até finalizar todo o vetor.
- Quadrática
- Estável
- Adaptável

```cpp
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```