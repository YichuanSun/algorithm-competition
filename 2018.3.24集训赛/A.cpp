#include <iostream>
#include <cstdio>
#define N 40
using namespace std;
int a[N][N];
int main()	{
	int n,k,k_1i=0,k_1j;
	scanf("%d",&n);
	int dn=n*n;
	k_1j=n/2;
	a[k_1i][k_1j]=1;
	for (k=2;k<=dn;k++)	{
		if (k_1i==0&&k_1j!=n-1)	{
			a[n-1][k_1j+1]=k;
			k_1i=n-1;
			k_1j=k_1j+1;
		}
		else if (k_1j==n-1&&k_1i!=0)	{
			a[k_1i-1][0]=k;
			k_1i=k_1i-1;
			k_1j=0;
		}
		else if (k_1i==0&&k_1j==n-1)	{
			a[k_1i+1][k_1j]=k;
			k_1i=k_1i+1;
		}
		else if (k_1i!=0&&k_1j!=n-1)	{
			if (a[k_1i-1][k_1j+1]==0)	{
				a[k_1i-1][k_1j+1]=k;
				k_1i=k_1i-1;
				k_1j=k_1j+1;
			}
			else	{
				a[k_1i+1][k_1j]=k;
				k_1i=k_1i+1;
			}
		}
	}
	for (int i=0;i<n;i++)	{
		for (int j=0;j<n;j++)	{
			printf("%d",a[i][j]);
			if (j!=n-1)	printf(" ");
			else	printf("\n");
		}
	}
	return 0;
}
