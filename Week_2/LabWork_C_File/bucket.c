#include <stdio.h>

void bucketSort(int arr[], int n) {
    int bucket[10][10], count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;     
        bucket[index][count[index]++] = arr[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < count[i]; j++) {
            int key = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }
    int idx = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < count[i]; j++)
            arr[idx++] = bucket[i][j];
}

int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = 7;

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
