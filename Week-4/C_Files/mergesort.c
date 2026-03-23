#include <stdio.h>

void merge(int *arr,int *arr1,int *arr2,int l1,int l2);

void mergeSort(int *arr,int s,int e){
    if(e-s<2){
        return;
    }
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid,e);
    int l1=mid-s;
    int l2=e-mid;
    int arr1[l1];
    int arr2[l2];
    for (int i = 0; i < l1; i++)
    {
        arr1[i]=arr[s+i];
    }
    
    for (int i = 0; i < l2; i++)
    {
        arr2[i]=arr[mid+i];
    }
    merge(arr+s,arr1,arr2,l1,l2);
}

void merge(int *arr,int *arr1,int *arr2,int l1,int l2){
    int i=0,j=0,k=0;
    while(i<l1 && j<l2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }

    while(i<l1){
        arr[k++]=arr1[i++];
    }
    while(j<l2){
        arr[k++]=arr2[j++];
    }
}

void main(){
    int arr[10]={38, 27, 43, 3, 9, 82, 10, 17, 1, 3};
    int l=10;
    printf("Array: \n");
    for (int i = 0; i < l; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
    mergeSort(arr,0,l);
    printf("Sorted Array: \n");
    for (int i = 0; i < l; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");    
}