// programm to add two polynomials

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int A;  //power of X
    int B;  //power of Y
    int C;  //power of Z
    struct node * next;
}; 


int ABC(struct node* term){
    return (term->A + term->B + term->C);
}

int ABCcompare(struct node* termP, struct node* termQ){
    if((termP->A == termQ->A) && (termP->B == termQ->B) && (termP->C == termQ->C) ) 
        return 1;
    else
        return 0;
}

struct node* smaller(struct node* x, struct node* y){
    if(x->A >  y->A){
        return y;
    }
    else if(x ->A == y->A){
        if(x->B >  y->B){
            return y;
        }
        else if(x ->B == y->B){
            if(x->C >  y->C){
                return y;
            }
            else if(x ->A == y->A){
                return y;
            }

            else
            {
                return x;
            }
        }
        else
        {
            return x;
        }
    }

    else
    {
        return x;
    }
    
}


struct node* insertInOrder(struct node* first,int coeff, int A, int B, int C){
    
    if(first == NULL){
        first = malloc(sizeof(struct node));
        first->coeff = coeff;
        first->A = A;
        first->B = B;
        first->C = C;
        first->next = NULL;
        return first;
    }
    
    struct node* temp = malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->A =A;
    temp->B =B;
    temp->C =C;
    temp->next = NULL;

    if(ABCcompare(temp,first)){
        first->coeff += temp->coeff;
        return first;
    }else if(smaller(temp,first) == temp){
        temp->next = first;
        first = temp;
        return first;
    }
       

    struct node* iter = first;
    struct node* iter2 = first;

    while (iter!= NULL )
    {
        if(ABCcompare(temp,iter) == 0){
            iter2 = iter;
            iter = iter->next;
            continue;
        }
        else if (ABCcompare(iter,temp))
        {
            iter->coeff += temp->coeff;
            return first;
        }
        iter2 = iter;
        iter = iter->next;
    }
    

    iter = first;
    iter2 = first;

    while (iter!= NULL)
    {
        if(smaller(iter,temp) == iter){
            iter2 = iter;
            iter = iter->next;
            continue;
        }
        else
        {
            temp->next = iter;
            iter2->next = temp;
            return first;
        }
        
        iter2 = iter;
        iter = iter->next;
    }

    temp->next = iter;
    iter2->next = temp;
    return first;
       
}

void traversal(struct node* first){
    if(first == NULL){
        printf("\nEmpty List!");
        return;
    }
    struct node* iter;
    iter = first;

    printf("\nPolynomial: ");
    while (iter->next != NULL)
    {
        printf("\n%d %d %d %d\n",iter->coeff,iter->A,iter->B,iter->C);
        iter = iter->next;
    }
    printf("\n%d %d %d %d\n",iter->coeff,iter->A,iter->B,iter->C);
}

struct node* Addition(struct node* P, struct node *Q){
    struct node* add;
    struct node* add_l;

    add = malloc(sizeof(struct node));
    add->A = add->B = add ->C = add->coeff = 0;
    add->next = NULL;
    add_l = add;

    struct node* iter_p = P;
    struct node* iter_q = Q;

    while(iter_p != NULL && iter_q != NULL){

        if(ABCcompare(iter_p,iter_q)){
            struct node* temp = malloc(sizeof(struct node));
            temp->A = iter_q->A;
            temp->B = iter_q->B;
            temp->C = iter_q->C;
            temp->coeff = iter_q->coeff + iter_p->coeff;
            temp->next = NULL;
            add_l->next = temp;
            add_l = temp;

            iter_q = iter_q->next;
            iter_p = iter_p->next;
        }else if(smaller(iter_p,iter_q) == iter_p){
            struct node* temp = malloc(sizeof(struct node));
            temp->A = iter_p->A;
            temp->B = iter_p->B;
            temp->C = iter_p->C;
            temp->coeff = iter_p->coeff;
            temp->next = NULL;
            add_l->next = temp;
            add_l = temp;

            iter_p = iter_p->next;
        }
        else{
            struct node* temp = malloc(sizeof(struct node));
            temp->A = iter_q->A;
            temp->B = iter_q->B;
            temp->C = iter_q->C;
            temp->coeff = iter_q->coeff;
            temp->next = NULL;
            add_l->next = temp;
            add_l = temp;

            iter_q = iter_q->next;
        }
        

    }

    if(iter_p == NULL){
        while (iter_q != NULL)
        {
            struct node* temp = malloc(sizeof(struct node));
            temp->A = iter_q->A;
            temp->B = iter_q->B;
            temp->C = iter_q->C;
            temp->coeff = iter_q->coeff;
            temp->next = NULL;
            add_l->next = temp;
            add_l = temp;

            iter_q = iter_q->next;
        }        
        return add;
    }

    if(iter_q == NULL){
        while (iter_p != NULL)
        {
            struct node* temp = malloc(sizeof(struct node));
            temp->A = iter_p->A;
            temp->B = iter_p->B;
            temp->C = iter_p->C;
            temp->coeff = iter_p->coeff;
            temp->next = NULL;
            add_l->next = temp;
            add_l = temp;

            iter_p = iter_p->next;
        }        
    }
    // add= add->next;
    return add;

}


int main(int argc, char const *argv[])
{
    struct node* P;
    P = NULL;
    struct node* Q;
    Q= NULL;

    printf("Enter Polynomial P: \n");
    while (1)
    {
        printf("\n1: Insert Term: (Coeff A B C)");
        printf("\n0: Exit\n");

        int choice;
        scanf("%d",&choice);

        if(choice == 0) 
            break;
        else if(choice == 1){
            int coeff,A,B,C;
            scanf("%d %d %d %d",&coeff, &A, &B, &C);
           P = insertInOrder(P,coeff,A,B,C);
        }
    }

    printf("Enter Polynomial Q: \n");
    while (1)
    {
        printf("\n1: Insert Term: (Coeff A B C)");
        printf("\n0: Exit\n");

        int choice;
        scanf("%d",&choice);

        if(choice == 0) 
            break;
        else if(choice == 1){
            int coeff,A,B,C;
            scanf("%d %d %d %d",&coeff, &A, &B, &C);
            Q = insertInOrder(Q,coeff,A,B,C);
        }
    }

    printf("\nP\t");
    traversal(P);

    printf("\nQ\t");
    traversal(Q);

    struct node* answer;
    answer =  Addition(P,Q);

    printf("\nAnswer\t");
    answer = answer->next;
    traversal(answer);

    return 0;
}
