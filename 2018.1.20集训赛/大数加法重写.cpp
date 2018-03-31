#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define N 1001
char a[N],b[N],c[N],d[N];
int a1[N],b1[N],c1[N],d1[N];
int main()	{
	int n;
	scanf("%d",&n);
	while (n--)	{
		scanf("%s",a);
		scanf("%s",b);
		scanf("%s",c);
		scanf("%s",d);
		int k=0,t;
		for (int i=N-1;i>=0;i--)
			if (a[i]!='\0')
				a1[k++]=a[i]-'0';
		k=0;
		for (int i=N-1;i>=0;i--)
			if (b[i]!='\0')
				b1[k++]=b[i]-'0';
		k=0;
		for (int i=N-1;i>=0;i--)
			if (c[i]!='\0')
				c1[k++]=c[i]-'0';
		k=0;
		for (int i=N-1;i>=0;i--)
			if (d[i]!='\0')
				d1[k++]=d[i]-'0';
		for (int i=0;i<N;i++)	{
			a1[i]=a1[i]+b1[i];
			if (a1[i]>9)	{
				a1[i+1]++;
				a1[i]-=10;
			}
		}
		for (int i=0;i<N;i++)	{
			c1[i]=c1[i]+d1[i];
			if (c1[i]>9)	{
				c1[i+1]++;
				c1[i]-=10;
			}
		}
		for (int i=0;i<N;i++)	{
			a1[i]=a1[i]+c1[i];
			if (a1[i]>9)	{
				a1[i+1]++;
				a1[i]-=10;
			}
		}
		for (t=N-1;t>=0;t--)
			if (a1[t]!=0)	break;
		if (t==-1)	printf("0");
		else
			for (int i=t;i>=0;i--)
				printf("%d",a1[i]);
		printf("\n");
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		memset(c,'\0',sizeof(c));
		memset(d,'\0',sizeof(d));
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		memset(c1,0,sizeof(c1));
		memset(d1,0,sizeof(d1));
	}
	return 0;
}




