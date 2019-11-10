#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
struct student
{
    int id;
    char name[20];
    float cpi;
}stu[5];

void insert (struct student *s, int choice)
{
    s=s+choice;

    if(s->id!=0)
    {
        printf("Already Registered!");
    }
    else
    {

    printf("Enter Name : ");
    scanf("%s",s->name);
    printf("Enter ID : ");
    scanf("%d",&s->id);
    printf("Enter cpi : ");
    scanf("%f",&s->cpi);
    }
}

void update (struct student *s, int choice)
{
    s=s+choice;
    printf("Enter Name : ");
    scanf("%s",s->name);
    printf("Enter ID : ");
    scanf("%d",&s->id);
    printf("Enter cpi : ");
    scanf("%f",&s->cpi);

}

void del (struct student *s, int choice)
{
    s=s+choice;
    s->id=0;
    s->cpi=0;
    strcpy(s->name,"\0");

}


void display (struct student *s)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("Name : %s\n",s->name);
        printf("ID : %d\n",s->id);
        printf("cpi : %.2f\n",s->cpi);
        printf("\n");
        s++;
    }


}

int main()
{
    int choice,menu,i; 
    for(i=0;i<5;i++)
    {
        strcpy((stu+i)->name,"\0");
        (stu+i)->id=0;
        (stu+i)->cpi=0;
    }

    // 
    do
    {
        printf("Enter 1 for Insert\n");
        printf("Enter 2 for display\n");
        printf("Enter 3 for delete\n");
        printf("Enter 4 for update\n");
        printf("Enter 5 for quit\n");
        scanf("%d",&menu);

        switch(menu)
        {
            case 1:
                    printf("Enter Index :");
                    scanf("%d",&choice);
                    insert(stu,choice);
                    break;
            case 2: display(stu);
                    break;
            case 3: printf("Enter Index :");
                    scanf("%d",&choice);
                    del(stu,choice);
                    break;
            case 4: printf("Enter Index :");
                    scanf("%d",&choice);
                    update(stu,choice);
                    break;
            case 5: printf("Bye!!");
                    break;
            default:
                    printf("Invalid Input\n");
                    break;
        }
    }while(menu!=5);
}
