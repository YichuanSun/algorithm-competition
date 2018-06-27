#include <bits/stdc++.h>
#define N 1000
using namespace std;
int dp[N][N];
string a1,a2;
int main()  {
    int n;
    cin>>a1>>a2;
    int len1=a1.length();
    int len2=a2.length();
    for (int i=1;i<=len1;i++)    {
        for (int j=1;j<=len2;j++)    {
            if (a1[i]==a2[j])   dp[i][j]=dp[i-1][j-1]+1;
            else    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}
