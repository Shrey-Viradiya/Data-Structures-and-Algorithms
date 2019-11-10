#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int id;
    float cpi;
    char name[10];
};

void insert(struct student (*s), int choice){
    s = s+choice;
    printf("\nEnter ID: ");
    scanf("%d",&s->id);
    printf("Enter CPI: ");
    scanf("%f",&s->cpi);
    printf("Enter Name: ");
    scanf("%s",s->name);
}

void display(struct student (*s)){
    int i;
    for(i=0;i<5;i++){
        s= s+i;
        printf("\n-------------------------\n");
        printf("ID: %d",s->id);
        printf("\nCPI: %f\n",s->cpi);
        puts(s->name);
        printf("\n-------------------------\n");
    }
}

int main()
{

    int i;
    struct student list[5];
    int choice=3;
    for(i = 0;i<5;i++){
        list[i].id = 0;
        list[i].cpi = 0;
        strcpy(list[i].name,"\0");
    }
   display(list);
    insert(list,choice);
//    insert(list,8);
    display(list);
    return 0;
}
