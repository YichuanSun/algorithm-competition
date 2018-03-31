#include <iostream>
#include <algorithm>
#include <cmath>
#define N 3000
using namespace std;
int a[N][N];
int s=0,t=1,n;
void snake();
int main()	{
	int i,j;
	scanf("%d%d%d",&n,&i,&j);
	snake();
	printf("%d\n",a[i][j]);
	return 0;
}

void snake()	{
	int i,j,k,l;
	if (n!=0)	{
		for (i=s;i<n;i++)
			a[s][i]=t++;
		for (j=s+1;j<n;j++)
			a[j][i-1]=t++;
		for (k=i-2;k>=s;k--)
			a[j-1][k]=t++;
		for (l=j-2;l>s;l--)
			a[l][k+1]=t++;
		s++;
		n--;
		snake();
	}
	else	return;
}
