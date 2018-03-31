#include <stdio.h>
#include <stdlib.h>
#define N 1001

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
} 

int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int i,t;
		scanf("%d",&t);
		long long a[N]={0};
		for (i=0;i<t;i++)
			scanf("%lld",&a[i]);
		qsort(a,t,sizeof(long long int),cmp);
		for (i=0;i<t;i++)
		{
			if (i!=t-1)
				printf("%lld ",a[i]);
			else
				printf("%lld\n",a[i]);
		}	
	}
	return 0;
}
