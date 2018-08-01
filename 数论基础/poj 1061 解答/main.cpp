#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define ll long long int
using namespace std;
long long exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return r;
}
int main()
{
    ll x,y,m,n,L;
    ll a,b,c,gcd;
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L)!=EOF)
    {
        a=m-n;
        b=L;
        c=y-x;
        if(a<0)
        {
            a=-a;
            c=-c;
        }
        gcd=exgcd(a,b,x,y);
        if(c%gcd!=0)
            printf("Impossible");
        else
        {
            x=x*c/gcd;
            int t=b/gcd;
            if(x>=0)
                x=x%t;
            else
                x=x%t+t;
            printf("%lld\n",x);
        }
    }
    return 0;
}
