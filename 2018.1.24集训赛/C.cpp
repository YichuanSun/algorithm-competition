#include <stdio.h>
#include <string.h>
#define N 2010
char t[N];
int main()
{
	while (gets(t),t[0]!='#')
	{
		int i,j,k=0,l,p=0,f=0,max=0;
		for (i=0;t[i]!=' ';i++);	//i为第一个空格的出现处 
		for (j=i;t[j]!='\0';j++)	//j为下一个字符串的首处 
			if (t[j]!=' ')
				break;
		while (t[k]!=' ')
		{
			p=k;
			for (;t[p]!=' ';)
			{
				for (l=j;t[l]!='\0';l++)
					if (t[p++]!=t[l])
						break;
				if (t[l]=='\0')
					f++;
			}
			k++;
			if (max<f)
				max=f;
		}
		printf("%d\n",max);
	}
	return 0;
}
