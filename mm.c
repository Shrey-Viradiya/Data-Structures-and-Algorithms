#include<stdio.h>

void main(){
    //  
    int a[100][100],b[100][100],c[100][100];

    printf("Enter the size of n x n matrix, n: ");
    int n;
    scanf("%d",&n);

    printf("Enter the Matrix A:");

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++)
            scanf("%d",&*(*(a+row)+col));
    }

    printf("Enter the Matrix B:");

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++)
            scanf("%d",&*(*(b+row)+col));
    }
 
    for(int row=0;row<n;row++){

        //int sum=0;

        for(int col=0;col<n;col++){

            for(int el=0;el<n;el++){

            *(*(c+row)+col) += *(*(a+row)+el) * *(*(b+el)+col);

            }

        }


    }

    printf("Matrix Mul of both AxB:\n");

    for(int row=0;row<n;row++){

        for(int col=0;col<n;col++)
            printf("%d\t",c[row][col]);

        printf("\n");

    }

    for(int row=0;row<n;row++){

        //int sum=0;

        for(int col=0;col<n;col++){

            for(int el=0;el<n;el++){

//            c[row][col] += b[row][el]*a[el][col];
            *(*(c+row)+col) += *(*(b+row)+el) * *(*(a+el)+col);

            }

        }


    }

    printf("Matrix Mul of both BxA:\n");

    for(int row=0;row<n;row++){

        for(int col=0;col<n;col++)
            printf("%d\t",*(*(c+row)+col));

        printf("\n");

    }

}