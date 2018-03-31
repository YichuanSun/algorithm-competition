#include <iostream>
#include <cstdio>
#define N 103
void search(int i,int j);
char a[N][N];
int n,m;
int main()	{
	scanf("%d %d",&n,&m);
	getchar();
	for (int i=0;i<n;i++)	{
		for (int j=0;j<m;j++)
			scanf("%c",&a[i][j]);
		getchar();
	}
	for (int i=0;i<n;i++)	{
		for (int j=0;j<m;j++)	{
			if (a[i][j]=='*')
				printf("*"); 
			else
				search(i,j);
			if (j+1==m)	printf("\n");
		}
	}
	return 0;
}
void search(int i,int j)	{
	int flag=0;
	for (int di=-1;di<2;di++)
		for (int dj=-1;dj<2;dj++)
			{
				int x=i+di;
				int y=j+dj;
				if ((di!=0||dj!=0)&&x>=0&&x<n&&y>=0&&y<m)
					if (a[x][y]=='*')
						flag++;
			}
	printf("%d",flag);
}
