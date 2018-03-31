#include <stdio.h>
#include <string.h>
#define N 1003
int b[N];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int a[N],i,j;
		for (i=0;;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]]++;
			if (getchar()=='\n')
				break;
		}
		for (j=0;i<=i;j++)
		{
			if (b[a[j]]==2)
				break;
		}
		printf("%d\n",a[j]);
		memset(b,0,sizeof(b));
	}
} 
