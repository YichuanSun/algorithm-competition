#include <stdio.h>
#include <string.h>
#define N 1000002
char a[N],b[N];

int main()	{
	gets(a);
	gets(b);
	strcat(a," ");
	strcat(b," ");
	lena=strlen(a);
	lenb=strleb(b);
	int i=0,j=0,time=0;
	while (j<lenb)	{
		if (b[j]==' '||j==0)	{
			for (i=0;i<lena;i++)	{
				if (a[i]==b[j])	{
					i++;j++;
				}
			}
			if (i==lena)	{
				time++;
			}
			else	j++;
		}
		else {
			j++;
		}
	}
	return 0;
}
