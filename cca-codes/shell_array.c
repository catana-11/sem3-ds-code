#include <stdio.h>

void shell_sort(int s, int arr[s]) {
    int gap = s / 2;

    // Shell sort algorithm
    while (gap > 0) {
        for (int i = gap; i < s; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }

    printf("\nThe sorted array is: ");
    for (int i = 0; i < s; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a = 0;
    printf("Enter the array size: ");
    scanf("%d", &a);

    int arr[a];

    // Input array elements
    for (int i = 0; i < a; i++) {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("The array is: ");
    for (int i = 0; i < a; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    // Call shell_sort to sort the array
    shell_sort(a, arr);

    return 0;
}