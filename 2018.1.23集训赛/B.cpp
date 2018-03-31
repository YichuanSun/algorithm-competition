#include <stdio.h>
#define N 1000001
int a[N];
int main()
{
	int n,i,j;
	while (scanf("%d",&n),n)
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (i=0;i<n;i++)
		{
			for (j=0;j<i;j++)
			{
				if (a[i]==a[j]&&a[i]&&a[j])
				{
					a[i]=0;a[j]=0;
				}
			}
		}
		for (i=0;i<n;i++)
			if (a[i])
			{
			    printf("%d\n",a[i]);
			    break;
			}		
	}
	return 0;
}
