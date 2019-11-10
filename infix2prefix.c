#include <stdio.h> 
#include <errno.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX 65535


struct stack
{
	
	int top;
	char arr[MAX+1];
}s;


char POP(struct stack* s)
{
	
	if(s->top == -1) {
        perror("Stack Underflow!");
    }

	char element = s->arr[s->top];

	s->arr[s->top] = 0;
	s->top--;
	return element;
}

void PUSH(struct stack* s, char value)
{

	if(s->top == MAX){
         perror("Stack Overflow!");
    }

	s->top++;
	s->arr[s->top] = value;
}

int f(char a)
{
	if(isalpha(a)) return 7;

	if(a == '*' || a == '/') return 3;

	if(a == '+' || a == '-') return 1;

    if(a == '^') return 6;

    if(a == '(') return 9;

	if(a == '#' || a == ')') return 0;
	else return -200;
}

int g(char a)
{
	if(isalpha(a)) return 8;

	if(a == '*' || a == '/') return 4;

	if(a == '+' || a == '-') return 2;

    if(a == '^') return 5;

    if(a == '(') return 0;

	if(a == '#' || a == ')') return -1;

	else return -1;
}

int r(char a)
{
	if(a == '#') return 0;
	if(isalpha(a)) return 1;
	return -1;
}

void main(){
    char temp[1000],infix[1000] = {'#'};
    scanf("%s",temp);

    strcat(infix,temp);
    puts(infix);

    char prefix[1000];
    int rank = 0;

    struct stack s;
    s.top=-1;
    PUSH(&s,'#');

    int i=strlen(infix)-1,j=0;
    while (infix[i]!='#')
    {
        while (g(s.arr[s.top]) >= f(infix[i]))
        {
            char temp = POP(&s); // first pop
			if(temp != '(' && temp != ')'){ 
                prefix[j++] = temp; // put that char to next empty index in the `r_polish` string.
			    rank += r(temp); // update rank
            }
        }
        PUSH(&s, infix[i--]);        
    }
    while(s.arr[s.top]!='#'){
            char temp = POP(&s); // pop
            if(temp != '(' && temp != ')'){ 
                prefix[j++] = temp; // put that char to next empty index in the `r_polish` string.
                rank += r(temp); // update rank
            }
        }
    prefix[j] = '\0';

    if(rank != 1){;printf("Error in rank! Check your input!\n");}

	// Show the parsed string.
    strrev(prefix);
	puts(prefix);
}