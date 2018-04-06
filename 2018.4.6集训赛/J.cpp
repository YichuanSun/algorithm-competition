#include <iostream>
#include <algorithm>
#define N 10050
using namespace std;
int a[2][N];
int main()	{
	int n;
	scanf("%d",&n);
	while (n--)	{
		int m,cnt0=0,cnt1=0,cnt2=0;
		scanf("%d",&m);
		for (int i=0;i<m;i++)	scanf("%d",&a[0][i]);
		for (int i=0;i<m;i++)	scanf("%d",&a[1][i]);
		for (int i=0;i<m;i++)	{
			a[0][i]%=3;
			a[1][i]%=3;
		}
		for (int i=0;i<m;i++)	{
			switch(a[0][i])	{
				case 0:	cnt0++;break;
				case 1:	cnt1++;break;
				case 2:	cnt2++;break;
				default:	break;
			}
			switch(a[1][i])	{
				case 0:	cnt0++;break;
				case 1:	cnt1++;break;
				case 2:	cnt2++;break;
				default:	break;
			}
		}
		if (cnt0>cnt1+cnt2)	printf("NO\n");
		else if (cnt0==cnt1+cnt2)	printf("YES\n");
		else	{
			if (cnt0>=3)	printf("YES\n");
			else if (cnt0==2)	{	
				if	((cnt1&1)&&(cnt2&1)) 	printf("YES\n");
				else if (((!cnt1)||(!cnt2))&&(cnt1+cnt2))	printf("YES\n");
				else printf("NO\n");
			}
			else	{
				if ((cnt1==0&&cnt2)||(cnt2==0&&cnt1))
					printf("YES\n");
				else	printf("NO\n");
			}
		}
	}
	return 0;
}
