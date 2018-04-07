#include <iostream>
#include <algorithm>
#define N 105
using namespace std;
int a[N][N];
int main()	{
	int n;
	scanf("%d",&n);
	while (n--)	{
		int n,m,A,B,temp,cnt=0;
		scanf("%d %d %d %d",&n,&m,&A,&B);
		if (A>B)	{
			printf("No Solution\n");
			continue;
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)	{
				scanf("%d",&temp);
				if (temp<A||temp>B)	cnt++;
			}
		printf("%d\n",cnt);
	}
	return 0;
}
