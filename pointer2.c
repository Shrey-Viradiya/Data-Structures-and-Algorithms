#include<stdio.h>

int main(int argc, char const *argv[])
{ 
    int A[5] = {1,2,3,4,5};
    // int* A = (int*)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        A[i] = i+1; 
    }
    int *p;
    p=A;
    printf("\n\n%d",A); //location of the first element of array A
    printf("\n%d",*A);  //value of the first element of array A
    printf("\n\n%d",A+1); //location of the second element of array A
    printf("\n%d",*A+1); //value of the second element of array A


    int ptr = &A; //ptr is an pointer to array 5 to int
    // printf("\n\n\n %u",*ptr); //dereferencing of the ptr
    printf("\n %u",ptr); //address of ptr
    // printf("\n %u",**ptr); // dual dereferencing of the ptr
    printf("\n %u",A); // location of the first element of array A

    ptr++; //increase in pointer
    
    // printf("\n\n\n %u",*ptr); //dereferencing of the ptr
    printf("\n %u",ptr); //address of ptr
    // printf("\n %u",**ptr); // dual dereferencing of the ptr
    printf("\n %u",A); // location of the first element of array A
    
    return 0;
}