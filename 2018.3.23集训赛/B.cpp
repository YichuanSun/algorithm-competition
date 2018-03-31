#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int jud(int a,int b);
int main()
{
    int A,B,L,a,b,mina,minb;
    double min=100000;
    scanf("%d %d %d",&A,&B,&L);
    
    for (a=1; a<=L; a++)
        for (b=1; b<=L; b++)
            if (jud(a,b)&&(1.0*a/b-1.0*A/B)>=0&&(1.0*a/b-1.0*A/B)<min)	{
	            min=(1.0*a/b-1.0*A/B);
	            mina=a;
	            minb=b;	
            }
    printf("%d %d\n",mina,minb);
    return 0;
}

int jud(int a,int b)
{
    int Min=min(a,b);
    for (int i=2; i<=Min; i++)
        if (a%i==0&&b%i==0)
            return 0;
    return 1;
}


