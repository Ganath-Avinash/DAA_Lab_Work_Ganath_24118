#include <stdio.h>

void bubble_sort(int* arr,int l){
  for(int i=0;i<l;i++){
    for(int j=0;j<l;j++){
      if(arr[j]>arr[j+1]){
        int t=arr[j];
        arr[j]=arr[i];
        arr[i]=t;
      }
    }
  }
}

int main(){
  int arr[]={11,2,12,3,245,3,4,2,4,5,7,4,567,5,4,44};
  bubble_sort(arr,15);
  printf("Bubble Sorted O(n^2): \n");
  for(int i=0;i<15;i++){
    printf(" %d ",arr[i]);    
  }
  printf("\n");
}
