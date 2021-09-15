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

## Merge

Faz a ordenação pela lógica "dividir pra conquistar", assim utiliza recursão para dividir o vetor em partes menores e fazendo a ordenação comparando esses subvetores entre eles, sendo que eles são salvos num vetor auxiliar.

- n Log(n)
- Instável
- Não adaptável

```cpp
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
```

