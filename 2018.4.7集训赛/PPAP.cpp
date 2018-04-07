#include <iostream>
#include <algorithm>

using namespace std;

int main()	{
	int n;
	scanf("%d",&n);
	while (n--)	{
		string a,b,c;
		cin >> a;
		cin >> b;
		c=b+a;
		c[0]+='A'-'a';
		cout << c << endl; 
	}
	return 0;
}
