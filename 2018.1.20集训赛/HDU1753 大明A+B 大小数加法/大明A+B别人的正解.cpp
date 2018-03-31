#include <stdio.h>
#include <string.h>
#define N 500

int a[N],b[N],c[N],d[N];
/*
void store(char str[N],int decimal[N],int integer[N])
{
	int i,j,k=0;
	int len = strlen(str);
	for (i=0;i<len;i++)
		if (str[i]=='.')
			break;
	if (i<len)
		f=1;
	k=0;
	for (j=i+1;j<len;j++)
		decimal[k++]=str[j]-'0';
	k=0;
	for (j=i-1;j>=0;j--)
		integer[k++]=str[j]-'0';
}
*/
int main()
{
	char str1[N],str2[N];
	while (scanf("%s%s",str1,str2)!=EOF)
	{
		memset(a,0,N);
		memset(b,0,N);
		memset(c,0,N);
		memset(d,0,N);
		//store(str1,a,b);
		//store(str2,c,d);
		int i,j,k=0;		
		int f=0;
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		for (i=0;i<len1&&str1[i]!='.';i++);
		if (i<len1)
			f=1;
		k=0;
		for (j=i+1;j<len1;j++)
			a[k++]=str1[j]-'0';
		k=0;
		for (j=i-1;j>=0;j--)
			b[k++]=str1[j]-'0';
		
		for (i=0;i<len2;i++)
			if (str2[i]=='.')
				break;
		if (i<len2)
			f=1;
		k=0;
		for (j=i+1;j<len2;j++)
			c[k++]=str2[j]-'0';
		k=0;
		for (j=i-1;j>=0;j--)
			d[k++]=str2[j]-'0';
		i=j=k=0;
		for (i=N;i>=0;i--)
		{
			a[i]+=c[i];
			if (i!=0&&a[i]>=10)
			{
				a[i]-=10;
				a[i-1]++;
			}
			if (i==0&&a[i]>=10)
			{
				a[i]-=10;
				b[0]++;
			}
		}
		for (i=0;i<N;i++)
		{
			b[i]+=d[i];
			if (b[i]>=10)
			{
				b[i]%=10;
				b[i+1]++;
			}	
		}
		k=0;
		for (i=N;i>=0;i--)
		{
			if (b[i]!=0)
				k=1;
			if (k==1)
				printf("%d",b[i]);
		}
		if (k==0)
			printf("0");
		if (f==1)
		{
			for (i=N;i>=0;i--)		//判断小数位是不是全是0，如果不是，就输出小数点；如果是，就不输出小数点 
				if (a[i]!=0)
					break;
			if (i>=0)
			{
				printf(".");
				for (j=0;j<=i;j++)
					printf("%d",a[j]);
			}
		}
		printf("\n");f=0;
	}
	return 0;
}
