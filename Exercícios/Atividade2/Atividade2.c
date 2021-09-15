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
    for (int i=0; i<n; i++) {
        j = i;
        left = i - 1;
        while (j > 0 && vector[j] < vector[left]) {
            swap (&vector[left], &vector[j]);
            j--;
            left = j - 1;
            countChanges++;
        }
    }
    printf ("I %i %i %i\n", n, countChanges, countComparison);
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
        insertionSort(matrix[i], tamVector[i]);
    }
    printMatrix(numVector, tamVector, max, matrix);

}