#include <stdio.h>

int main () {
    int a, b;
    
    scanf ("%i", &a);
    scanf ("%i", &b);

    printf("%i", a>b ? a : b);
}