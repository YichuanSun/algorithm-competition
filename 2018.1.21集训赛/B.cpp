#include <stdio.h>
#include <stdlib.h>
#define N 1000

int cmpltoh(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int cmphtol(const void *a,const void *b)
{
	return -*(int*)a+*(int*)b;
}

int main()
{
	int i,j,k,t;
	scanf("%d",&t);
	while (t--)
	{
		int s[N]={0},d[N]={0},ss=0,sd=0,n,m;
		scanf("%d %d",&n,&m);
		for (i=0;i<n;i++)
			scanf("%d",&s[i]);
		for (i=0;i<n;i++)
			scanf("%d",&d[i]);
		qsort(s,n,sizeof(int),cmpltoh);
		qsort(d,n,sizeof(int),cmphtol);
		for (i=0;i<m;i++)
		{
			ss=ss+s[i];
			sd=sd+d[i];
		}
		if (ss>sd)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 
