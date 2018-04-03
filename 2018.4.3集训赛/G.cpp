#include <iostream>
#include <algorithm>
#include <memory.h>
#define N 100005
using namespace std;
int flag[N],box[N];
int main()	{
	int n,m,cnt=1,l,r;
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++)	box[i]=1;
	flag[1]=1;
	for (int i=0;i<m;i++)	{
		scanf("%d%d",&l,&r);
		if (flag[l])	{
			box[l]--;
			box[r]++;
			if (box[l])	{
				if (flag[r]==0)	{
					flag[r]=1;
					cnt++;
				}
			}
			else	{		//left里面没球了
				if (flag[r]==1)
					cnt--;
				flag[l]=0; 
				flag[r]=1;
				
			}
		}
		else {
			box[l]--;
			box[r]++;
		}
	}
	cout << cnt <<endl;
	return 0;
}
