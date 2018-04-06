#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<memory.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):(-(a)))
#define lowbit(a) (a&(-a))
#define sqr(a) ((a)*(a))
#define swap(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
#define eps 1e-8
#define J 10000000
#define MAX 0x7f7f7f7f
#define PI 3.1415926535897
#define N 1007
#define M 10007
using namespace std;
typedef long long LL;
int cas,cass;
int n,m,lll,ans;
LL k[M];
char ch[N];
void gjdprint(LL a[])
{
	int i;
	printf("%lld",a[a[0]]);
	for(i=a[0]-1;i;i--)
		printf("%07lld",a[i]);
	puts("");
}
int gjdcompare(LL a[],LL b[])//-1:a=b  0:a<b  1:a>b
{
	int i;
	if(a[0]!=b[0])return a[0]>b[0];
	for(i=a[0];i;i--)
		if(a[i]!=b[i])return a[i]>b[i];
	return -1;
}
void gjdcheng(LL a[],LL b[],LL c[])
{
	LL t[M]={0};
	int i,j;
	t[0]=a[0]+b[0];
	for(i=1;i<=a[0];i++)
		for(j=1;j<=b[0];j++)
			t[i+j-1]+=a[i]*b[j];
	for(i=1;i<=t[0];i++)
		t[i+1]+=t[i]/J,t[i]%=J;
	while(t[t[0]+1])t[0]++;
	while(!t[t[0]] && t[0]>1)t[0]--;
	memcpy(c,t,sizeof(t));
}
void gjdquickpow(LL a[],LL x)
{
	LL t[M]={1,2,0};
	a[0]=a[1]=1;
	while(x)
	{
		if(x&1)
		{
			gjdcheng(a,t,a);
		}
		gjdcheng(t,t,t);
		x>>=1;
	}
}
void gjdchange(char s[],LL a[])
{
	int i,j,l;
	l=strlen(s);
	for(i=l,a[0]=1;i>6;i-=7,a[0]++)
	{
		for(j=0;j<7;j++)
			a[a[0]]=a[a[0]]*10+s[i-7+j]-'0';
	}
	for(j=0;j<i;j++)
		a[a[0]]=a[a[0]]*10+s[j]-'0';
}
void gjdjia(LL a[],LL b[],LL c[])
{
	int i;
	LL t[M]={0};
	t[0]=max(a[0],b[0]);
	for(i=1;i<=t[0];i++)
		t[i]=a[i]+b[i];
	for(i=1;i<=t[0];i++)
		t[i+1]+=t[i]/J,t[i]%=J;
	while(t[t[0]+1])t[0]++;
	while(!t[t[0]] && t[0]>1)t[0]--;
	memcpy(c,t,sizeof(t));
}
void gjdjian(LL a[],LL b[],LL c[])
{
	int i;
	LL t[M]={0};
	t[0]=a[0];
	for(i=1;i<=t[0];i++)
		t[i]=a[i]-b[i];
	for(i=1;i<t[0];i++)
		if(t[i]<0)t[i+1]--,t[i]+=J;
	while(!t[t[0]] && t[0]>1)t[0]--;
	memcpy(c,t,sizeof(t));
}
void gjdchu2(LL a[])
{
	int i;
	for(i=a[0];i>1;i--)
	{
		if(a[i]&1)a[i-1]+=J;
		a[i]>>=1;
	}
	a[1]>>=1;
	while(!a[a[0]] && a[0]>1)a[0]--;
}
void getsum(LL t[],LL mid,LL tt[])
{
	gjdquickpow(t,mid-1);
	tt[1]=n-3;
	gjdcheng(t,tt,t);
	tt[1]=mid*3;
	gjdjia(t,tt,t);
	tt[1]=n;
	gjdjian(t,tt,t);
}
void work()
{
	int i,j,l,r,mid;
	LL t[M]={0},tt[M]={1,0};
	l=1;r=4000;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		getsum(t,mid,tt);
		j=gjdcompare(k,t);
		if(j==-1)
		{
			gjdquickpow(t,mid-2);
			tt[1]=n-1;
			gjdcheng(t,tt,t);
			tt[1]=1;
			gjdjia(t,tt,t);
			gjdprint(t);
			return;
		}
		if(j)l=mid;
		else r=mid-1;
	}
	getsum(t,r,tt);
	gjdjian(k,t,k);
	gjdquickpow(t,r);
	tt[1]=2;
	gjdjian(t,tt,t);
	gjdjia(k,t,t);
	gjdprint(t);
}
int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		memset(k,0,sizeof(k));
		if(n<4)
		{
			scanf("%d",&m);
			if(n==1)
			{
				if(m==1)puts("1");
				else puts("-1");
			}
			else if(n==2)
			{
				if(m==1)puts("1");
				else if(m==2)puts("2");
				else if(m==3)puts("3");
				else puts("-1");
			}
			else if(n==3)
			{
				gjdquickpow(k,(m+2)/3);
				if(m%3==1)k[1]--;
				else if(m%3==0)k[1]++;
				gjdprint(k);
			}
			continue;
		}
		scanf("%s",ch);
		gjdchange(ch,k);
		if(k[0]==1 && k[1]<=n)
		{
			gjdprint(k);
			continue;
		}
		work();
	}
	return 0;
}