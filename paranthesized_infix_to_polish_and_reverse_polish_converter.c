#include <stdio.h> // Handles standard input/output
#include <errno.h> // Error Handling library
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The maximum number of elements that can be stored in a stack.
#define MAX 65535

// Structure of stack
struct stack
{
	// A integer pointing at the top of the stack.
	int top;
	// A array to hold the values of stack.
	char arr[MAX+1];
}s;

// Deletes and returns the top element in a stack.
char POP(struct stack* s)
{
	// IMPLEMENT POP

	// Handle error when stack is empty.
	if(s->top == -1) perror("Stack Underflow!");

	// Get a copy of value at the top of the stack
	// in a variable `element` that we are going to return.
	char element = s->arr[s->top];

	// Initialize the value at the top of the stack again to 0.
	s->arr[s->top] = 0;
	// Decrease the value of `top` by 1.
	s->top--;

	// Finally, return `element`.
	return element;
}

// Adds a element onto the top of stack
void PUSH(struct stack* s, char value)
{
	// IMPLEMENT PUSH

	// Handle error in case the stack has reached its maximum limit `MAX`.
	if(s->top == MAX) perror("Stack Overflow!");

	// Increase the value of `top` by 1.
	s->top++;
	// Insert element at the index `top`.
	s->arr[s->top] = value;
}

// f returns the precedence of the symbol in the input string.
int f(char a)
{
	// if a is a alphabet (variable) return precedence 3
	if(isalpha(a)) return 7;

	// Else if a is a `*` or `/` return lower precedence than variable
	if(a == '*' || a == '/') return 3;

	// Else if a is a `+` or `-` return lower precedence than `*` or `/`
	if(a == '+' || a == '-') return 1;

    if(a == '^') return 6;

    if(a == '(') return 9;

	// Else return lowest precednece!
	if(a == '#' || a == ')') return 0;
	else return -200;
}

// g returns the precedence of the symbol in the stack.
int g(char a)
{
	// if a is a alphabet (variable) return precedence 3
	if(isalpha(a)) return 8;

	// Else if a is a `*` or `/` return lower precedence than variable
	if(a == '*' || a == '/') return 4;

	// Else if a is a `+` or `-` return lower precedence than `*` or `/`
	if(a == '+' || a == '-') return 2;

    if(a == '^') return 5;

    if(a == '(') return 0;

	// Else return lowest precednece!
	if(a == '#' || a == ')') return -1;

	else return -1;
}

// Returns the rank of the character literal
int r(char a)
{
	// If the character is `#` return rank 0.
	// Else if it is a alphabet (variable) return 1.
	// Else if it is a operator return -1;
	if(a == '#') return 0;
	if(isalpha(a)) return 1;
	return -1;
}

// Use this function to parse infix to reverse polish
void parse_infix(char infix[])
{
	// Declare a string to store the reverse polish string and initialize rank to 0
	char r_polish[1000];int rank=0;

	// Creaste stack s
	struct stack s = {-1,0};
	// i and j will be used to access elements of infix and r_polish resp.
	int i=0,j=0;
	PUSH(&s, '#'); // Initialize stack by pushing `#` as the first character.

	// Until we dont reach the end of the infix string, parse it.
	while(infix[i] != '#')
	{
		// if precedence of element at the top of the stack is
		// more than that of next element of infix string, 
		// shift the element from the stack to the reverse polish string.
		while( g(s.arr[s.top]) >= f(infix[i]) )
		{
			char temp = POP(&s); // first pop
			if(temp != '(' && temp != ')'){ 
                r_polish[j++] = temp; // put that char to next empty index in the `r_polish` string.
			    rank += r(temp); // update rank
            }
		}

		// Once the shifting is done, push new element to the stack
		PUSH(&s, infix[i++]);
	}

	// Shift all the remaining elements from the stack to `r_polish` string.
	while(s.arr[s.top]!='#'){
		char temp = POP(&s); // pop
		if(temp != '(' && temp != ')'){ 
            r_polish[j++] = temp; // put that char to next empty index in the `r_polish` string.
			rank += r(temp); // update rank
        }
	}

	// End the `r_polish` string.
	r_polish[j] = '\0';

	// Check if rank is equal to 1. If not, show error in input.
    if(rank != 1){;printf("Error in rank! Check your input!\n");}

	// Show the parsed string.
	puts(r_polish);

}

int main()
{
	printf("Enter a infix string using any variables like a, b, c, etc.\nDon't use any whitespaces\nEnter string: ");
	char infix_string[1000];
	scanf("%s", infix_string);
    strcat(infix_string, "#");
    printf("%s\n", infix_string);
	parse_infix(infix_string);
}