#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define N 1000
#define M 1000000
int a[N],b[N],c[M];

void exc(int m,int a[N]);
void mul(int a[N],int b[N],int c[M]);

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int i=1;
		b[0]=1;
		for (i=2;i<=n;i++)
		{
			exc(i,a);
			mul(a,b,c);
			for (i=0;i<N;i++)
				b[i]=c[i];
		}
		for (i=0;i<N;i++)
			if (b[i]!=0)
				break;
		printf("%d\n",b[i]);
		memset(b,0,sizeof(b));
	}
	return 0;
}

void exc(int m,int a[N])
{
	int i=0;
	while (m!=0)
	{
		a[i++]=m%10;
		m=m/10;
	}
}

void mul(int a[N],int b[N],int c[N])
{
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			c[i+j]=a[i]*b[j];
		}
	}
	while (0);
	for (i=0;i<M;i++)
	{
		if (c[i]>9)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
}
