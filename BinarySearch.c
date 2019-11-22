#include <stdio.h> 
  
int binarySearch(int arr[], int left, int right, int x) 
{ 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 
  
        if (arr[mid] == x) return mid; 
        else if (arr[mid] > x) return binarySearch(arr, left, mid - 1, x); 
        else return binarySearch(arr, mid + 1, right, x); 
    } 
  
    return -1; 
} 
  
int main() 
{ 

    int arr[5];
    int temp;

    printf("Enter the 5 Elements\n");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }


    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(arr[i] > arr[j])
            {
                temp   = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }

    int n = sizeof(arr) / sizeof(arr[0]); 
    int x; 
    printf("\nEnter the Number to Search\n");
    scanf("%d",&x);
    
    
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d", 
                            result); 
    return 0; 
} 