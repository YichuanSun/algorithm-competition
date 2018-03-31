#include <stdio.h>

int fab(int n) 
{
	if (n==1||n==2)
		return 1;
	else
		return fab(n-1)+fab(n-2);
}

int main()
{
	int n,t;
	scanf("%d",&n);
	while (n--)
	{
		int t;
		scanf("%d",&t);
		printf("%d\n",fab(t));
	}
	return 0; 
}
