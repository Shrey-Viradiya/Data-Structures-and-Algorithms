#include <stdio.h>

void print(int n){
  if(n>4000) return;
  printf("%d\n",n );
  print(2*n);
  printf("%d\n",n );
}

int main(int argc, char const *argv[]) {
  print(1000);
  return 0;
}
