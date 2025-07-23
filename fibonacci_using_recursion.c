//WAP IN C to compute the fibonacci series using iterative and recursive functions

#include <stdio.h>

int fib(int n)
{
	if(n<=1)
	{
		return n;
	}
	else
	{
		return fib(n-2)+fib(n-1);
	}
}

int main()
{

int t;
printf("Enter the number of terms:");
scanf("%d",&t);

int res=0;

res=fib(t);

printf("The fibonacci series expansion for %d terms is:%d\n",t,res);

return 0;

}
