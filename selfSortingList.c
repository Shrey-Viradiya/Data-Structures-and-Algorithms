//progrmm incomplete

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}; 

int count = 0; 

struct node* insertInOrder(struct node* first,int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if(temp->data < first->data){
        temp->next = first;
        first = temp;
        count++;
        return first;
        
    }

    struct node* iter = first;

    while ( !(iter->next == NULL) && (iter->next->data < data) )
    {
        iter = iter->next;
    }

    temp->next = iter ->next;
    iter->next = temp;
    count++;
    return first;
    
}

void traversal(struct node* first){
    if(first == NULL){
        printf("Empty List!");
        return;
    }
    struct node* iter;
    iter = first;

    printf("Number of elements: %d\n",count);
    while (iter->next != NULL)
    {
        printf("%d\n",iter->data);
        iter = iter->next;
    }
    printf("%d\n",iter->data);
}




void main(){
    // struct node* first;
   

    struct node* first = malloc(sizeof(struct node));
    first->next = NULL;
    count++;

    printf("Enter the data of the first element: ");
    scanf("%d", &first->data);

    int choice;
    do
    {
        printf("\nOperations: \n");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n0. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data: ");
            int temp;
            scanf("%d", &temp);
            first = insertInOrder(first, temp);
            break;

        case 2:
            traversal(first);
            break;

        case 0:
            printf("Exiting..");
            break;
        
        default:
            break;
        }
    } while (choice != 0);
    
}