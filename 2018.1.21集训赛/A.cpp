#include<stdio.h>

int gcd(int n, int m) {
    if (m <= n) {
        return m == 0 ? n : gcd(m, n % m);
    } else {
        return gcd(m, n);
    }
}

int main()
{
	int a,b,i,n;
	scanf("%d",&n); 
	while (n--)
	{
		scanf("%d %d",&a,&b);
		for (i=b*2;;i+=b)
			if (gcd(a,i)==b)
				break;
		printf("%d\n",i);	
	}
	return 0;
}

