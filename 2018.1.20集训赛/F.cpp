#include <stdio.h>
#include <stdlib.h>

int main()
{
	double a,b,c;
	while (scanf("%lf %lf",&a,&b)!=EOF)
	{
		c=a+b;
		printf("%f\n",c);
	}
	return 0;
}
