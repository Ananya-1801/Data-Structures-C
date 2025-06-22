#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};


void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[(m->n * j + ((j-2) * (j - 1)) / 2) + (i - j)] = x;
    }
}


int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.A[(m.n * j + ((j-2) * (j - 1)) / 2) + (i - j)];
    }
    else
    {
        return 0;
    }
}


void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[(m.n * j + ((j-2) * (j - 1)) / 2) + (i - j)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int x;

    printf("Enter the size of the matrix: ");
    scanf("%d", &m.n);

   
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter the elements row-wise:\n");
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }

    printf("\nMatrix:\n");
    Display(m);

    free(m.A);
    return 0;
}
