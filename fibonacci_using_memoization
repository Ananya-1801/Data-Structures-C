//WAP IN C TO COMPUTE THE FIBONACCI SEQUENCE USING MEMOIZATION TECHNIQUE IN RECURSION

#include <stdio.h>

int F[10];

int fib(int n)
{

	if(n<=1)
	{
		F[n]=n;
		return n;
	}
	else
	{
		if( F[n-2]== -1 )
		{
			F[n-2]=fib(n-2);
		}
		if( F[n-1]== -1 )
		{
			F[n-1]=fib(n-1);
		}
	
	return F[n-2]+F[n-1];
	}

}

int main()
{

int t;
int res=0;

printf("Enter the number of terms of the fibonacci sequence:");
scanf("%d",&t);


for(int i=0;i<t;i++)
        {
                F[i]=-1;
        }

res=fib(t);

printf("The fibonacci sequence is:%d\n",res);

return 0;

}
