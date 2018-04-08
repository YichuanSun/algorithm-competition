//dfs写不出来，我写错了。 
#include <iostream>
#include <algorithm>
#define N 1005
using namespace std;
int dfs(int n);
char a[N][N];
bool mark[N][N],death[N][N];
int ans[N];
int depth;
int length(int ans[N])	{
	int i=0;
	for (int j=0;j<depth;j++)
		if (ans[j])	i++;
	return i;
}
void print(){
	for (int i=depth-2;i>=0;i--)	{
		printf("%d",ans[i]);
		if (i==0)	printf(" 0\n");
		else printf(" "); 
	}
}
int main()	{
	scanf("%d",&depth);
	getchar();
	for (int i=0;i<depth;i++)	{
		for (int j=0;j<depth;j++)	{
			scanf("%c",&a[i][j]);
			if (a[i][j]=='1')	mark[i][j]=1;
		}
		getchar();
	}
	dfs(0);
	return 0;
}
int dfs(int n)	{
	int l=length(ans);
	if (l==depth-1)	{
		print();
		return 1;
	}
	for (int i=0;i<depth;i++)	{
		if (mark[n][i]==true)	{
			if (death[n][i])	{
				printf("impossible\n");
				return 0;
			}
			ans[n]=i;
			death[n][i]=true;
			dfs(i);
		}
	}
	return 0;
}
