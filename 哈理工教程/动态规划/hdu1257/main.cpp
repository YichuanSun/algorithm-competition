/*
#include <iostream>
#include <algorithm>
#include <stdbool.h>
#define N 100005
using namespace std;
int a[N],dp[N];
bool spot[N];
int main()
{
    int n,sum=0;
    cin>>n;
    for (int c=0;c<n;c++)  cin>>a[c];
    for (int i=0;i<n;i++)   {
        for (int j=0;j<i;j++)   {
            if (a[j]<a[i])  {
                dp[i]=max(dp[j]+1,dp[i]);
                spot[j]=true;
            }
        }
    }
    for (int i=0;i<n;i++)   sum+=spot[i];
    cout<<sum<<endl;
    return 0;
}
*/
#include <cstdio>
#define INF 0x3f3f3f3f
int a[10010];
int dp[10010];//记录已经部署的拦截系统能打的最大高度
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int num=1;
		dp[0]=a[0];//设置前键
		for(int i=1;i<n;i++)
		{
			int flag=-1;//当标记使用并且如果能够找到之前已经部署的拦截系统来打新来的导弹，就作为所用的那个拦截系统的角标
			int MIN=INF;//找之前最垃圾的部署系统来打新来的导弹
			for(int j=0;j<num;j++)
			{
				if(dp[j]>=a[i]&&dp[j]<MIN)//找之前最垃圾的部署系统来打新来的导弹 ;注意那个大于等于，题中说不超过，那么可以等于
				{
					MIN=dp[j];
					flag=j;
				}
			}
			if(flag==-1)//之前的拦截系统们都打不下新来的导弹，那么就新部署一个拦截系统来打下当前的导弹
			{
				dp[num]=a[i];//新部署的打下了当前的导弹，那么新部署的高度降为了a[i]
				num++;//数量+1
			}
			else
			{
				dp[flag]=a[i];//能打下来的话就用最垃圾的那个防御系统来拦截，更新了dp[flag]
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
