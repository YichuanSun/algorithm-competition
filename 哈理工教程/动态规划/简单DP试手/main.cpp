#include <bits/stdc++.h>
#define N 1005
using namespace std;
int n,W,v[N],w[N],dp[N][N];
void solve()    {
    for (int i=0;i<n;i++)   {
        for (int j=0;j<=W;j++)   {
            if (j<w[i]) dp[i+1][j]=dp[i][j];
            else    dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }
}
int main()  {
    cin>>n;
    for (int i=0;i<n;i++)   cin>>w[i];
    for (int i=0;i<n;i++)   cin>>v[i];
    cin>>W;
    solve();
    for (int i=0;i<n;i++)   {
        for (int j=0;j<=W;j++)
            cout<<'\t'<<dp[i][j];
        cout<<endl;
    }
    cout<<dp[n-1][W]<<endl;
    return 0;
}
/*
4
2 1 3 2
3 2 4 2
5
*/
