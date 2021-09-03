#include <stdio.h>
#include <string.h>

#define MAX 10

void swap (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void printVector (int vector[], int n){
    for (int i=0; i<n; i++) {
        printf ("%i ", vector[i]);
    }
    printf("\n");
}

void selectionSort (int vector[], int n) {
    int min;
    for (int i=0; i<n; i++) {
        min = i;
        for (int j=i+1; j<n; j++) {
            printf ("C %i %i\n", i, j);
            if (vector[j] < vector[min])
                min = j;
        }
        printf ("T %i %i\n", i, min);
        swap (&vector[i], &vector[min]);
    }
}

void bubbleSort (int vector[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            printf ("C %i %i\n", j, j+1);
            if (vector[j] > vector[j+1]) {
                printf ("T %i %i\n", j, j+1);
                swap (&vector[j], &vector[j+1]);
            }
        }
    }
}

int main (int argc, char *argv[]) {
    
    int n;
    char sortType[MAX];

    scanf("%s", sortType);
    scanf("%i", &n);
    
    int vector[n];
    for (int i=0; i<n; i++){
        scanf("%i", &vector[i]);
    }

    if (strcmp(sortType, "selecao") == 0) {
        printf ("\nSelectionSort\n");
        selectionSort(vector, n);
    } else if (strcmp(sortType, "bolha") == 0) {
        bubbleSort(vector, n);
    }

    printVector(vector, size);
    return 0;
}