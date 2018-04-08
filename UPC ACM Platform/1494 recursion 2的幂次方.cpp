#include <iostream>
#include <algorithm>
using namespace std;
void fun(int n);
int main()	{
	int n;
	while (scanf("%d",&n)!=EOF)	{
		fun(n);
		printf("\n");
	}
	return 0;
}

void fun(int n)	{
	if (n==0)	{
		printf("2(0)");
		return;
	}
	else if (n==1)	{
		printf("2");
		return;
	}
	int s=1,cnt=0;
	while (s<=n)	{
		s<<=1;
		cnt++;
	}s>>=1,cnt--;	//s是不大于它的最大2幂次数，cnts是几次方
	cout <<"s=" <<s<<endl;
	cout <<"cnt=" <<cnt<<endl;
	if (s==n)	{
		printf("2(");
		fun(s);
		printf(")");
	}
	else if (s<=n)	{
		printf("2(");
		fun(n-s);
		printf(")");
	}
}



