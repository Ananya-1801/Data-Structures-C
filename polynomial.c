//WAP IN C TO DESIGN A POLYNOMIAL USING C AND ADD TWO POLYNOMIALS.

#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    printf("Enter the number of terms: ");
    scanf("%d", &p->n);
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    for (int i = 0; i < p->n; i++) {
        printf("Enter term %d (coefficient and exponent): ", i + 1);
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
	{
        printf("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i < p.n - 1)
            printf(" + ");
    }
    printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    struct Poly *sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    int i = 0, j = 0, k = 0;
    while (i < p1->n && j < p2->n) {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    while (i < p1->n) sum->terms[k++] = p1->terms[i++];
    while (j < p2->n) sum->terms[k++] = p2->terms[j++];

    sum->n = k;
    return sum;
}

int main()
{
    struct Poly p1, p2, *p3;

    printf("Enter the first polynomial:\n");
    create(&p1);
    printf("Enter the second polynomial:\n");
    create(&p2);
    printf("\n");

    p3 = add(&p1, &p2);

    printf("****** FIRST POLYNOMIAL ********\n");
    display(p1);
    printf("****** SECOND POLYNOMIAL ********\n");
    display(p2);
    printf("****** SUM POLYNOMIAL ********\n");
    display(*p3);

    free(p1.terms);
    free(p2.terms);
    free(p3->terms);
    free(p3);

    return 0;
}
