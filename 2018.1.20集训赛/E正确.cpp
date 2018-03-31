#include <stdio.h>
#include <memory.h>
#define N 1000000
int flag[N]={0};
int main()
{
	int i,n,point,x,z;
	while (scanf("%d",&n)!=EOF)
	{
		point=(n+1)/2;
		for (i=0;i<n;i++)
		{
			scanf("%d",&x);
			flag[x]++;
			if (flag[x]>=point)
				z=x;
		}
		printf("%d\n",z);
		memset(flag,0,sizeof(flag));
	}
	return 0;
}
