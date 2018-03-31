#include <stdio.h>
#include <memory.h>
#define N 1000000
int flag[N]={0};
int main()
{
	int i,n,point,x;
	while (scanf("%d",&n)!=EOF)
	{
		point=(n+1)/2;
		for (i=0;i<n;i++)
		{
			scanf("%d",&x);
			flag[x]++;
		}
		if (flag[x]>=point)
			printf("%d\n",x);
		/*
		for (i=0;i<n;i++)
		{
			if (flag[i]==0)
				continue;
			else if (flag[i]>=point)
			{
				printf("%d\n",i);
				break;
			}
		}
		*/
		memset(flag,0,sizeof(flag));
	}
	return 0;
}

//时间超限。这是错误用例，我不知道为什么错了。 
