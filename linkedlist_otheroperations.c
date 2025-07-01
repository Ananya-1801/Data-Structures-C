//WAP IN C TO IMPLEMENT LINEAR SEARCH OVER A LINKED LIST. USE IMPROVED LINEAR SEARCH AS WELL.
//includes create, display, search , insert and delete.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
	struct Node *t,*last;
	first=(struct Node*)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;

	for(int i=1;i<=n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void create2(int A[],int n)
{
        struct Node *t,*last;
        second=(struct Node*)malloc(sizeof(struct Node));
        second->data=A[0];
        second->next=NULL;
        last=second;

        for(int i=1;i<=n;i++)
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
	if(p!=NULL)
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

struct Node* Search(struct Node *p,int key)           //simple linear search
{
	while(p!=NULL)
	{
		if(key==p->data)
			return p;
	p=p->next;
	}
	return NULL;
}
struct Node* rsearch(struct Node *p,int key)    //recursive searching
{
	if(p==NULL)
		return NULL;
	if(key==p->data)
		return p;
	return rsearch(p->next,key);
}

struct Node* isearch(struct Node *p,int key)
{
	struct Node *q=NULL;
	//q=(struct Node *)malloc(sizeof(struct Node));
	while(p!=NULL)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=first;
			first=p;
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

void Insert(int pos,int x)
{
	struct Node *t,*p;
	if(pos==0)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		t->next=first;
		first=t;
	}
	else
	{
		p=first;
		for(int i=0;i<pos-1 && p!=NULL;i++)
			p=p->next;

			if(p!=NULL)
			{
				t=(struct Node*)malloc(sizeof(struct Node));
				t->data=x;
				t->next=p->next;
				p->next=t;
			}
			else
			{
				printf("Invalid position!\n");
			}
	}
}

void SortedInsert(struct Node *p,int x)
{
	struct Node *t,*q=NULL;

	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=x;
	t->next=NULL;
	if(first==NULL)
	{
		first=t;
	}
	else
	{
		while(p!=NULL && p->data<x)
		{
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next=first;
			first=t;
		}
		else
		{
			t->next=q->next;
			q->next=t;
		}
	}

}

int Delete(struct Node *p,int pos)
{
	struct Node *q=NULL;
	int x=-1,i;
	if(pos < 0 || pos> count(p))
		return -1;
	if(pos==0)
	{
		x=first->data;
		p=first;
		first=first->next;
		free(first);
	}
	else
	{
		p=first;
		for(i=0;i<pos-1 && p!=NULL;i++)
		{
			q=p;
			p=p->next;
		}
		if(p!=NULL)
		{
			q->next=p->next;
			x=p->data;
			free(p);
		}
	}
	return x;
}

int checkSorted(struct Node *p)
{
	int x=-32768;
	p=first;
	while(p!=NULL)
	{
		if(p->data<x)
			return false;
		x=p->data;
		p=p->next;
	}
	return true;
}

void Duplicate(struct Node *p)
{
	p=first;
	struct Node *q=first->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}

void reverse(struct Node *p)
{
    int *A, i = 0;
    int n = count(p);  // total number of nodes
    A = (int *)malloc(sizeof(int) * n);
    struct Node *q = p;

    // Store data in array
    while (q != NULL)
    {
        A[i++] = q->data;
        q = q->next;
    }

    // Copy back in reverse order
    q = p;
    i = n - 1;
    while (q != NULL)
    {
        q->data = A[i--];
        q = q->next;
    }

    free(A);  // Don't forget to free the allocated memory
}


void sreverse(struct Node *p)
{
	struct Node *q,*r;
	p=first;
	q=NULL;
	r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}

void recursivereverse(struct Node *q,struct Node *p)
{
	if(p!=NULL)
	{
		recursivereverse(p,p->next);
		p->next=q;
	}
	else
	{
		first=q;
	}

}

void Concat(struct Node *p,struct Node *q)
{
	third=p;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL) last->next = p;
    else last->next = q;
}

int isLoop(struct Node *f)
{
	struct Node *p,*q;
	p=q=f;
	do{
		p=p->next;
		q=q->next;
		q = q!=NULL?q->next:q;
		}while(p!=NULL && q!=NULL && p!=q);
	return p==q?true:false;
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {15, 25, 35, 45};

    create(A, 5);
    create2(B, 4);

    printf("The first linked list:\n");
    rdisplay(first);
    printf("\n");

    printf("The second linked list:\n");
    rdisplay(second);
    printf("\n");

    Merge(first, second);
    printf("The merged linked list is:\n");
    rdisplay(third);
    printf("\n");

    // For subsequent operations, assign third (merged list) to a working pointer
    first = third;

    int x;
    printf("Enter the element to be entered in the sorted list: ");
    scanf("%d", &x);

    SortedInsert(first, x);
    rdisplay(first);
    printf("\n");

    int pos, res;
    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &pos);

    res = Delete(first, pos);
    printf("The element deleted is: %d\n", res);
    rdisplay(first);
    printf("\n");

    int r;
    r = checkSorted(first);

    if (r == 0)
        printf("The list is not sorted!\n");
    else
        printf("The list is sorted!\n");

    Duplicate(first);
    printf("The list after removing duplicates is:\n");
    rdisplay(first);
    printf("\n");

    reverse(first);
    printf("The list after reversing:\n");
    rdisplay(first);
    printf("\n");

    // Check for loop AFTER using the list
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    if (t2 != NULL) t2->next = t1;

    int flag = isLoop(first);
    if (flag == 1)
        printf("The entered linked list has a loop!\n");
    else
        printf("The entered linked list is linear!\n");

    return 0;
}
