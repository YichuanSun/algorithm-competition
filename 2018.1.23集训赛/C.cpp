#include <stdio.h>
#define N 401
void bigsum(int a[N],int b[N],int c[N]);
int main()
{
	int i,n,num[N][N];		//��һ�������Ǳ�ţ��ڶ���ά�������ֵ���ʵλ 
	for (i=0;i<N;i++)
	{
		if (i==0||i==1||i==2)
			continue;
		else
			bigsum(num[i-2],num[i-1],num[i]);		//�˴�ӦΪ�߾��ȼӷ� 
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
