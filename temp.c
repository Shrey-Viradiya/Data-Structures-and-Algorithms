#include<stdio.h>
#include<string.h>

void main(){
	char a[100] = "Hello",b[100],c[100]="Bolo";

	puts(a);
	puts(b);
	puts(c);

	strcpy(b,strcat(a,c));

	puts(b);
}