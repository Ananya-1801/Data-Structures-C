//WAP IN C TO SORT THE ELEMENTS PRESENT IN A STACK USING RECURSION

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    int *s;
} stack;

void create(stack *st)
{
    printf("Enter the size of the stack : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void Display(stack st)
{
    for (int i = st.top; i >= 0; i--)   
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void push(stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}


void sortedInsert(stack *st, int x)
{
    if (st->top == -1 || x > st->s[st->top])
    {
        push(st, x);
        return;
    }
    int temp = pop(st);
    sortedInsert(st, x);
    push(st, temp);
}


void sortStack(stack *st)
{
    if (st->top == -1)
        return;

    int temp = pop(st);
    sortStack(st);
    sortedInsert(st,temp);
}

int main()
{
    stack st;
    create(&st);

    int n, val;
    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("*********** CREATE STACK ************\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        push(&st, val);
    }

    printf("Original Stack: ");
    Display(st);

    sortStack(&st);

    printf("Sorted Stack: ");
    Display(st);

    return 0;
}
