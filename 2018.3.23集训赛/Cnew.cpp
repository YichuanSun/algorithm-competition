#include <iostream>
#include <algorithm>
using namespace std;
int covernode(int n,int c);
int number(int n,int cover);
int sum=0;
int main()	{
	int n,i,j;
	scanf("%d%d%d",&n,&i,&j);
	int cover=min(min(i+1,j+1),min(n-i,n-j));
	int num=number(n,cover);
	printf("%d\n",num);
	return 0;
}

int covernode(int n,int c)	{
	if (c==1)
		return sum=n*2+(n-2)*2;
	else
		return sum+=covernode(n,c-1);
}

int number(int n,int cover)	{
	int sum=0;
	for (int i=n;i>n-cover;i-=2)
		sum+=4*(i-1);
	return sum;
}
