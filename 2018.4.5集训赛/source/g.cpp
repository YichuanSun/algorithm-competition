//including standard libraries
#include <iostream>	//	for standard input/output systems

using namespace std;

int main ()
{
	const int MAX = 99999;
	int n=10;
	int v=2000;
	int *coin_set =  new int[n];
	int *num_coin = new int[v+1];
	int *amt_coin = new int[v+1];
	int *ans_set = new int[n];
	while(cin >> v >> n)
	{
		for (int i=0;i<n;i++)
		{
			coin_set[i]=0;
			ans_set[i]=0;
		}
		for (int i=0;i<=v;i++)
			num_coin[i]=MAX;
		num_coin[0] = 0;
		for (int i=0;i<=v;i++)
			amt_coin[i]= -1;

		for (int i=0;i<n; i++)
			cin >> coin_set[i];
		
		for (int i = 0; i <= v; i++)
		{
			for (int j=0; j< n ; j++)
			{
				if (i >= coin_set[j])
				{
					int tmp = 1 + num_coin[i-coin_set[j]]; 
					if (num_coin[i] > tmp)
					{
						num_coin[i] = tmp;
						amt_coin[i] = j;
					}
				}	
			}	
		}

		//generate result
		int amt = v;
		while  (amt_coin[amt]!=-1)
		{
			ans_set[amt_coin[amt]]++;;
			amt = amt - coin_set[amt_coin[amt]];
		}
		
		//display result

		if (amt_coin[v]==-1)
			cout << -1 << endl;
		else {
			cout << ans_set[0];
			for (int i=1;i<n;i++)
				cout << " " << ans_set[i];
			cout << endl;
		}
	}
	return 0;
}
