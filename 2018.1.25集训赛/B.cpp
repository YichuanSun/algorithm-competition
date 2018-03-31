#include <stdio.h>
#include <stdlib.h>
#define N 1000
int a[N];

int cmpltoh(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int cmphtol(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	while (n--)
	{
		int l,ac;
		scanf("%d %d",&l,&ac);
		for (i=0;i<ac;i++)
			scanf("%d",&a[i]);
		qsort(a,ac,sizeof(int),cmphtol);
		printf("%d ",l-a[1]);
		qsort(a,ac,sizeof(int),cmpltoh);
		printf("%d\n",l-a[0]);
	}
	return 0;
}
