#include <stdio.h>
#include <stdlib.h>

void reverse(int *a, int s, int e)
{
    while (s < e)
    {
        int temp = *(a + s);
        *(a + s) = *(a + e);
        *(a + e) = temp;

        s++;
        e--;
    }
}

void display(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, *arr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the number of elements by which the array has to be rotated: ");
    scanf("%d", &k);

    if(k>n)
    {
        k = k % n;
    } 
    
    // Rotate the array to the right by k elements using reversal algorithm
    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);
    reverse(arr, 0, n - 1);

    printf("The array after rotating by %d elements is:\n", k);
    display(arr, n);

    free(arr);
    return 0;
}
