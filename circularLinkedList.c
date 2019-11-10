#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

int count = 0; 

void insertFirst(struct node * last, int data){
    struct node* temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    count++;
}

struct node* insertLast(struct node *last, int data){

    //insert at first initially
    insertFirst(last,data);
    
    last = last->next;
    return last;
}

struct node* insertAfter(struct node* last, int dt, int aft){
    
    struct node* temp = malloc(sizeof(struct node));

    temp->data = dt;    
    temp->next = NULL;


    struct node* iter;
    iter = last;

    

    while (iter->data != aft && iter->next != last)
    {
        iter = iter->next;
    }
    
    
    temp->next = iter->next;
    iter->next = temp;

    if(iter == last){
        last = temp;
    }
    count++;
    return last;
}



void traversal(struct node* last){
    struct node* iter;
    iter = last;

    printf("Number of elements: %d\n",count);
    while (iter->next != last)
    {
        iter = iter->next;
        printf("%d\n",iter->data);
        
    }
    iter = iter->next;
    printf("%d\n",iter->data);
}

void copyLinkedList(struct node* last,struct node* last2){
    // Code to copy Linked List

    printf("\n\nLinked List Copying.....\n");

    struct node* iter =last;
    struct node* iter2 = last2;

    last2->data = iter->data;    

    while (iter->next != last)
    {
        iter = iter->next;
        struct node* temp = malloc(sizeof(struct node));
        temp->data = iter->data;
        iter2->next = temp;
        iter2 = temp;
    }
    iter2->next = last2;

    printf("\nOriginal LinkedList\n\n");
    traversal(last);


    printf("\n\nCopied LinkedList\n\n");
    traversal(last2);
}

void insertAfterPosition(struct node** last,int position,int data){
    
    while (position > count)
        {
            printf("\n\nPosition greater than number of elements! Taking Last Position as default: ");
            position = count;
        }

    struct node* temp = malloc(sizeof(struct node));
    struct node* iter = *last;

    temp->data = data;

    if(position == count){
        *last = insertLast(*last,data);
    }
    else
    {
        for (int i = 1; i < position + 1; i++)
        {
            iter = iter->next;
        }

        temp->next = iter->next;
        iter->next = temp;
        count++; 
    }
    
}

struct node * deleteElement(struct node* last, int x){
    struct node *temp, *prev;
    prev = last;
    temp = last->next;

    while(temp->data != x && temp != last){
        prev = temp;
        temp = temp->next;
    }

    if(last->data == x){
        prev->next = last->next;
        last = prev;
        free(temp);
        --count;
        return last;
    } 

    prev->next = temp->next;
    --count;
    free(temp);
    return last;
}

struct node * removeFirst(struct node * last){
    last->next = last->next->next;
    return last;
}

struct node * removeLast(struct node* last){
    struct node* temp;

    temp = last;

    while(temp->next != last){
        temp = temp->next;
    }

    temp->next = last->next;
    free(last);
    last = temp;
    return last;
}


void main(){
    // struct node* first;
   

    struct node* last = malloc(sizeof(struct node));
    last->next = last;
    count++;

    printf("Enter the data of the first element: ");
    scanf("%d", &last->data);

    int choice;
    do
    {
        printf("\n\n\n-------------------\n");
        printf("List of operations:\n");
        printf("-------------------\n");
        printf("1: Insert at First location\n");
        printf("2: Insert at Last location\n");
        printf("3: Insert after specific value\n");
        printf("4: Display\n");
        printf("5: Copy Linked List\n");
        printf("6: Insert at Position\n");
        printf("7: Delete an element\n");
        printf("8: Delete First element\n");
        printf("9: Delete Last element\n");
        printf("0: Exit\n");
        printf("-------------------\n\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the Number: ");
            int x;
            scanf("%d",&x);
            insertFirst(last,x);
            break;

        case 2:
            printf("\nEnter the Number: ");
            int a;
            scanf("%d",&a);
            last = insertLast(last,a);
            break;

        case 3:
            printf("\nEnter the Number: ");
            int w;
            scanf("%d",&w);
            printf("\nEnter the value after: ");
            int y;
            scanf("%d",&y);
            last = insertAfter(last,w,y);
            break;

        case 4:
            traversal(last);
            break;

        case 5: ;
            struct node* last2 = malloc(sizeof(struct node));
            copyLinkedList(last,last2);
            free(last2);
            break;
        
        case 6: 
            printf("\nEnter the position: ");
            int position;
            scanf("%d",&position);
            printf("Enter the number: ");
            int temp;
            scanf("%d",&temp);
            insertAfterPosition(&last,position,temp);
            break;

        case 7: ;
            int h;
            printf("enter the element you want to delete :");
            scanf("%d",&h);
            last = deleteElement(last,h);
            break;

        case 8:
            last = removeFirst(last); 
            break;

        case 9:
            last = removeLast(last);
            break;
        case 0:
            printf("Exiting..! ");
            break;
        
        default:
            printf("Wrong Choice! ");
            break;
        }
    } while (choice != 0);
}