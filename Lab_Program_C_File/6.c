#include <stdio.h>

int fibbo(int n){
  int s=0;int s1=1;int num=0;
  for(int i=0;i<n-2;i++){
     num=s+s1;
     s=s1;
     s1=num;
  }
  return num;
}

void main(){
    int n=0;
    scanf("%d",&n);
    printf("Fact: %d\n",fibbo(n));
}
