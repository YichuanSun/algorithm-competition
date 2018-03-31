#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 105
using namespace std;

int main()	{
	int n,a[N],flag=0;
	scanf("%d",&n);
	for (int i=0;i<=n;i++)	scanf("%d",&a[i]);
	for (int i=0;i<=n;i++)	{
		if (a[i]>0&&flag)	printf("+");
		if (a[i]<0)	printf("-");
		if (a[i]){
			if (abs(a[i])!=1&&i!=n)	{
				if (n-i!=1)
					printf("%dx^%d",abs(a[i]),n-i);
				else if (n-i==1)
					printf("%dx",abs(a[i]));
				flag=1;
			}
			else if (abs(a[i])==1&&i!=n)	{
				if (n-i!=1)
					printf("x^%d",n-i);
				else if (n-i==1)
					printf("x");
				flag=1;
			}
			else if (i==n)	{
				printf("%d",abs(a[i]));
				flag=1;
			}
		}
	}
	cout << endl;
	return 0;
} 
