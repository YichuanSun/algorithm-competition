#include <iostream>
#include <algorithm>
#define N 105
using namespace std;
int findmax(int a[],int n)	{
	int max=-1,k=0,i;
	for (i=0;i<n;i++)
		if (a[i]>max)	{
		k=i;max=a[i];}
	return k;
}
int a[N];
int main()	{
	int n,suma=0,sumb=0,cnt=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)	
		scanf("%d",&a[i]);
	while (cnt<n)	{
		suma+=a[findmax(a,n)];
		a[findmax(a,n)]=0;
		sumb+=a[findmax(a,n)];
		a[findmax(a,n)]=0;
		cnt++;
	}
	printf("%d %d\n",suma,sumb);
	return 0;
}
