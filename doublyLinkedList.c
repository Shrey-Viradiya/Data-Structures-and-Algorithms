#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

int count = 0;

struct node* insertFirst(struct node* first,int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = first;
    temp->prev = NULL;
    first->prev = temp;

    first = temp;
    count++;
    return first;
}

struct node* insertLast(struct node* last,int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    last->next = temp;
    temp->prev = last;

    last = temp;

    count++;
    return last;
}

void traversal(struct node* first){
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

void insertAfter(struct node* first, struct node* last,int data, int after){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    struct node* iter;
    iter = first;

    while (iter->data != after && iter->next != NULL)
    {
        iter = iter->next;
    }

    if(iter->data != after && iter == last){
        printf("Data not found! By default inserting at last position..");
        temp->next = NULL;
        temp->prev = iter;
        iter->next = temp;
        last = temp;
        count++;
        return;
    }
    else if (iter == last)
    {
        temp->next = NULL;
        temp->prev = iter;
        iter->next = temp;
        last = temp;
        count++;
        return;
    }
 
    
    temp->next = iter->next;
    temp->prev = iter;
    iter->next->prev = temp;
    iter->next = temp;
    count++;

}

struct node* deleteElement(struct node* first, struct node* last, int x){
    struct node *temp, *prev;

    prev = first;
    temp = first;

    if(first->data == x){
        first = temp->next;
        free(temp);
        --count;
        first->prev=NULL;
        return first;
    }

    while (temp->data != x && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;

    }    

    if (temp == last && temp->data == x)
    {
        last = prev;
        last->next = NULL;
        free(temp);
        count--;
        return first;
    }
    
    prev->next = temp->next;
    temp->next->prev = prev;
    count--;
    free(temp);
    return first;
    
}

struct node* removeFirst(struct node* first){
    first = first->next;
    first->prev = NULL;
    count--;
    return first;
}

struct node* removeLast(struct node* last){
    last = last->prev;
    last->next = NULL;
    count--;
    return last; 
}

struct node* insertAfterPosition(struct node* first , int position, int data){
    
    if(position == 0){
        struct node* temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->next = first;
        temp->prev = NULL;
        first->prev = temp;

        first = temp;
        count++;
        return first;
    }
    

    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;

    struct node* iter = first;
    temp->prev = NULL;
    temp->data = data;

    if(position == 0){
        temp->next = first;
        first->prev = temp;
        first = temp;
        count++;
        return first;
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            iter = iter->next;
        }

        temp->next = iter->next;
        iter->next->prev = temp;
        iter->next = temp;
        temp->prev = iter;
        count++; 
        return first;
    }   
}

int main(){
    struct node* first = malloc(sizeof(struct node));
    struct node* last;
    first->prev = NULL;
    first->next = NULL;

    last = first;
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
        printf("5: Insert at Position\n");
        printf("6: Delete an element\n");
        printf("7: Delete First element\n");
        printf("8: Delete Last element\n");
        printf("0: Exit\n");
        printf("-------------------\n\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            int temp;
            scanf("%d", &temp);
            first = insertFirst(first,temp);
            break;

        case 2:
            printf("Enter the data: ");
            int temp2;
            scanf("%d", &temp2);
            last = insertLast(last,temp2);
            break;

        case 3:            
            printf("Enter the number: ");
            int temp3;
            scanf("%d",&temp3);
            printf("Insert after the number? : ");
            int temp4;
            scanf("%d",&temp4);
            insertAfter(first,last,temp3,temp4);
            break;

        case 4:
            traversal(first);
            break;


        case 5: 
            printf("Enter the position: ");
            int position;
            scanf("%d", &position);
            while (position > count)
            {
            printf("\n\nPosition greater than number of elements! Try again: ");
            scanf("%d",&position);
            }

            printf("Enter the data:");
            int data;
            scanf("%d",&data);

            if(position == count){
                last = insertLast(last,data);
                break;
            }
            first = insertAfterPosition(first, position, data);
            break;


        case 6: ;
            int x;
            printf("enter the element you want to delete :");
            scanf("%d",&x);
            first = deleteElement(first,last,x);
            break;

        case 7:
            first = removeFirst(first); 
            break;

        case 8:
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

    return 0;
}