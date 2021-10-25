# Aula 02 - Tipos de Ordenação

---

Primeiramente, quando analisado os tipos de ordenação é importante avaliar algumas propriedades:

- Estabilidade - Após a ordenação do vetor, a ordem entre variáveis de mesmo valor é mantida
- Adaptativo - Aproveita casos em que há uma parte do vetor já ordenado ou quase ordenado, mudando de complexidade em alguns casos (aleatórios, quase ordenados, fracionamente ordenado)

Além dessas propriedades, é importante classificar os métodos de ordenação pela sua complexidade:

- Tempo: Fornece o comportamento com que o tempo máximo de ordenação do vetor aumenta
- Comparações:  Fornece o comportamento com que o algoritmo realiza comparações entre os valores do vetor
- Cópias: Fornece o comportamento com que o algoritmo realiza cópias (trocas + valores salvos) entre os valores do vetor
- Espaço: Fornece o comportamento com que o algoritmo utiliza espaço de memória ao realizar a ordenação. Nesse caso é comum utilizar o termo "in place"  para algoritmos que possuem sua complexidade de espaço constantes, por fazerem as alterações necessárias diretamente no vetor

Agora, será apresentado os principais métodos de ordenação suas características e um exemplo de código em c++


## Bubble

Faz a verificação de vizinhos, sendo que  caso o da direita for menor ele faz a inversão da posição entre eles.
- Estável
- Adaptável
- Pior caso: $\Omega(n^2)$
- Médio caso: $\Omega(n^2)$
- Melhor caso: $\Omega(n)$
- Espaço: $\Omega(1)$

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
- Instável
- Não adaptável
- Pior caso: $\Omega(n^2)$
- Médio caso: $\Omega(n^2)$
- Melhor caso: $\Omega(n^2)$
- Espaço: $\Omega(1)$

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
- Estável
- Adaptável
- Pior caso: $\Omega(n^2)$
- Médio caso: $\Omega(n^2)$
- Melhor caso: $\Omega(n)$
- Espaço: $\Omega(1)$

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

Faz a ordenação pela lógica "dividir pra conquistar", assim utiliza recursão para dividir o vetor em partes menores e fazendo a ordenação comparando esses subvetores entre eles, sendo que eles são salvos num vetor auxiliar, tendo um primeiro caso onde o algoritmo não é considerado "in place".

- Instável
- Não adaptável
- Pior caso: $\Omega(nlog(n))$
- Médio caso: $\Omega(nlog(n))$
- Melhor caso: $\Omega(nlog(n))$
- Espaço: $\Omega(n)$

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

## Heap

Faz a sua ordenação através da utilização de Heaps, que são árvores binárias com caraterísticas especiais, nas quais os pais sempre tem que ser maior que seus dois filhos. Assim, sabendo onde está o valor máximo é possível ordenar o vetor.
- Instável
- Não adaptável
- Pior caso: $\Omega(nlog(n))$
- Médio caso: $\Omega(nlog(n))$
- Pior caso: $\Omega(nlog(n))$
- Espaço: $\Omega(1)$

```cpp
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
```

## Shell

Faz a ordenação utilizando a lógica do insertion, somada a uma lógica de gaps. Os gaps são valores que vão decaindo ao longo da ordenação do algoritmo e ele determina as áreas parciais nos quais o selection vai agir. A sua complexidade é determinada pelo gap escolhido.

- Instável
- Não adaptável
- Pior caso: $\Omega(n^{(3/2)})$
- Médio caso: $\Omega(n^{(3/2)})$
- Pior caso: $\Omega(n^{(3/2)})$
- Espaço: $\Omega(1)$

```cpp
int shellSort(int arr[], int n)
{
    int gap = 1;
    while (gap < n)
        gap *= 2;
    gap = gap/2 - 1;
    
    while (gap > 0)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j = i - gap;
            
            while(j >=0 && j arr[j] < temp)
            {
                arr[j + gap] = arr[j];
                j -= gap; 
            }

            arr[j] = temp;
        }
        gap /= 2;
    }
}
```

## Quick

Faz a ordenação com base em um pivô, após eleger um pivô é possível segregar o vetor entre valores maiores e menores que esse pivô e ao deslocá-los para satisfazer essa condição o vetor será ordenado. Vale ressaltar, que sua complexidade altera dependendo do pivô.

- Instável
- Não adaptável
- Pior caso: $\Omega(n^2)$
- Médio caso: $\Omega(nlog(n))$
- Pior caso: $\Omega(nlog(n))$
- Espaço: $\Omega(n) \Rightarrow \Omega(log(n))$

```cpp
int partition (int arr[], int low, int high) 
{
    if (low >= high) 
        return;
    
    int mid = (low + high) / 2;
    int pivot = arr[high]; 
    int i = low;
    int j = high;
  
    while(1)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (j <= i)
            break;

        swap (&arr[i], &arr[j]);
    }
    partition(arr, low, j);    
    partition(arr, j + 1, high); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    partition(arr, 0, n - 1);
} 
```