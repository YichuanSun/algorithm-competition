#include <stdio.h>
#include <string.h>
#define N 25
void bigoutput(int a[N]);
int sum[N],sum0[N];
int main()
{
	int n,j=0;
	scanf("%d",&n);
	while (n--)
	{
		int a,b;
		long long cube;
		memset(sum,0,sizeof(sum));
		scanf("%d %d",&a,&b);
		for (int i=a;i<=b;i++)
		{
			int k=0;
			cube=(long long)i*i*i;
			memset(sum0,0,sizeof(sum));
			while (cube)	//新数的cube 
			{
				sum0[k++]=cube%10;
				cube/=10;
			}
			for (int j=0;j<N;j++)
			{
				sum[j]=sum[j]+sum0[j];
				if (sum[j]>9)
				{
					sum[j+1]+=sum[j]/10;
					sum[j]%=10;
				}
			}
		}
		printf("Case #%d: ",++j);
		bigoutput(sum);
		printf("\n");
	}
}

void bigoutput(int a[N])		//按高位在前，低位在后的正常顺序打印 
{
	int i;
	for (i=N-1;i>=0;i--)
		if (a[i])
			break;
	for (int j=i;j>=0;j--)
		printf("%d",a[j]);
}
