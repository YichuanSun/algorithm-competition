#include <stdio.h>
#include <stdlib.h>
#define N 1000
int main()
{
	int t,n,A,B,L,i,j,Li,Ri,espend,eregain,r;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		int sum=0;
		scanf("%d %d %d %d",&n,&A,&B,&L);
		for (j=0;j<n;j++)
		{
			scanf("%d %d",&Li,&Ri);
			sum=sum+Ri-Li;
		}
		espend=sum*A;
		eregain=(L-sum)*B;
		r=espend-eregain;
		if (r<=0)
			printf("Case #%d: 0",i+1);
		else if (r>0)
			printf("Case #%d: %d",i+1,r);
	}
}
