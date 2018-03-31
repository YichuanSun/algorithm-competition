#include <stdio.h>
#include <string.h>
#define N 81
char a[N],b[N];
int main()
{
	int i;
	gets(a);
	gets(b);
	for (i=0;b[i]!='\0';i++)
	{
		if (b[i]>='A'&&b[i]<='Z')
			printf("%c",a[b[i]-'A']-32);
		else if (b[i]>='a'&&b[i]<='z')
			printf("%c",a[b[i]-'a']);
		else
			printf("%c",b[i]);
	}
	printf("\n");
	return 0;
}
