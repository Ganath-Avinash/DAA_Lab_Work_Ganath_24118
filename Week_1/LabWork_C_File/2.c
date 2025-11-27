#include <stdio.h>

int sum(int n){
  int s=0;
  for(int i=1;i<=n;i++){
      s+=(i*i);
  }
  return s;
}

void main(){
    int n=0;
    scanf("%d",&n);
    printf("sum: %d",sum(n));
}
