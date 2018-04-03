#include <iostream>
#include <algorithm>
#include <memory.h>
#define N 10003
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
			if (box[l]>=2)	{
				if (!flag[r])	{
					flag[r]=1;
					cnt++;
				}
				box[l]--;
				box[r]++;
			}
			else if (box[l]<2){
				box[l]--;
				box[r]++;
				if (box[l]==0&&flag[r]==1)	{
					cnt--;
				}
				flag[r]=1;
				flag[l]=0;	
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
