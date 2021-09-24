#include <stdio.h>

void swap (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void printMatrix (int n, int m[], int max, int matrix[n][max]){
    for (int i=0; i<n; i++) {
        for (int j=0; j<m[i]; j++) {
            printf ("%i ", matrix[i][j]);
        }
        printf ("\n");
    }
}

void insertionSort (int vector[], int n) {
    int countChanges = 0,
    countComparison = 0,
    left, j;
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
    printf ("I %i %i %i\n", n, countChanges, countComparison);
}

void merge (int vector[], int begin, int mid, int end) {
    int aux1 = begin;
    int aux2 = mid + 1;
    int vectorAux[end - begin + 1];
    int i = 0;
    while (aux1 <= mid && aux2 <= end) {
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
        vectorAux[i] = vector[aux1];
        i++;
        aux1++;
    }
    
    while (aux2 <= end) {
        vectorAux[i] = vector[aux2];
        i++;
        aux2++;
    }

    for (int i=begin, j=0; i<=end; i++, j++) {
        vector[i] = vectorAux[j];
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

    int matrix[numVector][max];
    for (int i=0; i<numVector; i++) {
        for (int j=0; j<tamVector[i]; j++){
            scanf("%i", &matrix[i][j]);
        }
    }

    printMatrix(numVector, tamVector, max, matrix);
    for (int i=0; i<numVector; i++) {
        //insertionSort(matrix[i], tamVector[i]);
        mergeSort(matrix[i], 0, tamVector[i] - 1);
    }
    printMatrix(numVector, tamVector, max, matrix);
}