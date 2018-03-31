#include <stdio.h>
#include <math.h>

double cal(double x)
{
	return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}

int main()
{
	int t;
	double y;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lf",&y);
		if (cal(0)>y||cal(100)<y)
		{
			printf("No solution!\n");
			continue;
		}
		double mid,low=0,high=100;
		mid=(low+high)/2;
		while (fabs(cal(mid)-y)>1e-5)
		{
			if (cal(mid)>y)
				high=mid-1;
			else
				low=mid+1;
			mid=(low+high)/2;
		}
		printf("%.4lf\n",mid);
	}
	return 0;
} 
