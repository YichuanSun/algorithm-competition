#include <iostream>
#include <algorithm>
#define N 10005
#define INF 0x3f3f3f3f
using namespace std;
int dp[N],a[N];
int main()
{
    int n;
    scanf("%d",&n);
    int number=1;
    for (int i=0; i<n; i++)
        cin>>a[i];
    dp[0]=a[0];
    for (int i=1; i<n; i++)
    {
        int flag=-1,mmin=INF;
        for (int j=0; j<number; j++)
        {
            if (dp[j]>=a[i]&&dp[j]<mmin)
            {
                mmin=dp[j];
                flag=j;
            }
        }
        if (flag==-1)
        {
            dp[number]=a[i];
            number++;
        }
        else
            dp[flag]=a[i];
    }
    cout<<number<<endl;
    return 0;
}
