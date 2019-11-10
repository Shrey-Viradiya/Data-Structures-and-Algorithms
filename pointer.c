#include<stdio.h>

int main(int argc, char const *argv[])
{
    int x = 5;
    int *p;
    p = &x;
    printf("\n\n%d\n",p);
    printf("%d\n",*p);
    p=p+1;
    printf("\n%d\n",p);
    printf("%d\n\n",*p);
    return 0;
}
