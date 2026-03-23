#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (last element as pivot)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1; // pivot index
}

// Quick Select function
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return quickSelect(arr, low, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, high, k);
    }
    return -1; 
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 26, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // k-th smallest (1-based)

    int result = quickSelect(arr, 0, n - 1, k - 1);

    printf("The %d-th smallest element is %d\n", k, result);

    return 0;
}