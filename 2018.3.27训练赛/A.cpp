#include <iostream>
#include <algorithm>
using namespace std;

int main()	{
	int n,time=3,min=200000000;
	scanf("%d",&n);
	while (time--)	{
		int num,money,tmoney;
		scanf("%d %d",&num,&money);
		if (n%num!=0)	num=n/num+1;
		else num=n/num;
		tmoney=num*money;
		if (tmoney<min)	min=tmoney;
	}
	printf("%d\n",min);
	return 0;
}
