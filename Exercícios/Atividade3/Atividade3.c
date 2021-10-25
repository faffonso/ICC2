#include <stdio.h>

int countChanges, countComparison;

void swap (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void _quick(int vector[], int begin, int end) {
    if (begin >= end){
        return;
    }

    int mid = (begin + end) / 2;
    int pivot = vector[mid];
    int i = begin;
    int j = end;
    while (1) {
        while (vector[i] < pivot) {
            i++;
        }
        while (vector[j] > pivot) {
            j--;
        }
        if (j <= i) {
            break;
        }

        swap (&vector[i], &vector[j]);
        countChanges += 3;
        i++;
        j--;
    }
    _quick(vector, begin, j);
    _quick(vector, j + 1, end);
}

int quickSort (int vector[], int n) {
    _quick(vector, 0, n - 1);
    return countChanges;
}

int main (int argc, char *argv[]) {
    countChanges = 0, countComparison = 0;
    int size;
    scanf ("%i", &size);
    int vector[size];
    for (int i=0; i<size; i++){
        scanf ("%i", &vector[i]);
    }

    quickSort (vector, size);
    for (int i=0; i<size; i++) {
        printf ("%i ", vector[i]);
    }
    printf ("\n%i\n", countChanges);
    printf ("\n%i\n", countComparison);
}