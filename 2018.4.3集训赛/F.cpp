#include <iostream>
#include <algorithm>
using namespace std;

int main()	{
	int a,b;
	scanf("%d%d",&a,&b);	
	if (a<=0&&b>=0)	cout << "Zero" <<endl;
	else if (a>0)	printf("Positive\n");
	else {
		int k=b-a;
		if (k&1)	printf("Positive\n");
		else	printf("Negative\n"); 
	}
	return 0;
}
