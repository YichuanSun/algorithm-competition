#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000000

int a[N],b[N];
int main()	{
	int n;
	while (scanf("%d",&n)!=EOF)	{
		int i=0;
		memset(b,0,sizeof(b));
		while (i<n)	
			scanf("%d",&a[i++]);
		for(i=0;i<n;i++)
			b[a[i]]++;
		for (i=0;i<N;i++)
			if (b[i]>=(n+1)/2)
				break;
		printf("%d\n",i);
	}
	return 0;
} 
