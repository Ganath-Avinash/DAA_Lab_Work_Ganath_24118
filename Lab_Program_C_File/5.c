#include <stdio.h>

void main(){
  int arr[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i<j){
        int tem=arr[i][j];
        arr[i][j]=arr[j][i];
        arr[j][i]=tem;
      }
    }
  }
  printf("Transpose: \n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf(" %d ",arr[i][j]);
    }
    printf("\n");
  }
}
