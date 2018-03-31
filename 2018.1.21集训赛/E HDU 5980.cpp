#include <stdio.h>

int main()
{
	int n,p=0;
	long long i;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&i);
		while (i!=0)
		{
			if (i%256==97)
				p++;
			i>>=8;
		}
	}
	printf("%d\n",p);
	return 0;
}
