#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,n,i;
	scanf("%d",&n);
	while (n--)
	{
		int sum=0;
		scanf("%d",&a);
		b=(int)sqrt(a);
		for (i=2;i<=b;i++)
		{
			if (a%i==0)
			{
				if (a/i!=i)
					sum=sum+i+a/i;
				else
					sum=sum+i;
			}
				
		}
		printf("%d\n",sum+1);
	}
	return 0;
}
