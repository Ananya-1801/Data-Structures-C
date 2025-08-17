/* TWO SUM - SUB ARRAY IN C */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int)); 

    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the value of sum/target : ");
    scanf("%d", &x);

    int count = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                count++;
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    printf("Total pairs with sum %d = %d\n", x, count);

    free(arr);
    return 0;
}
