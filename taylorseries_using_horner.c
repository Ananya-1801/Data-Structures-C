//WAP IN C TO COMPUTE THE TAYLOR SERIES USING HORNER'S RULE

#include <stdio.h>

double e(double x,double n)
{
	static double s=1;

	if(n==0)
	{
		return s;
	}
	else
	{
		s = 1 + (x/n)*s;
		return e(x,n-1);
	}
}

int main()
{

double a,b;

printf("Enter the number and terms in Taylor series:");
scanf("%lf%lf",&a,&b);

double res=0;

res=e(a,b);

printf("The Taylor series expansion is:%lf\n",res);

return 0;

}
