#include <iostream>
#include <algorithm>
#define M 5
#define N 203
using namespace std;

int main()	{
	int a[M][M]={0,-1,1,1,-1,1,0,-1,1,-1,-1,1,0,-1,1,-1,-1,1,0,1,1,1,-1,-1,0};
	int sa[N],sb[N],scorea=0,scoreb=0,na,nb,n;
	scanf("%d%d%d",&n,&na,&nb);
	for (int i=0;i<na;i++)
		scanf("%d",&sa[i]);
	for (int i=0;i<nb;i++)
		scanf("%d",&sb[i]);
	for (int i=0;i<n;i++)	{
		int t=a[sa[i%na]][sb[i%nb]];
		if (t==1)
			scorea++;
		else if (t==-1)
			scoreb++;
	}
	printf("%d %d\n",scorea,scoreb);
	return 0;
}
