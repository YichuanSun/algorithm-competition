#include <stdio.h>

int sqr(int n)
{
	int i,j=1;
	for (i=0;i<n;i++)
		j=j*2;
	return j;
}

int main()
{
	int n;
	while (scanf("%d",&n),n)
	{
		int i=0,y=0;
		while (y==0)
		{
			y=n%2;
			i++;
			n=n/2;
		}
		printf("%d\n",sqr(i-1));
	}
	return 0;
}
