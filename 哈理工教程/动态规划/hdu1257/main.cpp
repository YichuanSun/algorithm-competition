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
int dp[10010];//��¼�Ѿ����������ϵͳ�ܴ�����߶�
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
		dp[0]=a[0];//����ǰ��
		for(int i=1;i<n;i++)
		{
			int flag=-1;//�����ʹ�ò�������ܹ��ҵ�֮ǰ�Ѿ����������ϵͳ���������ĵ���������Ϊ���õ��Ǹ�����ϵͳ�ĽǱ�
			int MIN=INF;//��֮ǰ�������Ĳ���ϵͳ���������ĵ���
			for(int j=0;j<num;j++)
			{
				if(dp[j]>=a[i]&&dp[j]<MIN)//��֮ǰ�������Ĳ���ϵͳ���������ĵ��� ;ע���Ǹ����ڵ��ڣ�����˵����������ô���Ե���
				{
					MIN=dp[j];
					flag=j;
				}
			}
			if(flag==-1)//֮ǰ������ϵͳ�Ƕ����������ĵ�������ô���²���һ������ϵͳ�����µ�ǰ�ĵ���
			{
				dp[num]=a[i];//�²���Ĵ����˵�ǰ�ĵ�������ô�²���ĸ߶Ƚ�Ϊ��a[i]
				num++;//����+1
			}
			else
			{
				dp[flag]=a[i];//�ܴ������Ļ��������������Ǹ�����ϵͳ�����أ�������dp[flag]
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
