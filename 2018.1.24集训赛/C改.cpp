#include <stdio.h>
#include <string.h>
#define N 1003
char a[N],b[N];
int main()
{
	int k;
	while (scanf("%s",a))
	{
		int f=0;
		if (a[0]=='#')
			break;
		scanf("%s",b);
		int lenb=strlen(b);
		for (int i=0;a[i]!='\0';i++)
		{
			k=i;
			for (int j=0;b[j]!='\0';j++)
			{
				if (a[k]!=b[j])
					break;
				else
					k++;
			}
			if (k==i+lenb)
			{
				f++;
				i=i+lenb-1;
			} 
				
		}
		printf("%d\n",f);
	}
	return 0;
}
