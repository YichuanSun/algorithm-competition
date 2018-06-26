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
