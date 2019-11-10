#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}; 

int count = 0; 

void insertFirst(struct node** first){
    struct node* temp = malloc(sizeof(struct node));
    printf("Enter the number: ");
    scanf("%d",&temp->data);
    temp->next = *first;

    *first = temp;
    count++;
}

void insertAfter(struct node* first){
    int after;
    struct node* temp = malloc(sizeof(struct node));
    printf("Enter the number: ");
    scanf("%d",&temp->data);

    printf("Enter the number after which you want to enter: ");
    scanf("%d",&after);
    temp->next = NULL;


    struct node* iter;
    iter = first;

    while (iter->data != after && iter->next != NULL)
    {
        iter = iter->next;
    }

    if(iter->data != after){
        printf("Data not found! By default inserting at last position..");
    }
    
    temp->next = iter->next;
    iter->next = temp;
    count++;
}

void insertLast(struct node* first){
    struct node* temp = malloc(sizeof(struct node));
    printf("Enter the number: ");
    scanf("%d",&temp->data);
    temp->next = NULL;

    struct node* iter;
    iter = first;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = temp;

    count++;
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

void copyLinkedList(struct node* first,struct node* first2){
    // Code to copy Linked List

    printf("\n\nLinked List Copying.....\n");

    struct node* iter =first;
    struct node* iter2 = first2;

    first2->data = iter->data;    

    while (iter->next != NULL)
    {
        iter = iter->next;
        struct node* temp = malloc(sizeof(struct node));
        temp->data = iter->data;
        iter2->next = temp;
        iter2 = temp;
    }
    iter2->next = NULL;

    printf("\nOriginal LinkedList\n\n");
    traversal(first);
    printf("\n\nCopied LinkedList\n\n");
    traversal(first2);

    // End of copying code
}

void insertAfterPosition(struct node** first){
    int position;    

    printf("\nEnter the position: ");
    scanf("%d",&position);
    while (position > count)
        {
            printf("\n\nPosition greater than number of elements! Try again: ");
            scanf("%d",&position);
        }

    struct node* temp = malloc(sizeof(struct node));
    struct node* iter = *first;

    printf("Enter the number: ");
    scanf("%d",&temp->data);

    if(position == 0){
        temp->next = *first;
        *first = temp;
        count++;
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            iter = iter->next;
        }

        temp->next = iter->next;
        iter->next = temp;
        count++; 
    }
    
       
    
}

void reverseLinkedList(struct node* first){
    struct node* copy = malloc(sizeof(struct node));
    copyLinkedList(first,copy);
    
    struct node* previous = NULL;
    struct node* current = copy;
    struct node* next = NULL;

    while (current != NULL)
    {
        next = current->next; 
  
        current->next = previous; 
  
        previous = current; 
        current = next; 
    }

    copy = previous;

    printf("\n\nReversed Linked List\n\n");
    traversal(copy);

    free(copy);
    
}

struct node* deleteElement(struct node* first, int x){
    struct node *temp, *prev;

    prev = first;
    temp = first;

    while (temp->data != x && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;

    }

    if(first->data == x){
        first = temp->next;
        free(temp);
        --count;
        return first;
    }  
    prev->next = temp->next;
    count--;
    free(temp);
    return first;
    
}

struct node* removeFirst(struct node* first){
    first = first->next;
    return first;
}

struct node* removeLast(struct node* first){
    struct node* temp = first;

    while ((temp->next)->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = NULL;    return first;
    
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
        printf("\n\n\n-------------------\n");
        printf("List of operations:\n");
        printf("-------------------\n");
        printf("1: Insert at First location\n");
        printf("2: Insert at Last location\n");
        printf("3: Insert after specific value\n");
        printf("4: Display\n");
        printf("5: Copy Linked List\n");
        printf("6: Insert at Position\n");
        printf("7: Reverse the LinkedList\n");
        printf("8: Delete an element\n");
        printf("9: Delete First element\n");
        printf("10: Delete Last element\n");
        printf("0: Exit\n");
        printf("-------------------\n\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            insertFirst(&first);
            break;

        case 2:
            insertLast(first);
            break;

        case 3:
            insertAfter(first);
            break;

        case 4:
            traversal(first);
            break;

        case 5: ;
            struct node* first2 = malloc(sizeof(struct node));
            copyLinkedList(first,first2);
            free(first2);
            break;

        case 6: 
            insertAfterPosition(&first);
            break;

        case 7: 
            reverseLinkedList(first);
            break;

        case 8: ;
            int x;
            printf("enter the element you want to delete :");
            scanf("%d",&x);
            first = deleteElement(first,x);
            break;

        case 9:
            first = removeFirst(first); 
            break;

        case 10:
            first = removeLast(first);
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