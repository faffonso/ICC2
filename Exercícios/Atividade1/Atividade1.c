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
}

void selectionSort (int vector[], int n) {
    int min;
    for (int i=0; i<n; i++) {
        min = i;
        for (int j=i+1; j<n; j++) {
            printf ("C %i %i \n", min, j);
            if (vector[j] < vector[min])
                min = j;
        }
        if (i != min) {
            printf ("T %i %i \n", i, min);
            swap (&vector[i], &vector[min]);
        }
    }
}

void bubbleSort (int vector[], int n) {
    int key, min = n;
    for (int i=0; i<n; i++) {
        key = 0;
        for (int j=1; j<min; j++) {
            printf ("C %i %i \n", j-1, j);
            if (vector[j-1] > vector[j]) {
                printf ("T %i %i \n", j-1, j);
                swap (&vector[j-1], &vector[j]);
                key = j;
            }
        }
        min = key;
    }
}

int main(int argc, char *argv[]) {
    
    int n;
    char sortType[MAX];

    scanf("%s", sortType);
    scanf("%i", &n);
    
    int vector[n];
    for (int i=0; i<n; i++){
        scanf("%i", &vector[i]);
    }

    if (strcmp(sortType, "selecao") == 0) {
        selectionSort(vector, n);
    } else if (strcmp(sortType, "bolha") == 0) {
        bubbleSort(vector, n);
    }

    printVector(vector, n);
    return 0;
}
