//WAP IN C TO USE HEAD RECURSION

#include <stdio.h>

void fun(int n)
{
        if(n>0)
        {
                fun(n-1);
		printf("%d\t",n);
        }
}

int main()
{
int x=3;
fun(x);
return 0;
}
