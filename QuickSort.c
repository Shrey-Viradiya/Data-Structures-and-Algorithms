#include<stdio.h>
#include<stdlib.h>

void QuickSort(int * arr, int l, int r){
    int i;

    if(l<r)
    {
    int pivot = arr[r];
    i=l-1;

    for(int j= l;j<=r-1;j++){
        if(arr[j] < pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[++i];
    arr[i] = arr[r];
    arr[r] = temp;

        QuickSort(arr,l,i-1);
        QuickSort(arr,i+1,r);
    }



}


int main(){
    int * arr =(int*) malloc(10 * sizeof(int));

    for(int i = 0 ; i<10; i++){
        scanf("%d", &arr[i]);
    }

    QuickSort(arr,0,9);

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}