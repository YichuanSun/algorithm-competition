#include <stdio.h>
#include <string.h>
#define N 401
int a[N]={0},b[N]={0},c[N]={0},d[N]={0};
int main()
{
	char str1[N],str2[N];
	while (scanf("%s %s",str1,str2)!=EOF)
	{
		int i,j,k;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		int len1=strlen(str1),len2=strlen(str2);
		for (i=0;str1[i]!='.'&&i<len1;i++);
		k=0;
		for (j=i+1;j<len1;j++)	//С���Ӹ�λ����λ 
			a[k++]=str1[j]-'0';
		k=0;
		for (j=i-1;j>=0;j--)		//�����ӵ�λ����λ 
			b[k++]=str1[j]-'0';
		k=0; 
		for (i=0;str2[i]!='.'&&i<len2;i++);
		for (j=i+1;j<len2;j++)	//С���Ӹ�λ����λ 
			c[k++]=str2[j]-'0';
		k=0;
		for (j=i-1;j>=0;j--)		//�����ӵ�λ����λ 
			d[k++]=str2[j]-'0';
		k=0;
		for (i=N;i>=0;i--)		//С��������� 
		{
			a[i]+=c[i];
			if (i!=0&&a[i]>9)
			{
				a[i]%=10;
				a[i-1]++;
			}
			else if (i==0&&a[i]>9)
			{
				a[i]%=10;
				b[0]++;
			}
		}
		for (i=0;i<N;i++)		//��������������� 
		{
			b[i]+=d[i];
			if (b[i]>9)
			{
				b[i]%=10;
				b[i+1]++;
			}
		}
		for (i=N;i>=0&&b[i]==0;i--); //����������� 
		for (j=i;j>=0;j--)
			printf("%d",b[j]);
		for (i=N;i>=0&&a[i]==0;i--);	//���С������ 
		if (i>=0)
		{
			printf(".");
			for (j=0;j<=i;j++)
			{
				printf("%d",a[j]); 
			}	
		}
		printf("\n");
	}
	return 0;
}
