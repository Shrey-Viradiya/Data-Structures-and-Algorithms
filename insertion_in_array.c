#include <stdio.h>

void main() {
   int arr[] = {1,3,7,9,11};
   int item = 5, k = 2, n = 5;
   int j = n;

   printf("%d\n",n);
   printf("Before Insertion of 5 at index 2\n");
   for (int i = 0; i < n; i++)   
   {
      printf("arr[%d] = %d\n",i,arr[i]);
      
   }

   n = n+1;
   printf("outside while: %d\n",n);
   while (j >= k)
   {
      arr[j+1] = arr[j];
      j--;
      printf("%d\n",n);
   }

   arr[k] = item;

   printf("After Insertion of 5 at index 2\n");
   printf("%d\n",n);

   for (int i = 0; i < 6; i++)   
   {
      printf("arr[%d] = %d\n",i,arr[i]);
   }
   
   for (int i = 0; i < 6; i++)   
   {
      printf("");
   }

   printf("Execution complete");  
}