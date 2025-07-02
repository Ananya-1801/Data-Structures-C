//WAP IN C TO PERFORM OPERATIONS ON A STACK USING ARRAY

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int top;
	int *s;
}st;

void create(struct Stack *st)
{
	printf("Enter the size of the stack:");
	scanf("%d",&st->size);
	st->top=-1;
	st->s=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
	int i;
	for(i=st.top;i>=0;i--)
	{
		printf("%d ",st.s[i]);
	}
	printf("\n");
}

void push(struct Stack *st,int x)
{
	if(st->top==st->size-1)
		printf("Stack Overflow!\n");
	else
	{
		st->top++;
		st->s[st->top] = x;  
	}
}

int pop(struct Stack *st)
{
	int x= -1;
	if(st->top==-1)
		printf("Underflow!\n");
	else
	{
		x=st->s[st->top];
		st->top--;
	}
	return x;
}

int peek(struct Stack st,int index)
{
	int x= -1 ;
	if( (st.top-index+1) < 0 )
		printf("Invalid position or index!\n");
	else
	{
		x=st.s[st.top-index+1];
	}
	return x;
}

int isEmpty(struct Stack st)
{
	if(st.top==-1)
		return 1;
	else
		return 0;
}

int isFull(struct Stack st)
{
	return st.top==st.size-1;
}

int StackTop(struct Stack st)
{
	if(!isEmpty(st))
		return st.s[st.top];
	return -1;
}

int main()
{
	create(&st);
	Display(st);
	char ch;
	/*int x;
	for(int i=0;i<st.size;i++)
	{
	printf("Enter the element to be pushed: ");
	scanf("%d", &x);
	push(&st, x);
	}*/ 
do{
	printf("***** MENU *****\n");
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.PEEK\n");
	printf("4.STACKTOP\n");
	printf("5.ISEMPTY\n");
	printf("6.ISFULL\n");
	printf("Choose stack operation(1-6):");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			int x;
			printf("Enter the element to be pushed: ");
			scanf("%d", &x);
			push(&st, x);
			printf("After push, the stack is: ");
			Display(st);
			break;
		case 2:
			int res = pop(&st);  // Corrected line
			printf("The element popped is: %d\n", res);
			break;
		case 3:
			int index;
			printf("Enter the position of element to be searched/peeked: ");
			scanf("%d", &index);
			int res2 = peek(st, index);
			printf("The element after peeking is found to be: %d\n", res2);
			break;
		case 4:
			int top = StackTop(st);
			printf("The stack top is: %d\n", top);
			break;
		case 5:
			if (isEmpty(st))
			printf("Stack is empty!\n");
			else
			printf("The stack is not empty.\n");
			break;
		case 6:
			if (isFull(st))
			printf("Stack is full!\n");
			else
			printf("The stack is not full.\n");
			break;
		default:
			printf("Invalid choice!\n");
	}
	printf("Do you want to continue?(y/n):");
	scanf(" %c",&ch);
}while(ch=='y'||ch=='Y');

	return 0;
}

