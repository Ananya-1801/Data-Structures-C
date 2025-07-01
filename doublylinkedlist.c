//WAP IN C TO CREATE DISPLAY AND PERFORM OTHER OPERATIONS IN A DOUBLY LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
	struct Node *t,*last;
	int i;
	first=(struct Node*)malloc(sizeof(struct Node));
	first->data=A[0];
	first->prev=first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int Length(struct Node *p)
{
	int len=0;
	while(p!=NULL)
	{
		len++;
		p=p->next;
	}
	return len;
}

void Insert(struct Node *p,int index,int x)
{
	struct Node *t;
	int i;
	if(index <0 || index>Length(first))
		return;
	if(index==0)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
	}
	else
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		for(i=0;i<index-1;i++)
			p=p->next;
		t->next=p->next;
		t->prev=p;
		if(p->next!=NULL)
			p->next->prev=t;
		p->next=t;
	}

}

int Delete(struct Node *p, int index)
{
    int x = -1, i;
    if (index < 0 || index >= Length(first)) 
        return -1;

    if (index == 0)
    {
        x = first->data;
        p = first;
        first = first->next;
        if (first != NULL)
            first->prev = NULL;
        free(p);
    }
    else
    {
        for (i = 0; i < index; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p)
{
	struct Node *t;
	while(p!=NULL)
	{
		t=p->next;
		p->next=p->prev;
		p->prev=t;
		p=p->prev;
		if(p!=NULL && p->next==NULL)
			first=p;
	}

}

int main()
{
    int A[] = {3, 5, 7, 9, 11};

  
    create(A, 5);
    printf("Initial list: ");
    Display(first);

    // Get and display length
    int l = Length(first);
    printf("The length of the linked list is: %d\n", l);

    // Insert 12 at index 3
    Insert(first, 3, 12);
    printf("After inserting 12 at index 3: ");
    Display(first);

    int res = Delete(first, 1);
    if (res != -1)
        printf("The deleted element is: %d\n", res);
    else
        printf("Deletion failed. Invalid index.\n");

    printf("After deletion at index 1: ");
    Display(first);

    Reverse(first);
    printf("After reversing the list: ");
    Display(first);

    return 0;
}
