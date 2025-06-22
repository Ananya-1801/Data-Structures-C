//WAP in C to implement binary search in an array

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
	for(int i=0;i<arr.length;i++)
	{
		printf("%d ",arr.A[i]);
	}
}

int BinSearch(struct Array arr,int l,int h,int key)
{
	int mid=0;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
		{
			return mid;
		}
		else if(key<arr.A[mid])
		{
			h=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return -1;
}

int RBinarySearch(struct Array arr,int l,int h,int key)
{
	int mid;
	if(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
		{
			return mid;
		}
		else if(key<arr.A[mid])
		{
			return RBinarySearch(arr,l,mid-1,key);
		}
		else
		{
			return RBinarySearch(arr,mid+1,h,key);
		}
	}
	return -1;
}

int main()
{

int i,n;
int size;

struct Array arr;

printf("Enter the size of the array:");
scanf("%d",&arr.size);
arr.length=0;

arr.A=(int *)malloc(size*sizeof(int));

printf("Enter the number of elements in an array:");
scanf("%d",&n);

arr.length=n;

printf("---- Enter the number of elements -----\n");
for(int i=0;i<n;i++)
{
	printf("Enter the %d element:",i+1);
	scanf("%d",&arr.A[i]);
}
int key,res=0;

printf("Enter the element to be searched in the array:");
scanf("%d",&key);

int l,h;

h=arr.length-1;
l=0;

res=BinSearch(arr,l,h,key);

printf("The index found using Binary Search is:%d\n",res);

int res1=0;

res1=RBinarySearch(arr,l,h,key);

printf("The index found using Recursive Binary Search is:%d\n",res1);
return 0;

}


