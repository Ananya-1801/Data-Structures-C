#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int y)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = y;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

int main()
{
    struct Array arr;

    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;  // ✅ Initialize length to zero

    int ch;

    do
    {
        printf("\n********** MENU **********\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Sum\n");
        printf("5. Exit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &ch);

        int index, num, res;

        switch (ch)
        {
        case 1:
            printf("Enter the index and the element to be inserted: ");
            scanf("%d %d", &index, &num);
            insert(&arr, index, num);
            break;
        case 2:
            int del;
            printf("Enter the index of the element to be deleted: ");
            scanf("%d", &index);
            del = Delete(&arr, index);
            printf("The deleted element is: %d\n", del);
            break;
        case 3:
            printf("Array elements: ");
            Display(arr);
            break;
        case 4:
            printf("The sum of the elements in the array is: %d\n", sum(arr));
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice, choose between (1–5)!!\n");
        }
    } while (ch != 5);

    free(arr.A);  
    return 0;
}
