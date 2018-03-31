#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100001
int a[N]={0};

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int i,j,k,n,t,p;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		int flag=0;
		scanf("%d %d",&n,&k);
		for (j=0;j<n;j++)
			scanf("%d",&a[j]);
		qsort(a,N,sizeof(int),cmp);
		for (j=0;j<n-1;j++)
		{
			for (p=j+1;p<n;p++)
			{
				if (fabs(a[j]-a[p])<=k)
					flag++;
				else
					break;
			}
		}
		printf("%d\n",flag);
	}
}
