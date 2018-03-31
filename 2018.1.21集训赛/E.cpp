#include <stdio.h>
int main()
{
	int i,j=0,n;
	scanf("%d",&n);
	while (scanf("%d",&i),n--)
	{
		while (i)
		{
			if (i%256==97)
				j++;
			i=i/256;
		}
		if (n==0)
			break;
	}
	printf("%d\n",j);
	return 0;
}
