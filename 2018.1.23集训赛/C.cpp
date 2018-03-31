#include <stdio.h>
#define N 401
void bigsum(int a[N],int b[N],int c[N]);
int main()
{
	int i,n,num[N][N];		//第一个数字是编号，第二个维度是数字的真实位 
	for (i=0;i<N;i++)
	{
		if (i==0||i==1||i==2)
			continue;
		else
			bigsum(num[i-2],num[i-1],num[i]);		//此处应为高精度加法 
	}
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&i);	
	}
}

void bigsum(int a[N],int b[N],int c[N])
{
	for (int i=N;i>=0;i--)
	{
		c[i+1]=a[i]+b[i]+c[i+1];
		if (c[i+1]>9)
		{
			c[i+1]%=10;
			c[i]++;
		}
	}
	printf("\n");
}
