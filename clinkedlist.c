//WAP IN C TO CREATE AND DISPLAY A CIRCULAR LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*Head;

void create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	Head=(struct Node *)malloc(sizeof(struct Node));
	Head->data=A[0];
	Head->next=Head;
	last=Head;

	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *h)
{
	do
	{
		printf("\%d ",h->data);
		h=h->next;
	}while(h!=Head);
	printf("\n");
}

void RDisplay(struct Node *h)
{
	static int flag=0;
	if(h!=Head || flag==0)
	{
		flag=1;
		printf("%d ",h->data);
		RDisplay(h->next);
	}
	flag=1;
	printf("\n");
}

int Length(struct Node *h)
{
	int len=0;
	do
	{
		len++;
		h=h->next;
	}while(h!=Head);
	return len;
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;

    if (index < 0 || index > Length(Head))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {
        if (Head == NULL) {
            Head = t;
            Head->next = Head;
        } else {
            // Traverse to the last node
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    } else {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p,int index)
{
	struct Node *q;
	int i;
	int x=-1;
	if(index < 0 || index > Length(Head))
		return -1;
	if(index==1)
	{
		while(p!=Head)p=p->next;
		x=Head->data;
		if(Head==p)
		{
			free(Head);
			Head=NULL;
		}
		else
		{
			p->next=Head->next;
			free(Head);
			Head=p->next;
		}
	}
	else
	{
		for(i=0;i<index-2;i++)p=p->next;
		q=p->next;
		p->next=q->next;
		x=q->data;
		free(q);
	}
	return x;
}

int main()
{

int A[]={2,4,6,8,10};

create(A,5);
Display(Head);
Insert(Head,1,5);
Display(Head);
int res;
res=Delete(Head,4);
printf("The deleted element is:%d\n",res);
Display(Head);
return 0;
}
