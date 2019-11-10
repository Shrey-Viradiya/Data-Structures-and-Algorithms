//DSA1a
#include <stdio.h>
#include <stdlib.h>

void Menu(char *c){
    getchar();
    printf("U: Update\n");
    printf("I: Insert\n");
    printf("D: Delete\n");
    printf("P: Display\n");
    printf("Q: Quit Program\n");

    printf("\n\nEnter your choice: ");
    *c = getchar();
}

void update(int x, int y, int (*p)[3]){
    printf("Enter New Value: ");
    int temp;
    scanf("%d",&temp);
    *(*(p+x) + y) = temp;
}

void insert(int x, int y, int (*p)[3]){
    printf("Enter New Value: ");
    int temp;
    scanf("%d",&temp);
    *(*(p+x) + y) = temp;
}

void del(int x,int y, int (*p)[3]){
    *(*(p+x) + y) = 0;
}

void display(int (*p)[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",*(*(p+i) + j));
        }
        printf("\n");
    }
}

int main()
{
    int arr[3][3] = {0};

    char choice;

    while(1){
        Menu(&choice);

        if(choice == 'U' || choice == 'u'){
            int x,y;
            printf("Enter Position X Y: ");
            scanf("%d %d",&x,&y);
            printf("\n");
            if(arr[x][y] == 0){
                printf("Place Is Empty. Please Insert An Integer First.\n\n");
                continue;
            }
            else{
                update(x,y,arr);
                continue;
            }
        }
        if(choice == 'I' || choice == 'i'){
            int x,y;
            printf("Enter Position X Y: ");
            scanf("%d %d",&x,&y);
            printf("\n");
            if(arr[x][y] != 0){
                printf("Place Is Not Empty. Please Delete First.\n\n");
                continue;
            }
            else{
                insert(x,y,arr);
                continue;
            }
        }
        if(choice == 'D' || choice == 'd'){
            int x,y;
            printf("Enter Position X Y: ");
            scanf("%d %d",&x,&y);
            printf("\n");
            del(x,y,arr);
            continue;
        }
        if(choice == 'p' || choice == 'P'){
            display(arr);
            continue;
        }
        if(choice == 'Q' || choice == 'q'){
            break;
        }

    }
}