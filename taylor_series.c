//WAP IN C TO COMPUTE THE TAYLOR SERIES USING ITERATIVE FUNCTION

#include <stdio.h>

double e(double x,double n)
{
	double s=1;
	double p=1,f=1;
	for(;n>0;n--)
	{
	   s=1+(x/n)*s;
	}

	return s;
}

int main()
{

double a,b;

printf("Enter the number and the terms in the Taylor series:");
scanf("%lf%lf",&a,&b);

double res=0;

res=e(a,b);

printf("The Taylor series expansion is:%lf\n",res);

return 0;

}
