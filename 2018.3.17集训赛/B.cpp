#include <iostream>
#include <algorithm>
#include <cstring>
#define N 100
using namespace std;
char a[N],b[N];
int k=0,j=0;
int main()	{
	scanf("%s",a);
	if (a[0]=='-')	{
		printf("-");
		for (int i=strlen(a)-1;i>0;i--)
			b[k++]=a[i];
		j=1;
		while (b[j++]=='0');
		for (int i=j-1;b[i]!='\0';i++)
			printf("%c",b[i]);
		printf("\n");
	}
	else if (a[0]=='0')	{
		printf("0\n");
	}
	else
	{
		for (int i=strlen(a)-1;i>=0;i--)
			b[k++]=a[i];
		while (b[j++]=='0');
		for (int i=j-1;b[i]!='\0';i++)
			printf("%c",b[i]);
		printf("\n");
	}
	return 0;
} 
