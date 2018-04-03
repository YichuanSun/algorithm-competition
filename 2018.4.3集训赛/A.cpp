#include <iostream>
#include <algorithm>
#define N 204
using namespace std;
int cmp(const void *a,const void *b)	{
	return -*(int*)a+*(int*)b;
}
int main()	{
	int n,a[N],sum=0;
	scanf("%d",&n);
	for (int i=0;i<2*n;i+=2)	scanf("%d%d",&a[i],&a[i+1]);
	qsort(a,2*n,sizeof(int),cmp);
	for (int i=0;i<2*n;i+=2)
		sum+=min(a[i],a[i+1]);
	printf("%d\n",sum);
	return 0;
}
