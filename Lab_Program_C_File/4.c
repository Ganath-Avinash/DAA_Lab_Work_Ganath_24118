#include <stdio.h>

int fact(int n){
  if(n==1){
    return 1;
  }
  return n*fact(n-1);
}

void main(){
    int n=0;
    scanf("%d",&n);
    printf("Fact: %d",fact(n));
}
