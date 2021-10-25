#include <stdio.h>

int countChanges, countComparison;

void swap (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void _quick(int vector[], int begin, int end) {
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    int pivot = vector[mid];
    int i = begin;
    int j = end;
    while (1) {
        while (vector[i] < pivot) {
            i++;
            countComparison;
            }
        while (vector[j] > pivot) {
            j--;
            countComparison;
            }
        if (j <= i)
            break;
        
        swap (&vector[i], &vector[j]);
        countChanges += 3;
        
        i++;
        j--;
    }
    countChanges++;
    _quick(vector, begin, j);
    _quick(vector, j + 1, end);
}

void quickSort (int vector[], int n) {
    countChanges = 0;
    countComparison = 0;
    _quick(vector, 0, n - 1);
}

void shellSort (int vector[], int n) {
    countChanges = 0;
    countComparison = 0;

    int gap = 1;
    while (gap < n)
        gap *= 2;
    gap = gap / 2 - 1;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = vector[i];
            int j = i - gap;
            countChanges++;

            while (j >= 0 && vector[j] > temp) {
                vector[j + gap] = vector[j];
                j -= gap;
                countChanges++;
                countComparison++;
            }
            if (j >= 0 && vector[j] <= temp) {
                countComparison++;
            }

            vector[j + gap] = temp;
            countChanges;
        }
        gap /=  2;
    }
}

int main (int argc, char *argv[]) {
    int size, countShell, countQuick;
    scanf ("%i", &size);

    int vector[size];
    int vectorAux[size];

    for (int i=0; i<size; i++){
        scanf ("%i", &vector[i]);
        vectorAux[i] = vector[i];
    }

    for (int i=1; i <= size; i++) {
        shellSort(vector, i);
        countShell = countChanges + countComparison;
        for (int j=0; j < size; j++) {
            vector[j] = vectorAux[j];
        }
        quickSort(vector, i);
        countQuick = countChanges + countComparison;
        for (int j=0; j < size; j++) {
            vector[j] = vectorAux[j];
        }

        if (countQuick > countShell)
            printf("S ");
        else if(countShell > countQuick)
            printf("Q ");
        else
            printf("- ");
    }
    return 0;
}