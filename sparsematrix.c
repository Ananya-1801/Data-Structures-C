//WAP IN C TO CREATE AND DISPLAY AND PERFORM OPERATIONS ON A SPARSE MATRIX

#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i; // row
    int j;  // column
    int x; // value
};

struct Sparse
{
    int m;   // number of rows
    int n;  // number of columns
    int num; // number of non-zero elements
    struct Element *e;
};

void Create(struct Sparse *s)
{
    int i;
    printf("Enter dimensions (rows, columns): ");
    scanf("%d%d", &s->m, &s->n);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->num);

    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));

    printf("Enter row, column, and value for each non-zero element:\n");
    for (i = 0; i < s->num; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
    int i = 0, j = 0, k = 0;

    if (s1->m != s2->m || s1->n != s2->n)
    {
        printf("The matrices must have the same dimensions!\n");
        return NULL;
    }

    struct Sparse *sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->m = s1->m;
    sum->n = s1->n;
    sum->e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i ||
           (s1->e[i].i == s2->e[j].i && s1->e[i].j < s2->e[j].j))
        {
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[j].i ||
                (s1->e[i].i == s2->e[j].i && s1->e[i].j > s2->e[j].j))
        {
            sum->e[k++] = s2->e[j++];
        }
        else
        {
            sum->e[k] = s1->e[i];
            sum->e[k++].x += s2->e[j++].x;
            i++;
        }
    }

    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->num = k;
    return sum;
}


void Display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
   {
        for (j = 0; j < s.n; j++)
       {
            if (k < s.num && s.e[k].i == i && s.e[k].j == j)
                printf("%d ", s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
	printf("\n");
}


int main()
{
    struct Sparse s1,s2,*s3;
	printf("Enter the first matrix:\n");
	Create(&s1);
	printf("Enter the second matrix:\n");
	Create(&s2);
	
	s3=Add(&s1,&s2);

	printf("******** FIRST MATRIX ********\n");
	Display(s1);
	printf("******** SECOND MATRIX ********\n");
	Display(s2);
	printf("********* SUM MATRIX **********\n");
	Display(*s3);
	
	
    free(s1.e);
    free(s2.e);
    free(s3->e);

    return 0;
}
