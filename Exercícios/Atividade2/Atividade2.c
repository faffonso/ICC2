#include <stdio.h>

int countChanges, countComparison;

void swap (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertionSort (int vector[], int n) {
    int left, j;
    for (int i=1; i<n; i++) {
        j = i;
        left = i - 1;
        while (left >= 0 && vector[j] < vector[left]) {
            swap (&vector[left], &vector[j]);
            j--;
            left = j - 1;
            countChanges++;
            if (left >= 0)
                countComparison++;
        }
        countComparison++;
        countChanges += 2;
    }
}

void merge (int vector[], int begin, int mid, int end) {
    int aux1 = begin;
    int aux2 = mid + 1;
    int vectorAux[end - begin + 1];
    int i = 0;
    while (aux1 <= mid && aux2 <= end) {
        countComparison++;
        countChanges++;
        if (vector[aux1] <= vector[aux2]) {
            vectorAux[i] = vector[aux1];
            aux1++;
            i++;
        } else {
            vectorAux[i] = vector[aux2];
            aux2++;
            i++;
        }
    }

    while (aux1 <= mid) {
        countChanges ++;
        vectorAux[i] = vector[aux1];
        i++;
        aux1++;
    }
    
    while (aux2 <= end) {
        countChanges++;
        vectorAux[i] = vector[aux2];
        i++;
        aux2++;
    }
    
    for (int i=begin, j=0; i<=end; i++, j++) {
        vector[i] = vectorAux[j];
        countChanges ++;
    }
}

void mergeSort (int vector[], int begin, int end) {
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    mergeSort (vector, begin, mid);
    mergeSort (vector, mid + 1, end);
    merge (vector, begin, mid, end);
}

int main (int argc, char *argv[]) {
    int numVector;
    scanf("%i", &numVector);

    int tamVector[numVector], max;
    for (int i=0; i<numVector; i++) {
        scanf("%i", &tamVector[i]);
        if (i==0 || tamVector[i] > max)
            max = tamVector[i];
    }

    int matrixA[numVector][max];
    int matrixB[numVector][max];
    for (int i=0; i<numVector; i++) {
        for (int j=0; j<tamVector[i]; j++){
            scanf("%i", &matrixA[i][j]);
            matrixB[i][j] = matrixA[i][j];
        }
    }

    for (int i=0; i<numVector; i++) {
        countChanges = 0, countComparison = 0;
        insertionSort(matrixA[i], tamVector[i]);
        printf ("I %i %i %i\n", tamVector[i], countChanges, countComparison);

        countChanges = 0, countComparison = 0;
        mergeSort(matrixB[i], 0, tamVector[i] - 1);
        printf ("M %i %i %i\n", tamVector[i], countChanges, countComparison);
    }
    return 0;
}