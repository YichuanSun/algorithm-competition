#include <stdio.h>
#define N 35660
int a[N],b[N],c[N];

int mul(int n)
{
	int i,d=1;
	for (i=0;i<n;i++)
		d=d*10;
	return d;
}

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int n0=n,f=0;
		while (n0/=10)		//f是位数 
			f++;
		for (i=1;i<=n;i++)
		{
			for (j=i;j<f;j++)
			{
				a[j]=n%mul(f-j-1);
			}
		}
		
	}
}

void bigmulti(int a[N],int b[N],int e[N*N])		//高精度乘法，原理还未弄懂 
{
	int i,j,la,lb;
	for (la=N;a[la]==0;la--);
	for (lb=N;a[lb]==0;lb--);
	for (i=0;i<=la;i++)
		for (j=0;j<=lb;j++)
			e[i+j]+=a[i]*b[j];
	for (i=0;i<la+lb;i++)
		if (e[i]>9)
		{
			e[i+1]+=e[i]/10;
			e[i]%=10; 
		} 
}
