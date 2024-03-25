#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    int mid, max1, max2, min1, min2;

    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    mid = (low + high) / 2;
    findMaxMin(arr, low, mid, &max1, &min1);
    findMaxMin(arr, mid + 1, high, &max2, &min2);
    if (max1 > max2)
        *max = max1;
    else
        *max = max2;

    if (min1 < min2)
        *min = min1;
    else
        *min = min2;
}

int main() {
    int arr[100]; 
    int arr_size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &arr_size);

    printf("Enter %d elements:\n", arr_size);
    for (int i = 0; i < arr_size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max, min;
    findMaxMin(arr, 0, arr_size - 1, &max, &min);

    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}

