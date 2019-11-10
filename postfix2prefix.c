#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include<string.h>

#define MAX 200

struct stack
{
	
	int top;
	char arr[MAX+1][100];
}s;

void POP(struct stack* s,char *str)
{
	
	if(s->top == -1) {
        perror("Stack Underflow!");
    }

	strcpy(str,s->arr[s->top]);
	strcpy(s->arr[s->top],"");
	s->top--;
	return ;
}

void PUSH(struct stack* s, char value[])
{

	if(s->top == MAX){
         perror("Stack Overflow!");
    }

	s->top++;
	strcpy(s->arr[s->top],value);
}

int r(char a)
{
	if(a == '#') return 0;
	if(isalpha(a)) return 1;
	return -1;
}

void main(){
    char postfix[1000];
    printf("Ente the Postfix String: ");
    scanf("%s",postfix);
    strcat(postfix,"#");
    puts(postfix);

    struct stack s = {-1};
    // s.top=-1;

    int rank=0;
    for (int i = 0; i < strlen(postfix); i++)
    {
        rank += r(postfix[i]);
        if(rank < 1)
            perror("Invalid Expression!");
    }

    int i=0;
    while (postfix[i]!='#')
    {
        if (isalpha(postfix[i]))
        {
            char temp[100];
            temp[0] = postfix[i];
            temp[1] = '\0';
            PUSH(&s,temp);
        }else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%') 
        {
            char temp1[100],temp2[100],temp[100];
            POP(&s,temp2);
            POP(&s,temp1);
            char new[100];
            temp[0] = postfix[i];
            temp[1] = '\0';

            strcpy(new,strcat(temp,strcat(temp1,temp2)));
            PUSH(&s,new);
        }  
        i++;     
    }

    puts(s.arr[0]);
        

}