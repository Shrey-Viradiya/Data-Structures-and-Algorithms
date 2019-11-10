//Implement priority queue with all operations
 
#include<stdio.h>
#include<stdlib.h>
 
struct priorityQueue
{
   int rear;
   int front;
   int size;
   int p;
   int *priority;
   int *arr;
}Q;
 
void enQueue(struct priorityQueue* queue){
   if (queue->rear == queue->size - 1 )
   {
       printf("\nQueue is Full\n");
       return;
   }else
   {
       if(queue->front == -1 && queue->rear == -1 ){
           queue->front = 0;
           queue->rear = 0;
       }
       int num,pr,sum = 0;
       printf("\n Enter the number: \n");
       scanf("%d",&num);
       printf("\n Enter the prioroty: \n");
       scanf("%d",&pr);
 
 
       for (int i = pr+1 ; i < queue->p; i++)  sum += *(queue->priority + i);

       int i = 0,k = 0;
       for (i = 0; i < sum+1; i++)
       {    
           *(queue->arr + queue->rear - i + 1) = *(queue->arr + queue->rear - i);
           k = i;
       }
       
       *(queue->arr + queue->rear - k) = num;
       queue->rear ++;
       *(queue->priority + pr) += 1;
      
 
   }   
}
 
void deQueue(struct priorityQueue* queue){
   if (queue->front == -1)
   {
       printf("\nQueue is Empty\n");
       return;
   }else
   {
       printf("Removed Number is: %d\n", *(queue->arr));
       int i;
       for (i = 0; i < queue->rear; i++)
       {
           *(queue->arr + i) = *(queue->arr + i + 1);
       }
 
       for (int i = 0; i < queue->p; i++)
       {
           if (queue->priority[i] != 0)
           {
               queue->priority[i]--;
               break;
           }
          
       }
      
 
       queue->rear -=1;
       *(queue->arr + i) = 0;
 
   }   
}
 
void display(struct priorityQueue *queue)
{
   int i;
   if(queue->front==-1&&queue->rear==-1)
   {
       printf("Queue is underflow\n");
   }
 
   for (i = 0; i < queue->rear; i++)
   {
       printf("%d\t",*(queue->arr + i));
   }
   printf("\n");
 
}
 
void main(){
   int num,s;
   int choice;
   Q.rear=-1;
   Q.front=-1;
 
   printf("\nEnter the size of the Queue: ");
   scanf("%d",&Q.size);
   printf("\nEnter the number of the different priorities: ");
   scanf("%d",&Q.p);
 
   Q.arr = (int*) calloc(Q.size , sizeof(int));
   Q.priority = (int*) calloc(Q.p , sizeof(int));
 
   do
   {
       printf("\n1 : enQueue\n");
       printf("2 : deQueue\n");
       printf("3 : Display\n");
       printf("4 : Quit\n");
      
       printf("\n Enter your choice: \n");
       scanf("%i",&choice);
       getchar();
 
       switch (choice)
       {
       case 1:
           enQueue(&Q);
           break;
      
       case 2:
           deQueue(&Q);
           break;
 
       case 3:
           display(&Q);
           break;
 
       case 4:
           printf("\n..Exiting..\n");
           break;
 
       default:
           printf("\nWrong Input\n");
           break;
       }
   } while (choice != 4);
  
 
}
 

