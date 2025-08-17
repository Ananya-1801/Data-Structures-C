/* Three sum - sub array problem */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int x;
    printf("Enter the number/target: ");
    scanf("%d", &x);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == x)
            {
                count++;
                j++;
                k--;
            }
            else if (sum > x)
                k--;
            else
                j++;
        }
    }

    printf("Total triplets with sum %d: %d\n", x, count);

    free(arr);
    return 0;
}
