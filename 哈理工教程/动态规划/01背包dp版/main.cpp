#include <bits/stdc++.h>
#define N 105
using namespace std;
int n,W,dp[N][N],v[N],w[N];

int orisolve(int i,int j)  {
    if (i==n)   return dp[i][j]=0;
    else if (j<w[i]) return dp[i][j]=solve(i+1,j);
    else dp[i][j]=max(solve(i+1,j),solve(i+1,j-w[i])+v[i]);
}

int rec(int i,int j)    {
    if (dp[i][j]>=0)    return dp[i][j];
    int res;
    if (i==n)   res=0;
    else if (j<w[i])    res=rec(i+1,j);
    else res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    return dp[i][j]=res;
}
void solve()    {
    for (int i=n-1;i>=0;i--)    {
        for (int j=0;j<=W;j++)   {
            if (j<w[i])    dp[i][j]=dp[i+1][j];
            else dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[0][W]<<endl;
}
int main()  {
    cin>>n;
    for (int i=0;i<n;i++)   cin>>w[i];
    for (int i=0;i<n;i++) cin>>v[i];
    cin>>W;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W)<<endl;
    memset(dp,0,sizeof(dp));
    solve();
    return 0;
}
