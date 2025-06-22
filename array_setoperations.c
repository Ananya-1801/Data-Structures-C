//WAP IN C TO PERFORM SET OPERATIONS ON AN ARRAY ADT NAMELY UNION,INTERSECTION AND DIFFERENCE OPERATIONS

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

struct Array *Merge(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	i=j=k=0;
	struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //dynamically allocate memory for third array
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
		{
			arr3->A[k++]=arr1->A[i++];
		}
		else
		{
			arr3->A[k++]=arr2->A[j++];
		}
	}
	for(;i<arr1->length;i++)
	{
		arr3->A[k++]=arr1->A[i];
	}
	for(;j<arr2->length;j++)
	{
		arr3->A[k++]=arr2->A[j];
	}
	arr3->length=k;
	arr3->size=arr1->size+arr2->size;
	return arr3;
}

struct Array *Union(struct Array *arr1,struct Array *arr2)
{
        int i,j,k;
        i=j=k=0;
        struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //dynamically allocate memory for third array
	arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
        while(i<arr1->length && j<arr2->length)
        {
                if(arr1->A[i]<arr2->A[j])
                {
                        arr3->A[k++]=arr1->A[i++];
                }
                else if(arr1->A[i]>arr2->A[j])
                {
                        arr3->A[k++]=arr2->A[j++];
                }
		else
		{
			arr3->A[k++]=arr1->A[i++];
			j++;
		}
        }
        for(;i<arr1->length;i++)
        {
                arr3->A[k++]=arr1->A[i];
        }
        for(;j<arr2->length;j++)
        {
                arr3->A[k++]=arr2->A[j];
        }
        arr3->length=k;
        arr3->size=arr1->size+arr2->size;
        return arr3;
}

struct Array *Intersection(struct Array *arr1,struct Array *arr2)
{
        int i,j,k;
        i=j=k=0;
        struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //dynamically allocate memory for third array
	arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
        while(i<arr1->length && j<arr2->length)
        {
                if(arr1->A[i]<arr2->A[j])
                {
                        i++;
                }
                else if(arr1->A[i]>arr2->A[j])
                {
                        j++;
                }
		else //if both the elements in each of the array are equal
		{
			arr3->A[k++]=arr1->A[i++];
			j++;
		}
        }
        /* there is no requirement of copying left out elements since
		intersection requires extracting only common elements*/
        arr3->length=k;
        arr3->size=arr1->size+arr2->size;
        return arr3;
}

struct Array *Difference(struct Array *arr1,struct Array *arr2)
{
        int i,j,k;
        i=j=k=0;
        struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //dynamically allocate memory for third array
	arr3->A = (int *)malloc((arr1->length + arr2->length) * sizeof(int));
        while(i<arr1->length && j<arr2->length)
        {
                if(arr1->A[i]<arr2->A[j])
                {
                        arr3->A[k++]=arr1->A[i++];
                }
                else if(arr1->A[i]>arr2->A[j])
                {
                        j++;
                }
		else
		{
			i++;
			j++;
		}
        }
        for(;i<arr1->length;i++)
        {
                arr3->A[k++]=arr1->A[i];
        }
        arr3->length=k;
        arr3->size=arr1->size+arr2->size;
        return arr3;
}

int main()
{

struct Array arr1;
struct Array arr2;

int n1,n2,i;

arr1.length=0;
arr2.length=0;

printf("Enter the size of the first array:");
scanf("%d",&arr1.size);

arr1.A=(int *)malloc(arr1.size*sizeof(int));

printf("Enter the number of elements of the first array:");
scanf("%d",&n1);

printf("----- Enter the elements -----\n");
for(i=0;i<n1;i++)
{
	printf("Enter the %d element:",i+1);
	scanf("%d",&arr1.A[i]);
}
arr1.length=n1;


printf("Enter the size of the second array:");
scanf("%d",&arr2.size);

arr2.A=(int *)malloc(arr2.size*sizeof(int));

printf("Enter the number of elements of the second array:");
scanf("%d",&n2);

printf("----- Enter the elements -----\n");
for(i=0;i<n2;i++)
{
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr2.A[i]);
}
arr2.length=n2;

struct Array *arr3; //to store the structure pointer returned by function

//arr3=Union(&arr1,&arr2);
//arr3=Intersection(&arr1,&arr2);
arr3=Difference(&arr1,&arr2);
Display(*arr3);

printf("\n");

free(arr1.A); //deallocation of memory (DONT FORGET)
free(arr2.A); //deallocate using free(*pointer) arr - is name of structure !! so arr.A (since A is pointer)
free(arr3->A);

return 0;
}
