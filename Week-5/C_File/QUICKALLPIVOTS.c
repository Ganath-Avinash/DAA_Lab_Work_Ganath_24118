#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_first(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

void quick_first(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_first(arr, low, high);
        quick_first(arr, low, pi - 1);
        quick_first(arr, pi + 1, high);
    }
}

int partition_last(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_last(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_last(arr, low, high);
        quick_last(arr, low, pi - 1);
        quick_last(arr, pi + 1, high);
    }
}

int partition_random(int arr[], int low, int high) {
    int random_index = low + rand() % (high - low + 1);
    swap(&arr[random_index], &arr[high]);
    return partition_last(arr, low, high);
}

void quick_random(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_random(arr, low, high);
        quick_random(arr, low, pi - 1);
        quick_random(arr, pi + 1, high);
    }
}

int main() {
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nChoose Pivot Method:\n");
    printf("1. First Element Pivot\n");
    printf("2. Last Element Pivot\n");
    printf("3. Random Pivot\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    srand(time(NULL));

    switch(choice) {
        case 1:
            quick_first(arr, 0, n - 1);
            break;
        case 2:
            quick_last(arr, 0, n - 1);
            break;
        case 3:
            quick_random(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
