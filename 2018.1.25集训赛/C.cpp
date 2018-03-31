#include <stdio.h>
#include <math.h>
#define N 1000
int ar[N][N];
int main()
{
	int i,j,n,m,q,a,b,c,d;
	scanf("%d %d %d",&n,&m,&q);
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			scanf("%d",&ar[i][j]);
	while (q--)
	{
		int sum=0;
		double al,bl,avg;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		for (i=a-1;i<=c-1;i++)
			for (j=b-1;j<=d-1;j++)
				sum=sum+ar[i][j];
		al=1+fabs(a-c);
		bl=1+fabs(b-d);
		avg=1.0*sum/al/bl;
		printf("%.2lf\n",avg);
	}
	return 0;
}
