#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double fun(double x,double y);
int main()	{
	int n;
	double m;
	scanf("%d",&n);
	while (n--)	{
		double y,l=0,r=100;
		scanf("%lf",&y);
		if (fun(l,y)>0||fun(r,y)<0)	{
			printf("No solution!\n");
			continue;
		}
		m=(l+r)/2;
		while (fabs(fun(m,y))>0.0001)	{
			m=(l+r)/2;
			if	(fun(l,y)*fun(m,y)>0)	l=m;
			else	r=m;
		}
		printf("%.4lf\n",m);
	}
	return 0;
}

double fun(double x,double y)	{
	return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6-y;
}

