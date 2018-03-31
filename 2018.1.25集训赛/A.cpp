#include <stdio.h>

int fab(int n)
{
	if (n<4)
		return n;
	else
		return fab(n-1)+fab(n-3);
}

int main()
{
	int n;
	while (scanf("%d",&n),n)
	{
		printf("%d\n",fab(n));
	}
	return 0;
} 
