#include <stdio.h>
#define N 1000
int main()
{
	int t,i;
	unsigned long long int a,b,c,d,sum;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%llu %llu %llu %llu",&a,&b,&c,&d);
		sum=a+b+c+d;
		if (sum==0&&a&b&c&d)
			printf("18446744073709551616\n");
		else
			printf("%llu\n",sum);
	}
	return 0;
}
