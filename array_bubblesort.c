// WAP IN C TO SORT A SIMPLE ARRAY IN ASCENDING ORDER ( BUBBLE-SORT )

#include <stdio.h>

void sortAscending(int *arr, int n) 
{
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) 
    {
        swapped = 0; // Track if a swap happens

        for (j = 0; j < n - i - 1; j++) 
        {
            if (*(arr + j) > *(arr + j + 1)) 
            {
                // Swap using pointers
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swapped = 1;
            }
        }

        // If no swap happened, array is already sorted
        if (!swapped) 
            break;
    }
}

int main() 
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", arr + i);
    }

    sortAscending(arr, n);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *(arr + i)); 
    }
    printf("\n");

    return 0;
}
