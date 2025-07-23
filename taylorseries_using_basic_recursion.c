//WAP in C to calculate the taylor series of a number using basic recursion

#include <stdio.h>

/* makes use of sum, factorial and power functions wherein the sum and factorial value are added at return time */

double e(int x,int n)
{
	static double p=1,f=1;
	double r;
	if(n==0)
	{
		return 1;
	}
	else
	{
		r=e(x,n-1);
		p=p*x;
		f=f*n;
		return r+(p/f);
	}
}

int main()
{

double num;

//printf("Enter the number of terms:");
//scanf("%d",&num);

double res=0;

res=e(1,10);

printf("The taylor series is: %lf\n",res);

return 0;

}
