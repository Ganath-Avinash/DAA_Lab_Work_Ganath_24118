#include <stdio.h>

void selection_sort(int* arr,int l){
  for(int i=0;i<l;i++){
    int midx=i;
    for(int j=i+1;j<l;j++){
      if(arr[midx]>arr[j]){
        midx=j;
      }
    }
    int t=arr[i];
    arr[i]=arr[midx];
    arr[midx]=t;
  }
}

int main(){
  int arr[]={11,2,12,3,245,3,4,2,4,5,7,4,567,5,4,44};
  selection_sort(arr,15);
  printf("Selection Sorted O(n^2): \n");
  for(int i=0;i<15;i++){
    printf(" %d ",arr[i]);    
  }
  printf("\n");
}
