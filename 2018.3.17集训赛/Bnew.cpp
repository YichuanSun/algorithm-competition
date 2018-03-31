#include <stdio.h>
#include <math.h>

int main()	{
	int n;
	scanf("%d",&n);
	if (n<0){
		n=-1*n;
		printf("-");
	}
	else if (n==0)	{
		printf("0");
	}
	while (n>0)	{
		if (n%10==0)
			n/=10;	
		else
			break;
	}
	while (n>0)	{
		printf("%d",n%10);
		n/=10;
	}
	printf("\n");
	return 0;
}
