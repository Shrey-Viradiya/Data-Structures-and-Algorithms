//Implement circular queue with all operations

#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int rear;
    int front;
    int size;
    int *arr;
}Q;

void enQueue(struct circularQueue* queue){
    if (queue->front == (queue->rear + 1)% queue->size)
    {
        printf("\nQueue is Full\n");
        return;
    }else
    {
        int num;
        printf("\n Enter the number: \n");
        scanf("%d",&num);
        queue-> rear = (queue->rear + 1) % queue->size;
        *(queue->arr + queue->rear) = num;
        if (queue->front == -1) queue->front = 0;
    }
}

void deQueue(struct circularQueue* queue){
    if (queue->front == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }else
    {
        int num;
        num = *(queue->arr + queue->front);
        *(queue->arr + queue->front) = 0;
        if(queue->front == queue->rear){
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % queue->size;
        }
        printf("Removed Number is: %d\n", num);
    }    
}

void display(struct circularQueue *queue){
    if(queue->rear >= queue->front){
        for (int i = queue->front; i < queue->rear + 1  ; i++)
        {
            printf("\n%d",*(queue->arr + i) );
        }
    }
    else{
        for (int i = queue->front; i < queue->size  ; i++)
        {
            printf("\n%d",*(queue->arr + i) );
        }
        for (int i = 0; i < queue->rear + 1  ; i++)
        {
            printf("\n%d",*(queue->arr + i) );
        }
    }
}

void main(){
    int num,s;
    char choice;
    Q.rear=-1;
    Q.front=-1;

    printf("\nEnter the size of the Queue: ");
    scanf("%d",&Q.size);

    Q.arr = (int*) calloc(Q.size , sizeof(int));

    do
    {
        printf("\nI : enQueue\n");
        printf("D : deQueue\n");
        printf("P : Display\n");
        printf("Q : Quit\n");
        
        printf("\n Enter your choice: \n");
        scanf("%c",&choice);
        scanf("%c",&choice);

        switch (choice)
        {
        case 'I':
        case 'i':
            enQueue(&Q);
            break;
        
        case 'D':
        case 'd':
            deQueue(&Q);
            break;

        case 'P':
        case 'p':
            display(&Q);
            break;

        case 'Q':
            printf("\n..Exiting..\n");
            break;

        default:
            printf("\nWrong Input\n");
            break;
        }
    } while (choice != 'Q' || choice == 'q');
    

}
