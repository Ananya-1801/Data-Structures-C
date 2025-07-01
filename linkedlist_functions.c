//WAP IN C TO COUNT THE NUMBER OF NODES IN A LINKED LIST AND THE SUM OF IT'S ELEMENTS AS WELL

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
        int i;
        struct Node *t,*last;
        first=(struct Node *)malloc(sizeof(struct Node));
        first->data=A[0];
        first->next=NULL;
        last=first;

        for(i=1;i<n;i++)
        {
                t=(struct Node*)malloc(sizeof(struct Node));
                t->data=A[i];
                t->next=NULL;
                last->next=t;
                last=t;
        }
}

void rdisplay(struct Node *p)
{

        if(p!=NULL)                            //base condition of recursive function.
        {
                printf("%d ",p->data);
                rdisplay(p->next);
        }
}

int count(struct Node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		return count(p->next)+1;
	}
}

int Add(struct Node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		return Add(p->next)+p->data;
	}
}

int Max(struct Node *p)
{
	int max = -32768;
	while(p)
	{
		if(p->data>max)
			max=p->data;
		p=p->next;
	}
	return max;
}

int Min(struct Node *p)
{
	int min=9000000;
	while(p!=NULL)
	{
		if(min>p->data)
		{
			min=p->data;
		}
		p=p->next;
	}
	return min;
}

int main()
{

int A[]={3,5,7,10,15};

create(A,5);

rdisplay(first);
printf("\n");

int c=0;
int sum=0;

c=count(first);
sum=Add(first);

printf("The number of nodes in the created linked list is:%d\n",c);
printf("The sum of the elements in the given linked list is:%d\n",sum);

int m=0;
int n=0;
m=Max(first);
n=Min(first);

printf("The maximum element in linked list:%d\n",m);
printf("The minimum element in linked list:%d\n",n);

return 0;

}
