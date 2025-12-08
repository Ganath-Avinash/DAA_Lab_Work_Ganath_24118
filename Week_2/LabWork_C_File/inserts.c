#include <stdio.h>

void inser_sort(int* arr,int l){
  for(int i=0;i<l;i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
}

int main(){
  int arr[]={11,2,12,3,245,3,4,2,4,5,7,4,567,5,4,44};
  inser_sort(arr,15);
  printf("Insertion Sorted O(n^2): \n");
  for(int i=0;i<15;i++){
    printf(" %d ",arr[i]);    
  }
  printf("\n");
}
