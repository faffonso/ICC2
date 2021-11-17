#include <stdio.h>
  
void countingSort(int a[], int n, int key)   
{  
   int output[n+1];  
   int max = key;
   int count[max+1]; 
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; 
  }  
    
  for (int i = 0; i < n; i++) 
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   {
      count[i] += count[i-1]; 
   }
  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; 
}  

    for (int i = 0; i < n; i++) { 
        printf("%d %d\n", a[i], count[a[i]]);
        count[a[i]]++; 
    }
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; 
   }  
}

int main(int argc, char *argv[]) {
    int exp_key, size;
    scanf("%i", &exp_key);
    scanf("%i", &size);

    unsigned int vector[size];
    for (int i=0; i < size; i++) {
        scanf("%i", &vector[i]);
    }

    countingSort(vector, size, exp_key);
    //radixSort(vector, size, exp_key);
}