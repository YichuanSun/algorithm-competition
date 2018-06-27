#include <bits/stdc++.h>
#define MAX_N 10005
using namespace std;

int n,W;
int w[MAX_N],v[MAX_N];
int rec(int i,int j)    {       //i表示第i号物品，j表示剩余容量
    int res;
    if (i==n)   res=0;  //已经没有剩余物品了
    else if (j<w[i])    res=rec(i+1,j); //无法挑选这个物品
    else    res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);//挑选和不挑选
    return res;                                      //都尝试一下
}
int main()  {
    cin>>n;
    for (int i=0;i<n;i++)   cin>>w[i];
    for (int i=0;i<n;i++)   cin>>v[i];
    cin>>W;
    cout<<rec(0,W)<<endl;
    return 0;
}
