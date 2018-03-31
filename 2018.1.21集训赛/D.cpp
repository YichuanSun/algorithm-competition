#include <stdio.h>

int main()
{
	int a,b,c,q;
	double delta;
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if (a==0)
		{
			if (b==0)
			{
				if (c==0)
					printf("INF\n");
				else
					printf("0\n");
			}
			else
				printf("1\n");
		}
		else
		{
			delta=1.0*b*b-4.0*a*c;
			if (delta>0)
				printf("2\n");
			else if (delta==0)
				printf("1\n");
			else if (delta<0)
				printf("0\n");
		}	
	}
	return 0;
}
