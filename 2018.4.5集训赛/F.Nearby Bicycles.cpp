#include <iostream>
#include <algorithm>
#include <cmath>
#define N 1005		
using namespace std;
typedef struct poin{
	double x;
	double y;
}point;
double rad[N];
double db(double x)	{
	return x*x;
}
int main()	{
	int n,m;
	while (scanf("%d %d",&n,&m)==2&&n&&m)	{
		int cnt[N];
		point bic[N],peo[N];
		for (int i=0;i<m;i++)	cnt[i]=0;
		for (int i=0;i<n;i++)	{
			getchar();
			getchar();
			scanf("%lf,%lf",&bic[i].x,&bic[i].y);
			getchar();			
		}
		for (int i=0;i<m;i++)	{
			getchar();
			getchar();
			scanf("%lf,%lf",&peo[i].x,&peo[i].y);
			getchar();
		}
		for (int i=0;i<m;i++)	scanf("%lf",&rad[i]);
		for (int i=0;i<m;i++)	{
			for (int j=0;j<n;j++)	{
				double distance;
				double t1=bic[j].x-peo[i].x;
				double xx=db(t1);
				double t2=bic[j].y-peo[i].y;
				double yy=db(t2);
				distance=sqrt(xx+yy);
				if (distance<=rad[i])	cnt[i]++;
			}
		}
		for (int i=0;i<m;i++)	{
			if (i!=m-1)	printf("%d ",cnt[i]);
			else	printf("%d\n",cnt[i]);
		}
	}
	return 0;
}
