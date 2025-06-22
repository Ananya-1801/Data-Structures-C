//WAP IN C TO DEMONSTRATE ARRAY ADT
/* add functions - add/append(x) , insert(index,x), delete(index) , search(x),get&set,reverse() */

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
	for(i=0;i<arr.length;i++)
	{
		printf("%d ",arr.A[i]);
	}
}

void Append(struct Array *arr,int x)
{
	if(arr->length<arr->size)
	{
		arr->A[arr->length++]=x;
	}
}

void insert(struct Array *arr,int index,int y)
{
	if(index >=0 && index<=arr->length)
	{
		for(int i=arr->length;i>index;i--)
		{
			arr->A[i]=arr->A[i-1];
		}
		arr->A[index]=y;
		arr->length++;
	}
}

int Delete(struct Array *arr,int index)
{
	int x=0;
	if(index>=0 && index<=arr->length)
	{
		int x=arr->A[index];
		for(int i=index;i<arr->length-1;i++)
		{
			arr->A[i]=arr->A[i+1];
		}
		arr->length--;
		return x;
	}
	return 0;
}

int main()
{

struct Array arr;
int n,i;

printf("Enter the size of an array:");
scanf("%d",&arr.size);

arr.A=(int *)malloc(arr.size*sizeof(int));
arr.length=0;

printf("Enter the number of elements:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
	printf("Enter the %d element: ",i+1);
	scanf("%d",&arr.A[i]);
}

arr.length=n;

//Display(arr);

int index,x,a,in;

printf("Enter the element to be appended to the array adt:");
scanf("%d",&a);

Append(&arr,a);

printf("Enter the index and the element to be inserted at index:");
scanf("%d%d",&index,&x);

insert(&arr,index,x);

printf("Enter the index of the element to be deleted from the array:");
scanf("%d",&in);
int pop=0;

pop=Delete(&arr,in);

Display(arr);

printf("\nThe deleted element is:%d ",pop);

return 0;

}
