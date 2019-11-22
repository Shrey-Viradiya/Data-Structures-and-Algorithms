#include <stdio.h>
#include <stdlib.h>

void Heapify(int * arr, int size, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        Heapify(arr,size,largest);
    }
}

void HeapSort(int * arr, int size){
    for (int i = size/2 - 1 ; i >= 0; i--) {
        Heapify(arr,size,i);
    }

    for (int i= size-1;i>=0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr,i,0);
    }
}

int main() {
    printf("Enter the Number of Elements:\n");
    int size;
    scanf("%d" , &size);

    int *arr = (int*) calloc(size, sizeof(int));

    for (int j = 0; j < size; ++j) {
        scanf("%d",&arr[j]);
    }

    HeapSort(arr,size);

    for (int i = 0; i < size; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}