#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 103
using namespace std;
int cmp(const void *a,const void *b)	{
	return *(int*)a-*(int*)b;
}
int main()	{
	int i,j,k,n,a[N],b[N],flag=0;
	scanf("%d",&n);
	memset(b,0,sizeof(b));
	for (int p=0;p<n;p++)
		scanf("%d",&a[p]);
	qsort(a,n,sizeof(int),cmp);
	for (i=0;i<n-2;i++)
		for (j=i+1;j<n-1;j++)
			for (k=j+1;k<n;k++)
				if (a[i]+a[j]==a[k]&&b[k]==0)	{
					flag++;
					b[k]=1;
					break;
				}
	printf("%d\n",flag);
	return 0;
}
