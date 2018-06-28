//*******LCS

#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
int dp[1000][1000];
int len1,len2;
int main()
{
    while(cin>>s1>>s2)
    {
        memset(dp,0,sizeof(dp));
        len1=s1.length();
        len2=s2.length();
        for(int i=0; i<len1; i++)
            for(int j=0; j<len2; j++)
            {
                if(s1[i]==s2[j])    dp[i+1][j+1]=dp[i][j]+1;
                else    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
