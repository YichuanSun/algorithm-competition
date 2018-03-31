#include <stdio.h>
int t=0;
int dfp(int n)
{
	if (n==1)
		return t;
	if (n!=1&&n%2)
	{
		t++;
		return dfp(3*n+1);
	}
	else if (n%2==0)
	{
		t++;
		return dfp(n/2);
	}
}

int main()
{
	int i,j,k,max=0,s;
	while (scanf("%d %d",&i,&j)!=EOF)
	{
		for (k=i;k<=j;k++)
		{
			if (k!=1)
				s=dfp(k);
			else if (k)
			t=0;
			if (s>max)
				max=s;
		}
		printf("%d %d %d\n",i,j,max);
		max=0;
	}
	return 0;
}
