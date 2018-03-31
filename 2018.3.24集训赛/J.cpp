#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100001
using namespace std;
struct s	{
	int d;
	int wake;
}street[N];
int cmp(const void *a,const void *b)	{
	return (*(s*)a).d>(*(s*)b).d?1:-1;
}
int main()	{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&street[i].d);
	for (int i=0;i<n;i++)
		scanf("%d",&street[i].wake);
	qsort(street,n,sizeof(street[0]),cmp);
	int roadwake=2*n;
	for (int i=n-1;i>=0;i--)	{
		int sum=0;
		for (int j=i;j<n;j++)	{
			sum+=street[j].wake;
		}
		int all=roadwake+sum;
		printf("%d\n",all);
	}
	return 0;
}
