#include <stdio.h>

void main() {
    int arr[5], i, j, temp, n = 5;

    printf("\n Enter the array elements. ");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n The un-sorted elements are: \n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Added space to separate elements
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {  // Corrected the loop condition
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n The sorted elements are :\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Added space to separate elements
    }