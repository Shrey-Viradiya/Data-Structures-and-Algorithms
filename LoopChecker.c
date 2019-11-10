// Write an algorithm to checks whether a given singly linked list contains 

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}; 

int count = 0; 

void insertFirst(struct node** first, int d){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = d;
    temp->next = *first;

    *first = temp;
    count++;
}


void insertLast(struct node* first,int d){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = d;
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

int main(int argc, char const *argv[])
{
    struct node* first = (struct node *) malloc(sizeof(struct node));
    
    first->data = 5;
    first->next = NULL;
    count++;

    insertLast(first,6);
    insertLast(first,7);

    struct node * middle;
    middle = first;

    while (middle->data != 7)
    {
        middle = middle->next;
    }
    
    insertLast(first,8);
    insertLast(first,9);
    insertLast(first,10);

    traversal(first);

    struct node* last = first;

    while(last->next != NULL){
        last = last->next;
    }

    last->next = middle;

    traversal(first);

    // code to remove loop
    long addr[10];
    int i=0;
    // struct node *iter = first;

    // while (true)
    // {
    //     addr[i] = (iter);
    // }
    

    
    return 0;
}
