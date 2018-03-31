#include <stdio.h>
#include <string.h>
#define N 1000
char a[N],b[N],c[N];
int main()
{
	int i,j,k=0,n;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",a);
		getchar();
		scanf("%s",b);
		getchar();
		j=strlen(b);
		for (i=strlen(a);i>0;i--)
		{
			if (a[i]+b[j]-'0'<='9')
				c[k++]=a[i]+b[j]-'0';
			else
			{
				c[k++]=c[k]+a[i]+b[j]-'0'-10;
				c[k]++;
			}
			j--;
		}
		if (j>=0)
		{
			for (;b[j]!='\0';j--)
				c[k++]=b[j];
		}
		c[k]='\0';
	}
	puts(c);
}
