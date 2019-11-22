#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int left, int middle, int right){
    int size1 = middle - left + 1;
    int size2 = right - middle;

    int L[size1],R[size2];
    for (int i = 0; i < size1; ++i) {
        L[i] = arr[left+i];
    }
    for (int j = 0; j < size2; ++j) {
        R[j] = arr[middle + j + 1];
    }

    int i =0,j=0,k=left;

    while(i<size1 && j < size2) {
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while (i<size1){
        arr[k++] = L[i++];
    }

    while (j<size2){
        arr[k++] = R[j++];
    }
}

void MergeSort(int* arr, int left, int right){
    if(right > left){
        int middle = left + (right - left)/ 2;

        MergeSort(arr,left,middle);
        MergeSort(arr,middle+1,right);
        Merge(arr,left,middle,right);
    }
}

int main() {
    printf("Enter the size of the array: ");
    int size;

    scanf("%d", & size);

    int * arr = (int * ) calloc(size, sizeof(int));
    printf("\nEnter the elements\n");
    for (int q = 0; q < size; ++q) {
        scanf("%d", &arr[q]);
    }

    MergeSort(arr,0,size-1);

    for (int i = 0; i <size; ++i) {
        printf("%d ",arr[i]);
    }

    return 0;
}