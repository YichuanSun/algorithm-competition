#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f
int dp[10010],a[10010];
int main()  {
    int n;
    while (cin>>n&&n)   {
        for (int i=0;i<n;i++)   {
            cin>>a[i];
            dp[i]=INF;
        }
        for (int i=0;i<n;i++)
            *lower_bound(dp,dp+n,a[i])=a[i];
        cout<<lower_bound(dp,dp+n,INF)-dp<<endl;
    }
    return 0;
}
