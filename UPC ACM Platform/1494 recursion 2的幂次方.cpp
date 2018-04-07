#include <iostream>
#include <algorithm>
using namespace std;
void fun(int n);
int main()	{
	int n;
	while (scanf("%d",&n))	{
		fun(n);
	}
	return 0;
} 
void fun(int n)	{
	int cnt=0,ntemp=n;
	while (ntemp)	{
		ntemp>>=1;
		cnt++;
		if (ntemp<=n>>1)	break;
	}
	fun(ntemp);
	
}
